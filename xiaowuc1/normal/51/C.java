import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.Queue;

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
			TreeSet<Double> set = new TreeSet<Double>();
			while(n-- > 0)	{
				set.add(readDouble());
			}
			while(set.size() < 3)	{
				set.add(set.last() + 1);
			}
			double last = set.last();
			double min = 0;
			double max = 2e9;
			for(int qqq = 0; qqq < 100; qqq++)	{
				double mid = (min+max)/2;
				double curr = -1e18;
				boolean win = false;
				for(int k = 0; k < 3; k++)	{
					curr = set.higher(curr) + 2 * mid;
					if(curr >= last)	{
						win = true;
						break;
					}
				}
				if(win)	{
					max = mid;
				}
				else	{
					min = mid;
				}
			}
			min = max;
			pw.printf("%.6f\n", min);
			double curr = -1e18;
			StringBuilder sb = new StringBuilder();
			for(int k = 0; k < 3; k++)	{
				sb.append(String.format("%.6f ", set.higher(curr) + min));
				curr = set.higher(curr) + 2 * min;
				if(curr >= last)	{
					curr -= min - 1;
				}
			}
			pw.println(sb.toString().trim());
		}
		pw.close();
	}

	public static long pow(long b, long e)	{
		long r = 1;
		while(e > 0)	{
			if((e&1)==1)	{
				r *= b;
			}
			b *= b;
			e >>= 1;
		}
		return r;
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