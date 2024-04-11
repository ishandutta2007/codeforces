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
		String s = nextToken();
		boolean neg = s.charAt(0) == '-';
		if(neg)
			s = s.substring(1);
		String decimal = "00";
		if(s.indexOf(".") != -1)	{
			decimal = s.substring(s.indexOf(".")+1);
			if(decimal.length() > 2)
				decimal = decimal.substring(0,2);
			while(decimal.length() < 2)
				decimal += 0;
			s = s.substring(0, s.indexOf("."));
		}
		String ret = "";
		while(s.length() > 0)	{
			if(s.length() >= 3)	{
				ret = "," + s.substring(s.length()-3) + ret;
				s = s.substring(0, s.length()-3);
			}
			else	{
				ret = ',' + s + ret;
				break;
			}
		}
		ret = ret.substring(1);
		ret = "$" + ret;
		ret += ".";
		ret += decimal;
		if(neg)
			ret = "(" + ret + ")";
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