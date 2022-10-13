import java.util.*;

public class rumor {
	static int n;
	static ArrayList<Integer> [] adj;
	static boolean [] visited;
	static ArrayList<Integer> temp;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();;
		int m = sc.nextInt();
		adj = new ArrayList[n];
		for(int i=0;i<n;i++) {
			adj[i] = new ArrayList<Integer>();
		}
		int [] vals = new int[n];
		for(int i=0;i<n;i++) {
			vals[i] =sc.nextInt();
		}
		for(int i=0;i<m;i++) {
			int a = sc.nextInt()-1;
			int b = sc.nextInt()-1;
			adj[a].add(b);
			adj[b].add(a);
		}
		visited = new boolean[n];
		long count=0;
		for(int i=0;i<n;i++) {
			if(!visited[i]) {
				temp = new ArrayList<Integer>();
				dfs(i);
				int min = Integer.MAX_VALUE;
				for(int x : temp) {
					min = Math.min(min, vals[x]);
				}
				count+=min;
				
			}
		}
		System.out.println(count);

	}
	private static void dfs(int i) {
		visited[i]=true;
		temp.add(i);
		for(int x : adj[i]) {
			if(!visited[x]) {
				dfs(x);
			}
		}
		
	}
}