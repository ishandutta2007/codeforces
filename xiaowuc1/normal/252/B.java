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

	static int[] dx = new int[]{-1,0,1,0};
	static int[] dy = new int[]{0,1,0,-1};

	static Set<Integer>[] edges;

	static int k;

	static boolean[] seen;
	static boolean[] used;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			if(n <= 2)	{
				while(n-->0)readInt();
				pw.println(-1);
			}
			else	{
				int[] list = new int[n];
				for (int i = 0; i < list.length; i++) {
					list[i] = readInt();
				}
				long t = System.currentTimeMillis();
				while(System.currentTimeMillis() - t <= 100)	{
					int a = (int)(Math.random()*n);
					int b = (int)(Math.random()*n);
					if(list[a] == list[b])
						continue;
					int c = list[a];
					list[a] = list[b];
					list[b] = c;
					boolean le = true;
					boolean ge = true;
					for(int i = 1; i < n; i++)	{
						if(list[i] > list[i-1])	{
							ge = false;
						}
						if(list[i] < list[i-1])	{
							le = false;
						}
					}
					if(!le && !ge)	{
						pw.printf("%d %d\n", ++a, ++b);
						exitImmediately();
					}
					c = list[a];
					list[a] = list[b];
					list[b] = c;
				}
				pw.println(-1);
			}
		}
		pw.close();
	}

	public static long modpow(long b, long e, long m)	{
		long r = 1;
		while(e > 0)	{
			if(e%2==1)	{
				r *= b;
				r %= m;
			}
			b *= b;
			b %= m;
			e /= 2;
		}
		return r;
	}

	private static void exitImmediately()	{
		pw.close();
		System.exit(0);
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
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}