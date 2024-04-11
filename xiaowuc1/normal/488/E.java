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
			if(n == 1) {
				pw.println("YES\n1");
			}
			else if(n == 4) {
				pw.println("YES\n1\n3\n2\n4");
			}
			else if(!prime(n)){
				pw.println("NO");
			}
			else {
				int phi = phi(n);
				ArrayList<Integer> f = f(phi);
				int ret = -1;
				for(int i = 2; ret == -1; i++) {
					boolean bad = false;
					for(int out: f) {
						if(modpow(i, phi/out, n) == 1) {
							bad = true;
						}
					}
					if(!bad) {
						ret = i;
					}
				}
				int[] ans = new int[n];
				ans[0] = 1;
				for(int i = 1; i < ans.length; i++) {
					if(i%2 == 1) {
						ans[i] = modpow(ret, i, n);
					}
					else {
						ans[i] = modpow(ret, n-i-1, n);
					}
				}
				ans[n-1] = n;
				pw.println("YES");
				for(int out: ans) {
					pw.println(out);
				}
			}
		}
		exitImmediately();
	}

	public static ArrayList<Integer> f(int n) {
		ArrayList<Integer> ret = new ArrayList<Integer>();
		for(int i = 2; i * i <= n; i++) {
			if(n%i==0) {
				ret.add(i);
				while(n%i == 0) n /= i;
			}
		}
		if(n > 1)
			ret.add(n);
		return ret;
	}

	public static int phi(int n) {
		int r = n;
		for(int i = 2; i * i <= n; i++) {
			if(n%i == 0) {
				r /= i;
				r *= i-1;
				while(n%i==0) {
					n /= i;
				}
			}
		}
		if(n > 1) {
			r /= n;
			r *= n-1;
		}
		return r;
	}

	public static int modpow(long b, long e, long m) {
		long r = 1;
		while(e > 0) {
			if(e%2 == 1) {
				r *= b;
				r %= m;
			}
			b *= b;
			b %= m;
			e /= 2;
		}
		return (int)r;
	}

	public static boolean prime(int n) {
		for(int i = 2; i * i <= n; i++) {
			if(n%i==0) return false;
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