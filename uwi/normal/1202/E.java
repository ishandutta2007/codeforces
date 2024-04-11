//package educational.round70;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class ECRE5 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] t = ns().toCharArray();
		int n = ni();
		char[][] ss = new char[n][];
		for(int i = 0;i < n;i++)ss[i] = ns().toCharArray();

		int m = t.length;
		int[] hitsf;
		{
			TrieArrayByArray trie = new TrieArrayByArray(200005, 26);
			for(int i = 0;i < n;i++){
				trie.add(ss[i]);
			}
			trie.buildFailure();
			hitsf = trie.countHits(t);
		}
		
		int[] hitsb;
		t = rev_(t);
		for(int i = 0;i < n;i++){
			ss[i] = rev_(ss[i]);
		}
		{
			TrieArrayByArray trie = new TrieArrayByArray(200005, 26);
			for(int i = 0;i < n;i++){
				trie.add(ss[i]);
			}
			trie.buildFailure();
			hitsb = trie.countHits(t);
		}
		
		long ans = 0;
		for(int i = 0;i < m-1;i++){
			ans += (long)hitsf[i] * hitsb[m-1-(i+1)];
		}
		out.println(ans);
	}
	
	public static char[] rev_(char[] a)
	{
		for(int i = 0, j = a.length-1;i < j;i++,j--){
			char c = a[i]; a[i] = a[j]; a[j] = c;
		}
		return a;
	}
	
	public static class TrieArrayByArray {
		// root = 0
		public int K;
		public int[] next;
		public int gen;
		public int size;
		
		public int[] hit;
		
		public int[] fail;
		
		public static int f(char c)
		{
			return c - 'a';
		}
		
		public TrieArrayByArray(int n, int K)
		{
			this.K = K;
			this.size = n;
			this.next = new int[n*K];
			this.hit = new int[n];
			this.gen = 1;
			
			Arrays.fill(this.next, -1);
		}
		
		public void add(char[] s)
		{
			int cur = 0;
			for(char c : s){
				int v = f(c);
				int nex = next[cur*K+v];
				if(nex == -1)nex = next[cur*K+v] = gen++;
				cur = nex;
			}
			hit[cur]++;
		}
		
		public void buildFailure()
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
						int lch = next[to*K+i];
						if(lch != -1){
							fail[ch] = lch;
							hit[ch] += hit[lch];
							continue inner;
						}
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
		
		public int[] countHits(char[] q)
		{
			int[] hits = new int[q.length];
			int cur = 0;
			outer:
			for(int i = 0;i < q.length;i++){
				for(;cur != -1;cur = fail[cur]){
					int lch = next[cur*K+f(q[i])];
					if(lch != -1){
						hits[i] += hit[lch];
						cur = lch;
						continue outer;
					}
				}
				cur = 0;
			}
			return hits;
		}
		
		private void tr(Object... o) { System.out.println(Arrays.deepToString(o)); }
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
	
	public static void main(String[] args) throws Exception { new ECRE5().run(); }
	
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