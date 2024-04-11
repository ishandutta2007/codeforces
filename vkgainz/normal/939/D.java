import java.util.ArrayList;
import java.util.Scanner;

public class loverescue {
	static ArrayList<Integer>[] paths;
	static boolean [] visited;
	static String ref;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		 ref = "abcdefghijklmnopqrstuvwxyz";
		int n = sc.nextInt();
		String a = sc.next();
		String b = sc.next();	
		paths = new ArrayList[26];
		for(int i=0;i<26;i++) {
			paths[i] = new ArrayList<Integer>();
		}
		boolean [] appear = new boolean[26];
		for(int i=0;i<n;i++) {
			int x = ref.indexOf(a.charAt(i));
			int y = ref.indexOf(b.charAt(i));
			paths[x].add(y);
			paths[y].add(x);
			appear[x] = true;
			appear[y] = true;
		}
		int tot =0;
		visited = new boolean[26];
		for(int i=0;i<26;i++) {
			visited[i] = !appear[i];
			if(visited[i]==false) {
				tot++;
			}
		}
		
		int count =0;
		for(int i=0;i<26;i++) {
			if(visited[i]) {
				continue;
			}
			count++;
			dfs(i);
		}
		System.out.println(tot-count);
		visited = new boolean[26];
		for(int i=0;i<26;i++) {
			visited[i] = !appear[i];
		}
		for(int i=0;i<26;i++) {
			if(visited[i]) {
				continue;
			}
			
			second(i,i);
		}
	}
	private static void dfs(int i) {
		visited[i] = true;
		for(int k : paths[i]) {
			if(visited[k]) {
				continue;
			}
			visited[k] = true;
			dfs(k);
		}
		
	}
	private static void second(int i,int head) {
		visited[i] = true;
		if(i != head) {
			System.out.println(ref.charAt(head) + " " + ref.charAt(i));
		}
		for(int k : paths[i]) {
			if(visited[k]) {
				continue;
			}
			visited[k] = true;
			second(k,head);
		}
	}
}