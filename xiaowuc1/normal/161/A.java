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
		int m = readInt();
		int x = readInt();
		int y = readInt();
		int[] l = new int[n];
		int[] r = new int[m];
		for(int i = 0; i < n; i++)
			l[i] = readInt();
		for(int i = 0; i < m; i++)
			r[i] = readInt();
		ArrayList<Integer> rA = new ArrayList<Integer>();
		ArrayList<Integer> rB = new ArrayList<Integer>();
		int i = 0;
		int j = 0;
		while(i < n && j < m)	{
			if(r[j] >= l[i]-x && r[j] <= l[i]+y)	{
				rA.add(++i);
				rB.add(++j);
			}
			else if(r[j] < l[i]-x)	{
				j++;
			}
			else	{
				i++;
			}
		}
		pw.println(rA.size());
		for(i = 0; i < rA.size(); i++)	{
			pw.println(rA.get(i) + " " + rB.get(i));
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