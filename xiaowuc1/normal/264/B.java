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
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			boolean[] comp = new boolean[100000];
			for(int i = 3; i * i < comp.length; i += 2)	{
				if(!comp[i])	{
					for(int j = i * i; j < comp.length; j += 2 * i)	{
						comp[j] = true;
					}
				}
			}
			int[] p = new int[9592];
			int[] maxSeen = new int[9592];
			int c = 0;
			p[0] = 2;
			for(int i = 3; i < comp.length; i += 2)		{
				if(!comp[i])	{
					p[++c] = i;
				}
			}
			int n = readInt();
			while(n-- > 0)	{
				int curr = readInt();
				int copy = curr;
				int best = 0;
				Set<Integer> index = new HashSet<Integer>();
				for(int i = 0; i < p.length; i++)	{
					int out = p[i];
					if(copy%out == 0)	{
						index.add(i);
						best = Math.max(best, maxSeen[i]);
						while(copy%out==0)	{
							copy/=out;
						}
					}
					if(out * out > copy)	{
						break;
					}
				}
				if(copy != 1)	{
					int save = Arrays.binarySearch(p, copy); 
					index.add(save);
					best = Math.max(best, maxSeen[save]);
				}
				best++;
				for(int out: index)	{
					maxSeen[out] = best;
				}
			}
			int ret = 1;
			for(int out: maxSeen)	{
				ret = Math.max(ret, out);
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