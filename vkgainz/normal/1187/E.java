import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class treepainting {
	static int counter;
	static int [] euler;
	static int [] depth;
	static ArrayList<Integer>[] tree;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		tree = new ArrayList[n];
		for(int i=0;i<n;i++) {
			tree[i] = new ArrayList<Integer>();
		}
		for(int i=0;i<n-1;i++) {
			int a = sc.nextInt()-1;
			int b = sc.nextInt()-1;
			tree[a].add(b);
			tree[b].add(a);
		}
		Queue<Integer> q = new LinkedList<Integer>();
		depth = new int[n];
		Arrays.fill(depth,-1);
		depth[0] = 0;
		q.add(0);
		while(!q.isEmpty()) {
			int x = q.poll();
			for(int y : tree[x]) {
				if(depth[y]==-1) {
					depth[y] = depth[x]+1;
					q.add(y);
				}
			}
		}
		long [] dp = new long[n];
		int [] subtree = new int[n];
		euler = new int[2*n];
		counter = 0;
		dfs(0);
		int [] visited = new int[n];
		Arrays.fill(visited,-1);
		for(int i=0;i<2*n;i++) {
			if(visited[euler[i]]<0) {
				visited[euler[i]] = i;
			}
			else {
				subtree[euler[i]] = (i-visited[euler[i]]+1)/2;
			}
		}
	long c =0;
	for(int i=0;i<n;i++) {
		c+=subtree[i];
	}
	dp[0] = c;
	q= new LinkedList<Integer>();
	q.add(0);
	while(!q.isEmpty()) {
		int x = q.poll();
		for(int y : tree[x]) {
			if(depth[y]>depth[x]) {
				dp[y] = dp[x]+n-2*subtree[y];
				q.add(y);
			}
		}
	}
	long max =0;
	for(int i=0;i<n;i++) {
		max = Math.max(max,dp[i]);
//		System.out.print(dp[i]+ " ");
	}
	System.out.println(max);
	

	}
	static void dfs(int curr) {
		euler[counter] = curr;
		counter++;
		for(int y : tree[curr]) {
			if(depth[y]>depth[curr]) {
				dfs(y);
			}

		}
		euler[counter] =curr;
		counter++;
	}
}