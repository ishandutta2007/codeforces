import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*; 
import java.util.*;
import java.util.regex.*;

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int m = readInt();
			d = new int[n];
			p = new int[n];
			for(int i = 0; i < n; i++) {
				p[i] = i;
			}
			while(m-- > 0) {
				int a = readInt()-1;
				int b = readInt()-1;
				merge(a, b);
				d[a]++;
				d[b]++;
			}
			int[] dS = new int[n];
			int[] vS = new int[n];
			for(int i = 0; i < n; i++) {
				vS[find(i)]++;
				dS[find(i)] += d[i];
			}
			int ret = 0;
			for(int i = 0; i < n; i++) {
				if(dS[i] / 2 == vS[i] - 1) {
					ret++;
				}
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	static int[] d;
	static int[] p;
	public static int find(int x) {
		return p[x] == x ? x : (p[x] = find(p[x]));
	}
	public static void merge(int x, int y) {
		p[find(x)] = find(y);
	}
	
	private static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private static String nextLine() throws IOException  {
		if(!br.ready()) {
			exitImmediately();
		}
		st = null;
		return br.readLine();
	}

	private static String nextToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			if(!br.ready()) {
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}