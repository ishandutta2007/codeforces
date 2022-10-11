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
			int k = readInt();
			int a = readInt();
			TreeSet<State> set = new TreeSet<State>();
			int amt = num(n, a);
			set.add(new State(1, n));
			int nums = readInt();
			int[] all = new int[nums];
			for(int i = 0; i < nums; i++) {
				all[i] = readInt();
			}
			int ret = 0;
			for(int split: all) {
				ret++;
				State go = set.floor(new State(split, 0));
				set.remove(go);
				amt -= num(go.size, a);
				for(State add: go.split(split)) {
					amt += num(add.size, a);
					set.add(add);
				}
				if(amt < k) {
					break;
				}
			}
			if(amt >= k) ret = -1;
			pw.println(ret);
		}
		pw.close();
	}

	public static int num(int intervalSize, int size) {
		if(intervalSize < size) return 0;
		int ret = 1;
		intervalSize -= size;
		ret += intervalSize / (size+1);
		return ret;
	}
	
	static class State implements Comparable<State> {
		public int loc, size;
		public State(int a, int b) {
			loc = a;
			size = b;
		}
		
		public ArrayList<State> split(int x) {
			ArrayList<State> ret = new ArrayList<State>();
			if(size == 1) {
				return ret;
			}
			if(x > loc) {
				ret.add(new State(loc, x-loc));
			}
			if(x < loc+size-1) {
				ret.add(new State(x+1, loc+size-x-1));
			}
			return ret;
		}
		
		public int compareTo(State s) {
			return loc - s.loc;
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