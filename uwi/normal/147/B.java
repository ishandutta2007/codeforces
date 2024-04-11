//package test4;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class B4 {
	InputStream is;
	PrintWriter out;
	String INPUT = "4 4\r\n" + 
			"1 2 -10 3\r\n" + 
			"1 3 1 -10\r\n" + 
			"2 4 -10 -1\r\n" + 
			"3 4 0 -3";
//	String INPUT = "\r\n" + // case 3:3
//			"3 3\r\n" + 
//			"\r\n" + 
//			"1 2 -10 3\r\n" + 
//			"\r\n" + 
//			"1 3 1 -10\r\n" + 
//			"\r\n" + 
//			"2 3 -10 -1";
	
	void solve()
	{
//		long S = System.currentTimeMillis();
		int n = ni(), m = ni();
		int INF = Integer.MIN_VALUE / 301;
		int[][][] d = new int[9][n][n];
		for(int j = 0;j < 9;j++){
			for(int i = 0;i < n;i++){
				Arrays.fill(d[j][i], INF);
				d[j][i][i] = 0;
			}
		}
		for(int i = 0;i < m;i++){
			int f = ni()-1, t = ni()-1, ij = ni(), ji = ni();
			d[0][f][t] = ij;
			d[0][t][f] = ji;
		}
		
//		tr(System.currentTimeMillis() - S+"ms");
		for(int i = 1;i < 9;i++){
			for(int l = 0;l < n;l++){
				for(int j = 0;j < n;j++){
					if(d[i-1][j][l] == INF)continue;
					for(int k = 0;k < n;k++){
						if(d[i-1][l][k] == INF)continue;
						if(d[i-1][j][l] + d[i-1][l][k] > d[i][j][k]){
							d[i][j][k] = d[i-1][j][l] + d[i-1][l][k];
						}
					}
				}
			}
		}
//		tr(System.currentTimeMillis() - S+"ms");
		
		int h = Integer.highestOneBit(n+1);
		int u = Integer.numberOfTrailingZeros(h);
		int[][] b = new int[n][n];
		int[][] nb = new int[n][n];
		for(int i = 0;i < n;i++){
			Arrays.fill(b[i], INF);
			b[i][i] = 0;
		}
		
		int c = 0;
		for(;u >= 0;u--,h/=2){
			for(int i = 0;i < n;i++){
				Arrays.fill(nb[i], INF);
				nb[i][i] = 0;
			}
			for(int l = 0;l < n;l++){
				for(int j = 0;j < n;j++){
					if(b[j][l] == INF)continue;
					for(int k = 0;k < n;k++){
						if(d[u][l][k] == INF)continue;
						if(b[j][l]+d[u][l][k] > nb[j][k]){
							nb[j][k] = b[j][l]+d[u][l][k];
						}
					}
				}
			}
			
			boolean ok = false;
			for(int i = 0;i < n;i++){
				if(nb[i][i] > 0){
					ok = true;
					break;
				}
			}
			if(!ok){
				c += h;
				if(c >= n){
					out.println(0);
					return;
				}
				for(int j = 0;j < n;j++){
					for(int k = 0;k < n;k++){
						b[j][k] = nb[j][k];
					}
				}
			}
		}
		out.println(c+1);
	}
	
	void run() throws Exception
	{
//		int n = 300, m = 300*299/2;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for(int i = 1;i <= n;i++){
//			for(int j = i+1;j <= n;j++){
//				sb.append(i + " ");
//				sb.append(j + " ");
//				sb.append(gen.nextInt(10010)-10000 + " ");
//				sb.append(gen.nextInt(10010)-10000 + " ");
//			}
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
		new B4().run();
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
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}