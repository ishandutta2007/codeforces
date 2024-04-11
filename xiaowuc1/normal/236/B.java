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
		boolean[] comp = new boolean[101];
		comp[0] = true;
		comp[1] = true;
		for(int i = 2; i * i < comp.length; i++)	{
			if(!comp[i])	{
				for(int j = i*i; j < comp.length; j += i)
					comp[j] = true;
			}
		}
		int[] p = new int[25];
		int c = 0;
		for(int i = 2; i < comp.length; i++)	{
			if(!comp[i])	{
				p[c++] = i;
			}
		}
		int a = readInt();
		int b = readInt();
		c = readInt();
		long ret = 0;
		for(int i = 1; i <= a; i++)	{
			for(int j = 1; j <= b; j++)	{
				for(int k = 1; k <= c; k++)	{
					int numDiv = 1;
					int curr = i*j*k;
					for(int out: p)	{
						int num = 1;
						while(curr%out == 0)	{
							num++;
							curr /= out;
						}
						numDiv *= num;
					}
					ret += numDiv;
					ret %= 1<<30;
				}
			}
		}
		pw.println(ret);
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