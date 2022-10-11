import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*; 
import java.util.*;
import java.util.regex.*;
/*
	  br = new BufferedReader(new FileReader("input.txt"));
	  pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
	  br = new BufferedReader(new InputStreamReader(System.in));
	  pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
 */


public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		long[] fact = new long[100005];
		fact[0] = 1;
		for(int i = 1; i < fact.length; i++) {
			fact[i] = fact[i-1] * i;
			fact[i] %= MOD;
		}
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int k = readInt();
			int fill = 0;
			Map<Integer, Integer> count = new HashMap<Integer, Integer>();
			while(n-- > 0) {
				int curr = readInt();
				if(valid(curr)) {
					Integer value = count.get(curr);
					if(value == null) value = 0;
					count.put(curr, ++value);
				}
				else {
					fill++;
				}
			}
			long[] dp = new long[count.size()+1];
			dp[0] = 1;
			for(int out: count.values()) {
				long[] next = new long[count.size()+1];
				for(int i = 0; i < dp.length; i++) {
					next[i] += dp[i];
					if(next[i] >= MOD) next[i] -= MOD;
					if(i+1 < next.length) {
						next[i+1] += out * dp[i];
						next[i+1] %= MOD;
					}
				}
				dp = next;
			}
			long ret = 0;
			for(int i = 0; i < dp.length && i <= k; i++) {
				if(i + fill >= k) {
					long curr = dp[i];
					// fill choose (k-i) 
					curr *= fact[fill];
					curr %= MOD;
					curr *= inv(fact[fill-(k-i)]);
					curr %= MOD;
					// fill choose (k-i) 
					curr *= inv(fact[k-i]);
					curr %= MOD;
					ret += curr;
					ret %= MOD;
				}
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	static final int MOD = 1000000007;
	public static long inv(long b) {
		return modpow(b, MOD-2, MOD);
	}
	public static long modpow(long b, long e, long m) {
		long r = 1;
		while(e > 0) {
			if(e%2==1) {
				r*=b;
				r%=m;
			}
			b*=b;
			b%=m;
			e/=2;
		}
		return r;
	}
	
	public static boolean valid(int x) {
		while(x > 0) {
			int c = x%10;
			if(c != 4 && c != 7) return false;
			x /= 10;
		}
		return true;
	}
	
	private static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private static String nextLine() throws IOException  {
		if(!br.ready()) {
			exitImmediately();
		}
		st = null;
		return br.readLine();
	}

	private static String nextToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			if(!br.ready()) {
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}