//package round102;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "1000 1000";
	
//	static int[] DRK = {-2,-2,-1,-1,1,1,2,2};
//	static int[] DCK = {-1,1,-2,2,-2,2,-1,1};
	
	void solve()
	{
		int n = ni(), m = ni();
		if(n == 1){
			out.println(m);
		}else if(m == 1){
			out.println(n);
		}else if(n == 2){
			if(m % 4 == 1){
				out.println(m+1);
			}else{
				out.println((m+2)/4*4);
			}
		}else if(m == 2){
			if(n % 4 == 1){
				out.println(n+1);
			}else{
				out.println((n+2)/4*4);
			}
		}else if(n % 2 == 0 || m % 2 == 0){
			out.println(n*m/2);
		}else{
			out.println((n*m+1)/2);
		}
//		int f = 20;
//		int[][] w = new int[f+1][f+1];
//		for(int i = 1;i <= f;i++){
//			for(int j = 1;j <= f;j++){
//				boolean[][] g = new boolean[(i+1)*(j+1)/2][(i+1)*(j+1)/2];
//				for(int k = 0;k < i;k++){
//					for(int l = 0;l < j;l++){
//						if((k+l)%2 == 0){
//							for(int u = 0;u < 8;u++){
//								int r = k+DRK[u], c = l+DCK[u];
//								if(r >= 0 && r < i && c >= 0 && c < j){
//									g[k*((j+1)/2)+l/2][r*((j+1)/2)+c/2] = true;
//								}
//							}
//						}
//					}
//				}
//				w[i][j] = i*j-doBipartiteMatching(g);
////				tr(i, j, doBipartiteMatching(g), i*j-doBipartiteMatching(g));
//			}
//			tr(w[i]);
//		}
	}
	
	public static int doBipartiteMatching(boolean[][] g)
	{
		int n = g.length;
		if(n == 0)return 0;
		int m = g[0].length;
		if(m == 0)return 0;
		int[] im = new int[m];
		Arrays.fill(im, -1);
		BitSet visited = new BitSet();
		int matched = 0;
		for(int i = 0;i < n;i++){
			if(visit(g, i, visited, im)) {
				visited.clear();
				matched++;
			}
		}
		return matched;
	}

	public static boolean visit(boolean[][] g, int cur, BitSet visited, int[] im)
	{
		if(cur == -1)return true;

		for(int i = visited.nextClearBit(0);i != g[cur].length;i = visited.nextClearBit(i+1)){
			if(g[cur][i]){
				visited.set(i);
				if(visit(g, im[i], visited, im)){
					im[i] = cur;
					return true;
				}
			}
		}
		return false;
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