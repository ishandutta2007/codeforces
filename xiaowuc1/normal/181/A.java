import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Main {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int r = readInt();
		int c = readInt();
		char[][] grid = new char[r][c];
		for(int i = 0; i < r; i++)	{
			grid[i] = nextToken().toCharArray();
		}
		Set<Integer> rr = new HashSet<Integer>();
		Set<Integer> cc = new HashSet<Integer>();
		for(int i = 0; i < r; i++)	{
			for(int j = 0; j < c; j++)	{
				if(grid[i][j] == '*')	{
					rr.add(i);
					cc.add(j);
				}
			}
		}
		for(int out: rr)
			for(int out2: cc)
				if(grid[out][out2] != '*')	{
					pw.println((out+1) + " " + (out2+1));
				}
		pw.close();
	}

	public static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}
	public static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}
	public static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}
	public static short readShort() throws IOException	{
		return Short.parseShort(nextToken());
	}
	public static String nextToken() throws IOException	{
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}