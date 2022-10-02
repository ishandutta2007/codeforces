//package round101;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Random;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		Person[] ps = new Person[n];
		for(int i = 0;i < n;i++){
			ps[i] = new Person();
			ps[i].name = ns();
			ps[i].fr = ni();
		}
		
		Arrays.sort(ps, new Comparator<Person>(){
			public int compare(Person a, Person b){
				return a.fr - b.fr;
			}
		});
		
		for(int i = 0;i < n;i++){
			if(ps[i].fr > i){
				out.println(-1);
				return;
			}
		}
		
		int[] h = new int[n];
		SkipListNoVal sl = new SkipListNoVal(n);
		for(int i = 0;i < n;i++){
			sl.insert(i-ps[i].fr);
		}
		int[] inds = sl.inds();
		for(int i = 0;i < n;i++){
			h[inds[i]] = i+1;
		}
		for(int i = 0;i < n;i++){
			out.println(ps[i].name + " " + h[i]);
		}
	}
	
	static class Person
	{
		public String name;
		public int fr;
	}
	
	public static class SkipListNoVal {
		public int[][][] l; // [level][ind][next/prev/nextlen]
		Random gen = new Random();
		public double P = 0.05;
		public int len;
		public int h;
		
		public SkipListNoVal(int n)
		{
			h = (int)(Math.log(n)/-Math.log(P))+1;
			l = new int[h][n+2][3];
			for(int i = 0;i < h;i++){
				l[i][0][0] = 1;
				l[i][0][1] = -1;
				l[i][0][2] = 1;
				l[i][1][0] = -1;
				l[i][1][1] = 0;
				l[i][1][2] = 0;
			}
			len = 0;
		}
		
		public int find(int n)
		{
			if(n > len || n < 0)return Integer.MAX_VALUE;
			int d = -1;
			int cur = 0;
			for(int i = h-1;i >= 0;i--){
				for(;cur != -1;d += l[i][cur][2], cur = l[i][cur][0]){
					if(d == n){
						return cur-2;
					}else if(n < d+l[i][cur][2]){
						break;
					}
				}
			}
			return -1;
		}
		
		public int[] inds()
		{
			int[] ret = new int[len];
			for(int cur = l[0][0][0], p = 0;cur != 1;cur = l[0][cur][0], p++){
				ret[p] = cur-2;
			}
			return ret;
		}
		
		public int[][] findIndexEx(int n)
		{
			if(n > len || n < 0)return null;
			int d = -1;
			int cur = 0;
			int[] last = new int[h];
			int[] remain = new int[h];
			for(int i = h-1;i >= 0;i--){
				for(;;d += l[i][cur][2], cur = l[i][cur][0]){
					if(d == n){
						Arrays.fill(last, 0, i+1, cur);
						return new int[][]{last, remain};
					}else if(n < d+l[i][cur][2]){
						last[i] = cur;
						remain[i] = n-d;
						break;
					}
				}
			}
			return null;
		}
		
		/**
		 * n
		 * @param n
		 */
		public boolean insert(int n)
		{
			int[][] res = findIndexEx(n);
			if(res == null)return false;
			int[] inds = res[0];
			int[] remain = res[1];
			int k = len+2;
			len++;
			int znext = inds[0];
			int zprev = l[0][znext][1];
			l[0][k][0] = znext;
			l[0][k][1] = zprev;
			l[0][k][2] = 1;
			l[0][zprev][0] = k;
			l[0][znext][1] = k;
			boolean prom = true;
			for(int i = 1;i < h;i++){
				if(prom && gen.nextDouble() > P)prom = false;
				if(prom){
					if(inds[i] == znext){
						int prev = l[i][znext][1];
						l[i][k][0] = znext;
						l[i][k][1] = prev;
						l[i][k][2] = 1;
						l[i][prev][0] = k;
						l[i][znext][1] = k;
					}else{
						int prev = inds[i];
						int next = l[i][inds[i]][0];
						l[i][k][0] = next;
						l[i][k][1] = prev;
						l[i][k][2] = l[i][prev][2]-remain[i]+1;
						l[i][prev][0] = k;
						l[i][prev][2] = remain[i];
						l[i][next][1] = k;
					}
				}else{
					if(inds[i] == znext){
						int prev = l[i][znext][1];
						l[i][prev][2]++;
					}else{
						l[i][inds[i]][2]++;
					}
				}
			}
			return true;
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
		new C().run();
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