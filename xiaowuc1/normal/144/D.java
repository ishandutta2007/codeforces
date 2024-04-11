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
		int v = readInt();
		int e = readInt();
		int s = readInt() - 1;
		int[][] fullInfo = new int[e][3];
		LinkedList<int[]>[] edges = new LinkedList[v];
		for(int i = 0; i < v; i++)	{
			edges[i] = new LinkedList<int[]>();
		}
		for(int i = 0; i < e; i++)	{
			fullInfo[i][0] = readInt()-1;
			fullInfo[i][1] = readInt()-1;
			fullInfo[i][2] = readInt();
			edges[fullInfo[i][0]].add(new int[]{fullInfo[i][1], fullInfo[i][2]});
			edges[fullInfo[i][1]].add(new int[]{fullInfo[i][0], fullInfo[i][2]});
		}
		int goal = readInt();
		int[] dist = new int[v];
		Arrays.fill(dist, 1 << 28);
		dist[s] = 0;
		PriorityQueue<Vertex> q = new PriorityQueue<Vertex>();
		q.add(new Vertex(s,0));
		while(!q.isEmpty())	{
			Vertex curr = q.poll();
			if(dist[curr.v] != curr.w)
				continue;
			for(int[] out: edges[curr.v])	{
				int next = curr.w + out[1];
				if(dist[out[0]] > next)	{
					dist[out[0]] = next;
					q.add(new Vertex(out[0], next));
				}
			}
		}
		int ret = 0;
		for(int k = 0; k < dist.length; k++)	{
			if(dist[k] == goal)	{
				ret++;
			}
		}
		for(int i = 0; i < fullInfo.length; i++)	{
			ret += count(dist[fullInfo[i][0]], dist[fullInfo[i][1]], goal, fullInfo[i][2]);
		}
		pw.println(ret);
		pw.close();
	}

	public static int count(int lD, int rD, int goalD, int len)	{
		int ret = 0;
		double maxD = Math.max(lD, rD) + (len - Math.abs(lD - rD)) / 2.;
		if(goalD >= lD && goalD <= maxD && goalD != lD)
			ret++;
		if(goalD >= rD && goalD <= maxD && goalD != rD)
			ret++;
		if(goalD == maxD)
			ret--;
		return ret;
	}
	
	static class Vertex implements Comparable<Vertex> {
		public int v,w;
		public Vertex(int a, int b)	{
			v=a;
			w=b;
		}
		public int compareTo(Vertex curr)	{
			return w - curr.w;
		}
	}
	
	/* NOTEBOOK CODE */

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