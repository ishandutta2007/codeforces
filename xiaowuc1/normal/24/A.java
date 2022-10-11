import java.io.*;
import java.util.*;
public class AMain {
	static int[] from, to, weight;
	static int ret;
	public static void main(String[] args) throws IOException	{
		ret = Integer.MAX_VALUE;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		from = new int[n];
		to = new int[n];
		weight = new int[n];
		for(int i = 0; i < n; i++)	{
			StringTokenizer st = new StringTokenizer(br.readLine());
			from[i] = Integer.parseInt(st.nextToken())-1;
			to[i] = Integer.parseInt(st.nextToken())-1;
			weight[i] = Integer.parseInt(st.nextToken());
		}
		for(int i = 0; i < n; i++)	{
			if(from[i] == 0)
				dfs(to[i]);
			if(to[i] == 0)
				dfs(from[i]);
		}
		System.out.println(ret);
	}
	public static void dfs(int currV)	{
		int[] dist = new int[from.length];
		Arrays.fill(dist, 1 << 20);
		dist[0] = 0;
		dist[currV] = 1;
		LinkedList<Integer> q = new LinkedList<Integer>();
		q.add(currV);
		while(!q.isEmpty())	{
			int curr = q.removeFirst();
			for(int i = 0; i < from.length; i++)		{
				if(from[i] == curr && dist[to[i]] > 1 + dist[curr])	{
					q.addLast(to[i]);
					dist[to[i]] = 1 + dist[curr];
				}
				if(to[i] == curr && dist[from[i]] > 1 + dist[curr])	{
					q.addLast(from[i]);
					dist[from[i]] = 1 + dist[curr];
				}
			}
		}
		int cost = 0;
		for(int i = 0; i < from.length; i++)	{
			if((dist[from[i]] + 1) % from.length != (dist[to[i]]))	{
				cost += weight[i];
			}
		}
		ret = Math.min(ret, cost);
	}
}