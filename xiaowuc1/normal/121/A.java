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
		TreeSet<Long> set = new TreeSet<Long>();
		for(int len = 1; len <= 10; len++)	{
			for(int mask = 0; mask < 1 << len; mask++)	{
				long now = 0;
				for(int i = 0; i < len; i++)	{
					now *= 10;
					if((mask&(1<<i))==0)
						now += 4;
					else
						now += 7;
				}
				set.add(now);
			}
		}
		long min = readInt();
		long max = readInt();
		long ret = 0;
		while(min <= max)	{
			long up = set.ceiling(min);
			long maxToCount = Math.min(up, max);
			ret += (maxToCount - min+1) * up;
			min = up+1;
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