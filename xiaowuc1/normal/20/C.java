import java.io.*;
import java.util.*;
public class C20 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int v = Integer.parseInt(st.nextToken());
		int e = Integer.parseInt(st.nextToken());
		LinkedList<Edge>[] edges = new LinkedList[v];
		for(int i = 0; i < edges.length; i++)		{
			edges[i] = new LinkedList<Edge>();
		}
		while(e-- > 0)	{
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			a--;
			b--;
			if(a != b)	{
				edges[a].add(new Edge(b,w));
				edges[b].add(new Edge(a,w));
			}
		}
		long[] best = new long[v];
		Arrays.fill(best, 1L<<50);
		best[0] = 0;
		PriorityQueue<Vertex> q = new PriorityQueue<Vertex>();
		q.add(new Vertex(0,0));
		while(!q.isEmpty())		{
			Vertex curr = q.poll();
			if(curr.v == v-1)
				break;
			for(Edge out: edges[curr.v])	{
				long next = curr.w + out.w;
				if(next < best[out.d])		{
					best[out.d] = next;
					q.add(new Vertex(out.d, next));
				}
			}
		}
		if(best[v-1] == 1L<<50)		{
			System.out.println(-1);
			return;
		}
		LinkedList<Integer> ret = new LinkedList<Integer>();
		ret.add(v);
		int curr = v-1;
		q = new PriorityQueue<Vertex>();
		for(int i = 0; i < v-1; i++)	{
			q.add(new Vertex(i, -best[i]));
		}
		outer: while(!q.isEmpty())		{
			Vertex curr2 = q.poll();
			int testLoc = curr2.v;
			long currBest = -curr2.w;
			for(Edge out: edges[testLoc])		{
				if(currBest + out.w == best[curr] && out.d == curr)	{
					ret.addFirst(testLoc+1);
					curr = testLoc;
				}
			}
		}
		for(int x: ret)	{
			if(x != ret.peekLast())
				System.out.print(x + " ");
		}
		System.out.println(ret.peekLast());
	}
	static class Vertex implements Comparable<Vertex> {
		public int v;
		public long w;
		public Vertex(int a, long b)	{
			v=a;
			w=b;
		}
		public int compareTo(Vertex v)	{
			if(w<v.w)
				return -1;
			if(w>v.w)
				return 1;
			return 0;
		}
	}
	static class Edge	{
		public int d,w;
		public Edge(int a, int b)		{
			d=a;
			w=b;
		}
	}
}