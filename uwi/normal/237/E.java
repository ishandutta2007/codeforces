//package round147;
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
	String INPUT = "";
	
	void solve()
	{
		char[] s = ns().toCharArray();
		int n = ni();
		char[][] fr = new char[n][];
		int[] lim = new int[n];
		for(int i = 0;i < n;i++){
			fr[i] = ns().toCharArray();
			lim[i] = ni();
		}
		// 0,n-1
		// n,n+25
		// n+26
		// n+27
		int src = n+26, sink = n+27;
		int m = 2*(27*n+26);
		int[] from = new int[m];
		int[] to = new int[m];
		int[] cost = new int[m];
		int[] cap = new int[m];
		int p = 0;
		for(int i = 0;i < n;i++){
			from[p] = src; to[p] = i; cost[p] = 0; cap[p] = lim[i]; p++;
			int[] ct = new int[26];
			for(char c : fr[i]){
				ct[c-'a']++;
			}
			for(int j = 0;j < 26;j++){
				if(ct[j] > 0){
					from[p] = i; to[p] = n+j; cost[p] = i+1; cap[p] = ct[j]; p++;
				}
			}
		}
		int[] ct = new int[26];
		for(char c : s){
			ct[c-'a']++;
		}
		for(int i = 0;i < 26;i++){
			from[p] = n+i; to[p] = sink; cost[p] = 0; cap[p] = ct[i]; p++;
		}
		
		int[][][] caps = packWD(n+28, from, to, cap, p);
		int[][][] costs = packWD(n+28, from, to, cost, p);
		out.println(solveMinCostFlow(costs, caps, src, sink, s.length));
	}
	
	public static int[][][] packWD(int n, int[] from, int[] to, int[] w, int sup)
	{
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]][2];
		for(int i = 0;i < sup;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
		}
		return g;
	}
	
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
		if(all > 0)return -1;
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