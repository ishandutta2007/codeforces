
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class A {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		int wait = readInt();
		int[] d = new int[n];
		for(int i = 0; i < n; i++)
			d[i] = readInt();
		int[] gain = new int[n];
		for(int i = 0; i < n; i++)
			gain[i] = readInt();
		int numWait = 0;
		int max = 0;
		int curr = 0;
		for(int i = 0; i < n; i++)	{
			curr += gain[i];
			max = Math.max(max, gain[i]);
			while(curr < d[i])	{
				curr += max;
				numWait++;
			}
			curr -= d[i];
		}
		int ret = 0;
		for(int out: d)
			ret += out;
		pw.println(ret + numWait * 1L * wait);
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
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}