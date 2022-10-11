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
		//185A: 2^(n-1)*(1+2^n)
		long n = readLong();
		if(n==0)
			pw.println(1);
		else	{
			long a = pow(2, n-1, 1000000007);
			long b = 1 + pow(2, n, 1000000007);
			pw.println((a*b)%1000000007);
		}
		pw.close();
	}

	public static long pow(long b, long e, long m)	{
		long r = 1;
		while(e > 0)	{
			if(e%2==1)	{
				r *= b;
				r %= m;
			}
			b *= b;
			b %= m;
			e >>= 1;
		}
		return r;
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