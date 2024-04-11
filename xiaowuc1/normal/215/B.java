import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

/*
br = new BufferedReader(new FileReader("input.txt"));
pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
 */

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		int r1 = 0;
		while(n-- > 0)
			r1 = Math.max(r1, readInt());
		n = readInt();
		int d1 = 0;
		while(n-- > 0)
			d1 = Math.max(d1, readInt());
		n = readInt();
		int d2 = Integer.MAX_VALUE;
		while(n-- > 0)
			d2 = Math.min(d2, readInt());
		double ratio = readDouble()/readDouble();
		double min = 0;
		double max = r1;
		for(int qq = 0; qq < 60; qq++)	{
			double mid = (min+max)/2;
			double massOut = d1 * Math.PI*(r1*r1-mid*mid);
			double massIn = d2 * Math.PI * mid * mid;
			if(massOut / massIn > ratio)	{
				min = mid;
			}
			else	{
				max = mid;
			}
		}
		pw.println(min);
		pw.close();
	}

	public static void loadArray(int[] in) throws IOException {
		for(int i = 0; i < in.length; i++)
			in[i] = readInt();
	}
	
	private static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}

	private static String nextToken() throws IOException	{
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