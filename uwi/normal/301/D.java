//package round182;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] P = na(n);
		int[] ip = new int[n];
		for(int i = 0;i < n;i++){
			ip[P[i]-1] = i;
		}
//		int[][] es = new int[2500000][];
		long[] es = new long[2500000];
		int p = 0;
		for(int d = 1;d <= n;d++){
			for(int i = d*2;i <= n;i += d){
				// d,i
				int x = ip[d-1];
				int y = ip[i-1];
				if(x > y){
					int u = x; x = y; y = u;
				}
//				es[p++] = new int[]{x, y, -1};
				es[p++] = (long)(300000-x)<<40|(long)0<<20|y;
			}
		}
		for(int i = 0;i < m;i++){
			int l = ni()-1, r = ni()-1;
//			es[p++] = new int[]{l, r, i};
			es[p++] = (long)(300000-l)<<40|(long)(i+1)<<20|r;
		}
		Arrays.sort(es, 0, p);
//		Arrays.sort(es, 0, p, new Comparator<int[]>() {
//			public int compare(int[] a, int[] b) {
//				if(a[0] != b[0])return -(a[0] - b[0]);
//				return a[2] - b[2];
//			}
//		});
		
		int[] ft = new int[n+2];
		int[] ret = new int[m];
		for(int i = 0;i < p;i++){
			int ind = (int)(es[i]>>>20&((1<<20)-1))-1;
			int l = 300000-(int)(es[i]>>>40);
			int r = (int)(es[i]&((1<<20)-1));
			if(ind == -1){
				addFenwick(ft, r, 1);
			}else{
				ret[ind] = sumFenwick(ft, r)+r-l+1;
			}
		}
		for(int i = 0;i < m;i++){
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
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}
	
	void run() throws Exception
	{
//		int n = 200000, m = n;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for(int i = 0;i < n;i++){
//			sb.append((n-i) + " ");
//		}
//		for(int i = 0;i < m;i++){
//			int a = gen.nextInt(n)+1;
//			int b = gen.nextInt(n)+1;
//			if(a > b){
//				int d = a; a = b; b = d;
//			}
//			sb.append(a + " " );
//			sb.append(b + " " );
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D2().run(); }
	
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