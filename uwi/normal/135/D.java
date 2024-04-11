//package round97;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "5 5\r\n" + 
			"01010\r\n" + 
			"10101\r\n" + 
			"01010\r\n" + 
			"10101\r\n" + 
			"01010";
	
	void solve()
	{
		int n = ni(), m = ni(); // nm same sample!
		char[][] b = new char[n][];
		for(int i = 0;i < n;i++){
			b[i] = ns(m);
		}
		
		int[] dr = {0, 1, 0, -1}; // RDLU
		int[] dc = {1, 0, -1, 0};
		
		int[][][] next = new int[n][m][4];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(b[i][j] == '1'){
					outer:
					for(int k = 0;k < 4;k++){
						for(int r = i+dr[k], c = j+dc[k], f = 1; r >= 0 && r < n && c >= 0 && c < m; r+= dr[k], c += dc[k], f++){
							if(b[r][c] == '1'){
								next[i][j][k] = f;
								continue outer;
							}
						}
						next[i][j][k] = -3;
					}
				}else{
					next[i][j] = null;
				}
			}
		}
		int max = 0;
//		BitSet used = new BitSet();
		boolean[][][] used = new boolean[n][m][4];
		int[][] nya = new int[n][m];
		int[] oppo = new int[n*m];
		int[][] trail = new int[n*m][2];
		for(int i = 0;i < n;i++){
			ou:
			for(int j = 0;j < m;j++){
				if(!used[i][j][3] && b[i][j] == '1'){
//				if(!used.get(i*m+j) && b[i][j] == '1'){
					int r = i, c = j, dir = 3, d = 0;
					int color = i*m+j+111;
					int p = 0;
					ooo:
					while(!(d > 0 && r == i && c == j)){
//						tr(r, c, dir);
//						if(dir == 3)used.set(r*m+c);
						if(used[r][c][dir])continue ou;
						used[r][c][dir] = true;
						trail[d][0] = r;
						trail[d][1] = c;
						nya[r][c] = color;
						if(next[r][c][(dir+1)&3] < 0)continue ou;
						int or = r+next[r][c][(dir+1)&3]*dr[(dir+1)&3];
						int oc = c+next[r][c][(dir+1)&3]*dc[(dir+1)&3];
						oppo[p++] = or*m+oc;
						d++;
						for(int k = dir+5;k >= dir+3;k--){
							int kk = k&3;
//							int dist = Math.abs(next[r][c][kk][0]-r) + Math.abs(next[r][c][kk][1]-c);
//							tr(kk, dist);
							if(next[r][c][kk] == 1){
								int nr = r+next[r][c][kk]*dr[kk];
								int nc = c+next[r][c][kk]*dc[kk];
//								if(dir==1){
//									used.set(nr*m+nc);
//								}
//								used[nr][nc][(dir+2)%4] = true;
								dir = kk;
								r = nr; c = nc;
								continue ooo;
							}
						}
						continue ou;
					}
					if(max > d)continue ou;
					// inside 1
					for(int k = 0;k < p;k++){
						if(nya[oppo[k]/m][oppo[k]%m] != color){
							continue ou;
						}
					}
					// exactly two
					for(int k = 0;k < d;k++){ 
						int ne = 0;
						int R = trail[k][0];
						int C = trail[k][1];
						for(int l = 0;l < 4;l++){
//							if(nei[R][C][l] && nya[next[R][C][l][0]][next[R][C][l][1]] == color){
							if(next[R][C][l] == 1 && nya[R+dr[l]][C+dc[l]] == color){
								ne++;
							}
						}
						if(ne != 2){
							continue ou;
						}
					}
//					tr(d, Arrays.copyOf(oppo, p));
					max = Math.max(max, d);
				}
			}
		}
		out.println(max);
	}
	
	void run() throws Exception
	{
//		int n = 999, m = 1000;
//		Random gen = new Random(1234);
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " " + m + " ");
//		for(int i = 0;i < n;i++){
//			for(int j = 0;j < m;j++){
//				sb.append(gen.nextInt(8) >= 0 ? 1 : 0);
//			}
//			sb.append('\n');
//		}
//		INPUT = sb.toString();
		
//		int n = 1000, m = 1000;
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " " + m + " ");
//		for(int i = 0;i < n;i++){
//			for(int j = 0;j < m;j++){
//				sb.append((i == 0 || i == n-1 || j == 0 || j == m-1) ? 1 : 0);
//			}
//			sb.append('\n');
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
		new D2().run();
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