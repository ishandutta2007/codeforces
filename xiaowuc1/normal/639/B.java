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
			int d = readInt();
			int h = readInt();
			/*
			 * Construction
			 * 1 to 2
			 * 2 to 3
			 * ...
			 * h to h+1
			 * h is base
			 */
			if(2*h < d) {
				pw.println(-1);
				continue;
			}
			if(d == 1 && n > 2) {
				pw.println(-1);
				continue;
			}
			int curr = 1;
			while(curr <= h) {
				pw.println((curr) + " " + (curr+1));
				curr++;
			}
			curr++;
			int extra = d - h;
			if(extra > 0) {
				int connect = curr;
				extra--;
				pw.println(1 + " " + connect);
				curr++;
				while(extra-- > 0) {
					pw.println(connect + " " + curr);
					connect = curr;
					curr++;
				}
			}
			while(curr <= n) {
				pw.println(h + " " + curr);
				curr++;
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