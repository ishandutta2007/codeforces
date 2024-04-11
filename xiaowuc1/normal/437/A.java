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
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int[] len = new int[4];
			for(int i = 0; i < 4; i++) {
				len[i] = br.readLine().length() - 2;
			}
			Set<Integer> set = new HashSet<Integer>();
			for(int i = 0; i < 4; i++) {
				boolean twiceShorter = true;
				boolean twiceLonger = true;
				for(int j = 0; j < 4; j++) {
					if(i == j) continue;
					if(len[i] < 2 * len[j]) {
						twiceLonger = false;
					}
					if(2*len[i] > len[j]) {
						twiceShorter = false;
					}
				}
				if(twiceShorter || twiceLonger) {
					set.add(i);
				}
			}
			if(set.size() == 1) {
				for(int out: set) {
					pw.println((char)(out + 'A'));
				}
			}
			else {

				pw.println("C");
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