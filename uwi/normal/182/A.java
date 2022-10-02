//package round117;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.TreeSet;

public class A {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int a = ni(), b = ni();
		int ax = ni(), ay = ni(), bx = ni(), by = ni();
		int n = ni();
		int[][] u = new int[n][];
		for(int i = 0;i < n;i++){
			u[i] = new int[]{ni(), ni(), ni(), ni()};
		}
		double[][] g = new double[n+2][n+2];
		double I = Double.MAX_VALUE / 10000;
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				double dist = Double.MAX_VALUE;
				dist = Math.min(dist, Line2D.ptSegDist(u[i][0], u[i][1], u[i][2], u[i][3], u[j][0], u[j][1]));
				dist = Math.min(dist, Line2D.ptSegDist(u[i][0], u[i][1], u[i][2], u[i][3], u[j][2], u[j][3]));
				dist = Math.min(dist, Line2D.ptSegDist(u[j][0], u[j][1], u[j][2], u[j][3], u[i][0], u[i][1]));
				dist = Math.min(dist, Line2D.ptSegDist(u[j][0], u[j][1], u[j][2], u[j][3], u[i][2], u[i][3]));
				g[i][j] = g[j][i] = dist;
			}
			g[i][n] = g[n][i] = Line2D.ptSegDist(u[i][0], u[i][1], u[i][2], u[i][3], ax, ay);
			g[i][n+1] = g[n+1][i] = Line2D.ptSegDist(u[i][0], u[i][1], u[i][2], u[i][3], bx, by);
			g[i][i] = I;
		}
		g[n][n] = I;
		g[n+1][n+1] = I;
		g[n][n+1] = g[n+1][n] = Point2D.distance(ax, ay, bx, by);
		
		for(double[] q : g){
			tr(q);
		}
		
		final double[] d = new double[n+2];
		Arrays.fill(d, Double.MAX_VALUE / 10000);
		TreeSet<Integer> ts = new TreeSet<Integer>(new Comparator<Integer>(){
			public int compare(Integer a, Integer b){
				int c = (int)Math.signum(d[a] - d[b]);
				if(c != 0)return c;
				return a - b;
			}
		});
		
		d[n] = 0;
		ts.add(n);
		double EPS = 1E-9;
		while(!ts.isEmpty()){
			int cur = ts.pollFirst();
			if(cur == n+1)break;
			for(int i = 0;i < n+2;i++){
				if(g[cur][i] <= a + EPS){
					double nd = i == n+1 ? d[cur] + g[cur][i] : d[cur] + a + b;
					if(nd < d[i]){
						ts.remove(i);
						d[i] = nd;
						ts.add(i);
					}
				}
			}
		}
		tr(d);
		if(d[n+1] == I){
			out.println(-1);
		}else{
			out.printf("%.7f\n", d[n+1]);
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
		new A().run();
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