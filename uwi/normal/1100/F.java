//package round532;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F5 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int Q = ni();
		int[][] qs = new int[Q][];
		for(int i = 0;i < Q;i++){
			qs[i] = new int[]{ni()-1, ni()-1, i, -1};
		}
		dfs(0, n, qs, a);
		for(int[] v : qs){
			out.println(v[3]);
		}
	}
	
	int K = 20;
	
	void dfs(int l, int r, int[][] qs, int[] a)
	{
		if(qs.length == 0)return;
		if(r-l == 1){
			for(int[] q : qs){
				q[3] = a[l];
			}
			return;
		}
		int h = l+r>>1;
		int[][] bs = new int[h-l+1][];
		bs[0] = new int[K];
		for(int i = h-1;i >= l;i--){
			bs[h-i] = Arrays.copyOf(bs[h-i-1], K);
			add(bs[h-i], a[i]);
		}
		int[][] as = new int[r-h+1][];
		as[0] = new int[K];
		for(int i = h;i < r;i++){
			as[i-h+1] = Arrays.copyOf(as[i-h], K);
			add(as[i-h+1], a[i]);
		}
		
		int Q = qs.length;
		int[][] lqs = new int[Q][];
		int[][] rqs = new int[Q][];
		int lp = 0, rp = 0;
		for(int[] q : qs){
			if(q[1] < h){
				lqs[lp++] = q;
			}else if(q[0] >= h){
				rqs[rp++] = q;
			}else{
				int[] b = Arrays.copyOf(bs[h-q[0]], K);
				add(b, as[q[1]-h+1]);
				int w = 0;
				for(int i = K-1;i >= 0;i--){
					w = Math.max(w^b[i], w);
				}
				q[3] = w;
			}
		}
		dfs(l, h, Arrays.copyOf(lqs, lp), a);
		dfs(h, r, Arrays.copyOf(rqs, rp), a);
	}
	
	private int[] add(int[] b, int v)
	{
		while(v > 0){
			int h = 31-Integer.numberOfLeadingZeros(v);
			if(b[h] == 0){
				b[h] ^= v;
				break;
			}else{
				v ^= b[h];
			}
		}
		return b;
	}
	
	private void add(int[] b, int[] v)
	{
		for(int w : v)add(b, w);
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
	
	public static void main(String[] args) throws Exception { new F5().run(); }
	
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