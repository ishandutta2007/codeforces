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

public class D {
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
			int k = readInt();
			int[] ns = new int[3];
			int[] ts = new int[3];
			PriorityQueue<Integer>[] qs = new PriorityQueue[3];
			for(int i = 0; i < qs.length; i++) {
				qs[i] = new PriorityQueue<Integer>();
			}
			for(int i = 0; i < 3; i++) {
				ns[i] = readInt();
				for(int a = 0; a < ns[i]; a++) {
					qs[i].add(0);
				}
			}
			for(int i = 0; i < 3; i++) {
				ts[i] = readInt();
			}
			int ret = 0;
			while(k-- > 0) {
				int timeToStart = qs[0].peek();
				timeToStart = Math.max(timeToStart, qs[1].peek() - ts[0]);
				timeToStart = Math.max(timeToStart, qs[2].peek() - ts[0] - ts[1]);
				ret = Math.max(ret, timeToStart + ts[0] + ts[1] + ts[2]);
				qs[0].poll();
				qs[1].poll();
				qs[2].poll();
				qs[0].add(timeToStart + ts[0]);
				qs[1].add(timeToStart + ts[0] + ts[1]);
				qs[2].add(timeToStart + ts[0] + ts[1] + ts[2]);
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