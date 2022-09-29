//package round425;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), s = ni();
		int[][] ps = new int[n][];
		for(int i = 0;i < n;i++){
			ps[i] = na(3);
			ps[i][2]--;
		}
		int[][][] lr = group(ps, 2, 2);
		for(int[] u : lr[1]){
			u[0] = 1000000-u[0];
		}
		
		double low = 0, high = 1000005;
		outer:
		for(int rep = 0;rep < 50;rep++){
			double t = (high+low)/2; // 
			int[][] imoss = new int[2][];
			for(int z = 0;z < 2;z++){
				int[] imos = new int[1000005];
				int[][] row = lr[z];
				for(int[] p : row){
					double goalt = (double)p[0]/p[1];
					if(goalt <= t){
						// (575)
						imos[0]++;
						imos[1000001]--;
					}else{
						// d <= x <= d+(s-v)*(t(s+v)-d)/s
						double d = p[0], v = p[1];
						if(t*(s+v)-d >= 0){
							imos[p[0]]++;
							imos[(int)(Math.min(1000000, d+(s-v)*(t*(s+v)-d)/s)+1)]--;
						}
					}
				}
				for(int i = 0;i <= 1000000;i++){
					imos[i+1] += imos[i];
				}
				imoss[z] = imos;
			}
			for(int i = 0;i <= 1000000;i++){
				if(imoss[0][i] > 0 && imoss[1][1000000-i] > 0){ // t
					high = t;
					continue outer;
				}
			}
			low = t;
		}
		out.printf("%.14f\n", low);
	}
	
	int[][][] group(int[][] as, int ind, int lim)
	{
		int[][][] g = new int[lim][][];
		int[] gp = new int[lim];
		for(int[] a : as)gp[a[ind]]++;
		for(int i = 0;i < lim;i++)g[i] = new int[gp[i]][];
		for(int i = as.length-1;i >= 0;i--){
			int[] a = as[i];
			g[a[ind]][--gp[a[ind]]] = a;
		}
		return g;
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
	
	public static void main(String[] args) throws Exception { new C3().run(); }
	
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