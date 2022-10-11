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
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int[] amt = new int[200001];
			while(n-- > 0) {
				amt[readInt()]++;
			}
			boolean odd = false;
			for(int out: amt) {
				odd |= out%2 == 1;
			}
			int div = 1;
			if(odd) {
				div = 2;
			}
			else {
				for(int i = 0; i < amt.length; i++) {
					amt[i] /= 2;
				}
			}
			long ret = 1;
			long exp = 1;
			for(int i = 0; i < amt.length; i++) {
				if(odd)
					exp *= amt[i]+1;
				else
					exp *= (2*amt[i] + 1);
				exp %= 2*(MOD-1);
				for(int a = 0; a < amt[i]; a++) {
					ret *= i;
					ret %= MOD;
				}
			}
			exp /= div;
			pw.println(modpow(ret, exp, MOD));
		}
		exitImmediately();
	}

	static final int MOD = 1000000007;
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