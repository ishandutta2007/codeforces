import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class D {
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
			TreeMap<Integer, Integer> bought = new TreeMap<Integer, Integer>();
			TreeMap<Integer, Integer> available = new TreeMap<Integer, Integer>();
			TreeMap<Integer, Integer> sold = new TreeMap<Integer, Integer>();
			while(n-- > 0) {
				int curr = readInt();
				int availableProfit = -1;
				int tradeProfit = -1;
				if(!available.isEmpty() && available.firstKey() < curr) {
					// we can make another sale! sales are good
					int toPurchase = available.firstKey();
					availableProfit = curr - toPurchase;
					/*
					update(available, toPurchase, -1);
					update(bought, toPurchase, 1);
					update(sold, curr, 1);
					*/
				}
				if(!sold.isEmpty() && sold.firstKey() < curr) {
					// we can sell for a higher price! let's do it
					int oldSell = sold.firstKey();
					tradeProfit = curr - oldSell;
					/*
					update(sold, oldSell, -1);
					update(sold, curr, 1);
					update(available, oldSell, 1);
					*/
				}
				if(tradeProfit < 0 && availableProfit < 0) {
					update(available, curr, 1);
				}
				else if(tradeProfit >= availableProfit) {
					int oldSell = sold.firstKey();
					update(sold, oldSell, -1);
					update(sold, curr, 1);
					update(available, oldSell, 1);
				}
				else {
					int toPurchase = available.firstKey();
					update(available, toPurchase, -1);
					update(bought, toPurchase, 1);
					update(sold, curr, 1);
				}
			}
			long ret = 0;
			for(int out: bought.keySet()) {
				ret -= out * 1L * bought.get(out);
			}
			for(int out: sold.keySet()) {
				ret += out * 1L * sold.get(out);
			}
			pw.println(ret);
		}
		pw.close();
	}

	private static void update(Map<Integer, Integer> m, int k, int v) {
		if(!m.containsKey(k)) {
			m.put(k, 0);
		}
		int nv = m.get(k) + v;
		if(nv == 0) m.remove(k);
		else m.put(k, nv);
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