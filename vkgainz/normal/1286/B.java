import java.util.ArrayList;
import java.util.Scanner;

public class numbersonatree {
	static ArrayList<Integer> set ;
	static ArrayList<Integer>[] tree;
	static int n;
	static int [] c, ret;
	static int [] subsize = new int[n];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		 n = sc.nextInt();
		tree =new ArrayList[n];
		for(int i=0;i<n;i++) {
			tree[i] = new ArrayList<Integer>();
		}
		int root = -1;
		c = new int[n];
		for(int i=0;i<n;i++) {
			int a = sc.nextInt()-1;
			int b = sc.nextInt();
			c[i] = b;
			if(a==-1) {
				root = i;
			}
			else {
				tree[a].add(i);
				tree[i].add(a);
			}
			
		}
		set =new ArrayList<Integer>();
		for(int i=1;i<=n;i++) {
			set.add(i);
		}
		ret = new int[n];
		subsize = new int[n];
		subsize(root,-1);
		
		for(int i=0;i<n;i++) {

			if(c[i]>=subsize[i]) {
				fail = true;
			}
		}
		if(fail) {
			System.out.println("NO");
			return;
		}
		dfs(root,-1);
		StringBuilder sb = new StringBuilder();
		for(int i=0;i<n;i++) {
			sb.append(ret[i] + " ");
		}
		System.out.println("YES");
		System.out.println(sb.toString());
	}
	static boolean fail;
	static void subsize(int curr,int parent) {
		subsize[curr] = 1;
		for(int next : tree[curr]) {
			if(next!=parent) {
				subsize(next,curr);
			}
		}
		for(int next : tree[curr]) {
			if(next!=parent) {
				subsize[curr]+=subsize[next];
			}
		}
	}
	static void dfs(int curr,int parent) {
//		System.out.println(curr + "  " + parent + " " + c[curr]);
		int add = c[curr];
//		if(c[curr]>=set.size()) {
//			System.out.println("NO");
//			fail = true;
//			return;
//		}
		ret[curr] = set.get(add);
		set.remove(add);
		for(int next : tree[curr]) {
			if(next!=parent) {
				dfs(next,curr);
			}
		}
	}
}