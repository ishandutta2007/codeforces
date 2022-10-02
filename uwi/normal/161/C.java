//package vkcup2012.r1;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class C2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int l1 = ni(), r1 = ni(), l2 = ni(), r2 = ni();
		int[][] s1 = {{l1, r1}};
		int[][] s2 = {{l2, r2}};
		
		boolean a1 = false;
		boolean a2 = false;
		int max = 0;
		for(int i = 29;i >= 0;i--){
			int x = 1<<i+1;
			if(!a1){
				int[][] ns1 = new int[s1.length*2][];
				int p = 0;
				for(int j = 0;j < s1.length;j++){
					if(s1[j][0] <= x && x <= s1[j][1]){
						if(s1[j][0] <= x-1){
							ns1[p++] = new int[]{s1[j][0], x-1};
						}
						if(x+1 <= s1[j][1]){
							ns1[p++] = new int[]{1, s1[j][1]-x};
						}
					}else{
						ns1[p++] = new int[]{s1[j][0]%x, s1[j][1]%x};
					}
				}
				s1 = Arrays.copyOf(ns1, p);
				for(int j = 0;j < p;j++){
					if(ns1[j][0] == 1 && ns1[j][1] == x-1){
						a1 = true;
						s1 = null;
						break;
					}
				}
			}
			if(!a2){
				int[][] ns2 = new int[s2.length*2][];
				int p = 0;
				for(int j = 0;j < s2.length;j++){
					if(s2[j][0] <= x && x <= s2[j][1]){
						if(s2[j][0] <= x-1){
							ns2[p++] = new int[]{s2[j][0], x-1};
						}
						if(x+1 <= s2[j][1]){
							ns2[p++] = new int[]{1, s2[j][1]-x};
						}
					}else{
						ns2[p++] = new int[]{s2[j][0]%x, s2[j][1]%x};
					}
				}
				s2 = Arrays.copyOf(ns2, p);
				for(int j = 0;j < p;j++){
					if(ns2[j][0] == 1 && ns2[j][1] == x-1){
						a2 = true;
						s2 = null;
						break;
					}
				}
			}
			if(a1){
				if(a2){
					max = Math.max(max, x-1);
				}else{
					for(int[] s : s2){
						max = Math.max(max, s[1]-s[0]+1);
					}
				}
			}else{
				if(a2){
					for(int[] s : s1){
						max = Math.max(max, s[1]-s[0]+1);
					}
				}else{
					for(int j = 0;j < s1.length;j++){
						for(int k = 0;k < s2.length;k++){
							int[] a = and(s1[j], s2[k]);
							if(a != null){
								max = Math.max(max, a[1]-a[0]+1);
							}
						}
					}
				}
			}
			
		}
		out.println(max);
	}
	
	static int[][] cut(int[][] s, int x)
	{
		int[][] ns = new int[s.length+1][];
		int p = 0;
		for(int j = 0;j < s.length;j++){
			if(s[j][0] <= x && x <= s[j][1]){
				if(s[j][0] <= x-1){
					ns[p++] = new int[]{s[j][0], x-1};
				}
				
				if(1 <= s[j][1]-x){
					ns[p++] = new int[]{1, s[j][1]-x};
				}
			}else{
				ns[p++] = new int[]{s[j][0]%x, s[j][1]%x};
			}
		}
		return normalize(ns, p);
	}
	
	// inclusive
	static int[][] normalize(int[][] a, int n)
	{
		Arrays.sort(a, 0, n, new RangeComp());
		int cur = 0;
		for(int i = 1;i < n;i++){
			if(a[cur][1] + 1 >= a[i][0]){
				a[cur][1] = Math.max(a[cur][1], a[i][1]);
			}else{
				cur++;
				a[cur][0] = a[i][0];
				a[cur][1] = a[i][1];
			}
		}
		return Arrays.copyOf(a, cur+1);
	}
	
	public static class RangeComp implements Comparator<int[]> {
		public int compare(int[] a, int[] b) {
			if(a[0] != b[0])return a[0] - b[0];
			return a[1] - b[1];
		}
	};
	
	public static int[] and(int[] a, int[] b)
	{
		int from = Math.max(a[0], b[0]);
		int to = Math.min(a[1], b[1]);
		if(from > to)return null;
		return new int[] {from, to};
	}
	
	public static boolean intersects(int[] a, int[] b)
	{
		return Math.max(a[0], b[0]) < Math.min(a[1], b[1]);
	}
	
	public static int[][] invert(int[][] a)
	{
		int n = a.length;
		if(n == 0) {
			return new int[][] {new int[] {Integer.MIN_VALUE, Integer.MAX_VALUE}};
		}
		List<int[]> l = new ArrayList<int[]>();
		if(a[0][0] > Integer.MIN_VALUE)l.add(new int[] {Integer.MIN_VALUE, a[0][0]});
		for(int i = 0;i < n-1;i++) {
			if(a[i][1] < a[i+1][0])l.add(new int[] {a[i][1], a[i+1][0]});
		}
		if(a[0][1] < Integer.MAX_VALUE)l.add(new int[] {a[n-1][1], Integer.MAX_VALUE});
		return (int[][])l.toArray();
	}

	/**
	 * O(|a|+|b|)
	 * @param a
	 * @param b
	 * @return
	 */
	public static int[][] and(int[][] a, int[][] b)
	{
		int[][] rs = new int[Math.max(a.length, b.length)][2];
		int p = 0;
		int i = 0;
		int j = 0;
		while(i < a.length && j < b.length){
			int from = Math.max(a[i][0], b[j][0]);
			int to = Math.min(a[i][1], b[j][1]);
			if(from < to)rs[p++] = new int[] {from, to};
			
			if(a[i][0] < b[j][0] || a[i][0] == b[j][0] && a[i][1] <= b[j][1]) {
				i++;
			}else{
				j++;
			}
		}
		return Arrays.copyOf(rs, p);
	}
	
	/**
	 * O(|a|+|b|)
	 * @param a
	 * @param b
	 * @return
	 */
	public static int[][] or(int[][] a, int[][] b)
	{
		int na = a.length;
		int nb = b.length;
		int[][] rs = new int[na+nb][2];
		int p = 0;
		int i = 0;
		int j = 0;
		while(i < na || j < nb){
			if(i == na) {
				rs[p][0] = b[j][0];
				rs[p][1] = b[j][1];
				j++;
			}else if(j == nb) {
				rs[p][0] = a[i][0];
				rs[p][1] = a[i][1];
				i++;
			}else if(a[i][0] < b[j][0] || a[i][0] == b[j][0] && a[i][1] <= b[j][1]) {
				rs[p][0] = a[i][0];
				rs[p][1] = a[i][1];
				i++;
			}else {
				rs[p][0] = b[j][0];
				rs[p][1] = b[j][1];
				j++;
			}
			p++;
		}
		
		int n = na+nb;
		if(n == 0)return new int[][] {};
		p = 0;
		for(int k = 1;k < n;k++) {
			if(rs[p][1] >= rs[k][0]) {
				rs[p][1] = Math.max(rs[p][1], rs[k][1]);
			}else {
				p++;
				rs[p] = rs[k];
			}
		}
		p++;
		int[][] rets = new int[p][];
		System.arraycopy(rs, 0, rets, 0, p);
		return rets;
	}
	
	// a-b
	public static int[][] del(int[][] a, int[][] b)
	{
		int na = a.length;
		int nb = b.length;
		int[][] ret = new int[na+nb+2][2];
		int p = 0;
		for(int i = 0, j = 0;i < na && j < nb;) {
			// intersects
			if(Math.max(a[i][0], b[j][0]) < Math.min(a[i][1], b[j][1])){ 
				if(b[j][0] <= a[i][0]) {
					if(a[i][1] <= b[j][1]) {
						i++;
						continue;
					}else {
						a[i][0] = b[j][1];
					}
				}else {
					if(a[i][1] <= b[j][1]) {
						a[i][1] = b[j][0];
					}else {
						ret[p][0] = a[i][0];
						ret[p][1] = b[j][0];
						p++;
						a[i][0] = b[j][1];
					}
				}
			}
			if(j == nb-1) {
				ret[p][0] = a[i][0];
				ret[p][1] = a[i][1];
				p++;
				i++;
			}else if(i == na-1) {
				j++;
			}else if(a[i][1] < b[j][1]) {
				ret[p][0] = a[i][0];
				ret[p][1] = a[i][1];
				p++;
				i++;
			}else {
				j++;
			}
		}
		
		int[][] rets = new int[p][2];
		System.arraycopy(ret, 0, rets, 0, p);
		return rets;
	}
	
	public static int compare(int[] a, int[] b) {
		if(a[0] != b[0])return a[0] - b[0];
		return a[1] - b[1];
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
		new C2().run();
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