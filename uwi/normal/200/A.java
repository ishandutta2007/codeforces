//package round126;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class A2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), q = ni();
		
		boolean flip = false;
		if(n > m){
			flip = true;
			int d = n; n = m; m = d;
		}
		boolean[][] f = new boolean[n][m];
		DJSet[] ds = new DJSet[n];
		int[][] left = new int[n][m];
		int[][] right = new int[n][m];
		for(int i = 0;i < n;i++)ds[i] = new DJSet(m);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				left[i][j] = j+1;
				right[i][j] = j-1;
			}
		}
		for(int i = 0;i < q;i++){
//			tr(left, right);
			int r, c;
			if(!flip){
				r = ni()-1; c = ni()-1;
			}else{
				c = ni()-1; r = ni()-1;
			}
			int mind = 99999;
			int minr = -1, minc = -1;
			for(int j = r;j >= 0;j--){
				// (j,cc)
				{
					int cc = left[j][ds[j].root(c)];
//					tr("left ", r, c, j, cc);
					if(cc > 0){
						cc--;
						int d = Math.abs(r-j) + (c-cc);
						if(!flip){
//							tr(d,j,cc);
							if(d < mind || (d == mind && (j < minr || (j == minr && cc < minc)))){
								mind = d;
								minr = j; minc = cc;
							}
						}else{
							if(d < mind || (d == mind && (cc < minc || (cc == minc && j < minr)))){
								mind = d;
								minr = j; minc = cc;
							}
						}
					}
				}
				{
					int cc = right[j][ds[j].root(c)];
//					tr("right", r, c, j, cc);
					if(cc < m-1){
						cc++;
						int d = Math.abs(r-j) + (cc-c);
						if(!flip){
//							tr(d,j,cc);
							if(d < mind || (d == mind && (j < minr || (j == minr && cc < minc)))){
								mind = d;
								minr = j; minc = cc;
							}
						}else{
							if(d < mind || (d == mind && (cc < minc || (cc == minc && j < minr)))){
								mind = d;
								minr = j; minc = cc;
							}
						}
					}
				}
				if(!f[j][c])break;
			}
			for(int j = r+1;j < n;j++){
				// (j,cc)
				{
					int cc = left[j][ds[j].root(c)];
//					tr("left ", r, c, j, cc);
					if(cc > 0){
						cc--;
						int d = Math.abs(r-j) + (c-cc);
						if(!flip){
//							tr(d,j,cc);
							if(d < mind || (d == mind && (j < minr || (j == minr && cc < minc)))){
								mind = d;
								minr = j; minc = cc;
							}
						}else{
							if(d < mind || (d == mind && (cc < minc || (cc == minc && j < minr)))){
								mind = d;
								minr = j; minc = cc;
							}
						}
					}
				}
				{
					int cc = right[j][ds[j].root(c)];
//					tr("right", r, c, j, cc);
					if(cc < m-1){
						cc++;
						int d = Math.abs(r-j) + (cc-c);
						if(!flip){
//							tr(d,j,cc);
							if(d < mind || (d == mind && (j < minr || (j == minr && cc < minc)))){
								mind = d;
								minr = j; minc = cc;
							}
						}else{
							if(d < mind || (d == mind && (cc < minc || (cc == minc && j < minr)))){
								mind = d;
								minr = j; minc = cc;
							}
						}
					}
				}
				if(!f[j][c])break;
			}
			if(!flip){
				out.println((minr+1) + " " + (minc+1));
			}else{
				out.println((minc+1) + " " + (minr+1));
			}
			f[minr][minc] = true;
			int nl = minc;
			int nr = minc;
			if(minc-1 >= 0 && f[minr][minc-1]){
				nl = left[minr][ds[minr].root(minc-1)];
				ds[minr].union(minc, minc-1);
			}
			if(minc+1 < m && f[minr][minc+1]){
				nr = right[minr][ds[minr].root(minc+1)];
				ds[minr].union(minc, minc+1);
			}
			left[minr][ds[minr].root(minc)] = nl;
			right[minr][ds[minr].root(minc)] = nr;
		}
	}
	
	public static class DJSet { public int[] upper; public DJSet(int n){ upper = new int[n]; Arrays.fill(upper, -1);} public int root(int x){	return upper[x] < 0 ? x : (upper[x] = root(upper[x]));}	public boolean equiv(int x, int y){ return root(x) == root(y);} public void union(int x, int y){ x = root(x);y = root(y);if(x != y) { if(upper[y] < upper[x]) { int d = x; x = y; y = d;	} upper[x] += upper[y]; upper[y] = x;}} public int count(){	int ct = 0;	for(int i = 0;i < upper.length;i++){ if(upper[i] < 0)ct++; } return ct; }}
	
	void run() throws Exception
	{
//		int n = 2000, m = 2000;
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " " + m + " " + 100000 + " ");
//		int x = 1000, y = 1000;
//		for(int i = 0;i < 100000;i++){
//			sb.append(x + " " + y + " ");
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
		new A2().run();
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