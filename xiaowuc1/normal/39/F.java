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
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int m = readInt();
			int k = readInt();
			int[] frog = new int[m];
			for (int i = 0; i < frog.length; i++) {
				frog[i] = readInt();
			}
			int[] list = new int[k];
			for (int i = 0; i < list.length; i++) {
				list[i] = readInt();
			}
			int max = Integer.MAX_VALUE;
			ArrayList<Integer> ret = new ArrayList<Integer>();
			for(int i = 0; i < m; i++)	{
				int curr = frog[i];
				int now = 0;
				for(int out: list)	{
					if(out%curr==0)	{
						now++;
					}
				}
				if(now < max)	{
					ret = new ArrayList<Integer>();
					max = now;
				}
				if(now == max)	{
					ret.add(i+1);
				}
			}
			pw.println(ret.size());
			StringBuilder sb = new StringBuilder();
			for(int out: ret)	{
				sb.append(out + " ");
			}
			pw.println(sb.toString().trim());
		}
		pw.close();
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