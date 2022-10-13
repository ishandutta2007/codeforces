import java.util.ArrayList;
import java.util.Scanner;

public class E {
	static long freq[];
	static ArrayList<Integer>[] adj;
	static int [] subtreesz;
	static int [] numEven;
	static int n;
	static int MOD = 1000000007;
	static int [] depth;
	static int even;
	public static void main(String[] args) {
		Scanner sc=  new Scanner(System.in);
		n= sc.nextInt();
		int V[]  = new int[n];
		freq = new long[n];
		for(int i=0;i<n;i++) {
			V[i] = sc.nextInt();
		}
		adj = new ArrayList[n];
		for(int i=0;i<n;i++) {
			adj[i] = new ArrayList<>();
		}
		for(int i=0;i<n-1;i++) {
			int u = sc.nextInt()-1;
			int v = sc.nextInt()-1;
			adj[u].add(v);
			adj[v].add(u);
		}
		subtreesz =new int[n];
		numEven = new int[n];
		depth = new int[n];
		dfsDepth(0,0);
		even = 0;
		for(int i=0;i<n;i++) {
			if(depth[i]%2==1) {
				even++;
			}
		}
		dfs(0,0);
		long ans =0;
		for(int i=0;i<n;i++) {
			freq[i]%=MOD;
			ans+=(long) freq[i]*V[i];
			ans%=MOD;
		}
		if(ans<0) ans+=MOD;
		
		System.out.println(ans);
	}
	static void dfsDepth(int curr,int par) {
		depth[curr] = depth[par]+1;
		for(int next : adj[curr]) {
			if(next!=par) {
				dfsDepth(next,curr);
			}
		}
	}
	static void dfs(int curr,int par) {
		subtreesz[curr]++;
		numEven[curr]++;
		for(int next : adj[curr]) {
			if(next!=par) {
				dfs(next,curr);
				numEven[curr]+=(subtreesz[next]-numEven[next]);
				subtreesz[curr]+=subtreesz[next];
			}
		}
		//inside subtree
		for(int next : adj[curr]) {
			if(next!=par) {
				freq[curr]+=(long) (subtreesz[next]-numEven[next])*(n-subtreesz[next]);
				freq[curr]-=(long) (numEven[next])*(n-subtreesz[next]);
			}
		}
		freq[curr]+=(long) (n); 
		//outside subtree
		if(depth[curr]%2==1) {
			//even from 0
			freq[curr]+=(long) (even-numEven[curr])*subtreesz[curr];
			freq[curr]-=(long) (n-even-(subtreesz[curr]-numEven[curr]))*subtreesz[curr];
		}
		else {
			freq[curr]+=(long) (n-even-numEven[curr])*subtreesz[curr];
			freq[curr]-=(long) (even-(subtreesz[curr]-numEven[curr]))*subtreesz[curr];
		}
	}
}