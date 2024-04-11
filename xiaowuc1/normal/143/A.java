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
		int r1 = readInt();
		int r2 = readInt();
		int c1 = readInt();
		int c2 = readInt();
		int d1 = readInt();
		int d2 = readInt();
		for(int a = 1; a <= 9; a++)	{
			for(int b = 1; b <= 9; b++)	{
				for(int c = 1; c <= 9; c++)	{
					for(int d = 1; d <= 9; d++)	{
						Set<Integer> set = new HashSet<Integer>();
						set.add(a);
						set.add(b);
						set.add(c);
						set.add(d);
						if(set.size() != 4)
							continue;
						if(a+b == r1 && c+d == r2 && a+c == c1 && b+d ==c2 && a+d == d1 && b+c == d2)		{
							pw.println(a + " " + b);
							pw.println(c + " " + d);
							pw.close();
						}
					}
				}
			}
		}
		pw.println(-1);
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