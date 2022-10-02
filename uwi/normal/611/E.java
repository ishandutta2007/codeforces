//package gb2015;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] x = na(3);
		Arrays.sort(x);
		int[] t = na(n);
		for(int i = 0;i < n;i++){
			if(t[i] > x[0] + x[1] + x[2]){
				out.println(-1);
				return;
			}
		}
		
		int ret = 0;
		int[] f = new int[6];
		outer:
		for(int i = 0;i < n;i++){
			for(int j = 0;j < 3;j++){
				if(t[i] <= x[j]){
					f[j]++;
					continue outer;
				}
			}
			int p = 3;
			for(int j = 0;j < 3;j++){
				for(int k = j+1;k < 3;k++){
					if(t[i] <= x[j] + x[k]){
						f[p]++;
						continue outer;
					}
					p++;
				}
			}
			ret++;
		}
		int spe = 0;
		for(int i = 0;i < n;i++){
			if(x[0] + x[1] < t[i] && t[i] <= x[2]){
				spe++;
			}
		}
		int min = Integer.MAX_VALUE;
		while(f[2] >= spe){
			min = Math.min(min, check(Arrays.copyOf(f, 6)));
			f[2]--;
			f[3]++;
		}
		out.println(min+ret);
	}
	
	int check(int[] f)
	{
		f[0] -= f[5];
		f[1] -= f[4];
		f[2] -= f[3];
		int low = -1, high = 300000;
		while(high-low > 1){
			int h = (high+low)/2;
			int[] g = Arrays.copyOf(f, 6);
			if(g[0] > h){
				g[1] += g[0] - h;
			}
			if(g[1] > h){
				g[2] += g[1] - h;
			}
			if(g[2] <= h){
				high = h;
			}else{
				low = h;
			}
		}
		return f[3]+f[4]+f[5]+high;
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
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