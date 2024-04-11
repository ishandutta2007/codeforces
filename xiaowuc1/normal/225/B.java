import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.fill;
import static java.util.Arrays.sort;
import static java.util.Collections.binarySearch;
import static java.util.Collections.shuffle;
import static java.util.Collections.sort;

public class B {
	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;

	/*
	 * sorting primitive arrays is bad
	 */
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				System.out)));
		long[] list = new long[1000];
		fill(list, -1);
		list[0] = 1;
		list[1] = 1;
		int s = readInt();
		int k = readInt();
		for(int i = 2; i < list.length; i++)	{
			list[i] = 0;
			for(int a = 1; a <= k && i-a >= 0; a++)	{
				list[i] += list[i-a];
			}
			if(list[i] > s)
				break;
		}
		ArrayList<Long> ret = new ArrayList<Long>();
		for(int i = list.length-1; i >= 0; i--)	{
			if(list[i] >= 0 && s - list[i] >= 0)	{
				ret.add(list[i]);
				s -= list[i];
			}
		}
		if(ret.size() == 1)
			ret.add(0L);
		pw.println(ret.size());
		StringBuilder sb = new StringBuilder();
		for(long out: ret)	{
			sb.append(out + " ");
		}
		pw.println(sb.toString().trim());
		pw.close();
	}

	public static long readLong() throws IOException {
		return parseLong(nextToken());
	}

	public static double readDouble() throws IOException {
		return parseDouble(nextToken());
	}

	public static int readInt() throws IOException {
		return parseInt(nextToken());
	}

	public static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			if (!br.ready()) {
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}