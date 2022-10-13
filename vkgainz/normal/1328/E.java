import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class treequeries {
	static ArrayList<Integer>[] tree;
	static int [] depth;
	static int [] euler;
	static int [] parent;
	static int [] start, end;
	static int n,m;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		tree = new ArrayList[n];
		for(int i=0;i<n;i++) {
			tree[i] = new ArrayList<Integer>();
		}
		for(int i=0;i<n-1;i++) {
			int a = sc.nextInt()-1; int b = sc.nextInt()-1;
			tree[a].add(b); tree[b].add(a);
		}
		depth = new int[n]; euler = new int[2*n]; parent = new int[n]; 

		Queue<Integer> q = new LinkedList<Integer>();
		depth = new int[n];
		Arrays.fill(depth,-1);
		depth[0] = 0;
		parent[0] = 0;
		q.add(0);
		while(!q.isEmpty()) {
			int x = q.poll();
			for(int y : tree[x]) {
				if(depth[y]==-1) {
					depth[y] = depth[x]+1;
					parent[y] = x;
					q.add(y);
				}
			}
		}

		euler[0] = 0;
		counter++;
		dfs(0);
		start = new int[n];
		end = new int[n];
		Arrays.fill(start,-1);
		for(int i=0;i<2*n;i++) {
			if(start[euler[i]]==-1) {
				start[euler[i]] = i;
			}
			else {
				end[euler[i]] = i;
			}
		}
		StringBuilder sb = new StringBuilder();
		for(int i=0;i<m;i++) {
			int k = sc.nextInt();
			int [] vals= new int[k];
			for(int j=0;j<k;j++) {
				
				vals[j] = parent[sc.nextInt()-1];
			}
			int comp = vals[0];
			boolean works = true;
			for(int j=1;j<k;j++) {
				if(depth[vals[j]]>depth[comp]) {
					if(isParent(comp,vals[j])) {
						comp = vals[j];
					}
					else {
						works = false;
//						System.out.println("NO");
						break;
					}
				}
				else {
					if(!isParent(vals[j],comp)) {
						works = false;
//						System.out.println("NO");
						break;
					}
				}
			}
			if(works) {
				sb.append("YES");
				sb.append("\n");
			}
			else {
				sb.append("NO");
				sb.append("\n");
			}
			
		}
		System.out.println(sb.toString());
		
	}
	static int counter =0;
	static void dfs(int root) {

		for(int next : tree[root]) {
			if(depth[next]>depth[root]) {
				euler[counter] = next;
				counter++;
				dfs(next);
			}
		}
		euler[counter] = root;
		counter++;

	}
	static boolean isParent(int i,int j) {
		return start[i]<=start[j] && end[i]>=end[j];
	}
}
class MyScanner
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