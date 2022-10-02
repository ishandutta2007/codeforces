//package yandex2011.r1;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] val = new int[n];
		int root = -1;
		int[] l = new int[n];
		int[] r = new int[n];
		int[] par = new int[n];
		Arrays.fill(l, -1);
		Arrays.fill(r, -1);
		for(int i = 0;i < n;i++){
			par[i] = ni() - 1;
			int v = ni();
			val[i] = v;
			if(par[i] <= -1){
				root = i;
			}
		}
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				if(val[par[i]] < val[i]){
					r[par[i]] = i;
				}else{
					l[par[i]] = i;
				}
			}
		}
		if(root == -1){
			out.println("ya");
			return;
		}
		
		int[] ord = new int[n];
		ord[0] = root;
		int pp = 1;
		for(int i = 0;i < n;i++){
			if(l[ord[i]] != -1){
				ord[pp] = l[ord[i]];
				pp++;
				ord[pp] = r[ord[i]];
				pp++;
			}
		}
//		if(!(n == 7 || n == 3)){
//			out.println("AAA");
//			return;
//		}
		
		int[] min = new int[n];
		int[] max = new int[n];
		for(int i = n-1;i >= 0;i--){
			if(l[ord[i]] == -1){
				min[ord[i]] = val[ord[i]];
				max[ord[i]] = val[ord[i]];
			}else{
				min[ord[i]] = min[l[ord[i]]];
				max[ord[i]] = max[r[ord[i]]];
			}
		}
		
		int[] low = new int[n];
//		int[] high = new int[n];
		int leaf = 0;
		Arrays.fill(low, -2);
//		Arrays.fill(high, 1000000002);
		for(int i = 0;i < n;i++){
			if(l[ord[i]] != -1){
//				low[r[ord[i]]] = high[l[ord[i]]] = val[ord[i]];
				low[r[ord[i]]] = val[ord[i]];
				low[l[ord[i]]] = low[ord[i]];
//				high[r[ord[i]]] = high[ord[i]];
			}else{
				leaf++;
			}
		}
		
		long[] S = new long[n];
		int[] D = new int[n];
		for(int i = 1;i < n;i++){
			D[ord[i]] = D[par[ord[i]]] + 1;
			if(l[par[ord[i]]] == ord[i]){
				S[ord[i]] = S[par[ord[i]]] + min[r[par[ord[i]]]];
			}else{
				S[ord[i]] = S[par[ord[i]]] + max[l[par[ord[i]]]];
			}
		}
//		tr(S);
//		tr(D);
//		tr(E);
		if(leaf == 0){
			out.println("");
			return;
		}
		
		Datum[] ds = new Datum[leaf];
		int q = 0;
		for(int i = 1;i < n;i++){
			if(l[ord[i]] == -1){
				if(D[ord[i]] != 0){
					ds[q++] = new Datum((double)S[ord[i]] / D[ord[i]], low[ord[i]]);
				}
			}
		}
		for(int i = q;i < leaf;i++){
			ds[i] = new Datum(-9999,-9999);
		}
		
		Arrays.sort(ds);
//		tr(low);
//		tr(high);
		
		int m = ni();
		Datum key = new Datum(0, 0);
//		tr(ds);
		for(int i = 0;i < m;i++){
			key.low = ni();
			int ind = Arrays.binarySearch(ds, key);
			if(ind < 0){
				ind = -ind - 2;
			}
			if(ind < 0)continue;
//			tr(ind);
			out.printf("%1.9f\n", ds[ind].e);
		}
	}
	
	static class Datum implements Comparable<Datum> {
		public double e;
		public int low;

		public Datum(double e, int low) {
			this.e = e;
			this.low = low;
		}

		public int compareTo(Datum o) {
			return low - o.low;
		}

		public String toString() {
			return "(" + e + "," + low + ")";
		}
	}
	
	void run() throws Exception
	{
//		int n = 65535;
//		StringBuilder sb = new StringBuilder(n + " ");
//		int[] x = new int[n];
//		int[] d = new int[n];
//		for(int i = 0;i < n;i++){
//			int p = i == 0 ? -1 : (i+1)/2;
//			if(p == -1){
//				sb.append(p + " " + (1<<22) + " ");
//				x[i] = 1<<22;
//				d[i] = 22;
//			}else{
//				if(i % 2 == 1){
//					d[i] = d[p-1] - 1;
//					x[i] = x[p-1] - (1<<d[i]);
//				}else{
//					d[i] = d[p-1] - 1;
//					x[i] = x[p-1] + (1<<d[i]);
//				}
//				sb.append(p + " " + x[i] + " ");
//			}
//		}
//		sb.append(1000 + " ");
//		Random r = new Random();
//		for(int i = 0;i < 1000;i++){
//			sb.append((r.nextInt(100000)*8+1) + " ");
//		}
//		INPUT = sb.toString();
		
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}