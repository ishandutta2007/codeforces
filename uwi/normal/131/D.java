//package round95;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Queue;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "4 1 3 3 4 4 1 4 2";
	
	void solve()
	{
		int n = ni();
		int[] f = new int[n];
		int[] t = new int[n];
		for(int i = 0;i < n;i++){
			f[i] = ni()-1;
			t[i] = ni()-1;
		}
		
		int[][] g = packU(n, f, t);
		loop = new int[n];
		hasLoop(g, new BitSet(), 0, -1);
		loop = Arrays.copyOf(loop, P);
		Queue<Integer> q = new ArrayDeque<Integer>();
		int[] d = new int[n];
		Arrays.fill(d, -1);
		for(int l : loop){
			q.add(l);
			d[l] = 0;
		}
		
		while(!q.isEmpty()){
			int cur = q.poll();
			for(int e : g[cur]){
				if(d[e] == -1){
					q.add(e);
					d[e] = d[cur] + 1;
				}
			}
		}
		
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i < n;i++){
			sb.append(" " + d[i]);
		}
		out.println(sb.substring(1));
	}
	
	int[] loop;
	int base = -1;
	int P = 0;
	boolean nya = true;
	
	public boolean hasLoop(int[][] g, BitSet visited, int cur, int prev)
	{
		visited.set(cur);
		for(int e : g[cur]){
			if(e == prev)continue;
			if(visited.get(e)){
				base = e;
				loop[P++] = cur;
				return true;
			}else{
				if(hasLoop(g, visited, e, cur)){
					if(nya){
						loop[P++] = cur;
						if(cur == base)nya = false;
					}
					return true;
				}
			}
		}
		visited.clear(cur);
		return false;
	}
	
	public static int[] findLoop(int[][] g, int s)
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
				int nex = g[hist[p]][ind[p]];
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
	
	public static int[][] packU(int n, int[] from, int[] to)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int f : from)p[f]++;
		for(int t : to)p[t]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < from.length;i++){
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
	}
	
	void run() throws Exception
	{
//		int n = 3000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(1 + " " + (gen.nextInt(n-1)+2) + " ");
//		for(int i = 2;i <= n;i++){
//			sb.append(i + " " + (gen.nextInt(i-1)+1) + " ");
//		}
//		INPUT = sb.toString();
//		
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
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