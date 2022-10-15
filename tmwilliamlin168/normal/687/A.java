import java.io.*;
import java.util.*;

public class Solution {
	static List<Integer>[] graph;
	static int[] colors;
	
    public static void main(String args[]) {
    	Scanner in = new Scanner(System.in);
    	int n=in.nextInt(), m=in.nextInt();
    	graph = new List[n];
    	for(int i=0; i<n; ++i)
    		graph[i] = new ArrayList<Integer>();
    	colors = new int[n];
    	Arrays.fill(colors, -1);
    	for(int i=0; i<m; ++i) {
    		int u=in.nextInt()-1, v=in.nextInt()-1;
    		graph[u].add(v);
    		graph[v].add(u);
    	}
    	for(int i=0; i<n; ++i) {
    		if(colors[i]==-1) {
    			if(dfs(i, 0)) {
    				System.out.println(-1);
    				return;
    			}
    		}
    	}
    	List<Integer> color0s = new ArrayList<Integer>();
    	List<Integer> color1s = new ArrayList<Integer>();
    	for(int i=0; i<n; ++i)
    		if(colors[i]==0)
    			color0s.add(i);
    		else
    			color1s.add(i);
    	System.out.println(color0s.size());
    	for(int node : color0s)
    		System.out.print((node+1)+" ");
    	System.out.println("\n"+color1s.size());
    	for(int node : color1s)
    		System.out.print((node+1)+" ");
    }
    
    static boolean dfs(int node, int color) {
    	colors[node]=color;
    	for(int neighbor : graph[node]) {
    		if(colors[neighbor]==color)
    			return true;
    		if(colors[neighbor]==-1)
    			if(dfs(neighbor, (color+1)%2))
    				return true;
    	}
    	return false;
    }
}