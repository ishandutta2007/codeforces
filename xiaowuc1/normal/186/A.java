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
		String a = nextToken();
		String b = nextToken();
		if(a.length() != b.length())
			pw.println("NO");
		else	{
			ArrayList<Integer> list = new ArrayList<Integer>();
			for(int i = 0; i < a.length(); i++)	{
				if(a.charAt(i) != b.charAt(i))
					list.add(i);
			}
			if(list.size() != 2)
				pw.println("NO");
			else	{
				boolean win = a.charAt(list.get(0)) == b.charAt(list.get(1)) && a.charAt(list.get(1)) == b.charAt(list.get(0));
				if(win)
					pw.println("YES");
				else
					pw.println("NO");
			}
		}
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