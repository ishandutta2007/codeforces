//package round454;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] s = ns().toCharArray();
		char[] t = ns().toCharArray();
		char[] u = new char[s.length*2];
		for(int i = 0;i < s.length;i++){
			u[2*i] = s[i];
			u[2*i+1] = t[i];
		}
		go(u);
	}
	
	void go(char[] s)
	{
		PalindromicTreeByArray pt = new PalindromicTreeByArray(s);
//		tr(pt.toDot(true, true));
//		tr(pt.slinks());
		
		int n = s.length;
		int[] sl = pt.slinks();
		int[] dp = new int[n+1];
		int[] adp = new int[pt.gen];
		Arrays.fill(dp, 99999999);
		Arrays.fill(adp, 99999999);
		
		int cur = 1;
		dp[0] = 0;
		int[] prev = new int[n+1];
		int[] aprev = new int[pt.gen+1];
		Arrays.fill(prev, -1);
		Arrays.fill(aprev, -1);
		
		for(int i = 0;i < n;i++){
			char x = s[i];
			while(i-pt.lens[cur]-1 < 0 || s[i-pt.lens[cur]-1] != x)cur = pt.links[cur]; // find xAx
			int xax = pt.next(x, cur); // already exists
			
			for(int j = xax;j > 1;j = sl[j]){
				int lenSeriesFirst = pt.lens[sl[j]] + (pt.lens[j] - pt.lens[pt.links[j]]);
				adp[j] = dp[i+1 - lenSeriesFirst];
				aprev[j] = i+1 - lenSeriesFirst;
				
				if(sl[j] != pt.links[j]){
					if(adp[pt.links[j]] < adp[j]){
						adp[j] = adp[pt.links[j]];
						adp[j] = adp[pt.links[j]];
						aprev[j] = aprev[pt.links[j]];
					}
				}
				
				if(adp[j] + 1 < dp[i+1] && i % 2 == 1){
					dp[i+1] = adp[j] + 1;
					prev[i+1] = aprev[j];
				}
			}
			if(i > 0 && s[i] == s[i-1] && dp[i-1] < dp[i+1] && i % 2 == 1){
				dp[i+1] = dp[i-1];
				prev[i+1] = i-1;
			}
			cur = xax;
		}
//		tr(adp);
//		tr(new String(s));
//		tr(dp);
		if(dp[n] <= n+10){
			out.println(dp[n]);
			int c = n;
			for(;c != 0;c = prev[c]){
				if(c-prev[c] > 2){
					out.println(prev[c]/2+1 + " " + c/2);
				}
			}
		}else{
			out.println(-1);
		}
	}
	
	public class PalindromicTreeByArray {
		int[] firsts, lens, freqs;
		int[] firstChilds, nexts, links;
		char[] cs;
		int gen;
		
		int[] slinks()
		{
			int[] slinks = new int[gen];
			Arrays.fill(slinks, 1);
			for(int i = 2;i < gen;i++){
				if(lens[i] - lens[links[i]] == lens[links[i]] - lens[links[links[i]]]){
					slinks[i] = slinks[links[i]];
				}else{
					slinks[i] = links[i];
				}
			}
			return slinks;
		}
		
		public PalindromicTreeByArray(char[] s)
		{
			build(s);
		}
		
		public int newNode(int first, int len, char c)
		{
			firsts[gen] = first;
			lens[gen] = len;
			cs[gen] = c;
			freqs[gen] = 0;
			firstChilds[gen] = -1;
			links[gen] = -1;
			nexts[gen] = -1;
			return gen++;
		}
		
		public int next(char x, int id)
		{
			for(int ch = firstChilds[id];ch != -1;ch = nexts[ch]){
				if(cs[ch] == x)return ch;
			}
			return -1;
		}
		
		public void add(int x, int id)
		{
			int ch = firstChilds[id];
			firstChilds[id] = x;
			nexts[x] = ch;
		}
		
		public String toString(int id) {
			return "Node [id=" + id + ", first=" + firsts[id] + ", len=" + lens[id] + ", freq=" + freqs[id] + ", c=" + cs[id]
					+ ", firstChild=" + firstChilds[id] + ", sibling=" + nexts[id]
					+ ", link=" + links[id] + "]";
		}
		
		public void build(char[] s)
		{
			assert gen == 0;
			int n = s.length;
			
			firsts = new int[n+2];
			lens = new int[n+2];
			freqs = new int[n+2];
			firstChilds = new int[n+2];
			nexts = new int[n+2];
			links = new int[n+2];
			cs = new char[n+2];
			
			int hell = newNode(-1, -1, (char)0);
			int zero = newNode(-1, 0, (char)0);
			assert hell == 0;
			assert zero == 1;
			links[zero] = hell; 
			links[hell] = hell;
			add(zero, hell);
			
			int cur = zero; // current suffix palindrome
			for(int i = 0;i < n;i++){
				char x = s[i];
				while(i-lens[cur]-1 < 0 || s[i-lens[cur]-1] != x)cur = links[cur]; // find xAx
				int xax = next(x, cur); // already exists
				if(xax == -1){
					// new subpalindrome
					xax = newNode(i-lens[cur]-1, lens[cur]+2, x);
					add(xax, cur);
					
					// make suffix link
					if(lens[xax] == 1){
						links[xax] = zero;
					}else{
						int b = links[cur];
						while(true){
							while(i-lens[b]-1 < 0 || s[i-lens[b]-1] != x)b = links[b]; // find xBx
							int xbx = next(x, b);
							if(xbx != -1){
								links[xax] = xbx;
								break;
							}
						}
					}
				}
				
				// [i-cur.len-1, i]
				freqs[xax]++; // increment regardless new or not
				
				cur = xax;
			}
			
			for(int i = gen-1;i >= 2;i--){
				freqs[links[i]] += freqs[i];
			}
		}
		
		public String toDot(boolean next, boolean suffixLink)
		{
			StringBuilder sb = new StringBuilder("digraph{\n");
			sb.append("graph[rankdir=LR];\n");
			sb.append("node[shape=circle];\n");
			for(int i = 0;i < gen;i++){
				if(suffixLink && links[i] != -1){
					sb.append("\"" + i + "\"")
					.append("->")
					.append("\"" + links[i] + "\"")
					.append("[style=dashed];\n");
				}
				
				if(next){
					for(int ch = firstChilds[i]; ch != -1;ch = nexts[ch]){
						sb.append("\"" + i + "\"")
						.append("->")
						.append("\"" + ch + "\"")
						.append("[label=\"")
						.append(cs[ch] == 0 ? ' ' : cs[ch])
						.append("\"];\n");
					}
				}
			}
			sb.append("}\n");
			return sb.toString();
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
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
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