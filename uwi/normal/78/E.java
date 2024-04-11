//package round70;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class E {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int t = ni();
		char[][] map = new char[n][n]; // initial map
		char[][][] dmap = new char[t+1][n][n]; // dead map
		char[][] hmap = new char[n][n]; // hazard map
		int ct = 0, cct = 0;
		for(int i = 0;i < n;i++){
			map[i] = in.next().toCharArray();
			dmap[0][i] = Arrays.copyOf(map[i], n);
			for(int j = 0;j < n;j++){
				if(map[i][j] >= '1' && map[i][j] <= '9'){
					ct += map[i][j] - '0';
				}
			}
		}
		for(int i = 0;i < n;i++){
			hmap[i] = in.next().toCharArray();
			for(int j = 0;j < n;j++){
				if(hmap[i][j] >= '1' && hmap[i][j] <= '9'){
					cct += hmap[i][j] - '0';
				}
			}
		}
		
		int[] dr = {1,0,-1,0,0};
		int[] dc = {0,1,0,-1,0};
		for(int i = 1;i <= t;i++){
			for(int j = 0;j < n;j++){
				for(int k = 0;k < n;k++){
					if(dmap[i-1][j][k] == 'Z'){
						for(int l = 0;l < 5;l++){
							int nr = j + dr[l];
							int nc = k + dc[l];
							if(nr >= 0 && nr < n && nc >= 0 && nc < n && map[nr][nc] != 'Y'){
								dmap[i][nr][nc] = 'Z';
							}
						}
					}
				}
			}
//			tr(dmap[i]);
		}
		
		boolean[][] g = new boolean[n*n][n*n];
		BitSet[][][] alive = new BitSet[2][n*n][n*n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				alive[0][i][j] = new BitSet();
				alive[1][i][j] = new BitSet();
				if(map[i][j] >= '1' && map[i][j] <= '9'){
					alive[0][i][j].set(i*n+j);
				}
			}
		}
		
//		for(int i = 0;i < n;i++){
//			for(int j = 0;j < n;j++){
//				if(hmap[i][j] >= '1' && hmap[i][j] <= '9'){
//					for(int l = alive[0][i][j].nextSetBit(0);l != -1;l = alive[0][i][j]
//							.nextSetBit(l + 1)){
//						g[l][i*n+j] = true;
//					}
//				}
//			}
//		}
		for(int k = 0, w = 0;k < t;k++, w^=1){
			for(int i = 0;i < n;i++){
				for(int j = 0;j < n;j++){
					alive[w^1][i][j].clear();
				}
			}
			for(int i = 0;i < n;i++){
				for(int j = 0;j < n;j++){
					if(k == 0 || dmap[k][i][j] != 'Z'){
						for(int l = 0;l < 5;l++){
							int nr = i + dr[l];
							int nc = j + dc[l];
							if(nr >= 0 && nr < n && nc >= 0 && nc < n && map[nr][nc] != 'Y' && dmap[k][nr][nc] != 'Z'){
								alive[w^1][nr][nc].or(alive[w][i][j]);
//								if(alive[w^1][nr][nc].get(8)){
//									tr(k, nr, nc);
//								}
							}
						}
					}
				}
			}
			for(int i = 0;i < n;i++){
				for(int j = 0;j < n;j++){
					if(hmap[i][j] >= '1' && hmap[i][j] <= '9'){
						for(int l = alive[w^1][i][j].nextSetBit(0);l != -1;l = alive[w^1][i][j]
								.nextSetBit(l + 1)){
							g[l][i*n+j] = true;
						}
					}
				}
			}
		}
//		for(int i = 0;i < n*n;i++){
//			tr(g[i]);
//		}
		
		int[] indc = new int[n*n+1];
		int[] inds = new int[n*n+1];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				indc[i*n+j+1] = indc[i*n+j] + (hmap[i][j] >= '1' && hmap[i][j] <= '9' ? hmap[i][j]-'0' : 0);
				inds[i*n+j+1] = inds[i*n+j] + (map[i][j] >= '1' && map[i][j] <= '9' ? map[i][j]-'0' : 0);
			}
		}
		
		boolean[][] lg = new boolean[ct][cct];
		for(int i = 0;i < n*n;i++){
			for(int j = 0;j < n*n;j++){
				if(g[i][j]){
					for(int k = inds[i];k < inds[i+1];k++){
						for(int l = indc[j];l < indc[j+1];l++){
							lg[k][l] = true;
						}
					}
				}
			}
		}
//		tr(lg);
		
		out.println(doBipartiteMatching(lg));
	}
	
	public static int doBipartiteMatching(boolean[][] g)
	{
		if(g.length == 0)return 0;
		if(g[0].length == 0)return 0;
		
		int n = g.length;
		int m = g[0].length;
		int[] im = new int[m];
		Arrays.fill(im, -1);
		for(int i = 0;i < n;i++){
			BitSet visited = new BitSet();
			visit(g, i, visited, im);
		}

		int ct = 0;
		for(int i = 0;i < m;i++){
			if(im[i] != -1)ct++;
		}
		return ct;
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
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new E().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}