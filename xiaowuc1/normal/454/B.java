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
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			ArrayList<State> list = new ArrayList<State>();
			for(int i = 0; i < n; i++) {
				int curr = readInt();
				if(!list.isEmpty() && list.get(list.size()-1).num == curr) {
					list.get(list.size()-1).appear++;
				}
				else {
					list.add(new State(curr, 1));
				}
			}
			int minIndex = 0;
			for(int i = 1; i < list.size(); i++) {
				if(list.get(i).num <= list.get(minIndex).num) {
					minIndex = i;
				}
			}
			for(int a = 1; a < list.size(); a++) {
				int right = (minIndex + a) % list.size();
				int left = (right + list.size() - 1) % list.size();
				if(list.get(left).num > list.get(right).num) {
					pw.println(-1);
					exitImmediately();
				}
			}
			if(minIndex == 0) {
				pw.println(0);
			}
			else {
				int ret = 0;
				for(int i = minIndex; i < list.size(); i++) {
					ret += list.get(i).appear;
				}
				pw.println(ret);
			}
		}
		pw.close();
	}

	static class State {
		public int num, appear;
		public State(int a, int b) {
			num = a;
			appear = b;
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