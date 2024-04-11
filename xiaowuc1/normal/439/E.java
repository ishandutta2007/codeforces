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

	static Map<State, Integer> dp;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		//int qq = Integer.MAX_VALUE;
		int qq = readInt();
		
		ArrayList<Integer>[] facs = new ArrayList[100001];
		for(int i = 0; i < facs.length; i++) {
			facs[i] = new ArrayList<Integer>();
		}
		for(int i = 2; i < facs.length; i++) {
			if(facs[i].isEmpty()) {
				for(int j = i; j < facs.length; j += i) {
					facs[j].add(i);
				}
			}
		}
		fact = new long[2000005];
		fact[0] = 1;
		for(int i = 1; i < fact.length; i++) {
			fact[i] = fact[i-1] * i;
			fact[i] %= MOD;
		}
		dp = new HashMap<State, Integer>();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			int f = readInt();
			State key = new State(n, f);
			if(dp.containsKey(key)) {
				pw.println(dp.get(key));
				continue;
			}
			long ret = 0;
			ret += distribute(n, f);
			for(int mask = 1; mask < 1 << facs[n].size(); mask++) {
				int out = 1;
				for(int a = 0; a < facs[n].size(); a++) {
					if((mask&(1<<a)) != 0) {
						out *= facs[n].get(a);
					}
				}
				if(n / out < f) continue;
				long change = distribute(n/out, f);
				if(Integer.bitCount(mask) % 2 == 0) {
					ret += change;
					ret %= MOD;
				}
				else {
					ret -= change;
					ret += MOD;
					ret %= MOD;
				}
			}
			pw.println(ret);
			dp.put(key, (int)ret);
		}
		exitImmediately();
	}
	
	static class State {
		public int x,y;
		public State(int a, int b) {
			x=a;
			y=b;
		}
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			State other = (State) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}
		
	}
	
	static long[] fact;
	static final int MOD = 1000000007;
	
	public static long distribute(int n, int k) {
		return combo(n-1, k-1);
	}
	
	public static long combo(int n, int k) {
		long ret = fact[n];
		ret *= inv(fact[k], MOD);
		ret %= MOD;
		ret *= inv(fact[n-k], MOD);
		ret %= MOD;
		return ret;
	}
	
	public static long inv(long b, long m) {
		return modpow(b, m-2, m);
	}
	
	public static long modpow(long b, long e, long m) {
		long r = 1;
		while(e > 0) {
			if(e%2==1) {
				r *= b;
				r %= m;
			}
			b *= b;
			b %= m;
			e /= 2;
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