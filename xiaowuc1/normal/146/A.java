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
		String str = nextToken();
		Set<Character> set = new HashSet<Character>();
		for (int i = 0; i < str.length(); i++)
			set.add(str.charAt(i));
		if (set.size() > 2)
			pw.println("NO");
		else	{
			set.remove('4');
			set.remove('7');
			if (set.size() != 0)
				pw.println("NO");
			else	{
				int left = 0;
				int right = 0;
				for (int i = 0; i < n/2; i++)	{
					left += str.charAt(i) - '0';
					right += str.charAt(i + n/2) - '0';
				}
				pw.println(left == right ? "YES" : "NO");
			}
		}
		pw.close();
	}

	static class State	{
		public int x,y;
		public State(int a, int b)	{
			x=a;
			y=b;
		}
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