//package memsql.r2;
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
		int n = ni();
		int S = 3003;
		int[][] f = new int[S][S];
		for(int i = 0;i < S;i++){
			Arrays.fill(f[i], -1);
		}
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++){
			co[i] = na(4);
			for(int j = co[i][0];j < co[i][2];j++){
				for(int k = co[i][1];k < co[i][3];k++){
					f[j][k] = i;
				}
			}
		}
		
		
		int[][] imos = new int[S][S];
		for(int i = 1;i < S;i++){
			for(int j = 1;j < S;j++){
				imos[i][j] = imos[i-1][j] + imos[i][j-1] - imos[i-1][j-1] + (f[i-1][j-1] >= 0 ? 1 : 0);
			}
		}
		
		int[][] cr = new int[S][S];
		for(int i = 1;i <= S-1;i++){
			for(int j = 1;j <= S-1;j++){
				cr[i][j] = cr[i][j-1] + (f[i-1][j-1] == f[i][j-1] && f[i-1][j-1] >= 0 ? 1 : 0);
			}
		}
		int[][] cc = new int[S][S]; // 
		for(int i = 1;i <= S-1;i++){
			for(int j = 1;j <= S-1;j++){
				cc[j][i] = cc[j-1][i] + (f[j-1][i-1] == f[j-1][i] && f[j-1][i-1] >= 0 ? 1 : 0);
			}
		}
		
		for(int i = 0;i < n;i++){
			int x = co[i][0], y = co[i][1];
			for(int k = 1;;k++){
				if(imos[x+k][y+k] - imos[x][y+k] - imos[x+k][y] + imos[x][y] == k * k){
					if(!(cc[x+k][y] == cc[x][y] && cr[x][y+k] == cr[x][y])){
						break;
					}
					if(
							cc[x+k][y] == cc[x][y] && cc[x+k][y+k] == cc[x][y+k] && 
							cr[x][y+k] == cr[x][y] && cr[x+k][y+k] == cr[x+k][y]
									){
						
//						tr(x, y, k);
						int[] ok = new int[n];
						int p = 0;
						for(int j = 0;j < n;j++){
							if(x <= co[j][0] && co[j][2] <= x + k && y <= co[j][1] && co[j][3] <= y + k){
								ok[p++] = j;
							}
						}
						
						out.println("YES " + p);
						for(int j = 0;j < p;j++){
							if(j > 0)out.print(" ");
							out.print(ok[j]+1);
						}
						out.println();
						return;
					}
				}else{
					break;
				}
			}
		}
		out.println("NO");
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