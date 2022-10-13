import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;

public class lunarnewyear {
	static ArrayList<Integer>[] adj;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		adj = new ArrayList[n];
		for(int i=0;i<n;i++) {
			adj[i] = new ArrayList<Integer>();
		}
		for(int i=0;i<m;i++) {
			int a = sc.nextInt()-1;
			int b = sc.nextInt()-1;
			adj[a].add(b);
			adj[b].add(a);
		}
		boolean [] visited = new boolean[n];
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
		pq.add(0);
		
		int count =0;
		while(!pq.isEmpty()) {
			if(count==n) {
				break;
			}
			System.out.println(pq.peek()+1);
			visited[pq.peek()]=true;
			for(int x : adj[pq.poll()]) {
				if(!visited[x]) {
					visited[x]=true;
					pq.add(x);
				}
			}
			count++;
			
		}
		
	}
}