//package round82;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "6 10\r\n" +
			"##########\r\n" +
			"#K#..#####\r\n" +
			"#.#..##.##\r\n" +
			"#..L.#...#\r\n" +
			"###D###A.#\r\n" +
			"##########\r\n" +
			"4\r\n" +
			"N 2\r\n" +
			"S 1\r\n" +
			"E 1\r\n" +
			"W 2";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		char[][] b = new char[n][m];
		for(int i = 0;i < n;i++){
			b[i] = in.next().toCharArray();
		}
		
		int k = ni();
		int[][] dl = new int[k][2];
		for(int i = 0;i < k;i++){
			char dir = in.next().charAt(0);
			dl[i][0] = "NSWE".indexOf(dir);
			dl[i][1] = ni();
		}
		
		int[][] sw = new int[n][m];
		int[][] se = new int[n][m];
		int[][] sn = new int[n][m];
		int[][] ss = new int[n][m];
		for(int i = 0;i < n;i++){
			int cur = 0;
			for(int j = 0;j < m;j++){
				if(b[i][j] == '#'){
					cur = 0;
					sw[i][j] = 0;
				}else{
					sw[i][j] = cur++;
				}
			}
		}
		for(int i = 0;i < n;i++){
			int cur = 0;
			for(int j = m-1;j >= 0;j--){
				if(b[i][j] == '#'){
					cur = 0;
					se[i][j] = 0;
				}else{
					se[i][j] = cur++;
				}
			}
		}
		for(int i = 0;i < m;i++){
			int cur = 0;
			for(int j = 0;j < n;j++){
				if(b[j][i] == '#'){
					cur = 0;
					sn[j][i] = 0;
				}else{
					sn[j][i] = cur++;
				}
			}
		}
		for(int i = 0;i < m;i++){
			int cur = 0;
			for(int j = n-1;j >= 0;j--){
				if(b[j][i] == '#'){
					cur = 0;
					ss[j][i] = 0;
				}else{
					ss[j][i] = cur++;
				}
			}
		}
		
		int[][][] s = {sn, ss, sw, se};
		int[] dr = {-1,1,0,0};
		int[] dc = {0,0,-1,1};
		char[] ret = new char[26];
		int rp = 0;
		for(int i = 0;i < n;i++){
			outer:
			for(int j = 0;j < m;j++){
				if(b[i][j] >= 'A' && b[i][j] <= 'Z'){
					int r = i, c = j;
					for(int l = 0;l < k;l++){
						if(s[dl[l][0]][r][c] >= dl[l][1]){
							r += dr[dl[l][0]]*dl[l][1];
							c += dc[dl[l][0]]*dl[l][1];
							if(r >= 0 && r < n && c >= 0 && c < m){
							}else{
								continue outer;
							}
						}else{
							continue outer;
						}
					}
					ret[rp++] = b[i][j];
				}
			}
		}
		if(rp == 0){
			out.println("no solution");
			return;
		}
		ret = Arrays.copyOf(ret, rp);
		Arrays.sort(ret);
		out.println(new String(ret));
	}
	
	void run() throws Exception
	{
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}