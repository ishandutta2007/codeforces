
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class B {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	static int[] max = new int[]{0,31,28,31,30,31,30,31,31,30,31,30,31};
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		String str = nextToken();
		HashMap<String, Integer> count = new HashMap<String, Integer>();
		int max = 0;
		String best = "";
		for(int i = 0; i + 10 <= str.length(); i++)	{
			String portion = str.substring(i,i+10);
			if(valid(portion))	{
				Integer now = count.get(portion);
				if(now == null)
					now = 0;
				count.put(portion, ++now);
				if(now > max)	{
					max = now;
					best = portion;
				}
			}
		}
		pw.println(best);
		pw.close();
	}

	public static boolean valid(String date)	{
		boolean[] hyphen = new boolean[10];
		hyphen[2] = hyphen[5] = true;
		for(int i = 0; i < date.length(); i++)	{
			if((date.charAt(i) == '-') != hyphen[i])	{
				return false;
			}
		}
		int year = Integer.parseInt(date.substring(6));
		if(year < 2013 || year > 2015)
			return false;
		int month = Integer.parseInt(date.substring(3,5));
		if(month < 1 || month > 12)
			return false;
		int day = Integer.parseInt(date.substring(0,2));
		if(day < 1 || day > max[month])
			return false;
		return true;
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