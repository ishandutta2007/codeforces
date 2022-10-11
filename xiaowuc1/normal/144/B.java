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
		int x1 = readInt();
		int y1 = readInt();
		int x2 = readInt();
		int y2 = readInt();
		if(x1 > x2)	{
			int temp = x1;
			x1 = x2;
			x2 = temp;
		}
		if(y1 > y2)	{
			int temp = y1;
			y1 = y2;
			y2 = temp;
		}
		int n = readInt();
		int[] x = new int[n];
		int[] y = new int[n];
		int[] r = new int[n];
		for(int i = 0; i < n; i++)	{
			x[i] = readInt();
			y[i] = readInt();
			r[i] = readInt();
			r[i] *= r[i];
		}
		int ret = 0;
		for(int a = -1000; a <= 1000; a++)	{
			outer: for(int b = -1000; b <= 1000; b++)	{
				boolean valid = false;
				if(a == x1 && b >= y1 && b <= y2)
					valid = true;
				if(a == x2 && b >= y1 && b <= y2)
					valid = true;
				if(b == y1 && a >= x1 && a <= x2)
					valid = true;
				if(b == y2 && a >= x1 && a <= x2)
					valid = true;
				if(!valid)
					continue;
				for(int k = 0; k < n; k++)	{
					if(dist(a, b, x[k], y[k]) <= r[k])
						continue outer;
				}
				ret++;
			}
		}
		pw.println(ret);
		pw.close();
	}
	
	public static int dist(int a, int b, int c, int d)	{
		int x = a-c;
		int y = b-d;
		return x*x+y*y;
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