//package round174;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int[] a;
	int n;
	
	void solve()
	{
		n = ni();
		a = new int[n];
		for(int i = 1;i < n;i++)a[i] = ni();
		
		// find cycle
		boolean[] ved = new boolean[2*n];
		int[] hist = new int[2*n];
		boolean[] cycle = new boolean[2*n];
		outer:
		for(int i = 1;i < 2*n;i++){
			if(!ved[i]){
				int hp = 0;
				for(int j = i;!ved[j];){
					ved[j] = true;
					hist[hp++] = j;
					
					j = next(j);
					if(j == -1){
						continue outer;
					}
					if(j == -2){
						for(int k = 0;k < hp;k++){
							cycle[hist[k]] = true;
						}
						continue outer;
					}
					if(ved[j]){
						if(cycle[j]){
							for(int k = 0;k < hp;k++){
								cycle[hist[k]] = true;
							}
							continue outer;
						}
						for(int k = 0;k < hp;k++){
							if(hist[k] == j){
								for(k = 0;k < hp;k++){
									cycle[hist[k]] = true;
								}
								continue outer;
							}
						}
						continue outer;
					}
				}
			}
		}
		
		int[] f = new int[2*n+1];
		for(int i = 1;i < 2*n;i++){
			int j = next(i);
			if(j < 0){
				f[i] = 2*n;
			}else{
				f[i] = j;
			}
		}
		int[][] ig = invF(f);
		
		Queue<Integer> q = new ArrayDeque<Integer>();
		q.add(2*n);
		long[] dp = new long[2*n+1];
		Arrays.fill(dp, Long.MIN_VALUE / 100);
		dp[2*n] = 0;
		while(!q.isEmpty()){
			int cur = q.poll();
			if(ig[cur] == null)continue;
			for(int e : ig[cur]){
				dp[e] = dp[cur] + a[e%n];
				q.add(e);
			}
		}
		for(int i = 1;i < 2*n;i++){
			if(cycle[i]){
				dp[i] = -1;
			}else{
				dp[i] += i % n;
			}
		}
		
		for(int i = n+1;i < 2*n;i++){
			out.println(dp[i]);
			if(dp[i] < -1){
				throw new AssertionError();
			}
		}
	}
	
	public static int[][] invF(int[] g)
	{
		int n = g.length;
		int[] p = new int[n];
		for(int f = 0;f < n;f++)p[g[f]]++;
		int[][] r = new int[n][];
		for(int i = 0;i < n;i++)if(p[i] > 0)r[i] = new int[p[i]];
		for(int f = n-1;f >= 0;f--)r[g[f]][--p[g[f]]] = f;
		return r;
	}
	
	int next(int j)
	{
		if(j == 0){
			return -2;
		}else if(j == n){
			return -1;
		}else if(j < n){
			int v = j + a[j];
			if(v >= n){
				return -1;
			}else{
				return v+n;
			}
		}else{
			int v = j-n - a[j-n];
			if(v < 0){
				return -1;
			}else{
				return v;
			}
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
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
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