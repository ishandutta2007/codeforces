//package round93;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.TreeSet;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "BBWWRRYY\r\n" + 
			"\r\n" + 
			"WRRYYBBW\r\n" + 
			"\r\n" + 
			"WYBBWWRW\r\n" + 
			"\r\n" + 
			"BYWRRYRY\r\n" + 
			"\r\n" + 
			"BRWBBYBY\r\n" + 
			"\r\n" + 
			"WRYYWWBR\r\n" + 
			"\r\n" + 
			"WBBRRYYR\r\n" + 
			"\r\n" + 
			"0 0 0 7\r\n" + 
			"\r\n" + 
			"0 0 7\r\n" + 
			"\r\n" + 
			"0 7\r\n" + 
			"\r\n" + 
			"7";
	
	void solve()
	{
		b = new char[7][8];
		for(int i = 0;i < 7;i++){
			b[i] = ns(8);
		}
		int[] co = new int[10];
		for(int i = 0;i < 10;i++)co[i] = ni();
		
		String[] PILL = {
				"BY","BW","BR","BB",
				"RY","RW","RR",
				"WY","WW",
				"YY"	
		};
		int[][] ctp = new int[10][26];
		for(int i = 0;i < 10;i++){
			for(int j = 0;j < 2;j++){
				ctp[i][PILL[i].charAt(j)-'A']++;
			}
		}
		
		int[][] C = new int[10][10];
		for(int i = 0;i < 10;i++){
			for(int j = 0;j < 10;j++){
				int tot = 0;
				for(int k = 0;k < 26;k++){
					tot += Math.min(ctp[i][k], ctp[j][k]);
				}
				C[i][j] = tot;
			}
		}
		
		map = new int[26*26];
		for(int i = 0;i < 10;i++){
			int f = PILL[i].charAt(0)-'A';
			int l = PILL[i].charAt(1)-'A';
			map[f*26+l] = i;
			map[l*26+f] = i;
		}
		used = new boolean[7][8];
		ct = new int[10];
		hist = new int[28];
		ctmap = new HashMap<Integer, Datum>();
		step = 0;
		
		rec(0, 0);
		
		int m = 10+100+10;
		int[] from = new int[m];
		int[] to = new int[m];
		int[] c = new int[m];
		int[] cap = new int[m];
		int O = 0;
		for(int i = 0;i < 10;i++){
			from[i+O] = 20; to[i+O] = i; c[i+O] = 0; cap[i+O] = 0; // Datum
		}
		O += 10;
		for(int i = 0;i < 10;i++){
			from[i+O] = i+10; to[i+O] = 21; c[i+O] = 0; cap[i+O] = co[i];
		}
		O += 10;
		for(int i = 0;i < 100;i++){
			from[i+O] = i/10; to[i+O] = i%10+10; c[i+O] = 2-C[i/10][i%10]; cap[i+O] = 999;
		}
		
		int[][][] cost = packWD(22, from, to, c);
		int[][][] capacity = packWD(22, from, to, cap);
		
		// unweighted invgraph
		// curi=nextcurnext
		int n = 22;
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
		
		int mincost = 999;
		int[] opthist = null;
		int[][] optF = new int[10][10];
		for(Datum d : ctmap.values()){
			for(int i = 0;i < 10;i++){
				capacity[20][9-i][1] = d.ct[i];
			}
			int mc = solveMinCostFlow(cost, capacity, ig, 20, 21, 28);
			if(mc < mincost){
				mincost = mc;
				opthist = d.hist;
				for(int i = 0;i < 10;i++){
					for(int j = 0;j < 10;j++){
						optF[i][j] = F[i][9-j][1];
					}
				}
			}
		}
//		tr(mincost);
//		tr(opthist);
//		
//		int S = 0;
//		for(int i = 0;i < 10;i++){
//			for(int j = 0;j < 10;j++){
//				S += optF[i][j];
//			}
//		}
//		if(S != 28)throw new AssertionError(S);
		
		out.println(56-mincost);
		
		char[][] ret = new char[13][15];
		for(int i = 0;i < 13;i++){
			Arrays.fill(ret[i], '.');
		}
		
		for(int h : opthist){
			if(h < 64){
				// |
				int rr = h/8, cc = h%8;
				ret[rr*2+1][cc*2] = '|';
				
				int k = map[(b[rr][cc]-'A')*26+(b[rr+1][cc]-'A')];
				for(int i = 0;i < 10;i++){
					if(optF[k][i] > 0){
						if(flip(b[rr][cc], b[rr+1][cc], PILL[i].charAt(0), PILL[i].charAt(1))){
							ret[rr*2][cc*2] = PILL[i].charAt(1);
							ret[rr*2+2][cc*2] = PILL[i].charAt(0);
						}else{
							ret[rr*2][cc*2] = PILL[i].charAt(0);
							ret[rr*2+2][cc*2] = PILL[i].charAt(1);
						}
						optF[k][i]--;
						break;
					}
				}
			}else{
				h -= 64;
				// -
				int rr = h/8, cc = h%8;
				ret[rr*2][cc*2+1] = '-';
				
				int k = map[(b[rr][cc]-'A')*26+(b[rr][cc+1]-'A')];

				for(int i = 0;i < 10;i++){
					if(optF[k][i] > 0){
						if(flip(b[rr][cc], b[rr][cc+1], PILL[i].charAt(0), PILL[i].charAt(1))){
							ret[rr*2][cc*2] = PILL[i].charAt(1);
							ret[rr*2][cc*2+2] = PILL[i].charAt(0);
						}else{
							ret[rr*2][cc*2] = PILL[i].charAt(0);
							ret[rr*2][cc*2+2] = PILL[i].charAt(1);
						}
						optF[k][i]--;
						break;
					}
				}
			}
		}
		
		for(int i = 0;i < 13;i++){
			out.println(new String(ret[i]));
		}
	}
	
	static boolean flip(char a, char b, char c, char d)
	{
		int d1 = (a==c?1:0) + (b==d?1:0);
		int d2 = (a==d?1:0) + (b==c?1:0);
		return d2 > d1;
	}
	
	public static int[][][] packWD(int n, int[] from, int[] to, int[] w)
	{
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int f : from)p[f]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]][2];
		for(int i = 0;i < from.length;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
		}
		return g;
	}
	
	int[][][] F;
	
	public int solveMinCostFlow(int[][][] cost, int[][][] capacity, int[][][] ig, int src, int sink, int all)
	{
		int n = cost.length;
		
		int[][][] flow = new int[n][][];
		for(int i = 0;i < n;i++) {
			flow[i] = new int[cost[i].length][2];
			for(int j = 0;j < cost[i].length;j++){
				flow[i][j][0] = cost[i][j][0];
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
		F = flow;
		return mincost;
	}
	
	static class Datum
	{
		public int[] ct;
		public int[] hist;
	}
	
	boolean[][] used;
	int[] ct;
	int[] hist;
	Map<Integer, Datum> ctmap;
	int[] map;
	char[][] b;
	int step;
	
	void rec(int r, int c)
	{
		if(r >= 7){
			int h = Arrays.hashCode(ct);
			if(!ctmap.containsKey(h)){
				Datum d = new Datum();
				d.ct = Arrays.copyOf(ct, 10);
				d.hist = Arrays.copyOf(hist, 28);
				ctmap.put(h, d);
			}
			return;
		}
		if(c >= 8){
			rec(r+1, 0);
			return;
		}
		if(used[r][c]){
			rec(r, c+1);
			return;
		}
		if(r+1 < 7 && !used[r+1][c]){
			used[r][c] = true;
			used[r+1][c] = true;
			int kind = map[(b[r][c]-'A')*26+(b[r+1][c]-'A')];
			ct[kind]++;
			hist[step] = r*8+c;
			step++;
			rec(r, c+1);
			step--;
			ct[kind]--;
			used[r][c] = false;
			used[r+1][c] = false;
		}
		if(c+1 < 8 && !used[r][c+1]){
			used[r][c] = true;
			used[r][c+1] = true;
			int kind = map[(b[r][c]-'A')*26+(b[r][c+1]-'A')];
			ct[kind]++;
			hist[step] = r*8+c+64;
			step++;
			rec(r, c+2);
			step--;
			ct[kind]--;
			used[r][c] = false;
			used[r][c+1] = false;
		}
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