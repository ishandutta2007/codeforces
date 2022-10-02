//package educational.round04;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni()-1;
		int[] a = na(n);
		int[][] ai = new int[n][];
		for(int i = 0;i < n;i++){
			ai[i] = new int[]{a[i], i};
		}
		Arrays.sort(ai, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return a[1] - b[1];
			}
		});
		int[][] dp = new int[n+1][n];
		for(int i = 0;i < n+1;i++){
			Arrays.fill(dp[i], Integer.MAX_VALUE / 2);
		}
		dp[0][m] = 0;
		int[][] rot = new int[n+1][n];
		int[][] prev = new int[n+1][n];
		int phase = 0;
		for(int i = 0;i < n;){
			int j = i;
			for(;j < n && ai[j][0] == ai[i][0];j++);
			for(int k = i, r = i+1, l = j-1;k < j;k++,r++,l++){
				if(r == j)r = i;
				if(l == j)l = i;
				// k->r
				for(int z = 0;z < n;z++){
					int u = d(ai[k][1], ai[r][1], n);
					if(u == 0)u = n;
					int d = dp[phase][z] + Math.min(d(z, ai[k][1], n), d(ai[k][1], z, n)) + n-u;
					if(dp[phase+1][ai[r][1]] > d){
//						tr(phase+1, z, ai[k][1], ai[l][1], d, "r", dp[phase][0], n-d(ai[k][1], ai[r][1], n));
						dp[phase+1][ai[r][1]] = d;
						prev[phase+1][ai[r][1]] = z;
						rot[phase+1][ai[r][1]] = 1;
					}
				}
				// k->l
				for(int z = 0;z < n;z++){
					int u = d(ai[l][1], ai[k][1], n);
					if(u == 0)u = n;
					int d = dp[phase][z] + Math.min(d(z, ai[k][1], n), d(ai[k][1], z, n)) + n-u;
					if(dp[phase+1][ai[l][1]] > d){
//						tr(phase+1, z, ai[k][1], ai[l][1], d);
						dp[phase+1][ai[l][1]] = d;
						prev[phase+1][ai[l][1]] = z;
						rot[phase+1][ai[l][1]] = 0;
					}
				}
			}
			
			i = j;
			phase++;
		}
		
		int min = Integer.MAX_VALUE;
		int argmin = -1;
		for(int i = 0;i < n;i++){
			if(dp[phase][i] < min){
				min = dp[phase][i];
				argmin = i;
			}
		}
		out.println(min);
		int cur = argmin;
		char[] dir = new char[n];
		int[] amount = new int[n];
		int q = n-1;
		while(phase >= 1){
			int r = rot[phase][cur];
			int p = prev[phase][cur];
			int last = cur;
			if(r == 0){
				for(int i = cur-1;;i--){
					if(i < 0)i += n;
					if(i == cur)break;
					if(a[i] == a[cur]){
						amount[q] = d(i, last, n);
						dir[q] = '+';
						q--;
						last = i;
					}
				}
			}else{
				for(int i = cur+1;;i++){
					if(i >= n)i = 0;
					if(i == cur)break;
					if(a[i] == a[cur]){
						amount[q] = d(last, i, n);
						dir[q] = '-';
						q--;
						last = i;
					}
				}
			}
			if(d(p, last, n) < d(last, p, n)){
				dir[q] = '+';
				amount[q] = d(p, last, n);
				q--;
			}else{
				dir[q] = '-';
				amount[q] = d(last, p, n);
				q--;
			}
			cur = p;
			phase--;
		}
		
		for(int i = 0;i < n;i++){
			out.print(dir[i]);
			out.println(amount[i]);
		}
	}
	
	int d(int f, int t, int n)
	{
		int x = t-f;
		if(x < 0)x += n;
		return x;
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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