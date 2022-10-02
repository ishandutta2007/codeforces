//package round87;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] p = new int[n];
		for(int i = 0;i < n;i++)p[i] = ni()-1;
		
		DJSet ds = new DJSet(n);
		for(int i = 0;i < n;i++){
			if(p[i] != -2){
				ds.union(i, p[i]);
			}
		}
		
		int[] imap = new int[n];
		int[] map = new int[n];
		int max = 0;
		for(int i = 0;i < n;i++){
			if(ds.upper[i] < 0){
				int z = 0;
				for(int j = 0;j < n;j++){
					if(ds.root(j) == i){
						map[z] = j;
						imap[j] = z++;
					}
				}
				
				int[] lp = new int[-ds.upper[i]];
				int root = -1;
				for(int j = 0;j < z;j++){
					lp[j] = p[map[j]] == -2 ? -1 : imap[p[map[j]]];
					if(p[map[j]] == -2)root = j;
				}
				
				int[][] ch = parentToChildren(lp);
				int[] d = new int[z];
				Queue<Integer> q = new ArrayDeque<Integer>();
				q.add(root);
				d[root] = 1;
				while(q.size() > 0){
					int cur = q.poll();
					max = Math.max(max, d[cur]);
					for(int c : ch[cur]){
						d[c] = d[cur] + 1;
						q.add(c);
					}
				}
			}
		}
		out.println(max);
	}
	
	public class DJSet { public int[] upper; public DJSet(int n){ upper = new int[n]; Arrays.fill(upper, -1);} public int root(int x){	return upper[x] < 0 ? x : (upper[x] = root(upper[x]));}	public boolean equiv(int x, int y){ return root(x) == root(y);} public void union(int x, int y){ x = root(x);y = root(y);if(x != y) { if(upper[y] < upper[x]) { int d = x; x = y; y = d;	} upper[x] += upper[y]; upper[y] = x;}} public int count(){	int ct = 0;	for(int i = 0;i < upper.length;i++){ if(upper[i] < 0)ct++; } return ct; }}
	
	public static int[][] parentToChildren(int[] parent)
	{
		int n = parent.length;
		int[] ct = new int[n];
		for(int i = 0;i < n;i++){
			if(parent[i] >= 0){
				ct[parent[i]]++;
			}
		}
		int[][] ret = new int[n][];
		for(int i = 0;i < n;i++){
			ret[i] = new int[ct[i]];
		}
		for(int i = 0;i < n;i++){
			if(parent[i] >= 0){
				ret[parent[i]][--ct[parent[i]]] = i;
			}
		}
		
		return ret;
	}
	
	void run() throws Exception
	{
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}