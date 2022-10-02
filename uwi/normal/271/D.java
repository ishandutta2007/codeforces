//package round166;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] s = ns(1501);
		SuffixAutomaton sa = SuffixAutomaton.buildSuffixAutomaton(s);
		sa.filter = ns(26);
		sa.K = ni();
		out.println(sa.numberOfDistinctSubstrings());
	}
	
	public static class SuffixAutomaton {
		public int size;
		public int[] len; // initial
		public int[] link; // Failure Link
		public int[][] next; // 
		public int[] original; // clonedoriginal
		public char[] filter;
		public int K;
		
		private SuffixAutomaton(int sz) {
			size = sz;
			len = new int[sz];
			link = new int[sz];
			next = new int[sz][];
			original = new int[sz];
		}
		
		public static int enc(char c) { return c - 'a'; }
		public static char dec(int n) { return (char)('a'+n); }
		
		/**
		 * Suffix Automaton
		 * 1clone12|a|-1
		 * @param a
		 * @return
		 */
		public static SuffixAutomaton buildSuffixAutomaton(char[] a) {
			int n = a.length;
			int[] len = new int[2*n];
			int[] link = new int[2*n];
			int[][] next = new int[2*n][26];
			int[] original = new int[2*n];
			Arrays.fill(link, -1);
			for(int i = 0;i < 2*n;i++){
				Arrays.fill(next[i], -1);
			}
			Arrays.fill(original, -1);
			
			len[0] = 0;
			link[0] = -1;
			int last = 0;
			int sz = 1;
			
			// extend
			for(char c : a){
				int v = enc(c);
				int cur = sz++;
				len[cur] = len[last] + 1;
				int p;
				for(p = last; p != -1 && next[p][v] == -1; p = link[p]){
					next[p][v] = cur;
				}
				if(p == -1){
					link[cur] = 0;
				}else{
					int q = next[p][v];
					if(len[p] + 1 == len[q]){
						link[cur] = q;
					}else{
						int clone = sz++;
						original[clone] = original[q] != -1 ? original[q] : q;
						len[clone] = len[p]+1;
						System.arraycopy(next[q], 0, next[clone], 0, next[q].length);
						link[clone] = link[q];
						for(;p != -1 && next[p][v] == q; p = link[p]){
							next[p][v] = clone;
						}
						link[q] = link[cur] = clone;
					}
				}
				last = cur;
			}
			
			// topological sort
			int[] nct = new int[sz];
			for(int i = 0;i < sz;i++){
				for(int e : next[i]){
					if(e != -1)nct[e]++;
				}
			}
			int[] ord = new int[sz];
			int p = 1;
			ord[0] = 0;
			for(int r = 0;r < p;r++){
				for(int e : next[ord[r]]){
					if(e != -1 && --nct[e] == 0)ord[p++] = e;
				}
			}
			int[] iord = new int[sz];
			for(int i = 0;i < sz;i++)iord[ord[i]] = i;
			
			SuffixAutomaton sa = new SuffixAutomaton(sz);
			for(int i = 0;i < sz;i++){
				sa.len[i] = len[ord[i]];
				sa.link[i] = link[ord[i]] != -1 ? iord[link[ord[i]]] : -1;
				sa.next[i] = next[ord[i]];
				for(int j = 0;j < sa.next[i].length;j++)sa.next[i][j] = sa.next[i][j] != -1 ? iord[sa.next[i][j]] : -1;
				sa.original[i] = original[ord[i]] != -1 ? iord[original[ord[i]]] : -1;
			}
			
			return sa;
		}
		
		public String toString()
		{
			StringBuilder sb = new StringBuilder();
			for(int i = 0;i < size;i++){
				sb.append("{");
				sb.append(i).append("|");
				sb.append("len:").append(len[i]).append(", ");
				sb.append("link:").append(link[i]).append(", ");
				sb.append("original:").append(original[i]).append(", ");
				sb.append("next:{");
				for(int j = 0;j < 26;j++){
					if(next[i][j] != -1){
						sb.append(dec(j)).append(":").append(next[i][j]).append(",");
					}
				}
				sb.append("}}\n");
			}
			return sb.toString();
		}
		
		public int numberOfDistinctSubstrings()
		{
			int[][] dp = new int[size][K+1];
			for(int i = size-1;i >= 0;i--){
				dp[i][0] = 1;
				for(int u = 0;u < next[i].length;u++){
					int e = next[i][u];
					if(e != -1){
						if(filter[u] == '1'){
							for(int j = 0;j <= K;j++){
								dp[i][j] += dp[e][j];
							}
						}else{
							for(int j = 0;j < K;j++){
								dp[i][j+1] += dp[e][j];
							}
						}
					}
				}
			}
			int ret = -1;
			for(int i = 0;i <= K;i++){
				ret += dp[0][i];
			}
			return ret;
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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