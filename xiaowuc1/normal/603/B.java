import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.security.*;
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

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int k = readInt();
			final int MOD = 1000000007;
			if(k == 0) {
				long ret = 1;
				for(int a = 1; a < n; a++) {
					ret *= n;
					ret %= MOD;
				}
				pw.println(ret);
				continue;
			}
			long[] fact = new long[n+1];
			boolean[] seen = new boolean[n];
			int[] numCycles = new int[n+1];
			long ret = 1;
			fact[0] = 1;
			for(int i = 1; i <= n; i++) {
				fact[i] = fact[i-1] * i;
				fact[i] %= MOD;
			}
			for(int i = 0; i < n; i++) {
				if(seen[i]) continue;
				int len = 0;
				long curr = i;
				while(!seen[(int)curr]) {
					seen[(int)curr] = true;
					len++;
					curr *= k;
					curr %= n;
				}
				numCycles[len]++;
			}
			for(int i = 0; i <= n; i++) {
				if(numCycles[i] == 0) continue;
				long amtForOne = 0;
				for(int a = 1; a * a <= i; a++) {
					if(i%a == 0) {
						amtForOne += numCycles[a] * 1L * a;
						amtForOne %= MOD;
						if(a * a != i) {
							amtForOne += numCycles[(i/a)] * 1L * (i/a);
							amtForOne %= MOD;
						}
					}
				}
				for(int a = 0; a < numCycles[i]; a++) {
					ret *= amtForOne;
					ret %= MOD;
				}
			}
			pw.println(ret);
		}	
		exitImmediately();
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