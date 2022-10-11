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

	static final long HASH = 3137;
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int m = readInt();
			long[] curr = new long[2*n];
			while(m-- > 0)	{
				int a = readInt()-1;
				int b = readInt()-1;
				curr[a] += pow(HASH, b);
				curr[b] += pow(HASH, a);	
			}
			for(int i = 0; i < n; i++)	{
				curr[i+n] = curr[i] + pow(HASH, i);
			}
			Arrays.sort(curr);
			long ret = 0;
			for(int i = 0; i < curr.length;)	{
				int j = i+1;
				while(j < curr.length && curr[i] == curr[j])	{
					j++;
				}
				long diff = j-i;
				ret += diff * (diff-1) / 2;
				i = j;
			}
			pw.println(ret);
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