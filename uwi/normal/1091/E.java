//package goodbye2018;
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
		int[] ds = rev_(radixSort(na(n)));
		
		int pa = 0;
		for(int d : ds)pa ^= d&1;
		
		long inf = 0, sup = 0;
		{
			int low = -1, high = n/2+2;
			while(high - low > 1) {
				int h = high+low>>1;
				int K = pa + 2*h;
				if(K > n) {
					high = h;
				}else if(ok1(K, ds)) {
					high = h;
				}else {
					low = h;
				}
			}
			inf = high*2+pa;
		}
		
		{
			int low = -1, high = n/2+2;
			while(high - low > 1) {
				int h = high+low>>1;
				int K = pa + 2*h;
				if(K > n) {
					high = h;
				}else if(ok2(K, ds)) {
					low = h;
				}else {
					high = h;
				}
			}
			sup = low*2+pa;
		}
		if(inf > sup) {
			out.println(-1);
			return;
		}
		for(long i = inf;i <= sup;i+=2) {
			out.print(i + " ");
		}
		out.println();
	}
	
	boolean ok1(int K, int[] ds)
	{
		int n = ds.length;
		int id = 0;
		for(int i = 0;i < ds.length;i++) {
			if(ds[i] > K) {
				id++;
			}
		}
		int[] d = new int[n+1];
		System.arraycopy(ds, 0, d, 0, id);
		System.arraycopy(ds, id, d, id+1, n-id);
		d[id] = K;
		
		n++;
		long[] cum = new long[n+1];
		for(int i = 0;i < n;i++){
			cum[i+1] = cum[i] + d[i];
		}
		
		int p = n-1;
		for(int k = 1;k <= id;k++){
			while(p >= 0 && d[p] < k)p--;
			long right = (long)k*(k-1);
			if(k < p+1){
				right += cum[n] - cum[p+1] + (long)k * (p-k+1);
			}else{
				right += cum[n] - cum[k];
			}
			long left = cum[k];
			if(left > right)return false;
		}
		return true;
	}
	
	boolean ok2(int K, int[] ds)
	{
		int n = ds.length;
		int id = 0;
		for(int i = 0;i < ds.length;i++) {
			if(ds[i] > K) {
				id++;
			}
		}
		int[] d = new int[n+1];
		System.arraycopy(ds, 0, d, 0, id);
		System.arraycopy(ds, id, d, id+1, n-id);
		d[id] = K;
		
		n++;
		long[] cum = new long[n+1];
		for(int i = 0;i < n;i++){
			cum[i+1] = cum[i] + d[i];
		}
		
		int p = n-1;
		for(int k = 1;k <= n;k++) {
			while(p >= 0 && d[p] < k)p--;
			if(k >= id+1) {
				long right = (long)k*(k-1);
				if(k < p+1){
					right += cum[n] - cum[p+1] + (long)k * (p-k+1);
				}else{
					right += cum[n] - cum[k];
				}
				long left = cum[k];
				if(left > right)return false;
			}
		}
		return true;
	}
	
	public static boolean simpleGraphic(int[] d)
	{
		int parity = 0;
		for(int v : d)parity ^= v;
		if(parity<<31<0)return false;
		
		Arrays.sort(d);
		for(int p = 0, q = d.length-1;p < q;p++,q--){
			int u = d[p]; d[p] = d[q]; d[q] = u;
		}
		int n = d.length;
		
		int[] cum = new int[n+1];
		for(int i = 0;i < n;i++){
			cum[i+1] = cum[i] + d[i];
		}
		
		int p = n-1;
		for(int k = 1;k <= n;k++){
			while(p >= 0 && d[p] < k)p--;
			int right = k*(k-1);
			if(k < p+1){
				right += cum[n] - cum[p+1] + k * (p-k+1);
			}else{
				right += cum[n] - cum[k];
			}
			int left = cum[k];
			if(left > right)return false;
		}
		return true;
	}
	
	public static int[] rev_(int[] a)
	{
		for(int i = 0, j = a.length-1;i < j;i++,j--){
			int c = a[i]; a[i] = a[j]; a[j] = c;
		}
		return a;
	}

	
	public static int[] radixSort(int[] f){ return radixSort(f, f.length); }
	public static int[] radixSort(int[] f, int n)
	{
		int[] to = new int[n];
		{
			int[] b = new int[65537];
			for(int i = 0;i < n;i++)b[1+(f[i]&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < n;i++)to[b[f[i]&0xffff]++] = f[i];
			int[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < n;i++)b[1+(f[i]>>>16)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < n;i++)to[b[f[i]>>>16]++] = f[i];
			int[] d = f; f = to;to = d;
		}
		return f;
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