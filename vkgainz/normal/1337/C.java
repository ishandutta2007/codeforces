import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class linovaandkingdom {
	static ArrayList<Integer>[] edge;
	static int [] depth;
	static int[] subtree_sz;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		edge = new ArrayList[n];
		for(int i=0;i<n;i++) {
			edge[i] = new ArrayList<Integer>();
		}
		for(int i=0;i<n-1;i++) {
			int u = sc.nextInt()-1; int v = sc.nextInt()-1;
			edge[u].add(v); edge[v].add(u);
		}
		depth = new int[n];
		subtree_sz = new int[n];
		depth[0] = 0;
		dfs(0,-1);
//		for(int i=0;i<n;i++) {
//			System.out.println(depth[i]);
//		}
		for(int i=0;i<n;i++) {
			depth[i]-=subtree_sz[i];
			depth[i]++;
		}
		Arrays.sort(depth);
		long sum = 0;
		for(int i=depth.length-1;i>=depth.length-k;i--) {
			sum+=depth[i];
			
		}
		System.out.println(sum);
		
	}
	static void dfs(int curr,int par) {
		subtree_sz[curr]++;
		for(int x : edge[curr]) {
			if(x!=par) {
				depth[x] = depth[curr]+1;
				dfs(x,curr);
				subtree_sz[curr]+=subtree_sz[x];
			}
		}
	}
}