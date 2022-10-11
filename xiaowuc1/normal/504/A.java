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

public class A {
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
			int[] deg = new int[n];
			int[] xor = new int[n];
			LinkedList<Integer> q = new LinkedList<Integer>();
			for(int i = 0; i < n; i++) {
				deg[i] = readInt();
				xor[i] = readInt();
				if(deg[i] == 1) {
					q.add(i);
				}
			}
			LinkedList<Integer>[] edges = new LinkedList[n];
			for(int i = 0; i < n; i++) {
				edges[i] = new LinkedList<Integer>();
			}
			int add = 0;
			while(!q.isEmpty()) {
				int curr = q.removeFirst();
				if(deg[curr] == 0) {
					continue;
				}
				int next = xor[curr];
				edges[curr].add(next);
				edges[next].add(curr);
				add++;
				deg[curr]--;
				xor[curr] = 0;
				deg[next]--;
				xor[next] ^= curr;
				if(deg[next] == 1) {
					q.add(next);
				}
			}
			pw.println(add);
			for(int i = 0; i < n; i++) {
				for(int out: edges[i]) {
					if(out > i) {
						pw.println(i + " " + out);
					}
				}
			}
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