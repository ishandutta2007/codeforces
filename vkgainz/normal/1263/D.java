import java.util.ArrayList;
import java.util.Scanner;

public class D {
	static boolean[] visited;
	static ArrayList<Integer>[] adj;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String ref = "abcdefghijklmnopqrstuvwxyz";
		adj= new ArrayList[26];
		for(int i=0;i<26;i++) adj[i] = new ArrayList<>();
		boolean[] put = new boolean[26];
		int n = sc.nextInt();
		for(int i=0;i<n;i++) {
			String s = sc.next();
			put[ref.indexOf(s.charAt(0))]= true;
			for(int j=0;j<s.length()-1;j++) {
				adj[ref.indexOf(s.charAt(j))].add(ref.indexOf(s.charAt(j+1)));
				adj[ref.indexOf(s.charAt(j+1))].add(ref.indexOf(s.charAt(j)));
				put[ref.indexOf(s.charAt(j+1))] = true;
			}
			
		}
		int numComponents =0;
		visited = new boolean[26];
		for(int i=0;i<26;i++) {
			if(!visited[i] && put[i]) {
				numComponents++;
				dfs(i);
			}
			
		}
		System.out.println(numComponents);
		
	}
	static void dfs(int i) {
		visited[i] = true;
		for(int j : adj[i]) {
			if(!visited[j]) {
				dfs(j);
			}
		}
	}
}