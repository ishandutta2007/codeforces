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
			int e = readInt();
			LinkedList<Edge>[] edges = new LinkedList[n];
			for (int i = 0; i < edges.length; i++) {
				edges[i] = new LinkedList<Edge>();
			}
			int[] flow = new int[n];
			for(int k = 0; k < e; k++)	{
				int a = readInt()-1;
				int b = readInt()-1;
				int w = readInt();
				flow[a]+=w;
				flow[b]+=w;
				int orient = -1;
				if(a == 0)	{
					orient = 0;
				}
				if(b == 0)	{
					orient = 1;
				}
				Edge ee = new Edge(a,b,w,orient,k);
				edges[a].add(ee);
				edges[b].add(ee);
			}
			for (int i = 0; i < flow.length; i++) {
				flow[i] /= 2;
			}
			flow[0] = 0;
			LinkedList<Integer> q = new LinkedList<Integer>();
			q.add(0);
			while(!q.isEmpty())	{
				int curr = q.removeFirst();
				for(Edge out: edges[curr])	{
					if(out.orient == 1 && curr != out.b)
						continue;
					if(out.orient == 0 && curr != out.a)
						continue;
					if(curr == out.a)	{
						flow[out.b] -= out.w;
						out.orient = 0;
						if(out.b != n-1 && flow[out.b] == 0)	{
							q.addLast(out.b);
						}
					}
					else	{
						flow[out.a] -= out.w;
						out.orient = 1;	
						if(out.a != n-1 && flow[out.a] == 0)	{
							q.addLast(out.a);
						}
					}
				}
			}
			int[] ret = new int[e];
			for(int i = 0; i < n; i++)	{
				for(Edge out: edges[i])	{
					ret[out.i] = out.orient;
				}
			}
			for(int out: ret)
				pw.println(out);
		}
		pw.close();
	}

	static class Edge	{
		public int a,b,w,orient,i;

		public Edge(int a, int b, int w, int orient, int i) {
			super();
			this.a = a;
			this.b = b;
			this.w = w;
			this.orient = orient;
			this.i = i;
		}
		
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