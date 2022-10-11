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

public class A {
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
		int n = readInt();
		int top = readInt();
		int bottom = 7 - top;
		boolean win = true;
		for(int i = 0; i < n; i++)	{
			int a = readInt();
			int b = readInt();
			if(a==top || a==bottom || b==top || b==bottom)
				win = false;
		}
		pw.println(win ? "YES" : "NO");
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