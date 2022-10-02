//package round155;
import java.io.ByteArrayInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), d = ni();
		char[][] b = new char[n][];
		for(int i = 0;i < n;i++){
			b[i] = ns(m);
		}
		
		int[] rat = new int[n*m];
		int nrat = 0;
		
		int sr = -1, sc = -1;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(b[i][j] == 'R'){
					if(sr == -1){
						sr = i; sc = j;
					}
					rat[i*m+j] = 1;
					nrat++;
				}
			}
		}
		int[] ft = buildFenwick(rat);
		
		int[][] neis = neis(sr, sc, d, b);
		for(int[] nei : neis){
			int[] sec = burst(nei[0], nei[1], d, b, ft, rat, nrat);
			if(sec != null){
				out.println(
						(nei[0]+1) + " " +
								(nei[1]+1) + " " +
								(sec[0]+1) + " " +
								(sec[1]+1) + " "
								);
				return;
			}
		}
		out.println(-1);
	}
	
	
	int[] dr = { 1, 0, -1, 0 };
	int[] dc = { 0, 1, 0, -1 };
	
	int[] burst(int sr, int sc, int d, char[][] b, int[] ft, int[] rat, int nrat)
	{
		int n = b.length, m = b[0].length;
		int[][] neis = neis(sr, sc, d, b);
		for(int[] nei : neis){
			if(b[nei[0]][nei[1]] == 'R'){
				addFenwick(ft, nei[0]*m+nei[1], -1);
				rat[nei[0]*m+nei[1]]--;
				nrat--;
			}
		}
		
		int ind = findGFenwick(ft, 0);
//		tr(restoreFenwick(ft));
		if(ind >= (n*m)-1){
			// killed all
			for(int i = 0;i < n;i++){
				for(int j = 0;j < m;j++){
					if(b[i][j] != 'X' && !(sr == i && sc == j)){
						return new int[]{i, j};
					}
				}
			}
		}
		ind++;
		int[][] nneis = neis(ind/m, ind%m, d, b);
		for(int[] nnei : nneis){
			int[][] nx = neis(nnei[0], nnei[1], d, b);
			int orat = nrat;
			for(int[] x : nx){
				if(rat[x[0]*m+x[1]] == 1){
					orat--;
				}
			}
			if(orat == 0){
				return new int[]{nnei[0], nnei[1]};
			}
		}
		
		for(int[] nei : neis){
			if(b[nei[0]][nei[1]] == 'R'){
				addFenwick(ft, nei[0]*m+nei[1], 1);
				rat[nei[0]*m+nei[1]]++;
			}
		}
		
		return null;
	}
	
	int[][] neis(int sr, int sc, int d, char[][] b)
	{
		Queue<int[]> q = new ArrayDeque<int[]>();
		q.add(new int[]{sr, sc, 0});
		int[][] ret = new int[4*d*d+1][];
		int p = 0;
		ret[p++] = new int[]{sr, sc, 0};
		while(!q.isEmpty()){
			int[] cur = q.poll();
			int r = cur[0], c = cur[1], cd = cur[2];
			if(cd == d)continue;
			outer:
			for(int k = 0;k < 4;k++){
				int nr = r + dr[k], nc = c + dc[k];
				if(b[nr][nc] != 'X'){
					for(int i = 0;i < p;i++){
						if(ret[i][0] == nr && ret[i][1] == nc){
							continue outer;
						}
					}
					int[] nex = new int[]{nr, nc, cd+1};
					ret[p++] = nex;
					q.add(nex);
				}
			}
		}
		
		return Arrays.copyOf(ret, p);
	}
	
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static int[] restoreFenwick(int[] ft)
	{
		int n = ft.length-1;
		int[] ret = new int[n];
		for(int i = 0;i < n;i++)ret[i] = sumFenwick(ft, i);
		for(int i = n-1;i >= 1;i--)ret[i] -= ret[i-1];
		return ret;
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}
	
	public static int findGFenwick(int[] ft, int v)
	{
		int i = 0;
		int n = ft.length;
		for(int b = Integer.highestOneBit(n);b != 0 && i < n;b >>= 1){
			if(i + b < n){
				int t = i + b;
				if(v >= ft[t]){
					i = t;
					v -= ft[t];
				}
			}
		}
		return v != 0 ? -(i+1) : i-1;
	}
	
	public static int[] buildFenwick(int[] a)
	{
		int n = a.length;
		int[] ft = new int[n+1];
		System.arraycopy(a, 0, ft, 1, n);
		for(int k = 2, h = 1;k <= n;k*=2, h*=2){
			for(int i = k;i <= n;i+=k){
				ft[i] += ft[i-h];
			}
		}
		return ft;
	}
	
	void run() throws Exception
	{
		is = oj ? new FileInputStream("input.txt") : new ByteArrayInputStream(INPUT.getBytes());
		out = oj ? new PrintWriter("output.txt") : new PrintWriter(System.out);
		
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