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
	static int MOD;
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		String a = nextToken();
		String b = nextToken();
		String c = nextToken();
		int[] count = new int[256];
		for(int i = 0; i < a.length(); i++)
			count[a.charAt(i)]++;
		for(int i = 0; i < b.length(); i++)
			count[b.charAt(i)]++;
		for(int i = 0; i < c.length(); i++)
			count[c.charAt(i)]--;
		boolean win = true;
		for(int out: count)	{
			if(out != 0)	{
				pw.println("NO");
				win = false;
				break;
			}
		}
		if(win)
			pw.println("YES");
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