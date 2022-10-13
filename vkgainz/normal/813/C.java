import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class thetaggame {
	static ArrayList<Integer>[] adj;
	static int [] parent;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader( 
                new InputStreamReader(System.in)); 
//		 PrintWriter pw = new PrintWriter(new 
//				 BufferedWriter(new OutputStreamWriter(System.out)));

StringTokenizer st = new StringTokenizer(br.readLine()); 
		int n = Integer.parseInt(st.nextToken());
		int x = Integer.parseInt(st.nextToken())-1;
		 adj = new ArrayList[n];
		 for(int i=0;i<n;i++) {
			 adj[i] = new ArrayList<Integer>();
		 }
		 
		for(int i=0;i<n-1;i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken())-1;
			int b =Integer.parseInt(st.nextToken())-1;
			adj[a].add(b);
			adj[b].add(a);
		}
		int [] dist = new int[n];
		Arrays.fill(dist,-1);
		dist[0] = 0;
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(0);
		parent = new int[n];
		parent[0] = -1;
		while(!q.isEmpty()) {
			int a = q.poll();
			for(int next : adj[a]) {
				if(dist[next]<0) {
					parent[next] = a;
					q.add(next);
					dist[next]=dist[a]+1;
				}
			}
		}
		int d = dist[x];
		int numMoves = (d-1)/2;
		int currPos = x;
		for(int i=0;i<numMoves;i++) {
			currPos = parent[currPos];
		}
		//find height of largest subtree 
		//starting at currpos
		int currDist = 0;
		if(d%2==0) {
			currDist = 2;
		}
		else {
			currDist = 1;
		}
		dfs(currPos,0);
		System.out.println((currDist+max)*2+numMoves*2);
	}
	static int max;
	static void dfs(int x, int count) {
		max = Math.max(max,count);
		for(int next : adj[x]) {
			if(next != parent[x]) {
				dfs(next,count+1);
			}
		}
	}
}