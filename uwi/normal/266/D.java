//package round163;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D4 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int I = 100000000;
		int[][] d = new int[n][n];
		for(int i = 0;i < n;i++){
			Arrays.fill(d[i], I);
			d[i][i] = 0;
		}
		
		int[][] es = new int[m][];
		for(int i = 0;i < m;i++){
			int a = ni()-1, b = ni()-1, w = ni();
			es[i] = new int[]{a, b, w};
			d[a][b] = d[b][a] = Math.min(d[a][b], w);
		}
		for(int k = 0;k < n;k++){
			for(int i = 0;i < n;i++){
				for(int j = 0;j < n;j++){
					if(d[i][j] > d[i][k] + d[k][j]){
						d[i][j] = d[i][k] + d[k][j];
					}
				}
			}
		}
		
		double min = Double.POSITIVE_INFINITY;
		for(int i = 0;i < m;i++){
			// (0,s),(w,t)
			// s+x=t+(w-x)
			// x=(w+t-s)/2
			double[] xs = new double[n]; // peak x
			int[][] xss = new int[n][]; // peak x
			int[][] ss = new int[n][];
			int smax = 0, tmax = 0;
			for(int j = 0;j < n;j++){
				int s = d[es[i][0]][j], t = d[es[i][1]][j];
				xs[j] = (double)(es[i][2]+t-s) / 2;
				xss[j] = new int[]{es[i][2]+t-s, j};
				ss[j] = new int[]{s, j};
				smax = Math.max(smax, s);
				tmax = Math.max(tmax, t);
			}
			Arrays.sort(xss, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return a[0] - b[0];
				}
			});
			Arrays.sort(ss, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return -(a[0] - b[0]);
				}
			});
			int top = -1;
			int p = 0;
			boolean[] down = new boolean[n];
			int[] ys = new int[n+2];
			ys[0] = smax*2;
			ys[n+1] = tmax*2;
			for(int j = 0;j < n;j++){
				down[xss[j][1]] = true;
				if(top == -1 || xss[j][0]+d[es[i][0]][xss[j][1]]*2 > d[es[i][1]][top]*2 + (es[i][2]*2-xss[j][0])){
					top = xss[j][1];
				}
				int y = d[es[i][1]][top]*2 + (es[i][2]*2-xss[j][0]);
				while(p < n && down[ss[p][1]])p++;
				if(p != n){
					y = Math.max(y, d[es[i][0]][ss[p][1]]*2 + xss[j][0]);
				}
				ys[j+1] = y;
			}
//			tr(xss);
//			tr(ys);
			
			for(int j = 0;j < n+1;j++){
				// fl-d=fr-(D-d)
				// d=(fl-fr+D)/2, fl-d=(fl+fr-D)/2
				int wi = j == 0 ? xss[j][0] : (j == n ? es[i][2]-xss[j-1][0] : xss[j][0]-xss[j-1][0]);
				min = Math.min(min, (double)(ys[j]+ys[j+1]-wi)/4);
			}
			
		}
		for(int i = 0;i < n;i++){
			int smax = 0;
			for(int j = 0;j < n;j++){
				smax = Math.max(smax, d[i][j]);
			}
			min = Math.min(min, smax);
		}
		out.printf("%.3f\n", min);
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
	
	public static void main(String[] args) throws Exception { new D4().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}