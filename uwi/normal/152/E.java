//package round108;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;

public class E4 {
	InputStream is;
	PrintWriter out;
	String INPUT = "4 5 4\r\n" + 
			"1 4 5 1 2\r\n" + 
			"2 2 2 2 7\r\n" + 
			"2 4 1 4 5\r\n" + 
			"3 2 1 7 1\r\n" + 
			"1 1\r\n" + 
			"1 5\r\n" + 
			"4 1\r\n" + 
			"4 4";
//	String INPUT = "2 3 3\r\n" + 
//			"\r\n" + 
//			"1 1 3\r\n" + 
//			"\r\n" + 
//			"3 1 3\r\n" + 
//			"\r\n" + 
//			"2 2\r\n" + 
//			"\r\n" + 
//			"1 3\r\n" + 
//			"\r\n" + 
//			"1 1";
	void solve()
	{
		int n = ni(), m = ni(), z = ni();
		int er = 0;
		int[][] a = new int[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				a[i][j] = ni();
			}
		}
		
		int[][] im = new int[z][2];
		for(int i = 0;i < z;i++){
			im[i][0] = ni()-1;
			im[i][1] = ni()-1;
			er += a[im[i][0]][im[i][1]];
			a[im[i][0]][im[i][1]] = 0;
		}
		
		int v = n*m;
		int[][] d = new int[v][v];
		BitSet[][] path = new BitSet[v][v];
		for(int i = 0;i < v;i++){
			for(int j = 0;j < v;j++){
				path[i][j] = new BitSet();
			}
			path[i][i].set(i);
		}
		for(int i = 0;i < v;i++){
			Arrays.fill(d[i], 9999999);
			d[i][i] = 0;
		}
		
		for(int i = 0;i < n-1;i++){
			for(int j = 0;j < m;j++){
				d[i*m+j][(i+1)*m+j] = a[i+1][j];
				d[(i+1)*m+j][i*m+j] = a[i][j];
				path[i*m+j][(i+1)*m+j].set(i*m+j);
				path[i*m+j][(i+1)*m+j].set((i+1)*m+j);
				path[(i+1)*m+j][i*m+j].set(i*m+j);
				path[(i+1)*m+j][i*m+j].set((i+1)*m+j);
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m-1;j++){
				d[i*m+j][i*m+j+1] = a[i][j+1];
				d[i*m+j+1][i*m+j] = a[i][j];
				path[i*m+j][i*m+j+1].set(i*m+j+1);
				path[i*m+j][i*m+j+1].set(i*m+j);
				path[i*m+j+1][i*m+j].set(i*m+j);
				path[i*m+j+1][i*m+j].set(i*m+j+1);
			}
		}
		
		for (int k = 0; k < n*m; k++) {
			for (int i = 0; i < n*m; i++) {
				for (int j = 0; j < n*m; j++) {
					if (d[i][j] > d[i][k] + d[k][j]) {
						d[i][j] = d[i][k] + d[k][j];
						path[i][j].clear();
						path[i][j].or(path[i][k]);
						path[i][j].or(path[k][j]);
					}
				}
			}
		}
		
		int[][][] dp = new int[1<<z][n][m]; // [ptn][cent_row][cent_col]
		BitSet[][][] hist = new BitSet[1<<z][n][m]; 
		for(int i = 1;i < 1<<z;i++){
			if((i&i-1)==0){
				int ind = Integer.numberOfTrailingZeros(i);
				for(int j = 0;j < n;j++){
					for(int k = 0;k < m;k++){
						dp[i][j][k] = d[im[ind][0]*m+im[ind][1]][j*m+k];
						hist[i][j][k] = new BitSet();
						hist[i][j][k].or(path[im[ind][0]*m+im[ind][1]][j*m+k]);
					}
				}
			}else{
				for(int j = 0;j < n;j++){
					for(int k = 0;k < m;k++){
						int min = 9999999;
						int ff = -1;
						for(int f = 1;f < i;f++){
							if((f&i)==f){
								int w = dp[f][j][k]+dp[i^f][j][k]-a[j][k];
								if(w < min){
									ff = f;
									min = w;
								}
							}
						}
						dp[i][j][k] = min;
						hist[i][j][k] = new BitSet();
						hist[i][j][k].or(hist[ff][j][k]);
						hist[i][j][k].or(hist[i^ff][j][k]);
					}
				}
				for(int j = 0;j < n;j++){
					for(int k = 0;k < m;k++){
						for(int x = 0;x < n;x++){
							for(int y = 0;y < m;y++){
								int w = dp[i][x][y]+d[x*m+y][j*m+k];
								if(w < dp[i][j][k]){
									dp[i][j][k] = w;
									hist[i][j][k] = new BitSet();
									hist[i][j][k].or(hist[i][x][y]);
									hist[i][j][k].or(path[x*m+y][j*m+k]);
								}
							}
						}
					}
				}
			}
		}
		
		int min = 9999999;
		int mini = -1, minj = -1;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(dp[(1<<z)-1][i][j] < min){
					min = dp[(1<<z)-1][i][j];
					mini = i;
					minj = j;
				}
			}
		}
		;
		
		out.println(min+er);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(hist[(1<<z)-1][mini][minj].get(i*m+j)){
					out.print('X');
				}else{
					out.print('.');
				}
			}
			out.println();
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
		new E4().run();
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