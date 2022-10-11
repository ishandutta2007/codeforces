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

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int[] l = new int[n];
			Map<Integer, LinkedList<Integer>> indices = new HashMap<Integer, LinkedList<Integer>>();
			for(int i = 0; i < n; i++) {
				l[i] = readInt();
				if(!indices.containsKey(l[i])) {
					indices.put(l[i], new LinkedList<Integer>());
				}
				indices.get(l[i]).add(i);
			}
			for(int qqq = 0; qqq < 100; qqq++) {
				int i = (int)(n*Math.random());
				int j = (int)(n*Math.random());
				if(i != j) {
					l[i] ^= l[j];
					l[j] ^= l[i];
					l[i] ^= l[j];
				}
			}
			Arrays.sort(l);
			int maxSeen = -1;
			int ret = 0;
			for(int i = 0; i < n; i++) {
				maxSeen = Math.max(maxSeen, indices.get(l[i]).removeFirst());
				if(maxSeen == i) {
					ret++;
				}
			}
			pw.println(ret);
		}
		pw.close();
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