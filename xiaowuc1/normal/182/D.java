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
		String a = nextToken();
		String b = nextToken();
		if(a.length() > b.length())	{
			String c = a;
			a = b;
			b = c;
		}
		int ret = 0;
		outer: for(int i = 1; i <= a.length(); i++)	{
			if(a.length()%i!=0 || b.length()%i!=0)
				continue outer;
			String want = a.substring(0,i);
			for(int k = 1; k < a.length() / i; k++)	{
				if(!a.substring(k*i, (k+1)*i).equals(want))
					continue outer;
			}
			for(int k = 0; k < b.length() / i; k++)	{
				if(!b.substring(k*i, (k+1)*i).equals(want))
					continue outer;
			}
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
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}