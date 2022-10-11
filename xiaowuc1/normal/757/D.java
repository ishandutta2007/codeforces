import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

/*
br = new BufferedReader(new FileReader("input.txt"));
pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
br = new BufferedReader(new InputStreamReader(System.in));
pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
 */

public class D {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	static int[] need;
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		need = new int[1 << 21];
		int n = readInt();
		String s = nextToken();
		long ret = 0;
		for(int max = 1; max <= 21; max++) {
			ret += solve(s, max);
			ret %= MOD;
		}
		pw.println(ret);
		pw.close();
	}

	static final int MOD = 1000000007;
	
	public static int solve(String s, int max) {
		{
			Arrays.fill(need, 0);
			int len = 0;
			for(int i = 1; i <= max; i++) {
				if(Integer.bitCount(i) == 1) len++;
				for(int j = 0; j < need.length; j++) {
					if((j&(1<<(i-1))) == 0) {
						need[j] += len;
					}
				}
			}
		}
		Map<Integer, Integer>[] dp = new Map[s.length()+1];
		for(int i = 0; i < dp.length; i++) {
			dp[i] = new HashMap<Integer, Integer>();
			dp[i].put(0, 1);
		}
		int ret = 0;
		for(int i = 0; i < s.length(); i++) {
			if(dp[i].containsKey(-1 + (1 << max))) {
				ret += dp[i].get(-1 + (1 << max));
				ret %= MOD;
			}
			int now = 0;
			for(int j = i; j < s.length(); j++) {
				now *= 2;
				now += s.charAt(j) - '0';
				if(now > max) break;
				if(now == 0) continue;
				for(int key: dp[i].keySet()) {
					if(need[key] + i > s.length()) continue;
					int nextKey = key | (1 << (now - 1));
					if(!dp[j+1].containsKey(nextKey)) {
						dp[j+1].put(nextKey, 0);
					}
					dp[j+1].put(nextKey, (dp[j+1].get(nextKey) + dp[i].get(key)) % MOD);
				}
			}
		}
		if(dp[s.length()].containsKey((-1 + (1 << max)))) {
			ret += dp[s.length()].get(-1 + (1 << max));
			ret %= MOD;
		}
		return ret;
	}

	private static void exitImmediately()	{
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}

	private static String nextToken() throws IOException	{
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}