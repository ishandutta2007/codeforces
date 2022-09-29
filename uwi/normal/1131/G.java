//package round541;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class G {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
//	String INPUT = "1 7\n" + 
//			"7\n" + 
//			"1 3 1 1 1 5 1\n" + 
//			"1 1 4 5 1 4 8\n" + "1 1 1";
//	String INPUT = "2 7\n" + 
//			"3\n" + 
//			"1 2 2\n" + 
//			"1 2 1\n" + 
//			"1\n" + 
//			"3\n" + 
//			"2\n" + 
//			"3\n" + 
//			"2 2\n" + 
//			"1 3\n" + 
//			"1 1";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] as = new int[n][];
		int[][] cs = new int[n][];
		for(int i = 0;i < n;i++){
			int K = ni();
			as[i] = na(K);
			cs[i] = na(K);
		}
		
		int[] hs = new int[m];
		long[] costs = new long[m];
		
		int p = 0;
		int Q = ni();
		for(int z = 0;z < Q;z++){
			int id = ni()-1, mul = ni();
			for(int j = 0;j < as[id].length;j++){
				hs[p] = as[id][j];
				costs[p] = (long)cs[id][j] * mul;
				p++;
			}
		}
		
//		tr(hs);
//		tr(costs);
//		
		assert p == m;
		
		out.println(minimumDominoCost(hs, costs));
	}
	
	long minimumDominoCost(int[] hs, long[] costs)
	{
		int n = hs.length;
		assert n == costs.length;
		int[] pre = enumDominoReaches(hs);
		int[] suf = enumDominoReaches(rev_(hs));
		
		int[][] g = hopBucket(suf, n);
		long[] dp = new long[n+1];
		Arrays.fill(dp, Long.MAX_VALUE / 2);
		dp[0] = 0;
		
		int[] stack = new int[n+1]; // pos
		int sp = 0;
		stack[sp++] = 0;
		for(int i = 0;i < n;i++){
			// merge
			// dp[pre[i], i) + cost[i]
			while(sp-2 >= 0 && stack[sp-2] >= pre[i]){
				dp[stack[sp-2]] = Math.min(dp[stack[sp-2]], dp[stack[sp-1]]);
				sp--;
			}
//			tr("stack", Arrays.copyOf(stack, sp));
			assert sp-1 >= 0;
			dp[i+1] = Math.min(dp[i+1], dp[stack[sp-1]] + costs[i]);
//			tr("z", i+1, dp[i+1]);
			stack[sp++] = i+1;
			
			// dp[j-1] + cost[j] (j -> i)
			for(int j = g[0][n-1-i];j != -1;j = g[1][j]){
				dp[i+1] = Math.min(dp[i+1], dp[n-1-j] + costs[n-1-j]);
			}
		}
		
//		tr(dp);
		return dp[n];
	}
	
	public int[][] hopBucket(int[] a, int m)
	{
		int n = a.length;
		int[] first = new int[m];
		Arrays.fill(first, -1);
		int[] next = new int[n];
		for(int i = n-1;i >= 0;i--) {
			next[i] = first[a[i]];
			first[a[i]] = i;
		}
		return new int[][]{first, next};
	}
	
	public static int[] rev(int[] a)
	{
		int[] b = new int[a.length];
		for(int i = 0;i < a.length;i++)b[a.length-1-i] = a[i];
		return b;
	}
	
	public static int[] rev_(int[] a)
	{
		for(int i = 0, j = a.length-1;i < j;i++,j--){
			int c = a[i]; a[i] = a[j]; a[j] = c;
		}
		return a;
	}


	
	int[] enumDominoReaches(int[] hs)
	{
		int n = hs.length;
		int[] reach = new int[n];
		int[] stack = new int[n];
		int sp = 0;
		for(int i = 0;i < n;i++){
			// fall (i-hs[i], i]
			int min = i-hs[i]+1;
			while(sp > 0 && stack[sp-1] > i-hs[i]) {
				min = Math.min(min, reach[stack[sp-1]]);
				sp--;
			}
			reach[i] = Math.max(min, 0);
			stack[sp++] = i;
		}
		return reach;
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
	
	public static void main(String[] args) throws Exception { new G().run(); }
	
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