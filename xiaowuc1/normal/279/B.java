import java.awt.*;
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
			int t = readInt();
			int[] list = new int[n+1];
			for (int i = 1; i < list.length; i++) {
				list[i] = readInt();
			}
			for (int i = 2; i < list.length; i++) {
				list[i] += list[i-1];
			}
			int ret = 0;
			for (int i = 0; i < n; i++) {
				int min = i;
				int max = n;
				while(min != max)	{
					int mid = (min+max)/2;
					if(mid == min)	{
						mid++;
					}
					if(list[mid] - list[i] > t)
						max = mid-1;
					else
						min = mid;
				}
				ret = Math.max(ret, min-i);
			}
			pw.println(ret);
		}
		pw.close();
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
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}