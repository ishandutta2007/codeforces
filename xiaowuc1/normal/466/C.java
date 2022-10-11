import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

import static java.lang.Math.min;
import static java.lang.Math.max;

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
			int[] list = new int[n];
			long sum = 0;
			for(int i = 0; i < n; i++) {
				sum += list[i] = readInt();
			}
			LinkedList<Integer> a = new LinkedList<Integer>();
			LinkedList<Integer> b = new LinkedList<Integer>();
			long curr = 0;
			for(int i = 0; i < n; i++) {
				curr += list[i];
				if(curr * 3 == sum) {
					a.add(i);
				}
			}
			curr = 0;
			for(int i = n-1; i >= 0; i--) {
				curr += list[i];
				if(curr * 3 == sum) {
					b.addFirst(i);
				}
			}
			long ret = 0;
			for(int out: a) {
				while(!b.isEmpty() && b.peekFirst() <= out+1) b.removeFirst();
				ret += b.size();
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