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
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int s1 = readInt();
			int s2 = readInt();
			int k = readInt();
			String a = nextToken();
			String b = nextToken();
			int[] aHash = hash(a);
			int[] bHash = hash(b);
			int[] pows = new int[1001];
			pows[0] = 1;
			for(int i = 1; i < pows.length; i++) {
				pows[i] = (int)((pows[i-1]*HASH)%MOD);
			}
			// maxLen[i][j] is starting from a[i], b[j]
			int[][] maxLen = new int[a.length()][b.length()];
			for(int i = 0; i < a.length(); i++) {
				for(int j = 0; j < b.length(); j++) {
					int min = 0;
					int max = Math.min(a.length()-i, b.length()-j);
					while(min != max) {
						int mid = (min+max+1)/2;
						long aVal = aHash[i+mid] - aHash[i]*(long)pows[mid];
						aVal %= MOD; aVal += MOD; aVal %= MOD;
						long bVal = bHash[j+mid] - bHash[j]*(long)pows[mid];
						bVal %= MOD; bVal += MOD; bVal %= MOD;
						if(aVal == bVal) {
							min = mid;
						}
						else {
							max = mid-1;
						}
					}
					maxLen[i][j] = min;
				}
			}
			int[][] dp = new int[a.length()+1][b.length()+1];
			while(k-- > 0) {
				int[][] next = new int[a.length()+1][b.length()+1];
				for(int i = 0; i < dp.length; i++) {
					for(int j = 0; j < dp[i].length; j++) {
						next[i][j] = Math.max(next[i][j], dp[i][j]);
						if(i > 0) {
							next[i][j] = Math.max(next[i][j], next[i-1][j]);
						}
						if(j > 0) {
							next[i][j] = Math.max(next[i][j], next[i][j-1]);
						}
						if(i > 0 && j > 0) {
							next[i][j] = Math.max(next[i][j], next[i-1][j-1]);
						}
						if(i < a.length() && j < b.length()) {
							int inc = maxLen[i][j];
							next[i+inc][j+inc] = Math.max(next[i+inc][j+inc], dp[i][j] + inc);
						}
					}
				}
				dp = next;
			}
			int ret = 0;
			for(int[] out: dp) {
				for(int out2: out) {
					ret = Math.max(ret, out2);
				}
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	static final int MOD = 1000000007;
	static final long HASH = 3137;
	
	public static int[] hash(String s) {
		int[] ret = new int[s.length()+1];
		for(int i = 0; i < s.length(); i++) {
			ret[i+1] = (int)((ret[i]*HASH+s.charAt(i))%MOD);
		}
		return ret;
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
		String s = br.readLine();
		if(s == null) {
			exitImmediately();
		}
		st = null;
		return s;
	}

	private static String nextToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			st = new StringTokenizer(nextLine().trim());
		}
		return st.nextToken();
	}
}