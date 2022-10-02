//package vkcup2012.q2;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] b = new int[n][3];
		for(int i = 0;i < n;i++){
			b[i][0] = ni();
			b[i][1] = ni();
			b[i][2] = i;
		}
		int[][][] bt = bucket(b, 0);
		
		final Map<Integer, Long> sm = new HashMap<Integer, Long>();
		int m = bt.length;
		for(int i = 0;i < m;i++){
			long s = 0;
			for(int[] q : bt[i]){
				s += q[1];
			}
			sm.put(bt[i][0][0], s);
		}
		Arrays.sort(bt, new Comparator<int[][]>() {
			public int compare(int[][] a, int[][] b) {
				if(a.length - b.length != 0)return a.length - b.length;
				return -Long.signum(sm.get(a[0][0]) - sm.get(b[0][0]));
			}
		});
		long[][] h = new long[m][];
		for(int i = 0;i < m;i++){
			Arrays.sort(bt[i], new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return -(a[1] - b[1]);
				}
			});
			h[i] = new long[bt[i].length+1];
			for(int j = 1;j <= bt[i].length;j++){
				h[i][j] = h[i][j-1] + bt[i][j-1][1];
			}
		}
		
		long max = 0;
		int maxi = -1, maxj = -1, jh = -1;
		int ah = 0;
		for(int i = 0;i < m;i++){
			long htop = h[i][h[i].length-1];
			if(ah == h[i].length)continue;
			ah = h[i].length;
			for(int j = i+1;j < m;j++){
				if(h[j].length > h[i].length){
					long v = h[j][h[i].length] + htop;
					if(v > max){
						max = v;
						maxi = i; maxj = j; jh = h[i].length+1;
					}
				}else{
					long v = h[j][h[i].length-1] + htop;
					if(v > max){
						max = v;
						maxi = i; maxj = j; jh = h[i].length;
					}
				}
			}
		}
		out.println(max);
		out.println(h[maxi].length-1 + jh-1);
		for(int i = 0;i < h[maxi].length-1;i++){
			if(i > 0)out.print(" ");
			out.print(bt[maxj][i][2]+1);
			out.print(" ");
			out.print(bt[maxi][i][2]+1);
		}
		if(jh > h[maxi].length){
			out.print(" ");
			out.print(bt[maxj][jh-2][2]+1);
		}
		out.println();
	}
	
	int[][][] bucket(int[][] b, final int d)
	{
		Arrays.sort(b, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[d] - b[d];
			}
		});
		
		int n = b.length;
		int[][][] bt = new int[n][][];
		int pre = 0;
		int p = 0;
		for(int i = 0;i < n;i++){
			if(i == n-1 || b[i][d] != b[i+1][d]){
				bt[p] = new int[i-pre+1][];
				for(int j = pre;j <= i;j++){
					bt[p][j-pre] = b[j];
				}
				p++;
				pre = i+1;
			}
		}
		return Arrays.copyOf(bt, p);
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