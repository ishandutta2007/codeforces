import java.io.*;
import java.util.*;

public class Solution {
	static List<Integer>[] graph;
	static boolean[] visited;
	
    public static void main(String args[]) {
    	Scanner in = new Scanner(System.in);
    	int n=in.nextInt(), m=in.nextInt();
    	graph = new List[n+m];
    	for(int i=0; i<n+m; ++i)
    		graph[i] = new ArrayList<Integer>();
    	visited = new boolean[n+m];
    	boolean hasLanguage=false;
    	for(int i=0; i<n; ++i) {
    		int k=in.nextInt();
    		for(int j=0; j<k; ++j) {
    			int a=in.nextInt()-1;
    			graph[i].add(n+a);
    			graph[n+a].add(i);
    		}
    		if(k>0)
    			hasLanguage=true;
    	}
    	int t=hasLanguage?-1:0;
    	for(int i=0; i<n; ++i) {
    		if(!visited[i]) {
    			dfs(i);
    			++t;
    		}
    	}
    	System.out.println(t);
    }
    
    static void dfs(int node) {
    	visited[node]=true;
    	for(int neighbor : graph[node])
    		if(!visited[neighbor])
    			dfs(neighbor);
    }
}