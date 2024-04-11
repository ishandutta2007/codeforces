import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class sendthefool {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		ArrayList<Integer>[] adj = new ArrayList[n];
		for(int i=0;i<n;i++) {
			adj[i] = new ArrayList<Integer>();
		}
		int [][] cost = new int[n][n];
		for(int i=0;i<n-1;i++) {
			int u = sc.nextInt();
			int v = sc.nextInt();
			adj[u].add(v);
			adj[v].add(u);
			int c = sc.nextInt();
			cost[u][v] = c;
			cost[v][u]=c;
			
			
		}
		int [] dist = new int[n];
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(0);
		boolean [] visited = new boolean[n];
		while(!q.isEmpty()) {
			int u = q.poll();
			visited[u]=true;
			for(int x : adj[u]) {
				if(!visited[x]) {
					dist[x] = dist[u] + cost[u][x];
					visited[x]=true;
					q.add(x);
				}
			}
		}
		int max =0;
		for(int i=0;i<n;i++) {
			max = Math.max(max,dist[i]);
		}
		System.out.println(max);
		
	}
}