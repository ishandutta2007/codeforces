import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class cowandsnacks {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		ArrayList<Integer>[] adj = new ArrayList[n];
		for(int i=0;i<n;i++) {
			adj[i] = new ArrayList<Integer>();
		}
		
		
		for(int i=0;i<k;i++) {
			int a = sc.nextInt()-1;
			int b = sc.nextInt()-1;
			adj[a].add(b);
			adj[b].add(a);
		}
		int count =0;
		boolean [] visited = new boolean[n];
		for(int i=0;i<n;i++) {
			if(visited[i]) {
				continue;
			}
			int tempCount =0;
			Queue<Integer> q = new LinkedList<Integer>();
			q.add(i);
			visited[i] = true;
			while(!q.isEmpty()) {
				int x = q.poll();
				for(int y : adj[x]) {
					if(!visited[y]) {
						tempCount++;
						visited[y] = true;
						q.add(y);
					}
				}
			}
			count+=tempCount;
		}
		System.out.println(k-count);
		
	}
}