//package round333;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class EX {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int P = 10000019;
	int mod = 1000000007;
	
	
	void solve()
	{
		int n = ni();
		K = ni();
		vs = new int[n+10050];
		ws = new int[n+10050];
		for(int i = 0;i < n;i++){
			vs[i] = ni();
			ws[i] = ni();
		}
		
		Q = ni();
		qs = new boolean[Q];
		ls = new int[n+10050];
		rs = new int[n+10050];
		for(int i = 0;i < n;i++){
			ls[i] = 0;
			rs[i] = Q+1;
		}
		
		int pex = n;
		for(int i = 0;i < Q;i++){
			int t = ni();
			if(t == 1){
				int v = ni(), w = ni();
				vs[pex] = v;
				ws[pex] = w;
				ls[pex] = i+1;
				rs[pex] = Q+1;
				pex++;
			}else if(t == 2){
				int x = ni()-1;
				rs[x] = i+1;
			}else{
				qs[i] = true;
			}
		}
		
		int[] inds = new int[pex];
		for(int i = 0;i < pex;i++)inds[i] = i;
		
		dp = new int[20][K+1];
		dfs(0, Q+1, inds, 0);
	}
	
	int[] vs, ws, ls, rs;
	boolean[] qs;
	int[][] dp;
	int K, Q;
	
	void dfs(int l, int r, int[] inds, int dep)
	{
		if(r - l == 0)return;
		// [l,h),[L,R)
		// L<h, l<R
		// max(L,l)<max(h,R)
		if(dep >= 1){
			System.arraycopy(dp[dep-1], 0, dp[dep], 0, K+1);
		}
		int[] linds = new int[inds.length];
		int[] rinds = new int[inds.length];
		int lp = 0, rp = 0;
		int h = l+r>>>1;
		
		for(int ind : inds){
			if(ls[ind] <= l && r <= rs[ind]){
				for(int i = K;i >= ws[ind];i--){
					dp[dep][i] = Math.max(dp[dep][i], dp[dep][i-ws[ind]] + vs[ind]);
				}
			}else{
				if(ls[ind] < h && l < rs[ind]){
					linds[lp++] = ind;
				}
				if(ls[ind] < r && h < rs[ind]){
					rinds[rp++] = ind;
				}
			}
		}
		if(r - l == 1){
			if(l-1 >= 0 && l-1 < Q && qs[l-1]){
				long hash = 0;
				for(int i = K;i >= 1;i--){
					hash = (hash * P + dp[dep][i]) % mod;
				}
				out.println(hash);
			}
			return;
		}
		
		dfs(l, h, Arrays.copyOf(linds, lp), dep+1);
		dfs(h, r, Arrays.copyOf(rinds, rp), dep+1);
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
	
	public static void main(String[] args) throws Exception { new EX().run(); }
	
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