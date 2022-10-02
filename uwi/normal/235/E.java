//package round146;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	int[][] makeams(int n)
	{
		boolean[] ok = new boolean[n+1];
		for(int i = 1;i*i <= n;i++){
			ok[i] = true;
			ok[n/i] = true;
		}
		
		int[] map = new int[n+1];
		int[] imap = new int[n+1];
		Arrays.fill(imap, -1);
		int p = 0;
		for(int i = 0;i <= n;i++){
			if(ok[i]){
				map[p] = i;
				imap[i] = p;
				p++;
			}
		}
		return new int[][]{Arrays.copyOf(map, p), imap};
	}
	
	void solve()
	{
		int a = ni(), b = ni(), c = ni();
		int[][] am = makeams(a);
		int[][] bm = makeams(b);
		int[][] cm = makeams(c);
		int A = am[0].length, B = bm[0].length, C = cm[0].length;
		long[][][] dp = new long[A][B][C];
		int[] primes = sieveEratosthenes(2000);
		dp[A-1][B-1][C-1] = 1;
		for(int p : primes){
			if(p*p > 2000)break; // 1 
			
//			tr(p);
			for(int i = 0;i < A;i++){
				for(int j = 0;j < B;j++){
					for(int k = 0;k < C;k++){
						if(dp[i][j][k] == 0)continue;
						int aa = am[0][i], bb = bm[0][j], cc = cm[0][k];
//						tr(aa, bb, cc);
						for(int e = 0, aaa = aa;aaa >= 1;e++, aaa/=p){
							for(int f = 0, bbb = bb;bbb >= 1;f++, bbb/=p){
								for(int g = 0, ccc = cc;ccc >= 1;g++, ccc/=p){
									if(e+f+g==0)continue;
									dp[am[1][aaa]][bm[1][bbb]][cm[1][ccc]] += dp[i][j][k] * (e+f+g+1);
								}
							}
						}
					}
				}
			}
			for(int i = 0;i < A;i++){
				for(int j = 0;j < B;j++){
					for(int k = 0;k < C;k++){
						dp[i][j][k] %= 1<<30;
					}
				}
			}
		}
		
		// 1  b
		// a  2ab
		
		int[] ua = num(primes, am[0], a);
		int[] ub = num(primes, bm[0], b);
		int[] uc = num(primes, cm[0], c);
		long ret = 0;
		for(int i = 0;i < A;i++){
			for(int j = 0;j < B;j++){
				for(int k = 0;k < C;k++){
					ret += dp[i][j][k]*(
							(long)(1+2*(ua[i]+ub[j]+uc[k])+
									4*(ua[i]*ub[j]+ub[j]*uc[k]+uc[k]*ua[i])+
									8*ua[i]*ub[j]*uc[k]-(
											Math.min(ua[i], ub[j])+
											Math.min(uc[k], ub[j])+
											Math.min(ua[i], uc[k])+
											Math.min(ua[i], Math.min(ub[j], uc[k]))*-2+
											Math.min(ua[i], ub[j])*uc[k]*2+
											Math.min(uc[k], ub[j])*ua[i]*2+
											Math.min(ua[i], uc[k])*ub[j]*2
											)
											)
							)%(1<<30);
				}
			}
		}
		out.println(ret%(1<<30));
	}
	
	int[] num(int[] primes, int[] am, int a)
	{
		int A = am.length;
		int[] ua = new int[A];
		int bor = Arrays.binarySearch(primes, (int)Math.sqrt(2000)+1);
		if(bor < 0)bor = -bor-1;
		for(int i = 0;i < A;i++){
			int ind = Arrays.binarySearch(primes, am[i]);
			if(ind < 0)ind = -ind-2;
			ua[i] = Math.max(ind - bor + 1, 0);
		}
		return ua;
	}
	
	public static int[] sieveEratosthenes(int n) {
		if(n <= 32){
			int[] primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
			for(int i = 0;i < primes.length;i++){
				if(n < primes[i]){
					return Arrays.copyOf(primes, i);
				}
			}
			return primes;
		}

		int u = n + 32;
		double lu = Math.log(u);
		int[] ret = new int[(int) (u / lu + u / lu / lu * 1.5)];
		ret[0] = 2;
		int pos = 1;

		int[] isp = new int[(n + 1) / 32 / 2 + 1];
		int sup = (n + 1) / 32 / 2 + 1;

		int[] tprimes = { 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
		for(int tp : tprimes){
			ret[pos++] = tp;
			int[] ptn = new int[tp];
			for(int i = (tp - 3) / 2;i < tp << 5;i += tp)
				ptn[i >> 5] |= 1 << (i & 31);
			for(int i = 0;i < tp;i++){
				for(int j = i;j < sup;j += tp)
					isp[j] |= ptn[i];
			}
		}

		// 3,5,7
		// 2x+3=n
		int[] magic = { 0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4,
				13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14 };
		int h = n / 2;
		for(int i = 0;i < sup;i++){
			for(int j = ~isp[i];j != 0;j &= j - 1){
				int pp = i << 5 | magic[(j & -j) * 0x076be629 >>> 27];
				int p = 2 * pp + 3;
				if(p > n)
					break;
				ret[pos++] = p;
				for(int q = pp;q <= h;q += p)
					isp[q >> 5] |= 1 << (q & 31);
			}
		}

		return Arrays.copyOf(ret, pos);
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
	
	public static void main(String[] args) throws Exception
	{
		new E().run();
	}
	
	public int ni()
	{
		try {
			int num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public long nl()
	{
		try {
			long num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public String ns()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n' || b == ' '));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n' || b == ' ')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
	}
	
	public char[] ns(int n)
	{
		char[] buf = new char[n];
		try{
			int b = 0, p = 0;
			while((b = is.read()) != -1 && (b == ' ' || b == '\r' || b == '\n'));
			if(b == -1)return null;
			buf[p++] = (char)b;
			while(p < n){
				b = is.read();
				if(b == -1 || b == ' ' || b == '\r' || b == '\n')break;
				buf[p++] = (char)b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}
	
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}