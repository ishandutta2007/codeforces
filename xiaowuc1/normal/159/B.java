import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class B {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n1 = readInt();
		int n2 = readInt();
		int[][] grid1 = new int[1000][1000];
		int[][] grid2 = new int[1000][1000];
		int[] d1 = new int[1000];
		int[] d2 = new int[1000];
		while(n1-- > 0)	{
			int c = readInt();
			int d = readInt();
			c--;
			d--;
			grid1[c][d]++;
			d1[d]++;
		}
		while(n2-- > 0)	{
			int c = readInt();
			int d = readInt();
			c--;
			d--;
			grid2[c][d]++;
			d2[d]++;
		}
		int ret1 = 0;
		for(int i = 0; i < 1000; i++)
			ret1 += Math.min(d1[i], d2[i]);
		int ret2 = 0;
		for(int dd = 0; dd < 1000; dd++)	{
			for(int i = 0; i < 1000; i++)	{
				ret2 += Math.min(grid1[i][dd], grid2[i][dd]);
			}
		}
		pw.println(ret1 + " " + ret2);
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