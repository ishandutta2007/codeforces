//package round327;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Queue;

public class E4F3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		char[][] ss = new char[n][];
		for(int i = 0;i < n;i++)ss[i] = ns().toCharArray();
		int numnode = 1;
		for(char[] s : ss)numnode += s.length;
		TrieArrayByArray trie = new TrieArrayByArray(numnode, 2);
		int m = (n+1>>>6) + 1;
		long[][] g = new long[n+1][m];
		boolean[] ignore = new boolean[n+1];
		for(int i = 0;i < n;i++){
			ignore[i+1] = !trie.add(ss[i], i+1);
		}
		
		trie.buildFailure(g);
		for(int i = 0;i < n;i++){
			if(ignore[i+1])continue;
			int cur = 0;
			for(char x : ss[i]){
				if(trie.hit[cur] > 0){
					int hit = trie.hit[cur];
					g[i+1][hit>>>6] |= 1L<<hit;
				}
				cur = trie.next[cur*2+trie.f(x)];
			}
			assert trie.hit[cur] == i+1;
		}
		
		wfx(g);
		
		int[] mat = doBipartiteMatching(g, n+1);
//		tr(mat);
//		for(long[] u : g){
//			StringBuilder sb = new StringBuilder();
//			for(int i = 0;i < n;i++){
//				sb.append(u[i>>>6]>>>i&1);
//			}
//			tr(sb);
//		}
		boolean[] mincover = mincover(g, mat);
		List<Integer> ans = new ArrayList<>();
		for(int i = 1;i <= n;i++){
			if(!ignore[i] && !(mincover[i] || mincover[i+n+1])){
				ans.add(i);
			}
		}
		out.println(ans.size());
		for(int v : ans)out.print(v + " ");
		out.println();
	}
	
	void wfx(long[][] g)
	{
		int n = g.length;
		int m = g[0].length;
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				if(g[i][k>>>6]<<~k<0){
					for(int j = 0;j < m;j++){
						g[i][j] |= g[k][j];
					}
				}
			}
		}
	}
	
	boolean[] mincover(long[][] g, int[] mat)
	{
		int n = g.length, m = n;
		boolean[] z = new boolean[n+m];
		Queue<Integer> q = new ArrayDeque<Integer>();
		for(int i = 0;i < n;i++){
			if(mat[i] == -1){
				z[i] = true;
				q.add(i);
			}
		}
		while(!q.isEmpty()){
			int cur = q.poll();
			if(cur < n){
				for(int i = 0;i < m;i++){
					if(g[cur][i>>>6]<<~i<0 && mat[cur] != i && !z[i+n]){
						z[i+n] = true;
						q.add(i+n);
					}
				}
			}else{
				for(int i = 0;i < n;i++){
					if(mat[i] == cur-n && !z[i]){
						z[i] = true;
						q.add(i);
						break;
					}
				}
			}
		}
		
		// minimum vertex cover = (L and not Z) or (R and Z)
		for(int i = 0;i < n;i++)z[i] ^= true;
		return z;
	}
	
	public static int[] doBipartiteMatching(long[][] g, int m)
	{
		int n = g.length;
		if(n == 0)return new int[0];
		if(m == 0)return new int[n];
		int[] im = new int[m];
		Arrays.fill(im, -1);
		long[] visited = new long[g[0].length];
		int matched = 0;
		for(int i = 0;i < n;i++){
			if(visit(g, i, visited, im)) {
				Arrays.fill(visited, 0L);
				matched++;
			}
		}

		int[] ret = new int[n];
		Arrays.fill(ret, -1);
		for(int i = 0;i < m;i++){
			if(im[i] != -1)ret[im[i]] = i;
		}
		return ret;
	}

	public static boolean visit(long[][] g, int cur, long[] visited, int[] im)
	{
		if(cur == -1)return true;

		for(int j = 0;j < visited.length;j++){
			for(long x = g[cur][j]&~visited[j];x != 0;x &= x-1){
				int i = j<<6|Long.numberOfTrailingZeros(x);
				visited[j] |= 1L<<i;
				if(visit(g, im[i], visited, im)){
					im[i] = cur;
					return true;
				}
			}
		}
		return false;
	}

	public static void tf(boolean[][] b) {
		for (boolean[] r : b) {
			char[] s = new char[r.length];
			for (int i = 0; i < r.length; i++)
				s[i] = r[i] ? '#' : '.';
			System.out.println(new String(s));
		}
		System.out.println();
	}
	
	public class TrieArrayByArray {
		// root = 0
		public int K;
		public int[] next;
		public int gen;
		public int size;
		
		public int[] hit;
		
		public int[] fail;
		
		public TrieArrayByArray(int n, int K)
		{
			this.K = K;
			this.size = n;
			this.next = new int[n*K];
			this.hit = new int[n];
			this.gen = 1;
			
			Arrays.fill(this.next, -1);
		}
		
		public int f(char c)
		{
			return c - 'a';
		}
		
		public boolean add(char[] s, int id)
		{
			int cur = 0;
			for(char c : s){
				int v = f(c);
				int nex = next[cur*K+v];
				if(nex == -1)nex = next[cur*K+v] = gen++;
				cur = nex;
			}
			if(hit[cur] >= 1)return false;
			hit[cur] = id;
			return true;
		}
		
		public void buildFailure(long[][] g)
		{
			this.fail = new int[this.size];
			Arrays.fill(this.fail, -1);
			int[] q = new int[gen];
			int p = 1;
			for(int r = 0;r < p;r++){
				int cur = q[r];
				inner:
				for(int i = 0;i < K;i++){
					int ch = next[cur*K+i];
					if(ch == -1)continue;
					q[p++] = ch;
					for(int to = fail[cur]; to != -1; to = fail[to]){
						int fch = next[to*K+i];
						if(fch == -1)continue;
						fail[ch] = fch;
						if(hit[fch] >= 1 && hit[ch] >= 1){
							g[hit[ch]][hit[fch]>>>6] |= 1L<<hit[fch];
						}else if(hit[ch] == 0){
							hit[ch] = hit[fch];
						}
						continue inner;
					}
					fail[ch] = 0; // failed to root
				}
			}
			assert p == gen;
		}
		
		public int next(int cur, char c)
		{
			int val = f(c);
			for(;cur != -1;cur = fail[cur]){
				int ch = next[cur*K+val];
				if(ch != -1)return ch;
			}
			return 0;
		}
		
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
	
	public static void main(String[] args) throws Exception { new E4F3().run(); }
	
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