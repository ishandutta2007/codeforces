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
		String str = nextToken();
		int[] dp = new int[str.length()+1];
		for(int i = 0; i < str.length(); i++)	{
			dp[i+1] = dp[i];
			if(str.charAt(i) == '[')
				dp[i+1]++;
		}
		int ans = 0;
		int left = -1, right = -1;
		for(int i = 0; i < str.length();)	{
			if(str.charAt(i) == ')' || str.charAt(i) == ']')	{
				i++;
				continue;
			}
			Stack<State> stack = new Stack<State>();
			stack.push(new State(str.charAt(i), i));
			int j;
			for(j = i+1; j < str.length(); j++)	{
				if(str.charAt(j) == ')' && (stack.isEmpty() || stack.peek().ch == '['))	{
					break;
				}
				if(str.charAt(j) == ']' && (stack.isEmpty() || stack.peek().ch == '('))	{
					break;
				}
				if(str.charAt(j) == ')' || str.charAt(j) == ']')	{
					stack.pop();
					int l = stack.isEmpty() ? i : stack.peek().index+1;
					int r = j;
					if(dp[r+1]-dp[l] >= ans)	{
						ans = dp[r+1]-dp[l];
						left = l;
						right = j;
					}
				}
				else	{
					stack.push(new State(str.charAt(j), j));
				}
			}
			i=j;
		}
		pw.println(ans);
		if(left == -1)
			pw.println();
		else	{
			pw.println(str.substring(left, right+1));
		}
		pw.close();
	}

	static class State	{
		public char ch;
		public int index;
		public State(char a, int b)	{
			ch = a;
			index = b;
		}
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