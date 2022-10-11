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

	static int maxX, maxY;
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		maxX = readInt();
		maxY = readInt();
		long currX = readInt();
		long currY = readInt();
		long ret = 0;
		int n = readInt();
		while(n-- > 0)	{
			long dx = readInt();
			long dy = readInt();
			int min = 0;
			int max = 1000000000;
			while(min != max)	{
				int mid = (min+max)/2;
				if(min == mid)
					mid++;
				long nx = currX + mid * dx;
				long ny = currY + mid * dy;
				if(valid(nx, ny))
					min = mid;
				else
					max = mid-1;
			}
			ret += min;
			currX += dx * min;
			currY += dy * min;
		}
		pw.println(ret);
		pw.close();
	}

	public static boolean valid(long x, long y)	{
		return x >= 1 && x <= maxX && y >= 1 && y <= maxY;
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