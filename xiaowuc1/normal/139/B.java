import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

import com.sun.org.apache.bcel.internal.generic.LLOAD;


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

	static int[] dx = new int[]{-1,0,1,0};
	static int[] dy = new int[]{0,1,0,-1};

	static double[][] dragon, princess;
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		final int MOD = 1000000007;
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int[] p = new int[n];
			int[] h = new int[n];
			for(int i = 0; i < n; i++)	{
				p[i] = 2 * (readInt() + readInt());
				h[i] = readInt();
			}
			long[] cost = new long[n];
			Arrays.fill(cost, Long.MAX_VALUE);
			int m = readInt();
			while(m-- > 0)	{
				int len = readInt();
				int wid = readInt();
				int go = readInt();
				for(int i = 0; i < n; i++)	{
					if(len < h[i])	{
						continue;
					}
					int numPer = len / h[i];
					int numRoll = p[i] / wid;
					if(numRoll * wid != p[i])
						numRoll++;
					int actual = numRoll / numPer;
					if(actual * numPer != numRoll)	{
						actual++;
					}
					cost[i] = Math.min(cost[i], actual * 1L * go);
				}
			}
			long ret = 0;
			for(long out: cost)	{
				ret += out;
			}
			pw.println(ret);
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