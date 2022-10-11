import java.io.*;
import java.util.*;
public class C95 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		LinkedList<Edge>[] edges = new LinkedList[n];
		for(int i = 0; i < n; i++)
			edges[i] = new LinkedList<Edge>();
		st = new StringTokenizer(br.readLine());
		int start = Integer.parseInt(st.nextToken());
		int end = Integer.parseInt(st.nextToken());
		long[] best = new long[n];
		start--;
		end--;
		Arrays.fill(best, 1L<<50);
		best[start] = 0;
		while(m-- > 0)	{
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			a--;
			b--;
			edges[a].add(new Edge(b,c));
			edges[b].add(new Edge(a,c));
		}
		int[] dist = new int[n];
		int[] cost = new int[n];
		for(int i = 0; i < n; i++)	{
			st = new StringTokenizer(br.readLine());
			dist[i] = Integer.parseInt(st.nextToken());
			cost[i] = Integer.parseInt(st.nextToken());
		}
		PriorityQueue<Vertex> q = new PriorityQueue<Vertex>();
		q.add(new Vertex(start, 0));
		while(!q.isEmpty())		{
			Vertex curr = q.poll();
			if(curr.v == end)
				break;
			int[] travel = new int[n];
			Arrays.fill(travel, 1<<30);
			travel[curr.v] = 0;
			LinkedList<Integer> list = new LinkedList<Integer>();
			list.add(curr.v);
			while(!list.isEmpty())		{
				int currLoc = list.removeFirst();
				if(best[currLoc] > best[curr.v] + cost[curr.v])	{
					//System.out.println("From " + curr.v + " can travel to " + currLoc);
					best[currLoc] = best[curr.v] + cost[curr.v];
					//System.out.println("Cost to get to " + curr.v + ": " + best[curr.v]);
					//System.out.println("Best cost so far: " + best[currLoc]);
					q.add(new Vertex(currLoc, best[currLoc]));
				}
				for(Edge out: edges[currLoc])	{
					int pot = travel[currLoc] + out.w;
					if(pot <= dist[curr.v] && travel[out.d] > pot)	{
						travel[out.d] = pot;
						list.addLast(out.d);
					}
				}
			}
		}
		//for(long bb: best)
		//	System.out.print(bb + " ");
		System.out.println(best[end] == 1L<<50 ? -1 : best[end]);
	}
	static class Vertex	implements Comparable<Vertex> {
		public int v;
		public long w;
		public Vertex(int a, long b)		{
			v=a;
			w=b;
		}
		public int compareTo(Vertex v)	{
			if(w < v.w)
				return -1;
			if(w > v.w)
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