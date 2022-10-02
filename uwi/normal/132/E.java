//package round96;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.TreeSet;

public class E {
	InputStream is;
	PrintWriter out;
//	String INPUT = "7 2 1 2 2 4 2 1 2";
//	String INPUT = "6 3 1 2 3 1 2 3";
	String INPUT = "";
	
	public static int[] shrinkX(int[] a)
	{
		int n = a.length;
		long[] b = new long[n];
		for(int i = 0;i < n;i++)b[i] = (long)a[i]<<32|i;
		Arrays.sort(b);
		int[] ret = new int[n];
		int p = 0;
		ret[0] = (int)(b[0]>>32);
		for(int i = 0;i < n;i++) {
			if(i>0 && (b[i]^b[i-1])>>32!=0) {
				p++;
				ret[p] = (int)(b[i]>>32);
			}
			a[(int)b[i]] = p;
		}
		return Arrays.copyOf(ret, p+1);
	}
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		int[] imap = shrinkX(a);
		int sup = imap.length;
		
		int u = n+n-1;
		int[] from = new int[u];
		int[] to = new int[u];
		int[] cap = new int[u];
		int[] co = new int[u];
		int p = 0;
		for(int i = 0;i < n-1;i++){
			from[p] = i;
			to[p] = i+1;
			cap[p] = m-1;
			co[p] = 32;
			p++;
		}
		
		int[] prev = new int[sup];
		Arrays.fill(prev, -1);
		for(int i = 0;i < n;i++){
			if(prev[a[i]] != -1 && prev[a[i]]+1 < i){
				from[p] = prev[a[i]]+1;
				to[p] = i;
				cap[p] = 1;
				co[p] = (to[p]-from[p])*32-Integer.bitCount(imap[a[i]]);
				p++;
			}
			prev[a[i]] = i;
		}
//		tr(from);
//		tr(to);
//		tr(co);
		
		int[][][] capacity = packWD(n, from, to, cap, p);
		int[][][] cost = packWD(n, from, to, co, p);
		int icost = solveMinCostFlow(cost, capacity, 0, n-1, m-1);
//		out.println(icost);
//		tr(F);
		
		int[] q = new int[n];
		for(int i = 0;i < n-1;i++){
			q[i]++;
		}
		
		Arrays.fill(prev, -1);
		int[][] range = new int[n][2];
		for(int i = 0;i < n;i++){
			range[i][0] = i;
			if(i < n-1 && q[i+1] < F[i+1].length && F[i+1][q[i+1]][1] == 1){
				range[i][1] = F[i+1][q[i+1]][0]; // chigau
			}else{
				range[i][1] = i+1;
			}
		}
		
		int[] dead = new int[m];
		int[] ar = new int[m];
		Arrays.fill(ar, -1);
		Arrays.fill(dead, -1);
		StringBuilder sb = new StringBuilder();
		int item = 0, sub = 0;
		for(int i = 0;i < n;i++){
			int minj = -1;
			for(int j = 0;j < m;j++){
				if(ar[j] == a[i]){
					minj = j;
				}
			}
			if(minj == -1){
				int min = 9999999;
				for(int j = 0;j < m;j++){
					if(dead[j] < min){
						min = dead[j];
						minj = j;
					}
				}
				sb.append((char)('a'+minj) + "=" + imap[a[i]] + "\n");
				item++;
				sub+=Integer.bitCount(imap[a[i]]);
//				out.println((char)('a'+minj) + "=" + imap[a[i]]);
			}
			dead[minj] = range[i][1];
			ar[minj] = a[i];
			
//			out.println("print(" + (char)('a'+minj) + ")");
			sb.append("print(" + (char)('a'+minj) + ")\n");
			item++;
		}
		
		out.println(item + " " + sub);
		out.println(sb);
	}
	
	public static int[][][] packWD(int n, int[] from, int[] to, int[] w, int sup)
	{
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]][2];
		for(int i = 0;i < sup;i++){
			--p[from[i]];
			g[from[i]][g[from[i]].length-1-p[from[i]]][0] = to[i];
			g[from[i]][g[from[i]].length-1-p[from[i]]][1] = w[i];
		}
		return g;
	}
	
	static int[][][] F;
	
	public static int solveMinCostFlow(int[][][] cost, int[][][] capacity, int src, int sink, int all)
	{
		int n = cost.length;
		
		int[][][] flow = new int[n][][];
		for(int i = 0;i < n;i++) {
			flow[i] = new int[cost[i].length][2];
			for(int j = 0;j < cost[i].length;j++){
				flow[i][j][0] = cost[i][j][0];
			}
		}
		F = flow;
		
		// unweighted invgraph
		// curi=nextcurnext
		int[][][] ig = new int[n][][];
		{
			int[] p = new int[n];
			for(int i = 0;i < n;i++){
				for(int j = 0;j < cost[i].length;j++)p[cost[i][j][0]]++;
			}
			for(int i = 0;i < n;i++)ig[i] = new int[p[i]][2];
			for(int i = n-1;i >= 0;i--){
				for(int j = 0;j < cost[i].length;j++){
					int u = --p[cost[i][j][0]];
					ig[cost[i][j][0]][u][0] = i;
					ig[cost[i][j][0]][u][1] = j;
				}
			}
		}
		
		int mincost = 0;
		int[] pot = new int[n]; // 
		
		final int[] d = new int[n];
		TreeSet<Integer> q = new TreeSet<Integer>(new Comparator<Integer>(){
			public int compare(Integer a, Integer b)
			{
				if(d[a] - d[b] != 0)return d[a] - d[b];
				return a - b;
			}
		});
		while(all > 0){
			// src~sink
			int[] prev = new int[n];
			int[] myind = new int[n];
			Arrays.fill(prev, -1);
			Arrays.fill(d, Integer.MAX_VALUE / 2);
			d[src] = 0;
			q.clear();
			q.add(src);
			while(!q.isEmpty()){
				int cur = q.pollFirst();
				if(cur == sink)break;
				for(int i = 0;i < cost[cur].length;i++) {
					int next = cost[cur][i][0];
					if(capacity[cur][i][1] - flow[cur][i][1] > 0){
						int nd = d[cur] + cost[cur][i][1] + pot[cur] - pot[next];
						if(d[next] > nd){
							q.remove(next);
							d[next] = nd;
							prev[next] = cur;
							myind[next] = i;
							q.add(next);
						}
					}
				}
				for(int i = 0;i < ig[cur].length;i++) {
					int next = ig[cur][i][0];
					int cind = ig[cur][i][1];
					if(flow[next][cind][1] > 0){
						int nd = d[cur] - cost[next][cind][1] + pot[cur] - pot[next];
						if(d[next] > nd){
							q.remove(next);
							d[next] = nd;
							prev[next] = cur;
							myind[next] = -cind-1;
							q.add(next);
						}
					}
				}
			}
			
			if(prev[sink] == -1)break;
			
			int minflow = all;
			int sumcost = 0;
			for(int i = sink;i != src;i = prev[i]){
				if(myind[i] >= 0){
					minflow = Math.min(minflow, capacity[prev[i]][myind[i]][1] - flow[prev[i]][myind[i]][1]);
					sumcost += cost[prev[i]][myind[i]][1];
				}else{
					// cur->next
					// prev[i]->i
					// i
					// ig[cur][j][0]=nextg[next][ig[cur][j][1]] = cur
					int ind = -myind[i]-1;
//					tr(prev[i], ind);
					minflow = Math.min(minflow, flow[i][ind][1]);
					sumcost -= cost[i][ind][1];
				}
			}
			
			mincost += minflow * sumcost;
			for(int i = sink;i != src;i = prev[i]){
				if(myind[i] >= 0){
					flow[prev[i]][myind[i]][1] += minflow;
				}else{
					int ind = -myind[i]-1;
					flow[i][ind][1] -= minflow;
				}
			}
//			tr(flow);
			
			all -= minflow;
			for(int i = 0;i < n;i++){
				pot[i] += d[i];
			}
		}
		return mincost;
	}
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new E().run();
	}
	
	public int ni()
	{
		try {
			int num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public long nl()
	{
		try {
			long num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public String ns()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n' || b == ' '));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n' || b == ' ')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
	}
	
	public char[] ns(int n)
	{
		char[] buf = new char[n];
		try{
			int b = 0, p = 0;
			while((b = is.read()) != -1 && (b == ' ' || b == '\r' || b == '\n'));
			if(b == -1)return null;
			buf[p++] = (char)b;
			while(p < n){
				b = is.read();
				if(b == -1 || b == ' ' || b == '\r' || b == '\n')break;
				buf[p++] = (char)b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}
	
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}