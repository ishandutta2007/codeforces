//package round621;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E3 {
	InputStream is;
	PrintWriter out;
	// 12221
	String INPUT = "";
	
	public static long invl(long a, long mod) {
		long b = mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d;
			d = a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		return p < 0 ? p + mod : p;
	}

	
	void solve()
	{
		// no two cowssweetness100
		// sweetness
		// 
		// 1
		int n = ni(), m = ni();
		int[] s = na(n);
		int[][] cum = new int[n+1][n+1];
		for(int i = 0;i < m;i++){
			int a = ni(), b = ni();
			cum[a][b]++;
		}
		
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				cum[i][j] += cum[i][j-1];
			}
		}
		
		int[] f = new int[n+1];
		int[] rf = new int[n+1];
		for(int v : s)rf[v]++;
		
		int mod = 1000000007;
		long ans = 0;
		int maxnum = 0;
		long vt = 1;
		
		int[] pf = new int[n+1];
		int[] prf = new int[n+1];
		int[] vals = new int[n+1];
		int[] nums = new int[n+1];
		Arrays.fill(vals, 1);
		int numt = 0;
		for(int i = 0;i <= n;i++){
			// <= i, <=n-i
			if(i > 0)rf[s[i-1]]--;
			if(i > 0){
				for(int j = 1;j <= n;j++){
					if(pf[j] != f[j] || prf[j] != rf[j]){
						vt = vt * invl(vals[j], mod) % mod;
						numt -= nums[j];
						int L = cum[j][f[j]];
						int R = cum[j][rf[j]];
						if(L > R){
							int D = L; L = R; R = D;
						}
						if(L >= 1 && R >= 2){
							numt += 2;
							nums[j] = 2;
							vals[j] = L*(R-1);
							vt = vt * vals[j] % mod;
						}else if(R >= 1){
							numt++;
							nums[j] = 1;
							vals[j] = L+R;
							vt = vt * vals[j] % mod;
						}else{
							nums[j] = 0;
						}
						pf[j] = f[j];
						prf[j] = rf[j];
					}
				}
			}
			long myvt = vt;
			int mynum = i > 0 ? numt : -1;
			
			if(i > 0)f[s[i-1]]++;
			for(int j = 1;j <= n;j++){
				if(pf[j] != f[j] || prf[j] != rf[j]){
					vt = vt * invl(vals[j], mod) % mod;
					numt -= nums[j];
					
					int L = cum[j][f[j]];
					int R = cum[j][rf[j]];
					if(L > R){
						int D = L; L = R; R = D;
					}
					if(L >= 1 && R >= 2){
						numt += 2;
						nums[j] = 2;
						vals[j] = L*(R-1);
						vt = vt * vals[j] % mod;
					}else if(R >= 1){
						numt++;
						nums[j] = 1;
						vals[j] = L+R;
						vt = vt * vals[j] % mod;
					}else{
						nums[j] = 0;
					}
					pf[j] = f[j];
					prf[j] = rf[j];
				}
			}
			
			if(numt > maxnum){
				maxnum = numt;
				ans = vt;
			}else if(numt == maxnum){
				ans += vt;
			}
			if(mynum == maxnum){
				ans -= myvt;
			}
		}
		ans %= mod;
		if(ans < 0)ans += mod;
		
		out.println(maxnum + " " + ans);
	}
	
	static int[][] packD(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]];
		for (int i = 0; i < from.length; i++) {
			g[from[i]][--p[from[i]]] = to[i];
		}
		return g;
	}

	
	void run() throws Exception
	{
//		int n = 5000, m = 5000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(3)+1 + " ");
//		}
//		boolean[][] done = new boolean[n+1][n+1];
//		for(int i = 0;i < m;i++){
//			while(true){
//				int x = gen.nextInt(3)+1;
//				int y = gen.nextInt(n)+1;
//				if(!done[x][y]){
//					done[x][y] = true;
//					sb.append(x + " " + y + "\n");
//					break;
//				}
//			}
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E3().run(); }
	
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