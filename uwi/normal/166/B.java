//package round113;
import java.awt.geom.Line2D;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] a = new int[n][2];
		for(int i = 0;i < n;i++){
			a[i][0] = ni();
			a[i][1] = ni();
		}
		for(int p = 0, q = n-1;p < q;p++,q--){
			int[] u = a[p]; a[p] = a[q]; a[q] = u;
		}
		
		double cx = 0, cy = 0;
		for(int i = 0;i < n;i++){
			cx += a[i][0];
			cy += a[i][1];
		}
		cx /= n; cy /= n;
		
		double[] t = new double[n+1];
		double[] r = new double[n+1];
		for(int i = 0;i < n;i++){
			t[i] = Math.atan2(a[i][1]-cy, a[i][0]-cx);
			r[i] = Math.sqrt((a[i][0]-cx)*(a[i][0]-cx)+(a[i][1]-cy)*(a[i][1]-cy));
			if(i > 0 && t[i-1] > t[i]){
				t[i] += 2*Math.PI;
			}
		}
		r[n] = r[0];
		t[n] = t[0]+2*Math.PI;
		
		int m = ni();
		for(int i = 0;i < m;i++){
			int x = ni(), y = ni();
			if(cx == x && cy == y)continue;
			
			double tb = Math.atan2(y-cy,x-cx);
			if(tb < t[0]){
				tb += 2*Math.PI;
			}
			int ind = Arrays.binarySearch(t, tb);
			if(ind >= 0){
				double rb = Math.sqrt((x-cx)*(x-cx)+(y-cy)*(y-cy));
				if(rb >= r[ind]){
					out.println("NO");
					return;
				}
			}else{
				ind = -ind-2;
				if(Line2D.relativeCCW(a[ind][0], a[ind][1], a[(ind+1)%n][0], a[(ind+1)%n][1], x, y) != -1){
					out.println("NO");
					return;
				}
			}
		}
		out.println("YES");
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
		new B().run();
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