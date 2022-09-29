//package educational.round83;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T > 0;T--){
			go();
		}
	}
	
	void go()
	{
		int n = ni();
		int[] x = na(3);
		long[] a = new long[n];
		for(int i = 0;i < n;i++){
			a[i] = nl();
		}
		int D = 5000;
		int[][][] nim = new int[2][2][D];
		for(int i = 1;i < D;i++){
			for(int s = 0;s < 2;s++){
				for(int t = 0;t < 2;t++){
					long u = 0;
					for(int j = 0;j < 3;j++){
						if(j == 1 && s == 1)continue;
						if(j == 2 && t == 1)continue;
						int ns = j == 1 ? 1 : 0;
						int nt = j == 2 ? 1 : 0;
						u |= 1L<<nim[ns][nt][Math.max(i-x[j], 0)];
					}
					nim[s][t][i] = Long.numberOfTrailingZeros(~u);
				}
			}
//				tr(i, nim[0][0][i], nim[0][1][i], nim[1][0][i], nim[1][1][i]);
		}
//			for(int u = 0;u < 2;u++){
//				for(int v = 0;v < 2;v++){
//					for(int k = D-1;k >= D/2;k--){
//						assert nim[u][v][k] == nim[u][v][k-PE];
//					}
//				}
//			}
		
		int PE = 2520;
		int base = 0;
		for(long v : a){
			base ^= get(nim[0][0], v, D, PE);
		}
		
		long nwin = 0;
		for(long v : a){
			base ^= get(nim[0][0], v, D, PE);
			
			if((base ^ get(nim[0][0], v-x[0], D, PE)) == 0)nwin++;
			if((base ^ get(nim[1][0], v-x[1], D, PE)) == 0)nwin++;
			if((base ^ get(nim[0][1], v-x[2], D, PE)) == 0)nwin++;
			
			base ^= get(nim[0][0], v, D, PE);
		}
		out.println(nwin);
	}
	
	int get(int[] a, long v, int D, int pe)
	{
		if(v < 0)return a[0];
		if(v < D){
			return a[(int)v];
		}else{
			return a[(int)((v-D)%pe-pe+D)];
		}
	}
	
	public static boolean inc(int[] a, int base) {
		int n = a.length;
		int i;
		for (i = n - 1; i >= 0 && a[i] == base - 1; i--)
			;
		if (i == -1)
			return false;

		a[i]++;
		Arrays.fill(a, i + 1, n, 0);
		return true;
	}

	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new F2().run(); }
	
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