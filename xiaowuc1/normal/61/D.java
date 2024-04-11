import java.io.*;
import java.util.*;
public class D61 {
	static LinkedList<Edge>[] edges;
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		edges = new LinkedList[n];
		for(int i = 0; i < n; i++)	{
			edges[i] = new LinkedList<Edge>();
		}
		while(n-- > 1)	{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			a--;
			b--;
			edges[a].add(new Edge(b,w));
			edges[b].add(new Edge(a,w));
		}
		int[] dist = new int[edges.length];
		Arrays.fill(dist, 2100000000);
		dist[0] = 0;
		PriorityQueue<Vertex> q = new PriorityQueue<Vertex>();
		q.add(new Vertex(0, 0));
		while(!q.isEmpty())		{
			Vertex curr = q.poll();
			for(Edge out: edges[curr.v])	{
				if(dist[out.d] > dist[curr.v] + out.w)	{
					dist[out.d] = dist[curr.v] + out.w;
					q.add(new Vertex(out.d, dist[out.d]));
				}
			}
		}
		long ret = 0;
		for(LinkedList<Edge> list: edges)		{
			for(Edge out: list)			{
				ret += out.w;
			}
		}
		int max = 0;
		for(int x: dist)	{
			if(x>max)
				max = x;
		}
		ret -= max;
		System.out.println(ret);
	}
	static class Edge	{
		public int d,w;
		public Edge(int a, int b)	{
			d=a;
			w=b;
		}
	}
	static class Vertex implements Comparable<Vertex>	{
		public int v,w;
		public Vertex(int a, int b)	{
			v=a;
			w=b;
		}
		public int compareTo(Vertex v)	{
			return w-v.w;
		}
	}
}