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
		int max = readInt();
		int n = readInt();
		int[] list = new int[n];
		for(int i = 0; i < n; i++)
			list[i] = readInt();
		int curr = 0;
		int ret = 0;
		for(int i = 0; i < n; i++)	{
			for(int d = 1; d <= list[i]; d++)	{
				curr++;
				if(curr > max)
					curr -= max;
				while(curr != d)	{
					if(curr > d)		{
						ret += (max-curr);
						curr = 0;
					}
					else	{
						curr = d;
						ret += d;
					}
				}
				if(d != list[i])	{
					curr += list[i]-d;
					d = list[i];
				}
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