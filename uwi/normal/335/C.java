//package memsql.r2;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int[][][] win = new int[102][4][4];
		win[1][1][1] = 1;
		win[1][2][2] = 1;
		win[1][3][3] = 1;
		win[2][1][1] = 0;
		win[2][2][2] = 0;
		win[2][1][3] = 2;
		win[2][3][1] = 2;
		win[2][2][3] = 2;
		win[2][3][2] = 2;
		win[2][3][3] = 0;
		win[2][1][2] = 1;
		win[2][2][1] = 1;
		for(int i = 3;i <= 101;i++){
			for(int j = 1;j <= 3;j++){
				for(int k = 1;k <= 3;k++){
					BitSet bs = new BitSet();
					if(j == 1 || j == 3){
						bs.set(win[i-1][1][k]);
					}
					if(j == 2 || j == 3){
						bs.set(win[i-1][2][k]);
					}
					if(k == 1 || k == 3){
						bs.set(win[i-1][j][1]);
					}
					if(k == 2 || k == 3){
						bs.set(win[i-1][j][2]);
					}
					if(i == 3){
						if(j == 1 || j == 3){
							if(k == 1 || k == 3){
								bs.set(win[1][1][1]^win[1][1][1]);
							}else{
								bs.set(win[1][1][1]);
							}
						}else{
							if(k == 1 || k == 3){
								bs.set(win[1][1][1]);
							}else{
								bs.set(0);
							}
						}
						
						if(j == 2 || j == 3){
							if(k == 2 || k == 3){
								bs.set(win[1][2][2]^win[1][2][2]);
							}else{
								bs.set(win[1][2][2]);
							}
						}else{
							if(k == 2 || k == 3){
								bs.set(win[1][2][2]);
							}else{
								bs.set(0);
							}
						}
					}else{
						for(int L = 0;L < i-2;L++){
							if(L >= 1 && L < i-3){
								bs.set(win[L+1][j][1]^win[i-L-2][1][k]);
							}else if(L == 0){
								if(j == 1 || j == 3){
									bs.set(win[1][1][1]^win[i-L-2][1][k]);
								}else{
									bs.set(win[i-L-2][1][k]);
								}
							}else{
								if(k == 1 || k == 3){
									bs.set(win[L+1][j][1]^win[1][1][1]);
								}else{
									bs.set(win[L+1][j][1]);
								}
							}
						}
						for(int L = 0;L < i-2;L++){
							if(L >= 1 && L < i-3){
								bs.set(win[L+1][j][2]^win[i-L-2][2][k]);
							}else if(L == 0){
								if(j == 2 || j == 3){
									bs.set(win[1][2][2]^win[i-L-2][2][k]);
								}else{
									bs.set(win[i-L-2][2][k]);
								}
							}else{
								if(k == 2 || k == 3){
									bs.set(win[L+1][j][2]^win[1][2][2]);
								}else{
									bs.set(win[L+1][j][2]);
								}
							}
						}
					}
					win[i][j][k] = bs.nextClearBit(0);
				}
			}
		}
		
		int n = ni(), q = ni();
		boolean[][] obs = new boolean[n][2];
		for(int i = 0;i < q;i++){
			int r = ni()-1, c = ni()-1;
			obs[r][c] = true;
			if(r-1 >= 0)obs[r-1][1-c] = true;
			obs[r][1-c] = true;
			if(r+1 < n)obs[r+1][1-c] = true;
		}
		
		int w = 0;
		for(int i = 0;i < n;i++){
			if(obs[i][0] && obs[i][1])continue;
			int j;
			for(j = i;j < n;j++){
				if(obs[j][0] && obs[j][1])break;
//				if(j > i && (obs[j-1][0]||obs[j][0])&&(obs[j-1][1]||obs[j][1]))break;
			}
			// [i,j)
//			if(j-i == 1){
//				if(
//			}
			int left = (!obs[i][0] ? 1 : 0) + (!obs[i][1] ? 2 : 0);
			int right = (!obs[j-1][0] ? 1 : 0) + (!obs[j-1][1] ? 2 : 0);
			int len = j-i;
//			l.add(new int[]{left, right, len});
			i = j-1;
//			tr(len, left, right);
			w ^= win[len][left][right];
		}
//		out.println(w);
		if(w != 0){
			out.println("WIN");
		}else{
			out.println("LOSE");
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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