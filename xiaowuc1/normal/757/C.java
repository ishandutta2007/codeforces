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

public class C {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		long[] fact = new long[1000005];
		final int MOD = 1000000007;
		fact[0] = 1;
		for(int i = 1; i < fact.length; i++) {
			fact[i] = fact[i-1] * i;
			fact[i] %= MOD;
		}
		long ret = 1;
		int n = readInt();
		int m = readInt();
		long[] id = new long[m];
		while(n-- > 0) {
			int[] l = new int[readInt()];
			for(int i = 0; i < l.length; i++) {
				l[i] = readInt()-1;
			}
			update(id, l);
		}
		Map<Long, Integer> dp = new HashMap<Long, Integer>();
		for(long out: id) {
			if(!dp.containsKey(out)) {
				dp.put(out, 0);
			}
			dp.put(out, dp.get(out) + 1);
		}
		for(long out: dp.keySet()) {
			ret *= fact[dp.get(out)];
			ret %= MOD;
		}
		pw.println(ret);
		pw.close();
	}

	static long nextID = 1;
	
	public static void update(long[] id, int[] l) {
		Map<Integer, Integer> idToSize = new HashMap<Integer, Integer>();
		for(int out: l) {
			if(!idToSize.containsKey(out)) {
				idToSize.put(out, 0);
			}
			idToSize.put(out, idToSize.get(out) + 1);
		}
		Map<Integer, ArrayList<Integer>> sizeToIDS = new HashMap<Integer, ArrayList<Integer>>();
		for(int out: idToSize.keySet()) {
			int sz = idToSize.get(out);
			if(!sizeToIDS.containsKey(sz)) {
				sizeToIDS.put(sz, new ArrayList<Integer>());
			}
			sizeToIDS.get(sz).add(out);
		}
		for(int out: sizeToIDS.keySet()) {
			ArrayList<Integer> all = sizeToIDS.get(out);
			Map<Long, Long> nextIDMap = new HashMap<Long, Long>();
			for(int curr: all) {
				if(!nextIDMap.containsKey(id[curr])) {
					nextIDMap.put(id[curr], ++nextID);
				}
			}
			for(int curr: all) {
				id[curr] = nextIDMap.get(id[curr]);
			}
		}
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