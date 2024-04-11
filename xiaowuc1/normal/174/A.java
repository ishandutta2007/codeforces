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
		int n = readInt();
		double amt = readInt();
		double[] go = new double[n];
		double max = 0;
		for(int i = 0; i < n; i++)	{
			go[i] = readDouble();
			max = Math.max(max, go[i]);
		}
		double now = 0;
		double[] ret = new double[n];
		for(int i = 0; i < n; i++)	{
			ret[i] = max-go[i];
			now += ret[i];
		}
		if(now > amt)
			pw.println(-1);
		else	{
			amt -= now;
			for(int i = 0; i < n; i++)
				pw.println(ret[i] + amt/n);
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