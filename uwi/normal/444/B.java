//package round254;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	long x;
	
	void solve()
	{
		int n = ni(), d = ni(), x = ni();
		this.x = x;
		int[] a = new int[n];
		int[] b = new int[n];
		int[] ia = new int[n+1];
	    for(int i = 0; i < n; i = i + 1){
	        a[i] = i + 1;
	        ia[i+1] = i;
	    }
	    ia[0] = -1;
	    for(int i = 0; i < n; i = i + 1){
	    	int L = i;
	    	int R = (int)(getNextX() % (i + 1));
	    	int dd = ia[a[L]]; ia[a[L]] = ia[a[R]]; ia[a[R]] = dd;
	    	int dum = a[L]; a[L] = a[R]; a[R] = dum;
	    }
	    for(int i = 0; i < n; i = i + 1){
	        if (i < d)
	            b[i] = 1;
	        else
	            b[i] = 0;
	    }
	    for(int i = 0; i < n; i = i + 1){
	    	int L = i;
	    	int R = (int)(getNextX() % (i + 1));
	    	int dum = b[L]; b[L] = b[R]; b[R] = dum;
	    }
	    
	    int[] bx = new int[d];
	    int z = 0;
	    for(int i = 0;i < n;i++){
	    	if(b[i] == 1)bx[z++] = i;
	    }
	    
//	    tr(a);
//	    tr(ia);
//	    tr(b);
//	    tr(bx);
	    
	    int[] v = new int[n+1];
	    Arrays.fill(v, 1);
	    int[] ft = buildFenwick(v);
	    
	    int[] ret = new int[n];
	    for(int val = n;val >= 1;val--){
	    	int y = ia[val];
	    	
	    	if(y+bx[0] < n && v[y+bx[0]] == 1){
	    		v[y+bx[0]] = 0;
	    		addFenwick(ft, y+bx[0], -1);
	    		ret[y+bx[0]] = val;
	    	}
	    	int ind = 0;
	    	while(ind+1 < d && y+bx[ind] < n){
		    	int aft = after(ft, y+bx[ind]);
		    	int pos = y+bx[ind+1];
		    	if(aft == -1 || aft >= n)break;
		    	if(pos >= n)break;
		    	if(pos >= aft){
			    	if(v[pos] == 1){
			    		v[pos] = 0;
			    		addFenwick(ft, pos, -1);
			    		ret[pos] = val;
			    	}
			    	ind++;
		    	}else{
		    		int u = Arrays.binarySearch(bx, aft-y);
		    		if(u < 0)u = -u-1;
		    		ind = u-1;
		    	}
	    	}
//	    	tr(restoreFenwick(ft));
	    }
	    for(int i = 0;i < n;i++){
	    	out.println(ret[i]);
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
		if(v == 0 || i < 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}
	
	public static int findGFenwick(int[] ft, int v)
	{
		int i = 0;
		int n = ft.length;
		for(int b = Integer.highestOneBit(n);b != 0 && i < n;b >>= 1){
			if(i + b < n){
				int t = i + b;
				if(v >= ft[t]){
					i = t;
					v -= ft[t];
				}
			}
		}
		return v != 0 ? -(i+1) : i-1;
	}
	
	public static int valFenwick(int[] ft, int i)
	{
		return sumFenwick(ft, i) - sumFenwick(ft, i-1);
	}
	
	public static int[] restoreFenwick(int[] ft)
	{
		int n = ft.length-1;
		int[] ret = new int[n];
		for(int i = 0;i < n;i++)ret[i] = sumFenwick(ft, i);
		for(int i = n-1;i >= 1;i--)ret[i] -= ret[i-1];
		return ret;
	}
	
	public static int before(int[] ft, int x)
	{
		int u = sumFenwick(ft, x-1);
		if(u == 0)return -1;
		return findGFenwick(ft, u-1)+1;
	}
	
	public static int after(int[] ft, int x)
	{
		int u = sumFenwick(ft, x);
		int f = findGFenwick(ft, u);
		if(f+1 >= ft.length-1)return -1;
		return f+1;
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
	
	long getNextX() {
	    x = (x * 37 + 10007) % 1000000007;
	    return x;
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
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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