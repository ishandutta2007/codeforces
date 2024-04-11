//package round157;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] a = na(n);
		int[] ia = new int[n+1];
		for(int i = 0;i < n;i++){
			ia[a[i]] = i;
		}
		int[][] sw = new int[m][];
		for(int i = 0;i < m;i++){
			sw[i] = new int[]{ni(), ni()};
		}
		
		double[][] inv = new double[n+1][n+1];
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				if(a[i-1] > a[j-1]){
					inv[j][i] = inv[i][j] = 1;
				}
			}
		}
		
//		for(double[] row : inv){
//			tr(row);
//		}
		for(int i = 0;i < m;i++){
			int x = sw[i][0], y = sw[i][1];
			for(int j = 1;j <= n;j++){
				if(j != x && j != y){
					if(j < x && j < y || j > x && j > y){
						double plus = (inv[j][x] * (1 - inv[j][y]) - inv[j][y] * (1 - inv[j][x]))/2;
						inv[j][x] -= plus;
						inv[x][j] = inv[j][x];
						inv[j][y] += plus;
						inv[y][j] = inv[j][y];
					}else{
						double nx = inv[j][x] / 2 + (1-inv[j][y]) / 2;
						double ny = (1-inv[j][x]) / 2 + inv[j][y] / 2;
						inv[j][x] = inv[x][j] = nx;
						inv[j][y] = inv[y][j] = ny;
					}
				}
			}
			inv[x][y] = inv[y][x] = 0.5;
//			for(double[] row : inv){
//				tr(row);
//			}
//			tr();
		}
		
		double E = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				E += inv[i][j];
			}
		}
		out.printf("%.9f\n", E);
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
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