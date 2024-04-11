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
		LinkedList<Edge>[] edges = new LinkedList[n];
		for(int i = 0; i < n; i++)	{
			edges[i] = new LinkedList<Edge>();
		}
		for(int k = 1; k < n; k++)	{
			int a = readInt();
			int b = readInt();
			a--;
			b--;
			edges[a].add(new Edge(b, true));
			edges[b].add(new Edge(a, false));
		}
		int[] dist = new int[n];
		Arrays.fill(dist, 1 << 25);
		dist[0] = 0;
		LinkedList<Integer> q = new LinkedList<Integer>();
		q.add(0);
		LinkedList<Integer> order = new LinkedList<Integer>();
		while(!q.isEmpty())	{
			int curr = q.removeFirst();
			order.addLast(curr);
			for(Edge out: edges[curr])	{
				if(dist[out.d] > 1 + dist[curr])	{
					q.addLast(out.d);
					dist[out.d] = 1 + dist[curr];
				}
			}
		}
		int[] cost = new int[n];
		for(int i = 0; i < n; i++)	{
			for(Edge out: edges[i])	{
				if(dist[out.d] > dist[i] && !out.is)
					cost[0]++;
			}
		}
		while(!order.isEmpty()){
			int i = order.removeFirst();
			for(Edge out: edges[i])	{
				if(dist[out.d] > dist[i])	{
					if(out.is)	{
						cost[out.d] = 1 + cost[i];
					}
					else	{
						cost[out.d] = -1 + cost[i];
					}
				}
			}
		}
		int min = Integer.MAX_VALUE;
		for(int out: cost)	{
			min = Math.min(min, out);
		}
		pw.println(min);
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < n; i++)	{
			if(cost[i] == min)	{
				sb.append((i+1) + " ");
			}
		}
		pw.println(sb.toString().trim());
		pw.close(); 
	}

	static class Edge	{
		public int d;
		public boolean is;
		public Edge(int a, boolean b)	{
			d=a;
			is=b;
		}
	}
	
	/* NOTEBOOK CODE */

	public static void loadArray(int[][] grid) throws IOException {
		for(int[] a: grid)
			loadArray(a);
	}

	public static void loadArray(int[] in) throws IOException {
		for(int i = 0; i < in.length; i++)
			in[i] = readInt();
	}

	public static void loadArray(long[] in) throws IOException {
		for(int i = 0; i < in.length; i++)
			in[i] = readLong();
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