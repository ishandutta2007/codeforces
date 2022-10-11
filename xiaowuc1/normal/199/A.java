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
		long[] dist = new long[50];
		dist[1] = 1;
		for(int i = 2; i < dist.length; i++)	{
			dist[i] = dist[i-1] + dist[i-2];
		}
		long want = readLong();
		boolean win = false;
		for(int i = 0; !win && i < dist.length; i++)	{
			for(int j = 0; !win && j < dist.length; j++)	{
				for(int k = 0; !win && k < dist.length; k++)	{
					if(dist[i] + dist[j] + dist[k] == want)	{
						pw.println(dist[i] + " " + dist[j] + " " + dist[k]);
						win = true;
					}
				}
			}
		}
		if(!win)
			pw.println("I'm too stupid to solve this problem");
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