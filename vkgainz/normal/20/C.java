import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;


public class dijkstra {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		ArrayList<Node>[] adj = new ArrayList[n];
		for(int i=0;i<n;i++) {
			adj[i] = new ArrayList<Node>();
		}
		for(int i=0;i<m;i++) {
			int a = sc.nextInt()-1;
			int b = sc.nextInt()-1;
			int c = sc.nextInt();
			adj[a].add(new Node(b,c));
			adj[b].add(new Node(a,c));
		}
		long [] dist = new long[n];
		Arrays.fill(dist,(long) Math.pow(10,12));
		dist[0] =0;
		PriorityQueue<Node> pq = new PriorityQueue<Node>(new Comparator<Node>() {
			public int compare(Node o1, Node o2) {
				if(dist[o1.index]>dist[o2.index]) {
					return 1;
				}
				else if(dist[o1.index]==dist[o2.index]) {
					return 0;
				}
				else return -1;
			}
		});
		int [] parent = new int[n];
		parent[0] = -1;
		pq.add(new Node(0,0));
		while(!pq.isEmpty()) {
			Node rem = pq.poll();
			for(Node next : adj[rem.index]) {
				if(dist[rem.index]+next.val<dist[next.index]) {
					pq.add(next);
					parent[next.index] = rem.index;
					dist[next.index] = dist[rem.index]+next.val;
				}
			}
		}
		if(dist[n-1]==Math.pow(10,12)) {
			System.out.println(-1);
			return;
		}
		
		int x = n-1;
		StringBuilder sb = new StringBuilder();
		ArrayList<Integer> path = new ArrayList<Integer>();
		while(parent[x] !=-1) {
			path.add(x+1);
			x = parent[x];
			
		}
		path.add(1);
		for(int k=path.size()-1;k>=0;k--) {
			sb.append(path.get(k) + " ");
		}
		System.out.println(sb.toString());
	}
	static class Node{
		int index;
		int val;
		public Node(int i,int v) {
			index=i;
			val=v;
		}
	}
}