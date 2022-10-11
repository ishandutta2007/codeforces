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
			int n = readInt();
			char[][] grid = new char[n][5];
			for(int i = 0; i < n; i++) {
				String s = nextToken();
				for(int j = 0; j < 5; j++) {
					grid[i][j] = s.charAt(j);
				}
			}
			boolean can = false;
			for(int i = 0; i < n; i++) {
				if(grid[i][0] == 'O' && grid[i][1] == 'O') {
					grid[i][0] = '+';
					grid[i][1] = '+';
					can = true;
					break;
				}
				if(grid[i][3] == 'O' && grid[i][4] == 'O') {
					grid[i][3] = '+';
					grid[i][4] = '+';
					can = true;
					break;
				}
			}
			if(can) {
				pw.println("YES");
				for(char[] out: grid) {
					pw.println(new String(out));
				}
			}
			else {
				pw.println("NO");
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