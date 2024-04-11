//package round101;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		if(n % 2 == 0){
			out.println(-1);
			return;
		}
		
		int[] from = new int[m];
		int[] to = new int[m];
		char[] kind = new char[m];
		for(int i = 0;i < m;i++){
			from[i] = ni() - 1;
			to[i] = ni() - 1;
			kind[i] = nc();
		}
		
		DJSet ms = new DJSet(n);
		for(int i = 0;i < m;i++){
			if(kind[i] == 'M'){
				ms.union(from[i], to[i]);
			}
		}
		
		boolean[] used = new boolean[m];
		int us = 0;
		for(int i = 0;i < m;i++){
			if(kind[i] == 'S' && !ms.equiv(from[i], to[i])){
				used[i] = true;
				us++;
				ms.union(from[i], to[i]);
			}
		}
		if(ms.upper[ms.root(0)] != -n || us > (n-1)/2){
			out.println(-1);
			return;
		}
		
		DJSet ss = new DJSet(n);
		for(int i = 0;i < m;i++){
			if(used[i]){
				ss.union(from[i], to[i]);
			}
		}
		
		for(int i = 0;i < m && us < (n-1)/2;i++){
			if(kind[i] == 'S' && !used[i] && !ss.equiv(from[i], to[i])){
				used[i] = true;
				us++;
				ss.union(from[i], to[i]);
			}
		}
		if(us < (n-1)/2){
			out.println(-1);
			return;
		}
		
		for(int i = 0;i < m;i++){
			if(kind[i] == 'M' && !ss.equiv(from[i], to[i])){
				used[i] = true;
				us++;
				ss.union(from[i], to[i]);
			}
		}
		
		out.println(n-1);
		if(n == 1){
			out.println();
		}else{
			StringBuilder sb = new StringBuilder();
			for(int i = 0;i < m;i++){
				if(used[i]){
					sb.append(" ");
					sb.append(i+1);
				}
			}
			out.println(sb.substring(1));
		}
	}
	
	public static class DJSet { public int[] upper; public DJSet(int n){ upper = new int[n]; Arrays.fill(upper, -1);} public int root(int x){	return upper[x] < 0 ? x : (upper[x] = root(upper[x]));}	public boolean equiv(int x, int y){ return root(x) == root(y);} public void union(int x, int y){ x = root(x);y = root(y);if(x != y) { if(upper[y] < upper[x]) { int d = x; x = y; y = d;	} upper[x] += upper[y]; upper[y] = x;}} public int count(){	int ct = 0;	for(int i = 0;i < upper.length;i++){ if(upper[i] < 0)ct++; } return ct; }}
	
	char nc() {
		try {
			int b;
			while ((b = is.read()) != -1
					&& (b == ' ' || b == '\r' || b == '\n'))
				;
			if (b == -1)
				return 0;
			return (char) b;
		} catch (IOException e) {
		}
		return 0;
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