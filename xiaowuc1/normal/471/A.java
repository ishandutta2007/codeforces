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
			Map<Integer, Integer> map = new HashMap<Integer, Integer>();
			for(int i = 0; i < 6; i++) {
				int key = readInt();
				if(!map.containsKey(key)) map.put(key, 0);
				map.put(key, 1 + map.get(key));
			}
			if(map.size() == 1) {
				pw.println("Elephant");
			}
			else if(map.size() > 3) {
				pw.println("Alien");
			}
			else if(map.size() == 3) {
				boolean four = false;
				for(int out: map.keySet()) {
					if(map.get(out) == 4) {
						four = true;
					}
				}
				if(four) {
					pw.println("Bear");
				}
				else {
					pw.println("Alien");
				}
			}
			else {
				boolean four = false;
				boolean five = false;
				for(int out: map.keySet()) {
					if(map.get(out) == 4) {
						four = true;
					}
					if(map.get(out) == 5) {
						five = true;
					}
				}
				if(five) {
					pw.println("Bear");
				}
				else if(four) {
					pw.println("Elephant");
				}
				else {
					pw.println("Alien");
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