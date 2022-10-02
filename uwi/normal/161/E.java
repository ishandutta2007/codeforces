//package vkcup2012.r1;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int[][][] count;
	
	void solve()
	{
		int[] primes = sieveEratosthenes(100000);
		boolean[] pb = new boolean[100001];
		for(int p : primes)pb[p] = true;
		count = new int[6][][];
		int[] d = {1, 10, 100, 1000, 10000, 100000};
		for(int l = 2;l <= 5;l++){
			count[l] = new int[l][d[l-1]];
			for(int f = 0;f < l;f++){
				for(int m = 0;m < d[l-1];m++){
					int base = (m-m%d[f])*10+m%d[f];
					int ct = 0;
					for(int x = 0;x <= 9;x++){
						if(pb[base+x*d[f]])ct++;
					}
					count[l][l-1-f][m] = ct;
				}
			}
		}
		
		for(int t = ni();t >= 1;t--){
			int p = ni();
			int n = Integer.toString(p).length();
			if(n == 1){
				out.println(1);
				continue;
			}
			char[] ps = Integer.toString(p).toCharArray();
			int[][] b = new int[n][n];
			for(int i = 0;i < n;i++){
				b[i][0] = b[0][i] = ps[i]-'0';
			}
			
			gct = 0;
			rec(1, 2, b, n);
			out.println(gct);
		}
	}
	
	long gct = 0;
	
	void rec(int r, int c, int[][] b, int n)
	{
		if(r == n-1){
			long lct = 1;
			for(int i = 1;i < n;i++){
				int q = 0;
				for(int j = 0;j < n;j++){
					if(i != j)q = q * 10 + b[i][j];
				}
				lct *= count[n][i][q];
			}
			gct += lct;
			return;
		}
		if(c == n){
			rec(r+1, r+2, b, n);
			return;
		}
		for(int i = 0;i <= 9;i++){
			b[c][r] = b[r][c] = i;
			rec(r, c+1, b, n);
		}
	}
	
	public static int[] sieveEratosthenes(int n)
	{
		if(n <= 32){
			int[] primes = {2,3,5,7,11,13,17,19,23,29,31};
			for(int i = 0;i < primes.length;i++){
				if(n < primes[i]){
					return Arrays.copyOf(primes, i);
				}
			}
			return primes;
		}
		
		int u = n+32;
		double lu = Math.log(u);
		int[] ret = new int[(int)(u/lu+u/lu/lu*1.5)];
		ret[0] = 2;
		int pos = 1;
		
		int[] isp = new int[(n+1)/32/2+1];
		int sup = (n+1)/32/2+1;
		
		int[] tprimes = {3,5,7,11,13,17,19,23,29,31};
		for(int tp : tprimes){
			ret[pos++] = tp;
			int[] ptn = new int[tp];
			for(int i = (tp-3)/2;i < tp<<5;i+=tp)ptn[i>>5] |= 1<<(i&31);
			for(int i = 0;i < tp;i++){
				for(int j = i;j < sup;j += tp)isp[j] |= ptn[i];
			}
		}
		
		// 3,5,7
		// 2x+3=n
		int[] magic = {0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14};
		int h = n/2;
		for(int i = 0;i < sup;i++){
			for(int j = ~isp[i];j != 0;j &= j-1){
				int pp = i<<5|magic[(j&-j)*0x076be629>>>27];
				int p = 2*pp+3;
				if(p > n)break;
				ret[pos++] = p;
				for(int q = pp;q <= h;q += p)isp[q>>5] |= 1<<(q&31);
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