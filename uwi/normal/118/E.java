//package round89;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Comparator;
import java.util.Queue;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
//	String INPUT = "6 8\r\n" + 
//			"1 2\r\n" + 
//			"2 3\r\n" + 
//			"1 3\r\n" + 
//			"4 5\r\n" + 
//			"4 6\r\n" + 
//			"5 6\r\n" + 
//			"2 4\r\n" + 
//			"3 5";
//	String INPUT = "6 7\r\n" + 
//			"1 2\r\n" + 
//			"2 3\r\n" + 
//			"1 3\r\n" + 
//			"4 5\r\n" + 
//			"4 6\r\n" + 
//			"5 6\r\n" + 
//			"2 4";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni() - 1;
			to[i] = ni() - 1;
		}
		int[][][] g = packWU(n, from, to, new int[m]);
		for(int i = 0;i < g.length;i++){
			if(g[i].length < 2){
				out.println(0);
				return;
			}
			Arrays.sort(g[i], new Comparator<int[]>(){
				public int compare(int[] a, int[] b){
					return a[0] - b[0];
				}
			});
		}
		
		int[] loop = findLoop(g, 0);
		int cycle = loop.length;
		
		BitSet ved = new BitSet();
		
		for(int i = 0;i < cycle;i++){
			nya.append(loop[i]+1);
			nya.append(' ');
			nya.append(loop[(i+1)%cycle]+1);
			nya.append('\n');
//			out.printf("%d %d\n", loop[i]+1, loop[(i+1)%cycle]+1);
			for(int j = 0;j < g[loop[i]].length;j++){
				if(g[loop[i]][j][0] == loop[(i+1)%cycle]){
					g[loop[i]][j][1] = 1;
				}
				if(g[loop[i]][j][0] == loop[(i+cycle-1)%cycle]){
					g[loop[i]][j][1] = -1;
				}
			}
//			toto[loop[i]] = new int[]{loop[(i+1)%cycle], loop[(i+cycle-1)%cycle]};
			ved.set(loop[i]);
		}
//		tr(loop);
		
		for(int l : loop){
			rec(l, g, -1);
		}
		if(isSource(g, 0, 1) && isSource(g, 0, -1)){
			out.print(nya);
		}else{
			out.println(0);
		}
	}
	
	public int[] findLoop(int[][][] g, int s)
	{
		int n = g.length;
		int[] hist = new int[n];
		int[] ind = new int[n];
		int[] ihist = new int[n];
		Arrays.fill(ihist, -1);
		
		hist[0] = s;
		ihist[s] = 0;
		int p = 0;
		while(p >= 0){
			if(ind[p] < g[hist[p]].length){
				int nex = g[hist[p]][ind[p]][0];
				if(ihist[nex] >= 0){
					if(ihist[nex] == p-1){
						ind[p]++;
						continue;
					}
					return Arrays.copyOfRange(hist, ihist[nex], p+1);
				}
				hist[p+1] = nex;
				ihist[nex] = p+1;
				p++;
			}else{
				ihist[hist[p]] = -1;
				p--;
				if(p>=0)ind[p]++;
			}
		}
		return null;
	}
	
	public boolean isSource(int[][][] g, int s, int r)
	{
		int n = g.length;
		BitSet ved = new BitSet();
		Queue<Integer> q = new ArrayDeque<Integer>();
		q.add(s);
		ved.set(s);
		while(q.size() > 0){
			int cur = q.poll();
			for(int[] e : g[cur]){
				if(e[1] == r && !ved.get(e[0])){
					ved.set(e[0]);
					q.add(e[0]);
				}
			}
		}
		return ved.cardinality() == n;
	}
	
	BitSet gved = new BitSet();
	StringBuilder nya = new StringBuilder();
	
	void rec(int pos, int[][][] g, int prev)
	{
		if(gved.get(pos))return;
		gved.set(pos);
		for(int i = 0;i < g[pos].length;i++){
			int[] e = g[pos][i];
			if(e[0] != prev && e[1] == 0){
				g[pos][i][1] = 1;
				int low = 0;
				int high = g[e[0]].length;
				while(high - low > 1){
					int mid = (high + low) / 2;
					if(g[e[0]][mid][0] == pos){
						low = mid;
						break;
					}
					if(g[e[0]][mid][0] < pos){
						low = mid;
					}else{
						high = mid;
					}
				}
				g[e[0]][low][1] = -1;
				nya.append(pos+1);
				nya.append(' ');
				nya.append(e[0]+1);
				nya.append('\n');
				rec(e[0], g, pos);
//				tr(pos, toto[e], e, ret);
			}
		}
	}
	
	public static int[][][] packWU(int n, int[] from, int[] to, int[] w)
	{
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int f : from)p[f]++;
		for(int t : to)p[t]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]][2];
		for(int i = 0;i < from.length;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
			--p[to[i]];
			g[to[i]][p[to[i]]][0] = from[i];
			g[to[i]][p[to[i]]][1] = w[i];
		}
		return g;
	}
	
	void run() throws Exception
	{
//		int n = 100000;
//		StringBuilder sb = new StringBuilder(n + " " + n*3 + " ");
//		for(int i = 0;i < n;i++){
//			sb.append((i+1) + " " + ((i+1)%n+1) + " ");
//			sb.append((i+1) + " " + ((i+2)%n+1) + " ");
//			sb.append((i+1) + " " + ((i+3)%n+1) + " ");
//		}
//		INPUT = sb.toString();
		
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new E2().run();
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
	
	public String nline()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n'));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
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
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}