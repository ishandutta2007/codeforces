//package abbyy3.f;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		for(int i = 0;i < n;i++)a[i]--;
		int[] ia = new int[n];
		for(int i = 0;i < n;i++){
			ia[a[i]] = i;
		}
		int[] leap = new int[n-1];
		for(int i = 0;i < n-1;i++){
			if(ia[i] > ia[i+1]){
				leap[i] = 1;
			}
		}
		int[] ft = buildFenwick(leap);
		
		int Q = ni();
		for(int i = 0;i < Q;i++){
			int t = ni();
			if(t == 1){
				int x = ni()-1, y = ni()-1;
				int c = sumFenwick(ft, y-1) - sumFenwick(ft, x-1) + 1;
				out.println(c);
			}else{
				int x = ni()-1, y = ni()-1;
				int v = a[x], w = a[y];
				int d = a[x]; a[x] = a[y]; a[y] = d;
				if(v < n-1 && ia[v] > ia[v+1]){
					addFenwick(ft, v, -1);
				}
				if(v-1 >= 0 && ia[v-1] > ia[v]){
					addFenwick(ft, v-1, -1);
				}
				if(w+1 != v && w < n-1 && ia[w] > ia[w+1]){
					addFenwick(ft, w, -1);
				}
				if(w-1 != v && w-1 >= 0 && ia[w-1] > ia[w]){
					addFenwick(ft, w-1, -1);
				}
				d = ia[v]; ia[v] = ia[w];ia[w] = d;
				if(v < n-1 && ia[v] > ia[v+1]){
					addFenwick(ft, v, 1);
				}
				if(v-1 >= 0 && ia[v-1] > ia[v]){
					addFenwick(ft, v-1, 1);
				}
				if(w+1 != v && w < n-1 && ia[w] > ia[w+1]){
					addFenwick(ft, w, 1);
				}
				if(w-1 != v && w-1 >= 0 && ia[w-1] > ia[w]){
					addFenwick(ft, w-1, 1);
				}
			}
		}
	}
	
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}
	
	public static int[] buildFenwick(int[] a)
	{
		int n = a.length;
		int[] ft = new int[n+1];
		System.arraycopy(a, 0, ft, 1, n);
		for(int k = 2, h = 1;k <= n;k*=2, h*=2){
			for(int i = k;i <= n;i+=k){
				ft[i] += ft[i-h];
			}
		}
		return ft;
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
	
	public static void main(String[] args) throws Exception { new B2().run(); }
	
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