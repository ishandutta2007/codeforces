//package round354;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		int n = ni(), m = ni();
		char[][] map = nm(n,m);
		int[][] pm = new int[n][m];
		String T = "+-|^><vLRUD*";
		int[] ptns = {
				0, 5, 10, 11, 13, 7, 14, 8, 2, 4, 1, 15
		};
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				pm[i][j] = ptns[T.indexOf(map[i][j])];
			}
		}
		int sr = ni()-1, sc = ni()-1;
		int tr = ni()-1, tc = ni()-1;
		
		int[] d = new int[1<<22];
		int I = 999999999;
		Arrays.fill(d, I);
		
		Queue<Integer> q = new ArrayDeque<Integer>();
		q.add(sr<<12|sc<<2|0);
		d[sr<<12|sc<<2|0] = 0;
		
		while(!q.isEmpty()){
			int cur = q.poll();
			int r = cur>>>12, c = cur>>>2&1023, rot = cur&3;
			for(int k = 0, kk = k+rot&3;k < 4;k++,kk++) {
				if(kk == 4)kk = 0;
				if(pm[r][c]<<~kk<0)continue;
				int nr = r + dr[k];
				int nc = c + dc[k];
				if(nr >= 0 && nr < n && nc >= 0 && nc < m && 
						pm[nr][nc]<<~(kk^2)>=0){
					int nex = nr<<12|nc<<2|rot;
					if(d[nex] > d[cur] + 1){
						d[nex] = d[cur] + 1;
						q.add(nex);
					}
				}
			}
			{
				int nex = r<<12|c<<2|(rot+1&3);
				if(d[nex] > d[cur] + 1){
					d[nex] = d[cur] + 1;
					q.add(nex);
				}
			}
		}
		int ret = I;
		for(int k = 0;k < 4;k++){
			ret = Math.min(ret, d[tr<<12|tc<<2|k]);
		}
		out.println(ret >= I ? -1 : ret);
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