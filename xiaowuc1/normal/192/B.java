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
		int[] destroy = new int[n];
		for(int i = 0; i < n; i++)
			destroy[i] = readInt();
		int min = 0;
		int max = Math.min(destroy[0], destroy[n-1]);
		while(min != max)	{
			int mid = (min+max)/2;
			if(mid == min)
				mid++;
			boolean[] can = new boolean[n];
			can[0] = true;
			for(int i = 0; i < can.length; i++)	{
				if(!can[i])
					continue;
				if(i+2 < can.length && destroy[i+2] >= mid)
					can[i+2] = true;
				if(i+1 < can.length && destroy[i+1] >= mid)
					can[i+1] = true;
			}
			if(can[n-1])
				min = mid;
			else
				max = mid-1;
		}
		pw.println(min);
		pw.close();
	}

	public static int score(char a, char b)	{
		if(a == b)
			return 0;
		if(a == 'P')
			if(b == 'R')
				return 1;
			else
				return -1;
		if(a == 'R')
			if(b == 'S')
				return 1;
			else
				return -1;
		if(a == 'S')
			if(b == 'P')
				return 1;
			else
				return -1;
		return 0;
	}

	public static int lcm(int a, int b)	{
		return a * b / gcd(a,b);
	}

	public static int gcd(int a, int b)	{
		return a%b==0 ? b : gcd(b, a%b);
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