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
			int a = readInt();
			int b = readInt();
			int qqq = readInt();
			long[] amt = new long[1000001];
			long[] pref = new long[amt.length+1];
			for(int i = 0; i < amt.length; i++) {
				pref[i+1] = pref[i] + (amt[i] = (i*1L*b+a));
			}
			while(qqq-- > 0) {
				int left = readInt()-1;
				long times = readInt();
				long size = readInt();
				if(amt[left] > times) {
					pw.println(-1);
					continue;
				}
				int min = left;
				int max = 1000000;
				while(min != max) {
					int mid = (min+max+1)/2;
					if(amt[mid] > times) {
						max = mid-1;
						continue;
					}
					if(pref[mid+1] - pref[left] > times * size) {
						max = mid-1;
						continue;
					}
					min = mid;
				}
				pw.println(min+1);
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