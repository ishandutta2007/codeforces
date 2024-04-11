//package ecr086;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class F4 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T > 0;T--)go();
	}
	
	public static int[] shuffle(int[] a, Random gen){ for(int i = 0, n = a.length;i < n;i++){ int ind = gen.nextInt(n-i)+i; int d = a[i]; a[i] = a[ind]; a[ind] = d; } return a; }

	
	// core [pos][rem]
	void go()
	{
		int n = ni();
		int[] a = na(n);
		int maxlen = 0;
		int arg = 0;
		
		for(int core = (1<<n)-1;core >= 1;core--){
			if(Integer.bitCount(core) <= maxlen)continue;
			int[] o = new int[n];
			int[] b = new int[n];
			
			int p = 0, q = 0;
			for(int i = 0;i < n;i++){
				if(core<<~i>=0){
					b[p++] = i;
				}else{
					o[q++] = i;
				}
			}
			b = Arrays.copyOf(b, p);
			o = Arrays.copyOf(o, q);
			
			int[] sums = new int[1<<p];
			for(int i = 1;i < 1<<p;i++){
				sums[i] = sums[i&i-1] + a[b[Integer.numberOfTrailingZeros(i)]];
			}
			
			boolean[][] dp = new boolean[q+1][1<<p];
			int[][] argmins = new int[q+1][1<<p];
			for(int i = 0;i <= q;i++){
				Arrays.fill(argmins[i], -1);
			}
			dp[0][0] = true;
			argmins[0][0] = 0;
			for(int i = 0;i < q;i++){
				for(int j = (1<<p)-1;j >= 0;j--){
					if(!dp[i][j])continue;
					int minpw = sums[argmins[i][j]] + (i == 0 ? 0 : a[o[i-1]]);
					int mask = ~j&(1<<p)-1;
					for(int l = mask;;l = l-1&mask){
						int npw = a[o[i]] + sums[l];
						if(minpw < npw){
							dp[i+1][j|l] = true;
							if(argmins[i+1][j|l] == -1 ||
									sums[l] < sums[argmins[i+1][j|l]]){
								argmins[i+1][j|l] = l;
							}
						}
						if(l == 0)break;
					}
				}
			}
			if(dp[q][(1<<p)-1]){
				maxlen = Integer.bitCount(core);
				arg = core;
			}
		}
		
		{
			int core = arg;
			int[] o = new int[n];
			int[] b = new int[n];
			
			int p = 0, q = 0;
			for(int i = 0;i < n;i++){
				if(core<<~i>=0){
					b[p++] = i;
				}else{
					o[q++] = i;
				}
			}
			b = Arrays.copyOf(b, p);
			o = Arrays.copyOf(o, q);
			int[] sums = new int[1<<p];
			for(int i = 1;i < 1<<p;i++){
				sums[i] = sums[i&i-1] + a[b[Integer.numberOfTrailingZeros(i)]];
			}
			
			boolean[][] dp = new boolean[q+1][1<<p];
			int[][] argmins = new int[q+1][1<<p];
			for(int i = 0;i <= q;i++){
				Arrays.fill(argmins[i], -1);
			}
			dp[0][0] = true;
			argmins[0][0] = 0;
			for(int i = 0;i < q;i++){
				for(int j = (1<<p)-1;j >= 0;j--){
					if(!dp[i][j])continue;
					int minpw = sums[argmins[i][j]] + (i == 0 ? 0 : a[o[i-1]]);
					int mask = ~j&(1<<p)-1;
					for(int l = mask;;l = l-1&mask){
						int npw = a[o[i]] + sums[l];
						if(minpw < npw){
							dp[i+1][j|l] = true;
							if(argmins[i+1][j|l] == -1 ||
									sums[l] < sums[argmins[i+1][j|l]]){
								argmins[i+1][j|l] = l;
							}
						}
						if(l == 0)break;
					}
				}
			}
			
			if(dp[q][(1<<p)-1]){
				int ptn = (1<<p)-1;
				int[] lasts = new int[q];
				for(int j = q;j >= 1;j--){
					int pl = argmins[j][ptn];
					lasts[j-1] = pl;
					ptn ^= pl;
				}
				
				out.println(n-lasts.length);
				boolean[] alive = new boolean[n];
				Arrays.fill(alive, true);
				
				int h = 0;
				for(int j = 0;j < n;j++){
					if(core<<~j>=0){
						for(int k = 0;k < lasts.length;k++){
							if(lasts[k]<<~h<0){
								int na = 0;
								for(int u = 0;u <= j;u++){
									if(alive[u])na++;
								}
								out.print(na + " ");
								na = 0;
								for(int u = 0;u <= o[k];u++){
									if(alive[u])na++;
								}
								out.println(na);
								alive[j] = false;
							}
						}
						h++;
					}
				}
				return;
			}
		}
	}
	
	
	
	void run() throws Exception
	{
//		int n = 15, m = 1;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(m + " ");
//		for(int rep = 0;rep < m;rep++){
//			sb.append(n + " ");
//			for (int i = 0; i < n; i++) {
//				sb.append(gen.nextInt(100)+1 + " ");
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
	
	public static void main(String[] args) throws Exception { new F4().run(); }
	
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