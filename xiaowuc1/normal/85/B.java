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

	static String base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int[] num = new int[3];
		int[] time = new int[3];
		loadArray(num);
		loadArray(time);
		int n = readInt();
		long[] orig = new long[n];
		long[] curr = new long[n];
		for(int i = 0; i < n; i++)	{
			orig[i] = curr[i] = readInt();
		}
		for(int qq = 0; qq < 3; qq++)	{
			PriorityQueue<Long> q = new PriorityQueue<Long>();
			for(int k = 0; k < n; k++)	{
				if(q.size() != num[qq])	{
					curr[k] += time[qq];
					q.add(curr[k]);
				}
				else	{
					long early = q.poll();
					curr[k] = Math.max(early, curr[k]) + time[qq];
					q.add(curr[k]);
				}
			}
		}
		long ret = 0;
		for(int i = 0; i < n; i++)	{
			ret = Math.max(ret, curr[i] - orig[i]);
		}
		pw.println(ret);
		pw.close(); 
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