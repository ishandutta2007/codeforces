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

public class B {
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
			int[] a = reverse(repr(getList(n)));
			int[] b = reverse(repr(getList(n)));
			int[] actual = new int[a.length];
			for(int i = 0; i < actual.length; i++) {
				actual[i] += a[i] + b[i];
				while(actual[i] >= i+2) {
					actual[i] -= i+2;
					if(i+1 < actual.length) {
						actual[i+1]++;
					}
				}
			}
			init(n);
			int[] ret = new int[n];
			for(int i = actual.length-1; i >= 0; i--) {
				int min = 1;
				int max = n;
				while(min != max) {
					int mid = (min+max)/2;
					int num = mid - query(mid) - 1;
					if(num >= actual[i]) {
						max = mid;
					}
					else {
						min = mid+1;
					}
				}
				ret[ret.length-2-i] = min-1;
				update(min, 1);
			}
			for(int x = 1; x <= n; x++) {
				if(x != query(x)) {
					ret[ret.length-1] = x-1;
					break;
				}
			}
			for(int out: ret) {
				pw.print(out + " ");
			}
			pw.println();
		}
		pw.close();
	}

	public static int[] reverse(int[] list) {
		int[] ret = new int[list.length];
		for(int i = 0; i < ret.length; i++) {
			ret[i] = list[list.length-1-i];
		}
		return ret;
	}
	
	public static int[] getList(int n) throws IOException {
		int[] ret = new int[n];
		for(int i = 0; i < n; i++) {
			ret[i] = readInt() + 1;
		}
		return ret;
	}
	
	public static int[] repr(int[] list) {
		int[] ret = new int[list.length-1];
		init(list.length);
		for(int i = 0; i < list.length-1; i++) {
			ret[i] = list[i] - query(list[i]) - 1;
			update(list[i], 1);
		}
		return ret;
	}
	
	static int[] tree;
	public static void init(int n) {
		tree = new int[n+5];
	}
	public static void update(int index, int val) {
		while(index < tree.length) {
			tree[index] += val;
			index += index & -index;
		}
	}
	public static int query(int index) {
		int ret = 0;
		while(index > 0) {
			ret += tree[index];
			index -= index & -index;
		}
		return ret;
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