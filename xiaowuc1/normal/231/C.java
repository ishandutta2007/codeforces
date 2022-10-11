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
		int n = readInt();
		int k = readInt();
		int[] list = new int[n];
		for(int i = 0; i < n; i++)	{
			list[i] = readInt();
		}
		for(int qq = 0; qq < 10; qq++)	{ // anti-quick-sort destroyer?
			int a = (int)(n*Math.random());
			int b = (int)(n*Math.random());
			if(a != b)	{
				list[a] ^= list[b];
				list[b] ^= list[a];
				list[a] ^= list[b];
			}
		}
		Arrays.sort(list);
		int ret = 1;
		int min = list[0];
		int lastIndex = 0;
		long diff = 0;
		for(int i = 1; i < n; i++)	{
			if(list[i] != list[i-1])	{
				diff += (i-lastIndex) * 1L * (list[i] - list[i-1]);
				while(diff > k)	{
					diff -= list[i] - list[lastIndex++];
				}
			}
			if(i - lastIndex + 1 > ret)	{
				ret = i - lastIndex + 1;
				min = list[i];
			}
		}
		pw.println(ret + " " + min);
		pw.close();
	}

	/* NOTEBOOK CODE */

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