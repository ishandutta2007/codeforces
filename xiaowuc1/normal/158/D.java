import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class D {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		int[] list = new int[n];
		for(int i = 0; i < n; i++)
			list[i] = readInt();
		int ret = Integer.MIN_VALUE;
		for(int s = 3; s <= n; s++)	{
			if(n%s!=0)
				continue;
			int[] go = new int[n/s];
			for(int i = 0; i < n; i++)
				go[i%(n/s)] += list[i];
			for(int out: go)
				ret = Math.max(ret, out);
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