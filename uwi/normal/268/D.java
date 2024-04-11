//package round164;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D2H5 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int mod = 1000000009;
		
		int[][][][] cur = new int[m+1][m+1][m+1][2];
		int[][][][] pre = new int[m+1][m+1][m+1][2];
		pre[0][0][0][1] = 1;
		for(int i = 0;i < n;i++){
			for(int j = 0;j <= m;j++){
				for(int k = j;k <= m;k++){
					for(int l = k;l <= m;l++){
						cur[j][k][l][0] = cur[j][k][l][1] = 0;
					}
				}
			}
			for(int j = 0;j <= m;j++){
				int nj = Math.min(j+1, m);
				for(int k = j;k <= m;k++){
					int nk = Math.min(k+1, m);
					for(int l = k;l <= m;l++){
						int nl = Math.min(l+1, m);
						if(pre[j][k][l][0] > 0){
							{
								cur[nj][nk][nl][0] += pre[j][k][l][0];
								if(cur[nj][nk][nl][0] >= mod)cur[nj][nk][nl][0] -= mod;
							}
							{
								int nv = j == m ? 0 : 1;
								cur[nk][nl][m][nv] += pre[j][k][l][0];
								if(cur[nk][nl][m][nv] >= mod)cur[nk][nl][m][nv] -= mod;
							}
							{
								int nv = k == m ? 0 : 1;
								cur[nj][nl][m][nv] += pre[j][k][l][0];
								if(cur[nj][nl][m][nv] >= mod)cur[nj][nl][m][nv] -= mod;
							}
							{
								int nv = l == m ? 0 : 1;
								cur[nj][nk][m][nv] += pre[j][k][l][0];
								if(cur[nj][nk][m][nv] >= mod)cur[nj][nk][m][nv] -= mod;
							}
						}
						if(pre[j][k][l][1] > 0){
							{
								cur[nj][nk][nl][1] += pre[j][k][l][1];
								if(cur[nj][nk][nl][1] >= mod)cur[nj][nk][nl][1] -= mod;
							}
							{
								int nv = j == m ? 0 : 1;
								cur[1][nk][nl][nv] += pre[j][k][l][1];
								if(cur[1][nk][nl][nv] >= mod)cur[1][nk][nl][nv] -= mod;
							}
							{
								int nv = k == m ? 0 : 1;
								cur[1][nj][nl][nv] += pre[j][k][l][1];
								if(cur[1][nj][nl][nv] >= mod)cur[1][nj][nl][nv] -= mod;
							}
							{
								int nv = l == m ? 0 : 1;
								cur[1][nj][nk][nv] += pre[j][k][l][1];
								if(cur[1][nj][nk][nv] >= mod)cur[1][nj][nk][nv] -= mod;
							}
						}
					}
				}
			}
			int[][][][] dum = pre; pre = cur; cur = dum;
		}
		long ret = 0;
		for(int j = 0;j <= m;j++){
			for(int k = j;k <= m;k++){
				for(int l = k;l <= m;l++){
					for(int v = 0;v < 2;v++){
						if(v == 0 && j == m && k == m && l == m)continue;
						ret += pre[j][k][l][v];
					}
				}
			}
		}
		out.println(ret%mod);
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
	
	public static void main(String[] args) throws Exception { new D2H5().run(); }
	
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