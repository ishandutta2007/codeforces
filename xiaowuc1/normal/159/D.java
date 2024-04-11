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
		String next = nextToken();
		int n = next.length();
		int[] begin = new int[n];
		int[] end = new int[n];
		outer: for(int i = 0; i < next.length(); i++)	{
			begin[i]++;
			end[i]++;
			int diff = 1;
			while(true)	{
				if(i-diff < 0 || i+diff >= next.length())
					continue outer;
				if(next.charAt(i-diff) != next.charAt(i+diff))
					continue outer;
				begin[i-diff]++;
				end[i+diff]++;
				diff++;
			}
		}
		outer: for(int i = 0; i + 1 < next.length(); i++)	{
			if(next.charAt(i) != next.charAt(i+1))
				continue outer;
			begin[i]++;
			end[i+1]++;
			int diff = 1;
			while(true)	{
				if(i-diff < 0 || i+1+diff >= next.length())
					continue outer;
				if(next.charAt(i-diff) != next.charAt(i+1+diff))
					continue outer;
				begin[i-diff]++;
				end[i+1+diff]++;
				diff++;
			}
		}
		long ret = 0;
		for(int i = 0; i < n; i++)	{
			for(int j = i+1; j < n; j++)	{
				ret += end[i]*1L*begin[j];
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