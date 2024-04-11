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
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.sort;
import static java.util.Collections.binarySearch;
import static java.util.Collections.shuffle;
import static java.util.Collections.sort;

public class A {
	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				System.out)));
		int n = readInt();
		int k = readInt()-1;
		int[] list = new int[n];
		for(int i = 0; i < n; i++)	{
			list[i] = readInt();
		}
		Set<Integer> set = new HashSet<Integer>();
		for(int i = k; i < n; i++)
			set.add(list[i]);
		if(set.size() > 1)	{
			pw.println(-1);
		}
		else	{
			int ret = 0;
			for(int i = k-1; i >= 0; i--)	{
				if(list[i] != list[k])	{
					ret = i+1;
					break;
				}
			}
			pw.println(ret);
		}
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