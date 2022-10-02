//package yandex2011.finals;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		char[][] b = new char[n][m];
		for(int i = 0;i < n;i++){
			b[i] = in.next().toCharArray();
		}
		boolean[][] ok = new boolean[n][m];
		int[][] co = new int[14][2];
		int p = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(b[i][j] != '.' && !ok[i][j]){
					co[p][0] = i;
					co[p][1] = j;
					p++;
					for(int k = 0;k <= 1;k++){
						for(int l = 0;l <= 1;l++){
							ok[i+k][j+l] = true;
						}
					}
				}
			}
		}
		
		boolean[][] nei = new boolean[n][m];
		int[] dr = {1,-1,0,0};
		int[] dc = {0,0,-1,1};
		int[][] mino = new int[28][4];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(b[i][j] != '.' && !nei[i][j]){
					nei[i][j] = true;
					for(int k = 0;k < 4;k++){
						int nr = i + dr[k];
						int nc = j + dc[k];
						if(nr >= 0 && nr < n && nc >= 0 && nc < m && b[i][j] == b[nr][nc]){
							int cod = code(b[i][j]);
							mino[cod][0] = i;
							mino[cod][1] = j;
							mino[cod][2] = nr;
							mino[cod][3] = nc;
							nei[nr][nc] = true;
							break;
						}
					}
				}
			}
		}
		
		filled = new char[n][m];
		retf = new char[n][m];
		for(int i = 0;i < n;i++){
			Arrays.fill(filled[i], '.');
		}
		
		long ret = rec(b,n,m,co,0,0,new int[7], new int[14], mino);
		out.println(ret*5040);
		for(char[] q : retf){
			out.println(new String(q));
		}
	}
	
	int code(char c)
	{
		if(c == 'A')return 26;
		if(c == 'B')return 27;
		return c - 'a';
	}
	
	char[][] filled;
	char[][] retf;
	
	long rec(char[][] b, int n, int m, int[][] co, int pos, int sup, int[] used, int[] ar, int[][] mino)
	{
		if(pos == 14){
			long f = 0;
			for(int i = 0;i < 28;i++){
				int q = filled[mino[i][0]][mino[i][1]] - '0';
				int r = filled[mino[i][2]][mino[i][3]] - '0';
				long o = 1L<<(Math.min(q,r)*7+Math.max(q,r));
				if((f&o) != 0){
					return 0;
				}
				f |= o;
			}
			if(retf[0][0] == 0){
				for(int i = 0;i < n;i++){
					for(int j = 0;j < m;j++){
						retf[i][j] = filled[i][j];
					}
				}
			}
			return 1;
		}
		
		long u = 0;
		for(int i = 0;i <= sup;i++){
			if(used[i] < 2){
				used[i]++;
				ar[pos] = i;
				for(int j = 0;j <= 1;j++){
					for(int k = 0;k <= 1;k++){
						filled[co[pos][0]+j][co[pos][1]+k] = (char)('0'+i);
					}
				}
				u += rec(b,n,m,co,pos+1,sup+(i==sup&&sup<=5?1:0),used,ar, mino);
				used[i]--;
			}
		}
		
		return u;
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
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}