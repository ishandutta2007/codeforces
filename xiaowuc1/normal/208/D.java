import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		int[] stream = new int[n];
		int[] cost = new int[5];
		loadArray(stream);
		loadArray(cost);
		int curr = 0;
		long[] ret = new long[5];
		for(int out: stream)	{
			curr += out;
			for(int i = 4; i >= 0; i--)	{
				ret[i] += curr / cost[i];
				curr %= cost[i];
			}
		}
		StringBuilder sb = new StringBuilder();
		for(long out: ret)
			sb.append(out + " ");
		pw.println(sb.toString().trim());
		pw.println(curr);
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
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}