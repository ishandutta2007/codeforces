import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.Queue;

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

	static long[] amt;
	static int[] dist;

	static LinkedList<Integer>[] edges;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int e = readInt();
			edges = new LinkedList[n];
			for (int i = 0; i < edges.length; i++) {
				edges[i] = new LinkedList<Integer>();
			}
			while(e-- > 0)	{
				int a = readInt()-1;
				int b = readInt()-1;
				edges[a].add(b);
				edges[b].add(a);
			}
			dist = new int[n];
			Arrays.fill(dist, 1<<25);
			dist[0] = 0;
			amt = new long[n];
			amt[n-1] = 1;
			LinkedList<Integer> q = new LinkedList<Integer>();
			q.add(0);
			while(!q.isEmpty())	{
				int curr = q.removeFirst();
				for(int out: edges[curr])	{
					if(dist[out] > dist[curr]+1)	{
						dist[out] = dist[curr]+1;
						q.addLast(out);
					}
				}
			}
			q.add(n-1);
			Arrays.fill(amt, 0);
			amt[n-1] = 1;
			boolean[] seen = new boolean[n];
			while(!q.isEmpty())	{
				int curr = q.removeFirst();
				for(int out: edges[curr])	{
					if(dist[out] == dist[curr]-1)	{
						amt[out] += amt[curr];
						if(!seen[out])	{
							seen[out] = true;
							q.addLast(out);
						}
					}
				}
			}
			long pathCount = amt[0];
			double max = 1;
			for(int i = 1; i < n-1; i++)	{
				q.add(n-1);
				Arrays.fill(amt, 0);
				amt[n-1] = 1;
				seen = new boolean[n];
				while(!q.isEmpty())	{
					int curr = q.removeFirst();
					for(int out: edges[curr])	{
						if(out == i)
							continue;
						if(dist[out] == dist[curr]-1)	{
							amt[out] += amt[curr];
							if(!seen[out])	{
								seen[out] = true;
								q.addLast(out);
							}
						}
					}
				}
				max = Math.max(max, 2. * (pathCount-amt[0]) / pathCount);
			}
			pw.println(max);
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