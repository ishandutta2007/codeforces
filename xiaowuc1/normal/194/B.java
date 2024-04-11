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
		while(n-- > 0)	{
			long a = readInt();
			if(a % 4 == 0)
				pw.println(4*a+1);
			if(a % 4 == 1)
				pw.println(2*a+1);
			if(a % 4 == 2)
				pw.println(4*a+1);
			if(a % 4 == 3)
				pw.println(a+1);
		}
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