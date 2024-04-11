import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.*;
import java.io.*;

public class treecutting {
	public static void main(String [] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n= Integer.parseInt(st.nextToken());
		ArrayList<Integer>[] adj = new ArrayList[n];
		for(int i=0;i<n;i++) {
			adj[i] = new ArrayList<Integer>();
		}
		int [] vals = new int[n];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			vals[i] = Integer.parseInt(st.nextToken());
		}
		for(int i=0;i<n-1;i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken())-1;
			int b = Integer.parseInt(st.nextToken())-1;
			adj[a].add(b);
			adj[b].add(a);
		}
		LinkedList<Integer> q = new LinkedList<Integer>();
		boolean [] visited = new boolean[n];
		int [] parent = new int[n];
		q.add(0);
		parent[0] = -1;
		while(!q.isEmpty()) {
			int x = q.pop();
			visited[x] =true;
			for(int a : adj[x]) {
				if(!visited[a]) {
					parent[a] = x;
					q.add(a);
				}
			}
		}
		int [] height = new int[n];
		q.add(0);
		while(!q.isEmpty()) {
			int x = q.pop();
			for(int a : adj[x]) {
				if(a != parent[x]) {
				height[a] = height[x]+1;
				q.add(a);
				}
			}
		}
//		for(int i=0;i<n;i++) {
//			System.out.println(height[i]);
//		}
		visited = new boolean[n];
		int [] numBlue = new int[n];
		int [] numRed = new int[n];
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>(new Comparator<Integer>(){
			public int compare(Integer o1, Integer o2) {
				return height[o2]-height[o1];
			}
		});
		for(int i=0;i<n;i++) {
			pq.add(i);
		}
		while(!pq.isEmpty()) {
			int x = pq.poll();
			if(vals[x]==1) {
				numRed[x]++;
			}
			else if(vals[x]==2){
				numBlue[x]++;
			}
			if(x!=0) {
				numRed[parent[x]]+=numRed[x];
				numBlue[parent[x]]+=numBlue[x];
			}
		}
		
//		for(int i=0;i<n;i++) {
//			System.out.print(parent[i] + " ");
//		}
//		System.out.println();
//		/*
//		 * for(int i=0;i<n;i++) { System.out.println(numBlue[i] + " " + numRed[i]); }
//		 */
		int totBlue = numBlue[0];
		int totRed = numRed[0];
		int count =0;
		for(int i=0;i<n;i++) {
			for(int j : adj[i]) {
				if(parent[j]==i) {
					int a = numBlue[j];
					int b = numRed[j];
					int c =totBlue-a;
					int d = totRed-b;
					if(a> 0 && b>0) {
						continue;
						
					}
					if(c>0 && d>0) {
						continue;
					}
					count++;
				}
			}
		}
		System.out.println(count);
	}
	

		
	}