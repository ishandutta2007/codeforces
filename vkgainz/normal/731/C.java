import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

public class socks{
	static ArrayList<Integer> temp;
	static ArrayList<Integer>[] paths ;
	static boolean [] visited;
	static int [] sockCols;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int k = sc.nextInt();
		  sockCols = new int[n];
		for(int i=0;i<n;i++) {
			sockCols[i] = sc.nextInt()-1;
		}
		paths = new ArrayList[n];
		for(int i=0;i<n;i++) {
			paths[i] = new ArrayList<Integer>();
		}
		for(int i=0;i<m;i++) {
			int a = sc.nextInt()-1;
			int b = sc.nextInt()-1;
			paths[a].add(b);
			paths[b].add(a);
		}
		int count =0;
		 visited = new boolean[n];
		for(int i=0;i<n;i++) {
			if(visited[i]) {
				continue;
			}
			 temp = new ArrayList<Integer>();
			 dfs(i);
			 count+=temp.size();
			 count-=mostFrequent(temp,temp.size());
			
		}
		System.out.println(count);
		
		
	}
	static void dfs(int i) {
		visited[i] = true;
		temp.add(sockCols[i]);
		for(int x : paths[i]) {
			if(visited[x]) {
				continue;
			}
			dfs(x);
		}
	}
	 static int mostFrequent(ArrayList<Integer> arr, int n) 
	    { 
	          
	        // Insert all elements in hash 
	        Map<Integer, Integer> hp = 
	               new HashMap<Integer, Integer>(); 
	          
	        for(int i = 0; i < n; i++) 
	        { 
	            int key = arr.get(i);
	            if(hp.containsKey(key)) 
	            { 
	                int freq = hp.get(key); 
	                freq++; 
	                hp.put(key, freq); 
	            } 
	            else
	            { 
	                hp.put(key, 1); 
	            } 
	        } 
	          
	        // find max frequency. 
	        int max_count = 0, res = -1; 
	          
	        for(Entry<Integer, Integer> val : hp.entrySet()) 
	        { 
	            if (max_count < val.getValue()) 
	            { 
	                res = val.getKey(); 
	                max_count = val.getValue(); 
	            } 
	        } 
	          
	        return max_count; 
	    } 
}