//package corc2013.r1;
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
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		
		DJSet[] left = new DJSet[m+1];
		left[0] = new DJSet(n);
		int[] lclus = new int[m+1];
		lclus[0] = n;
		for(int i = 0;i < m;i++){
			left[i+1] = new DJSet(left[i]);
			lclus[i+1] = lclus[i];
			if(!left[i+1].union(from[i], to[i]))lclus[i+1]--;
		}
		
		DJSet[] right = new DJSet[m+1];
		right[m] = new DJSet(n);
		for(int i = m;i >= 1;i--){
			right[i-1] = new DJSet(right[i]);
			right[i-1].union(from[i-1], to[i-1]);
		}
		
		int K = ni();
		for(int i = 0;i < K;i++){
			int l = ni()-1, r = ni()-1;
			DJSet ds = new DJSet(left[l]);
			int lc = lclus[l];
			for(int j = 0;j < n;j++){
				int u = right[r+1].upper[j];
				if(u >= 0){
					if(!ds.union(j, u))lc--;
				}
			}
			out.println(lc);
		}
	}
	
	public static class DJSet { public int[] upper;
	public DJSet(DJSet o) { upper = Arrays.copyOf(o.upper, o.upper.length); }
	public DJSet(int n){ upper = new int[n]; Arrays.fill(upper, -1);} public int root(int x){	return upper[x] < 0 ? x : (upper[x] = root(upper[x]));}	public boolean equiv(int x, int y){ return root(x) == root(y);} public boolean union(int x, int y){ x = root(x);y = root(y);if(x != y) { if(upper[y] < upper[x]) { int d = x; x = y; y = d;	} upper[x] += upper[y]; upper[y] = x;} return x == y;} public int count(){ int ct = 0; for(int u : upper)if(u < 0)ct++; return ct; }}
	
	public static int[][][] packWD(int n, int[] from, int[] to, int[] w) {
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]][2];
		for(int i = 0;i < from.length;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
		}
		return g;
	}
	
	void run() throws Exception
	{
//		int n = 500, m = 10000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for(int i = 0;i < m;i++){
//			sb.append(gen.nextInt(n)+1 + " ");
////			sb.append(1 + " ");
//			sb.append(gen.nextInt(n)+1 + " ");
//		}
//		int k = 20000;
//		sb.append(k + " ");
//		for(int i = 0;i < k;i++){
//			int a = gen.nextInt(m)+1;
//			int b = gen.nextInt(m)+1;
//			if(a > b){
//				int d = a; a = b; b = d;
//			}
////			sb.append(1 + " ");
////			sb.append(gen.nextInt(m)+1 + " ");
//			sb.append(a + " ");
//			sb.append(b + " ");
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
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}