import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class decorateappletree {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader( 
                new InputStreamReader(System.in)); 
		 PrintWriter pw = new PrintWriter(new 
				 BufferedWriter(new OutputStreamWriter(System.out)));

StringTokenizer st = new StringTokenizer(br.readLine()); 
		int n= Integer.parseInt(st.nextToken());
		if(n==1) {
			pw.println(1);
			pw.close();
		}
		ArrayList<Integer>[] adj = new ArrayList[n];
		for(int i=0;i<n;i++) {
			adj[i] = new ArrayList<Integer>();
		}
		st = new StringTokenizer(br.readLine());
		for(int i=1;i<n;i++) {
			
			int a = Integer.parseInt(st.nextToken())-1;
			adj[i].add(a);
			adj[a].add(i);
			
		}
		int [] height = new int[n];
		int [] parent = new int[n];
		Arrays.fill(height,-1);
		Arrays.fill(parent,-1);
		height[0] = 0;
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(0);
		while(!q.isEmpty()) {
			int k = q.poll();
			for(int x : adj[k]) {
				if(x != parent[k]) {
					height[x] = height[k]+1;
					q.add(x);
					parent[x] = k;
				}
			}
		}
		
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>(new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				// TODO Auto-generated method stub
				return height[o2]-height[o1];
			}
			
		});
		int [] num = new int[n];
		pq.add(0);
		for(int i=1;i<n;i++) {
			pq.add(i);
			if(adj[i].size()==1) {
				num[i] = 1;
			}
		}
		while(!pq.isEmpty()) {
			int x = pq.poll();
			if(x==0) {
				break;
			}
			num[parent[x]]+=num[x];
		}
		
		Arrays.sort(num);
		for(int i=0;i<n;i++) {
			pw.println(num[i]);
		}
		pw.close();
		
		
	}
}