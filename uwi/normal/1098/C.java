//package round530;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	boolean ok(int h, int n, long s)
	{
		if(h == 1){
			return s == (long)n*(n+1)/2-(2*n-1);
		}
		
		long[] f = new long[n-1];
		Arrays.fill(f, 1);
		for(int i = 1;i < n-1;i++){
			s -= i;
		}
		
		int v = 0;
		long lim = h;
		for(int i = n-2;i >= 0 && s < 0;i--){
			if(v >= i)break;
			if(f[v] == lim){
				v++;
				lim *= h;
				if(lim > 1e12){
					lim = 1000000;
				}
			}
			int up = (int)Math.min(-s, i-v);
			s += up;
			f[i-up]++;
			f[i]--;
		}
//		tr(h, f, s);
		return s == 0;
	}
	
	int[] construct(int h, int n, long s)
	{
		if(h == 1){
			int[] par = new int[n];
			for(int i = 0;i < n;i++)par[i] = i-1;
			return par;
		}
		
		long[] f = new long[n-1];
		Arrays.fill(f, 1);
		for(int i = 1;i < n-1;i++){
			s -= i;
		}
		
		int v = 0;
		long lim = h;
		for(int i = n-2;i >= 0 && s < 0;i--){
			if(v >= i)break;
			if(f[v] == lim){
				v++;
				lim *= h;
				if(lim > 1e12){
					lim = 1000000;
				}
			}
			int up = (int)Math.min(-s, i-v);
			s += up;
			f[i-up]++;
			f[i]--;
		}
		
		int[] par = new int[n];
		par[0] = -1;
		int q = 0;
		int p = 1;
		for(int i = 0;i < n-1;i++){
			int rem = h;
			int op = p;
			for(int j = 0;j < f[i];j++){
				par[p++] = q;
				if(--rem == 0){
					q++;
					rem = h;
				}
			}
			q = op;
		}
		return par;
		
	}
	
	void solve()
	{
		int n = ni();
		long s = nl();
		if(!(2*n-1 <= s && s <= (long)n*(n+1)/2)){
			out.println("No");
			return;
		}
		s -= 2*n-1;
		
		int low = 0, high = n+1;
		while(high - low > 1){
			int h = high+low>>1;
			if(ok(h, n, s)){
				high = h;
			}else{
				low = h;
			}
		}
		int[] par = construct(high, n, s);
		out.println("Yes");
		for(int i = 1;i < n;i++){
			out.print(par[i]+1 + " ");
		}
		out.println();
	}
	
	public static void tf(boolean[]... b)
	{
		for(boolean[] r : b) {
			for(boolean x : r)System.out.print(x?'#':'.');
			System.out.println();
		}
		System.out.println();
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
	
	public static void main(String[] args) throws Exception { new C2().run(); }
	
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