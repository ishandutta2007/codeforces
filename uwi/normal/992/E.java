//package round489;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E5 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		int[] a = na(n);
		int B = Math.max(1, (int)Math.sqrt(n));
		int D = 256;
		int mask = 64*D-1;
		long[][] maps = new long[n/B+1][D];
		
		long[] offset = new long[n/B+2];
		{
			long cum = 0;
			for(int i = 0;i < n;i++){
				if(i % B == 0)cum = 0;
				if(cum-a[i] <= 0){
					int v = h(cum-a[i])&mask;
					maps[i/B][v>>>6] |= 1L<<v;
				}
				cum += a[i];
				offset[i/B+1] += a[i];
			}
			for(int i = 0;i <= n/B;i++){
				offset[i+1] += offset[i];
			}
		}
		
		outer:
		for(int z = 0;z < Q;z++){
			int x = ni()-1, v = ni();
			int b = x/B;
			for(int i = b+1;i < maps.length;i++){
				offset[i] += v-a[x];
			}
			a[x] = v;
			
			Arrays.fill(maps[b], 0L);
			long cum = 0;
			for(int i = x/B*B;i < n && i < x/B*B+B;i++){
				if(cum-a[i] <= 0){
					int w = h(cum-a[i])&mask;
					maps[i/B][w>>>6] |= 1L<<w;
				}
				cum += a[i];
			}
			for(int i = 0;i <= n/B;i++){
				int h = h(-offset[i])&mask;
				if(maps[i][h>>>6]<<~h<0){
					long lcum = 0;
					for(int j = i*B;j < n && j < i*B+B;j++){
						if(lcum-a[j] + offset[i] == 0){
							out.println(j+1);
							continue outer;
						}
						lcum += a[j];
					}
				}
			}
			out.println(-1);
		}
	}
	
	int h(long x)
	{
		x ^= x>>>33;
		x *= 0xff51afd7ed558ccdL;
		x ^= x>>>33;
		x *= 0xc4ceb9fe1a85ec53L;
		x ^= x>>>33;
		return (int)x;
	}
	
	void run() throws Exception
	{
//		StringBuilder sb = new StringBuilder();
//		Random gen = new Random(1000000009L);
//		int n = 200000;
//		int Q = 200000;
//		sb.append(n + " ");
//		sb.append(Q + " ");
//		for(int i = 0;i < n;i++){
//			sb.append(gen.nextInt(1001) + " ");
//		}
//		sb.append("\n");
//		for(int i = 0;i < Q;i++){
//			sb.append(gen.nextInt(n)+1 + " ");
//			sb.append(gen.nextInt(1001) + "\n");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E5().run(); }
	
	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}