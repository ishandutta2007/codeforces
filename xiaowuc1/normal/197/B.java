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
		int m = readInt();
		int[] a = new int[n+1];
		int[] b = new int[m+1];
		for(int i = 0; i <= n; i++)
			a[i] = readInt();
		for(int i = 0; i <= m; i++)
			b[i] = readInt();
		if(m > n)
			pw.println("0/1");
		else if(m < n)	{
			boolean neg = a[0] < 0 ^ b[0] < 0;
			pw.println(neg ? "-Infinity" : "Infinity");
		}
		else	{
			Fraction f = new Fraction(a[0], b[0]);
			pw.println(f.a + "/" + f.b);
		}
		pw.close();
	}

	static class Fraction	{
		public int a,b;
		public Fraction(int x, int y)	{
			a=x;
			b=y;
			boolean neg = a<0 ^ b<0;
			if((neg && a > 0) || (a<0 && b<0))	{
				a = -a;
				b = -b;
			}
			for(int i = 2; i <= 100; i++)	{
				while(a%i==0 && b%i==0)	{
					a/=i;
					b/=i;
				}
			}
		}
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