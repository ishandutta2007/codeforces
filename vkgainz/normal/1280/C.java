import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class jeremybearimy {
	static ArrayList<Node>[] adj;
	static int [] subsize;
	static int [] depth;
	public static void main(String[] args) throws IOException{
		MyScanner sc = new MyScanner();
		StringBuilder sb = new StringBuilder();
		int t = sc.nextInt();
		for(int i=0;i<t;i++) {
			int k = sc.nextInt();
			
			adj = new ArrayList[2*k+1];
			for(int j=0;j<=2*k;j++) {
				adj[j] = new ArrayList<Node>();
			}
			for(int j=0;j<2*k-1;j++) {
				int a = sc.nextInt();
				int b = sc.nextInt();
				int c = sc.nextInt();
				adj[a].add(new Node(b,c));
				adj[b].add(new Node(a,c));
			}
			subsize = new int[2*k+1];
			depth = new int[2*k+1];
			long x = 0;
			long y = 0;
			dfs(1,0);
			for(int j=1;j<=2*k;j++) {
				for(Node next : adj[j]) {
					int child = next.dest;
					if(depth[next.dest]<depth[j]) {
						continue;
					}
					
					if(subsize[child]%2!=0) {
						x+=(long)next.cost;
					}
					y+=(long)next.cost*Math.min(subsize[child],2*k-subsize[child]);
				}
			}
			sb.append(x + " " + y + " ");
		}
		System.out.println(sb.toString());
	}
	static void dfs(int curr,int parent) {
		depth[curr] = depth[parent]+1;
		subsize[curr]++;
		for(Node next : adj[curr]) {
			if(next.dest!=parent) {
				dfs(next.dest,curr);
			}
		}
		for(Node next : adj[curr]) {
			if(next.dest!=parent) {
				subsize[curr]+=subsize[next.dest];
			}
		}
	}
	static class Node{
		int dest;
		int cost;
		public Node(int d,int c) {
			dest = d;
			cost =c;
		}
	}
	 static class MyScanner
	   {
	      BufferedReader br;
	      StringTokenizer st;
	 
	      public MyScanner() {
	         br = new BufferedReader(new InputStreamReader(System.in));
	      }
	 
	      String next() {
	          while (st == null || !st.hasMoreElements()) {
	              try {
	                  st = new StringTokenizer(br.readLine());
	              } catch (IOException e) {
	                  e.printStackTrace();
	              }
	          }
	          return st.nextToken();
	      }
	 
	      int nextInt() {
	          return Integer.parseInt(next());
	      }
	 
	      long nextLong() {
	          return Long.parseLong(next());
	      }
	 
	      double nextDouble() {
	          return Double.parseDouble(next());
	      }
	 
	      String nextLine(){
	          String str = "";
		  try {
		     str = br.readLine();
		  } catch (IOException e) {
		     e.printStackTrace();
		  }
		  return str;
	      }
	      
	      

	   }
}