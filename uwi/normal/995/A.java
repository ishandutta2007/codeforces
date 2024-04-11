//package round492;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Random;

public class A {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int m = ni(), K = ni();
		int[][] a = new int[4][];
		for(int i = 0;i < 4;i++){
			a[i] = na(m);
		}
		List<String> ret = new ArrayList<>();
		for(int i = 0;i < m;i++){
			if(a[1][i] > 0 && a[1][i] == a[0][i]){
				ret.add(a[1][i] + " " + 1 + " " + (i+1));
				a[0][i] = a[1][i] = 0;
			}
			if(a[2][i] > 0 && a[2][i] == a[3][i]){
				ret.add(a[2][i] + " " + 4 + " " + (i+1));
				a[3][i] = a[2][i] = 0;
			}
		}
		int spr = -1, spc = -1;
		for(int i = 1;i < 3;i++){
			for(int j = 0;j < m;j++){
				if(a[i][j] == 0){
					spr = i; spc = j;
				}
			}
		}
		if(spr == -1){
			out.println(-1);
			return;
		}
		
		int[] sp = {spr, spc};
		
		for(int i = 0;i < m;i++){
			if(a[0][i] != 0){
				for(int j = 0;j < m;j++){
					if(a[1][j] == a[0][i]){
						move(1, j, 1, i, a, sp, ret);
						break;
					}
					if(a[2][j] == a[0][i]){
						move(2, j, 1, i, a, sp, ret);
						break;
					}
				}
				ret.add(a[1][i] + " " + 1 + " " + (i+1));
				a[0][i] = a[1][i] = 0;
			}
		}
		for(int i = 0;i < m;i++){
			if(a[3][i] != 0){
				for(int j = 0;j < m;j++){
					if(a[1][j] == a[3][i]){
						move(1, j, 2, i, a, sp, ret);
						break;
					}
					if(a[2][j] == a[3][i]){
						move(2, j, 2, i, a, sp, ret);
						break;
					}
				}
				ret.add(a[2][i] + " " + 4 + " " + (i+1));
				a[3][i] = a[2][i] = 0;
			}
		}
		
		if(ret.size() > 20000){
			throw new RuntimeException();
		}
		out.println(ret.size());
		for(String line : ret){
			out.println(line);
		}
	}
	
	void move(int sr, int sc, int tr, int tc, int[][] a, int[] sp, List<String> ret)
	{
		if(sr != tr){
			movesp(sp, 3-sr, sc, sr, sc, a, ret);
			movesp(sp, sr, sc, -1, -1, a, ret);
			sr = 3-sr;
		}
		while(tc < sc){
			movesp(sp, tr, sc-1, sr, sc, a, ret);
			movesp(sp, tr, sc, -1, -1, a, ret);
			sc--;
		}
		while(tc > sc){
			movesp(sp, tr, sc+1, sr, sc, a, ret);
			movesp(sp, tr, sc, -1, -1, a, ret);
			sc++;
		}
		assert a[tr][tc] == a[tr^1][tc];
	}
	
	void movesp(int[] sp, int tr, int tc, int ngr, int ngc, int[][] a, List<String> ret)
	{
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		outer:
		while(!(sp[0] == tr && sp[1] == tc)){
//			tr(sp, tr, tc, ngr, ngc);
			for(int k = 0;k < 4;k++){
				int nr = sp[0] + dr[k], nc = sp[1] + dc[k];
				if(nr == ngr && nc == ngc)continue;
				if(Math.abs(sp[0]-tr)+Math.abs(sp[1]-tc) > 
				Math.abs(nr-tr) + Math.abs(nc-tc)){
					if(a[nr][nc] > 0){
						ret.add(a[nr][nc] + " " + (sp[0]+1) + " " + (sp[1]+1));
						a[sp[0]][sp[1]] = a[nr][nc];
						a[nr][nc] = 0;
					}
					sp[0] = nr;
					sp[1] = nc;
					continue outer;
				}
			}
			
			int kk = -1;
			for(int k = 0;k < 4;k++){
				int nr = sp[0] + dr[k], nc = sp[1] + dc[k];
				if(nr == ngr && nc == ngc){
					kk = k;
				}
			}
			
			{
				int nr = 3-sp[0], nc = sp[1];
				if(a[nr][nc] > 0){
					ret.add(a[nr][nc] + " " + (sp[0]+1) + " " + (sp[1]+1));
					a[sp[0]][sp[1]] = a[nr][nc];
					a[nr][nc] = 0;
				}
				sp[0] = nr;
				sp[1] = nc;
			}
			{
				int nr = sp[0] + dr[kk], nc = sp[1] + dc[kk];
				if(a[nr][nc] > 0){
					ret.add(a[nr][nc] + " " + (sp[0]+1) + " " + (sp[1]+1));
					a[sp[0]][sp[1]] = a[nr][nc];
					a[nr][nc] = 0;
				}
				sp[0] = nr;
				sp[1] = nc;
			}
		}
	}
	
	public static int[] shuffle(int n, Random gen){ int[] a = new int[n]; for(int i = 0;i < n;i++)a[i] = i; for(int i = 0;i < n;i++){ int ind = gen.nextInt(n-i)+i; int d = a[i]; a[i] = a[ind]; a[ind] = d; } return a; }

	
	void run() throws Exception
	{
//		int n = 50, m = 99;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(i + " ");
//		}
//		int[] a = shuffle(2*n, gen);
//		for (int i = 0; i < 2*n; i++) {
//			sb.append(a[i] + " ");
//		}
//		for (int i = 0; i < n; i++) {
//			sb.append(i+n + " ");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new A().run(); }
	
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