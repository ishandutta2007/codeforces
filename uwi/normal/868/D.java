//package round438;
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
		int M = 11;
		int n = ni();
		char[][] ss = new char[n][];
		for(int i = 0;i < n;i++){
			ss[i] = ns().toCharArray();
		}
		char[][] prefs = new char[n+100][];
		char[][] suffs = new char[n+100][];
		boolean[][][] ptns = new boolean[n+100][M+1][1<<M];
		for(int i = 0;i < n;i++){
			prefs[i] = Arrays.copyOf(ss[i], Math.min(M, ss[i].length));
			suffs[i] = Arrays.copyOfRange(ss[i], Math.max(0, ss[i].length-M), ss[i].length);
			for(int j = 1;j <= M;j++){
				for(int k = 0;k+j <= ss[i].length;k++){
					int h = 0;
					for(int l = k;l < k+j;l++){
						h = h<<1|ss[i][l]-'0';
					}
					ptns[i][j][h] = true;
				}
			}
//			tf(Arrays.copyOf(ptns[i], 5));
		}
//		tr(prefs, suffs);
		for(int Q = ni(), u = n;Q > 0;Q--,u++){
			int x = ni()-1, y = ni()-1;
			for(int j = 1;j <= M;j++){
				for(int k = 0;k < 1<<M;k++){
					ptns[u][j][k] = ptns[x][j][k] | ptns[y][j][k];
				}
				for(int f = 1;f < j;f++){
					int b = j-f;
					if(suffs[x].length-f < 0 || b > prefs[y].length)continue;
					int h = 0;
					for(int k = suffs[x].length-f;k < suffs[x].length;k++){
						h = h<<1|suffs[x][k]-'0';
					}
					for(int k = 0;k < b;k++){
						h = h<<1|prefs[y][k]-'0';
					}
					ptns[u][j][h] = true;
				}
			}
			int ans = 0;
			inner:
			for(int j = 1;j <= M;j++){
				for(int k = 0;k < 1<<j;k++){
					if(!ptns[u][j][k]){
						out.println(ans);
						break inner;
					}
				}
				ans++;
			}
			
			// merge
			prefs[u] = Arrays.copyOf(prefs[x], Math.min(prefs[x].length + prefs[y].length, M));
			for(int i = 0;i < prefs[y].length && i+prefs[x].length < M;i++){
				prefs[u][i+prefs[x].length] = prefs[y][i];
			}

			suffs[u] = Arrays.copyOf(suffs[x], suffs[x].length + suffs[y].length);
			for(int i = 0;i < suffs[y].length;i++){
				suffs[u][i+suffs[x].length] = suffs[y][i];
			}
			suffs[u] = Arrays.copyOfRange(suffs[u], Math.max(0, suffs[u].length-M), suffs[u].length);
		}
	}
	
	public static void tf(boolean[]... b)
	{
		for(boolean[] r : b) {
			for(boolean x : r)System.out.print(x?'#':'.');
			System.out.println();
		}
		System.out.println();
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
	public int lenbuf = 0, ptrbuf = 0;
	
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