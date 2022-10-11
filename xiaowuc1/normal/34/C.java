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
		StringTokenizer su = new StringTokenizer(nextToken(), ",");
		boolean[] used = new boolean[10000];
		while(su.hasMoreTokens())
			used[Integer.parseInt(su.nextToken())] = true;
		StringBuilder sb = new StringBuilder();
		for(int i = 1; i < used.length; i++)	{
			if(!used[i])
				continue;
			int j = i+1;
			while(used[j])
				j++;
			j--;
			if(i == j)
				sb.append(i + ",");
			else
				sb.append(i + "-" + j + ",");
			i=j;
		}
		sb.deleteCharAt(sb.length()-1);
		pw.println(sb.toString());
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