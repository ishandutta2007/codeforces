
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
		int ret = 0;
		while(n-- > 0)	{
			if(readInt()+readInt()+readInt()>=2)
				ret++;
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
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}