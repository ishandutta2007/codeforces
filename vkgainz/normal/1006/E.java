import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class E {
	static int [] subtreeSize;
	static ArrayList<Integer>[] edge;
	static int [] order;
	static int [] invOrder;
	static int counter;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int q= sc.nextInt();
		edge = new ArrayList[n];
		for(int i=0;i<n;i++) {
			edge[i] = new ArrayList<>();
		}
		
		for(int i=1;i<n;i++) {
			int a = sc.nextInt()-1;
			edge[a].add(i);
			edge[i].add(a);
		}
		for(int i=0;i<n;i++) {
			Collections.sort(edge[i]);
		}
		subtreeSize = new int[n];
		dfsSubtree(0,-1);
		counter =1;
		order = new int[n];
		invOrder = new int[n+1];
		dfsOrder(0,-1);
		for(int i=0;i<q;i++) {
			int u = sc.nextInt()-1;
//			System.out.println(order[u]);
			int k = sc.nextInt()-1;
			k+=order[u];
//			System.out.println(k);
			if(k<=n && (k-order[u]+1)<=subtreeSize[u]) {
				System.out.println(invOrder[k]+1);

			}
			else {
				System.out.println(-1);
			}
		}
	}
	static void dfsOrder(int curr,int par) {
		order[curr] = counter;
		invOrder[counter] = curr;
		counter++;
		for(int next : edge[curr]) {
			if(next!=par) {
				dfsOrder(next,curr);
			}
		}
	}
	static void dfsSubtree(int curr,int par) {
		subtreeSize[curr]++;
		for(int next : edge[curr]) {
			if(next!=par) {
				dfsSubtree(next,curr);
				subtreeSize[curr]+=subtreeSize[next];
			}
		}
	}
	
}