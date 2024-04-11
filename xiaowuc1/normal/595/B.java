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
			int[] a = new int[n/k];
			for(int i = 0; i < a.length; i++) {
				a[i] = readInt();
			}
			int[] b = new int[n/k];
			for(int i = 0; i < a.length; i++) {
				b[i] = readInt();
			}
			long ans = 1;
			for(int i = 0; i < a.length; i++) {
				ans *= numRespect(a[i], b[i], k);
				ans %= 1000000007;
			}
			pw.println(ans);
		}
		exitImmediately();
	}

	public static long numRespect(long a, long b, int blockLength) {
		// compute total number of multiples with length <= blockLength
		long biggestValidNumber = pow(10, blockLength) - 1;
		long totalMultiple = numMultiple(biggestValidNumber, a);
		long biggestInvalidNumber = b;
		for(int i = 1; i <= blockLength - 1; i++) {
			biggestInvalidNumber *= 10;
			biggestInvalidNumber += 9;
		}
		long intermediateMultiple = numMultiple(biggestInvalidNumber, a);
		
		long answer = totalMultiple - intermediateMultiple;
		if(b > 0) {
			long biggestValidNumberLessThanInvalid = biggestInvalidNumber - pow(10, blockLength-1);
			long smallerValidMultiples = numMultiple(biggestValidNumberLessThanInvalid, a);
			answer += smallerValidMultiples;
		}
		return answer;
	}
	
	public static long pow(long b, long e) {
		// returns b^e
		long r = 1;
		for(int i = 1; i <= e; i++) {
			r *= b;
		}
		return r;
	}
	
	public static long numMultiple(final long MAX, long k) {
		// returns a number X - there are X multiple of K <= MAX
		return MAX / k + 1;
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