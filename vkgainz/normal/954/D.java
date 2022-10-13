import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class fighttraffic {
	static ArrayList<Integer>[] adj;
	static boolean [][] connected;
	static int n,s,t;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		 n = sc.nextInt();
		int m = sc.nextInt();
		 s = sc.nextInt()-1;
		 t = sc.nextInt()-1;
		connected = new boolean[n][n];
		adj = new ArrayList[n];
		for(int i=0;i<n;i++) {
			adj[i] = new ArrayList<Integer>();
		}
		for(int i=0;i<m;i++) {
			int a = sc.nextInt()-1;
			int b = sc.nextInt()-1;
			connected[a][b] = true;
			connected[b][a] = true;
			adj[a].add(b);
			adj[b].add(a);
		}
		
		int [] sdist = bfs(s);
		int [] tdist = bfs(t);
		
		int dist = sdist[t];
		int count =0;
		for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++) {
				if(!connected[i][j]) {
					int next = Math.min(sdist[i]+1+tdist[j], sdist[j]+1+tdist[i]);
					if(next>=dist) {
						count++;
					}
				}
			}
		}
		System.out.println(count);
	}
	static int [] bfs(int src) {
		boolean [] visited = new boolean[n];
		int [] dist = new int[n];
		dist[src]=0;
		visited[src]=true;
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(src);
		while(!q.isEmpty()) {
			int u = q.peek();
			q.poll();
			for(int x : adj[u]) {
				if(!visited[x]) {
					visited[x]=true;
				dist[x] = dist[u]+1;
				q.add(x);
				}
			}
		}
		
		
		
		
		
		return dist;
	}
}