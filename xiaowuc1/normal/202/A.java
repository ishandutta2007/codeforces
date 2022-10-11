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
		String str = nextToken();
		ArrayList<String> ret = new ArrayList<String>();
		for(int i = 0; i < 1 << str.length(); i++)	{
			StringBuilder sb = new StringBuilder();
			for(int j = 0; j < str.length(); j++)	{
				if(((1<<j)&i) != 0)	{
					sb.append(str.charAt(j));
				}
			}
			String a = sb.toString();
			String b = sb.reverse().toString();
			if(a.equals(b))
				ret.add(a);
		}
		Collections.sort(ret);
		pw.println(ret.get(ret.size()-1));
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