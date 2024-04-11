import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

/*
br = new BufferedReader(new FileReader("input.txt"));
pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
br = new BufferedReader(new InputStreamReader(System.in));
pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
 */

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int x1 = readInt();
		int y1 = readInt();
		int r1 = readInt();
		int x2 = readInt();
		int y2 = readInt();
		int r2 = readInt();
		double ret = Double.MAX_VALUE;
		final int MAX_ITER = 10000;
		final double LEARNING_RATE = 0.99;
		double theta = 0;
		double alpha = 0.1;
		for(int qq = 0; qq < MAX_ITER; qq++)	{
			double x = x2 + r2 * Math.cos(theta);
			double y = y2 + r2 * Math.sin(theta);
			double dist = dist(x,y,x1,y1);
			dist = Math.abs(dist-r1);
			ret = Math.min(ret, dist/2);
			x = x2 + r2 * Math.cos(theta+alpha);
			y = y2 + r2 * Math.sin(theta+alpha);
			double d1 = dist(x,y,x1,y1);
			d1 = Math.abs(d1-r1);
			x = x2 + r2 * Math.cos(theta-alpha);
			y = y2 + r2 * Math.sin(theta-alpha);
			double d2 = dist(x,y,x1,y1);
			d2 = Math.abs(d2-r1);
			if(d1 < d2)	{
				theta += alpha;
			}
			else	{
				theta -= alpha;
			}
			alpha *= LEARNING_RATE;
		}
		pw.println(ret);
		pw.close(); 
	}

	public static double dist(double a, double b, double c, double d)	{
		double x = a-c;
		double y = b-d;
		return Math.sqrt(x*x+y*y);
	}
	
	/* NOTEBOOK CODE */

	public static void loadArray(int[][] grid) throws IOException {
		for(int[] a: grid)
			loadArray(a);
	}

	public static void loadArray(int[] in) throws IOException {
		for(int i = 0; i < in.length; i++)
			in[i] = readInt();
	}

	public static void loadArray(long[] in) throws IOException {
		for(int i = 0; i < in.length; i++)
			in[i] = readLong();
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