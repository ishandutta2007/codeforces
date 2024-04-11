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
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		int a = 0;
		int b = 0;
		int c = 0;
		int d = 0;
		int ret = 0;
		while(n-- > 0)	{
			int curr = readInt();
			if(curr == 1)
				a++;
			if(curr == 2)
				b++;
			if(curr == 3)
				c++;
			if(curr == 4)
				d++;
		}
		while(d > 0)	{
			ret++;
			d--;
		}
		while(c > 0)	{
			ret++;
			c--;
			if(a > 0)
				a--;
		}
		while(b > 0)	{
			ret++;
			b--;
			if(b > 0)	{
				b--;
			}
			else	{
				if(a > 0)
					a--;
				if(a > 0)
					a--;
			}
		}
		while(a > 0)	{
			ret++;
			a -= 4;
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