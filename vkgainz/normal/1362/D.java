import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class D {
	static ArrayList<Integer>[] edge;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt();
		int m = sc.nextInt();
		edge = new ArrayList[n];
		for(int i=0;i<n;i++) edge[i] = new ArrayList<>();
		
		for(int i=0;i<m;i++) {
			int a = sc.nextInt()-1;
			int b = sc.nextInt()-1;
			edge[a].add(b);
			edge[b].add(a);
		}
		int [] valDes = new int[n];
		int [] minPos = new int[n];
		for(int i=0;i<n;i++) {
			valDes[i] =sc.nextInt();
		}
		for(int i=0;i<n;i++) {
			Collections.sort(edge[i],new Comparator<Integer>() {

				@Override
				public int compare(Integer o1, Integer o2) {
					// TODO Auto-generated method stub
					return valDes[o1]-valDes[o2];
				}
				
			});
		}
		int [] p = new int[n];
		PriorityQueue<Integer> q= new PriorityQueue<Integer>(new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				// TODO Auto-generated method stub
				return valDes[o1]-valDes[o2];
			}
			
		});
		for(int i=0;i<n;i++) {
			if(valDes[i]==1) {
				q.add(i);
				minPos[i]=1;
			}
		}
		int counter = 0;
		while(!q.isEmpty()) {
			int x = q.poll();
			p[counter] = x;
			counter++;
			
			for(int y : edge[x]) {
				if(minPos[y]==0) {
					minPos[y] = valDes[y];
					q.add(y);
				}
			}
		}
		boolean work = true;
		for(int i=0;i<n;i++) {
			HashSet<Integer> set = new HashSet<Integer>();
			for(int j : edge[i]) {
				if(valDes[j]==valDes[i]) {
					work = false;
				}
				if(valDes[j]<valDes[i]) {
					set.add(valDes[j]);
				}
			}
			if(set.size()!=(valDes[i]-1)) {
				work =false;
			}
		}
		if(!work) {
			System.out.println(-1);
			return;
		}
		StringBuilder sb = new StringBuilder();
		for(int i=0;i<n;i++) {
			sb.append((p[i]+1) + " ");
		}
		
		System.out.println(sb.toString());
		
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