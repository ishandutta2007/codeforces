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

	static LinkedList<Integer>[] edges;
	static int[] list;
	static int[] dist;
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			list = new int[n];
			dist = new int[n];
			edges = new LinkedList[n];
			for (int i = 0; i < list.length; i++) {
				list[i] = readInt();
				edges[i] = new LinkedList<Integer>();
				dist[i] = 1 << 25;
			}
			LinkedList<Integer> q = new LinkedList<Integer>();
			for(int qqq = 1; qqq < n; qqq++)	{
				int a = readInt()-1;
				int b = readInt()-1;
				edges[a].add(b);
				edges[b].add(a);
			}
			int s = readInt()-1;
			q.add(s);
			dist[s] = 0;
			while(!q.isEmpty())	{
				int curr = q.removeFirst();
				for(int out: edges[curr])	{
					if(dist[out] > 1 + dist[curr])	{
						dist[out] = 1 + dist[curr];
						q.addLast(out);
					}
				}
			}
			pw.println(solve(s));
		}
		pw.close();
	}
	
	public static long solve(int curr)	{
		if(list[curr] == 0)	{
			return 0;
		}
		LinkedList<Long> best = new LinkedList<Long>();
		for(int out: edges[curr])	{
			if(dist[out] > dist[curr])	{
				list[out]--;
				best.add(1+solve(out));
			}
		}
		if(best.isEmpty())	{
			return 0;
		}
		Collections.sort(best);
		long ret = 0;
		while(!best.isEmpty() && list[curr] > 0)	{
			ret += best.removeLast();
			ret++;
			list[curr]--;
		}
		long other = 0;
		for(int out: edges[curr])	{
			if(dist[out] > dist[curr])	{
				other += list[out];
			}
		}
		other = Math.min(other, list[curr]);
		ret += 2*other;
		list[curr] -= other;
		return ret;
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