import java.io.*;
import java.math.*;
import java.util.*;
public class AMain	{
	static Edge[] edges;
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		edges = new Edge[n];
		for(int q = 0; q < n; q++)	{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			edges[q] = new Edge(--a, --b);
		}
		int bad = findBad();
		int[] dist = new int[n];
		Arrays.fill(dist, 1<<30);
		dist[edges[bad].a] = 0;
		for(int a = 0; a < n; a++)	{
			for(int i = 0; i < n; i++)	{
				if(i == bad)
					continue;
				dist[edges[i].a] = Math.min(dist[edges[i].a], 1 + dist[edges[i].b]);
				dist[edges[i].b] = Math.min(dist[edges[i].b], 1 + dist[edges[i].a]);
			}
		}
		boolean[] ring = new boolean[n];
		ring[edges[bad].b] = true;
		int curr = edges[bad].b;
		outer: while(dist[curr] != 0)	{
			for(int i = 0; i < n; i++)	{
				if(edges[i].a == curr && dist[edges[i].b] + 1 == dist[curr])	{
					curr = edges[i].b;
					ring[curr] = true;
					continue outer;
				}
				else if(edges[i].b == curr && dist[edges[i].a] + 1 == dist[curr])	{
					curr = edges[i].a;
					ring[curr] = true;
					continue outer;
				}
			}
		}
		Arrays.fill(dist, 1 << 30);
		for(int i = 0; i < ring.length; i++)
			if(ring[i])	{
				dist[i] = 0;
			}
		for(int a = 0; a < n; a++)	{
			for(int i = 0; i < n; i++)	{
				dist[edges[i].a] = Math.min(dist[edges[i].a], 1 + dist[edges[i].b]);
				dist[edges[i].b] = Math.min(dist[edges[i].b], 1 + dist[edges[i].a]);
			}
		}
		for(int out: dist)
			System.out.print(out + " ");
	}
	public static int findBad()	{
		boolean[] used = new boolean[edges.length];
		boolean[] seen = new boolean[edges.length];
		seen[0] = true;
		int numSeen = 1;
		while(numSeen != seen.length)	{
			for(int i = 0; i < used.length; i++)	{
				if(!used[i] && (seen[edges[i].a] ^ seen[edges[i].b]))	{
					used[i] = true;
					seen[edges[i].a] = true;
					seen[edges[i].b] = true;
					numSeen++;
				}
			}
		}
		for(int i = 0; i < used.length; i++)	{
			if(!used[i])
				return i;
		}
		return -1;
	}
	static class Edge	{
		public int a,b;
		public Edge(int x, int y)	{
			a=x;
			b=y;
		}
	}
}