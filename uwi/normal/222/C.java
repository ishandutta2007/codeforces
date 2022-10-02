//package round137;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class C2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int[] primes = sieveEratosthenes(10000000);
		int z = primes.length;
		int zz = -Arrays.binarySearch(primes, (int)Math.sqrt(10000000))-1;
		
		int n = ni(), m = ni();
		int[] num = new int[n];
		for(int i = 0;i < n;i++)num[i] = ni();
		int[] den = new int[m];
		for(int i = 0;i < m;i++)den[i] = ni();
		
		for(int i = 0;i < zz;i++){
			int p = 0, q = 0;
			while(true){
				while(p < n && num[p] % primes[i] != 0)p++;
				while(q < m && den[q] % primes[i] != 0)q++;
				if(p == n || q == m)break;
				num[p] /= primes[i];
				den[q] /= primes[i];
			}
		}
		
		int[] retnum = new int[n];
		int[] retden = new int[m];
		Arrays.fill(retnum, 1);
		Arrays.fill(retden, 1);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < zz;j++){
				while(num[i] % primes[j] == 0){
					num[i] /= primes[j];
					retnum[i] *= primes[j];
				}
			}
		}
		for(int i = 0;i < m;i++){
			for(int j = 0;j < zz;j++){
				while(den[i] % primes[j] == 0){
					den[i] /= primes[j];
					retden[i] *= primes[j];
				}
			}
		}
		
		int[][] num2 = new int[n][];
		for(int i = 0;i < n;i++){
			num2[i] = new int[]{num[i], i};
		}
		Arrays.sort(num2, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		int[][] den2 = new int[m][];
		for(int i = 0;i < m;i++){
			den2[i] = new int[]{den[i], i};
		}
		Arrays.sort(den2, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		
		for(int p = 0, q = 0;p < n && q < m;){
			if(num2[p][0] == den2[q][0]){
				num2[p][0] = den2[q][0] = 1;
				p++; q++;
			}else if(num2[p][0] < den2[q][0]){
				p++;
			}else{
				q++;
			}
		}
		for(int i = 0;i < n;i++){
			retnum[num2[i][1]] *= num2[i][0];
		}
		for(int i = 0;i < m;i++){
			retden[den2[i][1]] *= den2[i][0];
		}
		
		out.println(n + " " + m);
		for(int i = 0;i < n;i++){
			if(i > 0)out.print(" ");
			out.print(retnum[i]);
		}
		out.println();
		for(int i = 0;i < m;i++){
			if(i > 0)out.print(" ");
			out.print(retden[i]);
		}
		out.println();
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
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append(gen.nextInt(10000000)+1 + " ");
//		}
//		for(int i = 0;i < n;i++){
//			sb.append(gen.nextInt(10000000)+1 + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new C2().run();
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