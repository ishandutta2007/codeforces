
import java.util.ArrayList;
import java.util.Scanner;

public class edgeweightassignment {
	static int [] depth;
	static ArrayList<Integer>[] edge;
	static ArrayList<Integer> leaves;
	static boolean odd;
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		int n= sc.nextInt();
		edge = new ArrayList[n];
		for(int i=0;i<n;i++) {
			edge[i] = new ArrayList<Integer>();
		}
		for(int i=0;i<n-1;i++) {
			int a = sc.nextInt()-1; int b = sc.nextInt()-1;
			edge[b].add(a); edge[a].add(b);
		}
		depth = new int[n];
		depth[0] = 1;
		dfs(0,-1);
//		for(int i=0;i<n;i++) {
//			System.out.println(depth[i]);
//		}
		leaves = new ArrayList<Integer>();
		for(int i=0;i<n;i++) {
			if(edge[i].size()==1) {
				leaves.add(i);
			}
		}
		findOdd();
		int numTwo = 0;
		for(int i=0;i<n;i++) {
			int temp = 0;
			for(int j : edge[i]) {
				
				if(edge[j].size()==1) {
					temp++;
				}
			}
			numTwo+=Math.max(0,temp-1);
		}
		int lowerBound = 0;
		int upperBound =0;
		if(odd) {
			lowerBound = 3;
		}
		else {
			lowerBound = 1;
		}
		upperBound = n-1-numTwo;
		System.out.println(lowerBound + " " + upperBound);
	}
	static void dfs(int curr,int parent) {
		for(int x : edge[curr]) {
			if(x==parent) {
				continue;
			}
			depth[x] = depth[curr]+1;
			dfs(x,curr);
		}
	}
	static void findOdd() {
		int numOdd =0;
		int numEven = 0;
		for(int leaf : leaves) {
			if(depth[leaf]%2==0) {
				numEven++;
			}
			else {
				numOdd++;
			}
		}
		if(numEven >=1 && numOdd>=1) {
			odd = true;
		}
		else {
			odd = false;
		}
	}
}