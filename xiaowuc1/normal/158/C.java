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

	static final double EPS = 5.0/10;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		ArrayList<String> ret = new ArrayList<String>();
		while(n-- > 0)	 {
			if(nextToken().equals("pwd"))	{
				pw.print("/");
				for(String out: ret)
					pw.print(out + "/");
				pw.println();
			}
			else	{
				String token = nextToken();
				if(token.startsWith("/"))	{
					ret.clear();
					token = token.substring(1);
				}
				StringTokenizer su = new StringTokenizer(token, "/");
				while(su.hasMoreTokens())	{
					String next = su.nextToken();
					if(next.equals(".."))	{
						ret.remove(ret.size()-1);
					}
					else	{
						ret.add(next);
					}
				}
			}
		}
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