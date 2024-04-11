//package round144;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class A2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] a = new int[101][];
		int[][] b = new int[9000][];
		int q = 0;
		for(int i = 3;i <= 100;i++){
			int h = i*(i-1)*(i-2)/6;
			for(int j = i;j >= 2;j-=2){
				b[q++] = new int[]{h, i, (i-j)/2};
				h -= i-2;
			}
		}
		Arrays.sort(b, 0, q, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return -(a[0] - b[0]);
			}
		});
		
		int p = 0;
		int s = 2;
		for(int i = 0;i < q;i++){
			if(b[i][0] == 0)break;
			while(n >= b[i][0]){
				n -= b[i][0];
				a[p++] = b[i];
				s += b[i][1]-2;
			}
		}
		
		out.println(s);
		char[][] g = new char[s][s];
		for(int i = 0;i < s;i++){
			Arrays.fill(g[i], '0');
		}
		g[0][1] = g[1][0] = '1';
		int cur = 2;
		for(int i = 0;i < p;i++){
			for(int j = cur;j < cur+a[i][1]-2;j++){
				g[j][0] = g[0][j] = '1';
				g[j][1] = g[1][j] = '1';
				for(int k = cur;k < cur+a[i][1]-2;k++){
					if(j != k){
						g[j][k] = g[k][j] = '1';
					}
				}
			}
			for(int k = cur, l = 0;l < a[i][2];k+=2, l++){
				g[k][k+1] = g[k+1][k] = '0';
			}
			cur += a[i][1]-2;
		}
		for(int i = 0;i < s;i++){
			out.println(new String(g[i]));
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