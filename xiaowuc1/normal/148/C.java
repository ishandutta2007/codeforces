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
		int a = readInt();
		int b = readInt();
		int[] list = new int[n];
		Arrays.fill(list, 1);
		int next = 0;
		for(int k = 0; k < b; k++)	{
			if(next+1 < list.length)
				list[next+1] = list[next] * 2;
			next++;
		}
		if(b == 0)	{
			next++;
		}
		for(int k = 0; k < a; k++)	{
			if(next+1 < list.length)
				list[next+1] = list[next] + 1;
			next++;
		}
		int actualA = 0;
		int actualB = 0;
		int max = list[0];
		int maxTotal = list[0];
		for(int i = 1; i < n; i++)	{
			if(list[i] > maxTotal)	{
				actualB++;
			}
			else if(list[i] > max)	{
				actualA++;
			}
			max = Math.max(max, list[i]);
			maxTotal += list[i];
		}
		if(a == actualA && b == actualB)	{
			StringBuilder sb = new StringBuilder();
			for(int out: list)	{
				sb.append(out + " ");
			}
			pw.println(sb.toString().trim());
		}
		else	{
			pw.println(-1);
		}
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