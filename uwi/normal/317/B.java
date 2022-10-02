//package round188;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), t = ni();
		int[][] co = new int[t][];
		for(int i = 0;i < t;i++){
			int x = ni(), y = ni();
			co[i] = new int[]{x, y};
		}
		
		int N = 66;
		int[][] pre = new int[N][N];
		int[][] cur = new int[N][N];
		pre[0][0] = n;
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		int[][] ved = new int[10000][];
		boolean[][] touch = new boolean[N][N];
		touch[0][0] = true;
		int p = 0;
		ved[p++] = new int[]{0, 0};
		for(int i = 0;;i++){
			boolean ouch = false;
			for(int j = 0;j < N;j++){
				Arrays.fill(cur[j], 0);
			}
			for(int j = p-1;j >= 0;j--){
				int r = ved[j][0], c = ved[j][1];
				if(pre[r][c] >= 4){
					ouch = true;
					cur[r][c] += pre[r][c] & 3;
					for(int l = 0;l < 4;l++){
						int nr = r + dr[l], nc = c + dc[l];
						if(nr >= 0 && nc >= 0){
							cur[nr][nc] += pre[r][c]>>>2;
							if(!touch[nr][nc]){
								touch[nr][nc] = true;
								ved[p++] = new int[]{nr, nc};
							}
						}
					}
					if(r == 1){
						cur[0][c] += pre[r][c]>>>2;
					}
					if(c == 1){
						cur[r][0] += pre[r][c]>>>2;
					}
				}else{
					cur[r][c] += pre[r][c];
				}
			}
			int[][] dum = pre; pre = cur; cur = dum;
			if(!ouch)break;
		}
		for(int i = 0;i < t;i++){
			int r = Math.abs(co[i][0]);
			int c = Math.abs(co[i][1]);
			if(r < 66 && c < 66){
				out.println(cur[r][c]);
			}else{
				out.println(0);
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
	
	public static void main(String[] args) throws Exception { new B2().run(); }
	
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
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
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
	
	private long nl()
	{
		long num = 0;
		int b;
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