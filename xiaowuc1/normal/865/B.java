import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class B {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			numSlices = readLong();
			ret = 0;
			ArrayList<State> lhs = new ArrayList<State>();
			ArrayList<State> rhs = new ArrayList<State>();
			long total = 0;
			while(n-- > 0) {
				long need = readInt();
				total += need;
				long a = readInt();
				long b = readInt();
				if(a == b) {
					ret += need * 1L * a;
				}
				else if(a < b) {
					ret += need * 1L * a;
					rhs.add(new State(need, b-a));
				}
				else {
					ret += need * 1L * b;
					lhs.add(new State(need, a-b));
				}
			}
			long pizzaCount = (total + (numSlices - 1)) / numSlices;
			Collections.sort(lhs);
			Collections.sort(rhs);
			pizzaCount -= cleanse(lhs);
			pizzaCount -= cleanse(rhs);
			if(pizzaCount == 0) {
				// nothing
			}
			else if(pizzaCount == 1) {
				ret += Math.max(singleton(lhs), singleton(rhs));
			}
			else {
				ret += singleton(lhs) + singleton(rhs);
			}
			pw.println(ret);
		}
		pw.close();
	}

	public static long singleton(ArrayList<State> l) {
		long ret = 0;
		long haveLeft = numSlices;
		for(int i = l.size()-1; haveLeft > 0 && i >= 0; i--) {
			long ate = Math.min(l.get(i).amt, haveLeft);
			haveLeft -= ate;
			ret += ate * l.get(i).inc;
		}
		return ret;
	}
	
	public static long cleanse(ArrayList<State> l) {
		long total = 0;
		for(State out: l) {
			total += out.amt; 
		}
		if(total == 0) return 0;
		long buy = total / numSlices;
		long own = buy * numSlices;
		for(int i = l.size()-1; i >= 0; i--) {
			long ate = Math.min(own, l.get(i).amt);
			ret += ate * l.get(i).inc;
			own -= ate;
			if(ate == l.get(i).amt) l.remove(i);
			else {
				l.get(i).amt -= ate;
				break;
			}
		}
		return buy;
	}
	
	static long numSlices;
	static long ret;
	
	static class State implements Comparable<State> {
		public long amt, inc;
		public State(long a, long b) {
			amt = a;
			inc = b;
		}
		public int compareTo(State s) {
			return Long.compare(inc, s.inc);
		}
	}
	
	public static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	public static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public static String nextLine() throws IOException {
		st = null;
		if(!br.ready()) {
			exitImmediately();
		}
		return br.readLine();
	}

	public static String nextToken() throws IOException {
		while(st == null || !st.hasMoreTokens()) {
			if(!br.ready()) {
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}