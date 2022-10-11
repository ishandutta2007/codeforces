
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

	static int[] a,b;
	static int m,n;
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new FileReader("input.txt"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
		m = readInt();
		a = new int[m];
		for(int i = 0; i < m; i++)	{
			a[i] = readInt();
		}
		n = readInt();
		b = new int[n];
		for(int i = 0; i < n; i++)	{
			b[i] = readInt();
		}
		int first = m-1;
		int second = n-1;
		int[] ret = new int[m+n];
		int count = m+n-1;
		while(first >= 0 || second >= 0)	{
			while(first >= 0 && a[first] == 0)	{
				ret[count--] = first+1;
				first--;
			}
			while(second >= 0 && b[second] == 0)	{
				ret[count--] = m+second+1;
				second--;
			}
			while(first >= 0 && a[first] == 1)	{
				ret[count--] = first+1;
				first--;
			}
			while(second >= 0 && b[second] == 1)	{
				ret[count--] = m+second+1;
				second--;
			}
		}
		StringBuilder sb = new StringBuilder();
		for(int out: ret)
			sb.append(out + " ");
		pw.println(sb.toString().trim());
		ArrayList<Integer> loc = new ArrayList<Integer>();
		for(int i = 1; i < ret.length; i++)	{
			if(get(ret[i]) != get(ret[i-1]))
				loc.add(i);
		}
		if(get(ret[ret.length-1]) == 1)
			loc.add(ret.length);
		pw.println(loc.size());
		sb = new StringBuilder();
		for(int out: loc)
			sb.append(out + " ");
		pw.println(sb.toString().trim());
		pw.close();
	}

	public static int get(int index)	{
		index--;
		if(index < a.length)
			return a[index];
		return b[index-a.length];
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