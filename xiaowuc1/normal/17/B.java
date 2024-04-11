import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
public class B {
	static boolean[][] edges;
	static int[] priority;
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int v = Integer.parseInt(br.readLine());
		priority = new int[v];
		StringTokenizer st = new StringTokenizer(br.readLine());
		int e = Integer.parseInt(br.readLine());
		PriorityQueue<Edge> q = new PriorityQueue<Edge>();
		while(e-- > 0)	{
			st = new StringTokenizer(br.readLine());
			q.add(new Edge(Integer.parseInt(st.nextToken())-1, Integer.parseInt(st.nextToken())-1, Integer.parseInt(st.nextToken())));
		}
		boolean[] has = new boolean[v];
		long x = 0;
		while(!q.isEmpty())	{
			Edge ee = q.poll();
			if(!has[ee.b])	{
				has[ee.b] = true;
				x += ee.w;
			}
		}
		int num = 0;
		for(boolean b: has)
			if(!b)
				num++;
		System.out.println(num == 1 ? x : -1);
	}
	public static boolean isConnected(int a, int b, int l)	{
		boolean[] q = new boolean[l];
		LinkedList<Integer> queue = new LinkedList<Integer>();
		queue.add(a);
		while(!queue.isEmpty())	{
			int x = queue.removeFirst();
			if(q[x])
				continue;
			q[x] = true;
			if(x == b)
				return true;
			for(int i = 0; i < edges.length; i++)	{
				if(edges[x][i])	{
					queue.addLast(i);
				}
			}
		}
		return false;
	}
	static class Edge implements Comparable<Edge> {
		public int a,b,w;
		public Edge(int x, int y, int z)	{
			a=x;
			b=y;
			w=z;
		}
		public int compareTo(Edge e)	{
			return w-e.w;
		}
	}
}