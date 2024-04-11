import java.util.ArrayList;
import java.util.Scanner;

public class coverit {
	static ArrayList<Integer>[] adj;
	static int [] vals;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		StringBuilder sb = new StringBuilder();
		for(int i=0;i<t;i++) {
			
			int n = sc.nextInt();
			int m = sc.nextInt();
			adj = new ArrayList[n];
			for(int j=0;j<n;j++) {
				adj[j] = new ArrayList<Integer>();
			}
			for(int j=0;j<m;j++) {
				int a = sc.nextInt()-1;
				int b = sc.nextInt()-1;
				adj[a].add(b);
				adj[b].add(a);
			}
			boolean [] visited = new boolean[n];
			vals = new int[n];
			vals[0] = 1;
			floodfill(0,visited);
			int num1 = 0;
			for(int j=0;j<n;j++) {
				if(vals[j]==1) {
					num1++;
				}
			}
			if(num1<=n/2) {
				sb.append(num1 + " ");
//				System.out.print(num1 + " " );
				for(int j=0;j<n;j++) {
					if(vals[j]==1) {
						sb.append(j+1 + " ");
//						System.out.print(j+1 + " " );
					}
					
				}
			}
			else {
//				System.out.print(n-num1 + " " );
				sb.append(n-num1 + " " );
				for(int j=0;j<n;j++) {
					if(vals[j]==2) {
//						System.out.print(j+1 + " ");
						sb.append(j+1 + " ");
					}
				}

			}

		}
		
		System.out.println(sb.toString());
	}
	private static void floodfill(int i, boolean [] visited) {
		// TODO Auto-generated method stub
		visited[i] = true;
		for(int x : adj[i]) {
			if(vals[i]==1 && !visited[x]) {
				vals[x] = 2;
				floodfill(x,visited);
			}
			else if(!visited[x]){
				vals[x]= 1;

				floodfill(x,visited);
			}
		}
	}
}