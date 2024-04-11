import java.util.ArrayList;
import java.util.Scanner;

public class twofairs {
	static ArrayList<Integer>[] adj;
	static boolean[] visited;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		StringBuilder sb = new StringBuilder();
		for(int i=0;i<t;i++) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			int a = sc.nextInt();
			int b = sc.nextInt();
			adj = new ArrayList[n+1];
			for(int j=1;j<=n;j++) {
				adj[j] = new ArrayList<Integer>();
			}
			for(int j=0;j<m;j++) {
				int x = sc.nextInt();
				int y =sc.nextInt();
				adj[x].add(y);
				adj[y].add(x);
			}
			visited =new boolean[n+1];
			count =0;
			dfs(a,b);
			int u = n-count-1;
			visited = new boolean[n+1];
			count =0;
			dfs(b,a);
			int v = n-count-1;
//			System.out.println(u*v);
			sb.append((long)u*v + " ");
			
		}
		System.out.println(sb.toString());
	}
	static int count;
	static void dfs(int curr,int ex) {
		count++;
		visited[curr] = true;
		for(int next : adj[curr]) {
			if(next!=ex && !visited[next]) {
				dfs(next,ex);
			}
		}
	}
}