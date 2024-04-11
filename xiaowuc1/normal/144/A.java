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
		int[] list = new int[n];
		int max = -1;
		int min = 101;
		for (int i = 0; i < n; i++)	{
			list[i] = readInt();
			max = Math.max(max, list[i]);
			min = Math.min(min, list[i]);
		}
		int ret = 0;
		for (int i = 0; i < n; i++)	{
			if (list[i] == max)	{
				ret += i;
				for (int j = i-1; j >= 0; j--)	{
					list[j+1] = list[j];
				}
				list[0] = max;
				break;
			}
		}
		for (int i = n-1; i >= 0; i--)	{
			if (list[i] == min)	{
				ret += (n-1-i);
				break;
			}
		}
		pw.println(ret);
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