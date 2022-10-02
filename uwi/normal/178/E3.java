//package abbyy2.hard;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;


public class EH2 {
	BufferedReader br;
	PrintWriter out;
	String INPUT = "";
	
	void solve() throws Exception
	{
		int n = Integer.parseInt(br.readLine());
		DJSet ds = new DJSet(n*n);
//		long S = System.currentTimeMillis();
		int[][] pp = new int[n][n];
		int[][] p = new int[n][n];
		for(int i = 0;i < n;i++){
			String line = br.readLine();
			for(int j = 0;j < n;j++){
				pp[i][j] = line.charAt(j*2)-'0';
			}
		}
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				int ct = 0;
				int all = 0;
				for(int k = -1;k <= 1;k++){
					for(int l = -1;l <= 1;l++){
						if(k == 0 && l == 0)continue;
						int nx = i+k, ny = j+l;
						if(nx >= 0 && nx < n && ny >= 0 && ny < n){
							all++;
							ct += pp[nx][ny];
						}
					}
				}
				if(ct > all/2+1){
					p[i][j] = 1;
				}else if(ct < all/2-1){
					p[i][j] = 0;
				}else{
					p[i][j] = pp[i][j];
				}
			}
		}
		
//		tr(System.currentTimeMillis() - S);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n-1;j++){
				if(p[i][j] == 1 && p[i][j+1] == 1){
					ds.union(i*n+j, i*n+(j+1));
				}
			}
		}
		for(int i = 0;i < n-1;i++){
			for(int j = 0;j < n;j++){
				if(p[i][j] == 1 && p[i+1][j] == 1){
					ds.union(i*n+j, (i+1)*n+j);
				}
			}
		}
		double[][] cent = new double[n*n][2];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				int clus = ds.root(i*n+j);
				cent[clus][0] += i;
				cent[clus][1] += j;
			}
		}
//		tr(System.currentTimeMillis() - S);
		
		Map<Integer, Integer> ics = new HashMap<Integer, Integer>();
		int[] nums = new int[100];
		int q = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(ds.upper[i*n+j] < -100){
					int num = -ds.upper[i*n+j];
					int clus = i*n+j;
					cent[clus][0] /= num;
					cent[clus][1] /= num;
					nums[q] = num;
					ics.put(clus, q++);
				}
			}
		}
		
		int N = 9;
		double[][] max = new double[q][N];
		double[] v = new double[q];
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(ds.upper[ds.root(i*n+j)] < -100){
					int clus = ds.root(i*n+j);
					int id = ics.get(clus);
					double D = (i-cent[clus][0])*(i-cent[clus][0])+(j-cent[clus][1])*(j-cent[clus][1]);
					for(int k = 0;k <= N-1;k++){
						if(D > max[id][k]){
							for(int l = N-2;l >= k;l--){
								max[id][l+1] = max[id][l];
							}
							max[id][k] = D;
						}
					}
					v[id] += D;
				}
			}
		}
		
		int cir = 0, sq = 0;
		for(int i = 0;i < q;i++){
			v[i] /= nums[i];
			if(v[i] > 13*max[i][0]/36){
				cir++;
			}else{
				sq++;
			}
		}
		out.println(cir + " " + sq);
	}
	
	public static class DJSet { public int[] upper; public DJSet(int n){ upper = new int[n]; Arrays.fill(upper, -1);} public int root(int x){	return upper[x] < 0 ? x : (upper[x] = root(upper[x]));}	public boolean equiv(int x, int y){ return root(x) == root(y);} public void union(int x, int y){ x = root(x);y = root(y);if(x != y) { if(upper[y] < upper[x]) { int d = x; x = y; y = d;	} upper[x] += upper[y]; upper[y] = x;}} public int count(){	int ct = 0;	for(int i = 0;i < upper.length;i++){ if(upper[i] < 0)ct++; } return ct; }}
	
	void run() throws Exception
	{
		long S = System.currentTimeMillis();
		br = new BufferedReader(INPUT.isEmpty() ? new InputStreamReader(System.in) : new StringReader(INPUT));
//		br = new BufferedReader(new InputStreamReader(new FileInputStream(new File("x:\\hard_2.in"))));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
		long G = System.currentTimeMillis();
		tr(G-S+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new EH2().run();
	}
	
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}