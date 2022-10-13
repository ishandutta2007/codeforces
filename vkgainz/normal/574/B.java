import java.util.ArrayList;
import java.util.Scanner;

public class bearandthreemusketeers{
	static ArrayList<Integer>[] adj;
	static int n;
	static boolean [][] knows;
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		 n = sc.nextInt();
		int m = sc.nextInt();
		adj = new ArrayList[n];
		knows = new boolean[n][n];
		for(int i=0;i<n;i++) {
			adj[i] = new ArrayList<Integer>();
		}
		for(int i=0;i<m;i++) {
			int a = sc.nextInt()-1;
			int b = sc.nextInt()-1;
			adj[b].add(a);
			adj[a].add(b);
			knows[b][a]  = true;
			knows[a][b]= true;
		}
		int min = 12000;
		for(int i=0;i<n;i++) {
			for(int j : adj[i]) {
				for(int k : adj[j]) {
					if(k==i) {
						continue;
					}
					if(knows[i][k]) {
						min = Math.min(min,adj[i].size()+adj[j].size()+adj[k].size()-6);
					}
				}
					
			}
			
		}
		if(min==12000) {
			System.out.println(-1);
			return;
		}
		System.out.println(min);
	}
}