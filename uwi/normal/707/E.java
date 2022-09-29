//package round368;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), K = ni();
		int[][] inds = new int[n*2+3][m*2+3];
		for(int i = 0;i < n*2+3;i++){
			Arrays.fill(inds[i], -1);
		}
//		int[][] firsts = new int[K][];
		int[][] lasts = new int[K][];
		int[] lens = new int[K];
		long[][] cums = new long[K][];
		for(int i = 0;i < K;i++){
			int L = ni();
			lens[i] = L;
			int[] a = new int[L];
			int pr = -1, pc = -1;
			for(int j = 0;j < L;j++){
				int r = ni()-1, c = ni()-1, v = ni();
//				if(j == 0){
//					firsts[i] = new int[]{r, c};
//				}
				if(j == L-1){
					lasts[i] = new int[]{r, c};
				}
				a[j] = v;
				inds[r*2+1][c*2+1] = i;
				if(j > 0){
					int di = r+c >= pr+pc ? 1 : 0;
					inds[pr+r+1][pc+c+1] = j-1<<1|di;
				}
				pr = r; pc = c;
			}
			long[] cum = new long[L+1];
			for(int j = 0;j < L;j++){
				cum[j+1] = cum[j] + a[j];
			}
			cums[i] = cum;
		}
		
		boolean[] garon = new boolean[K];
		Arrays.fill(garon, true);
		for(int Q = ni();Q > 0;Q--){
			String com = ns();
			if(com.charAt(0) == 'A'){
				int r1 = ni()-1, c1 = ni()-1;
				int r2 = ni()-1, c2 = ni()-1;
				long ret = 0;
				for(int c = c1;c <= c2;c++){
					int ind = inds[r1*2+1-1][c*2+1]; 
					if(ind != -1){
						int id = ind>>>1;
						int di = ind&1;
						int gid = inds[r1*2+1][c*2+1];
						if(garon[gid]){
							if(di == 1){
								ret -= cums[gid][id+1];
							}else{
								ret += cums[gid][id+1];
							}
						}
					}
				}
				for(int c = c1;c <= c2;c++){
					int ind = inds[r2*2+1+1][c*2+1]; 
					if(ind != -1){
						int id = ind>>>1;
						int di = ind&1;
						int gid = inds[r2*2+1][c*2+1];
						if(garon[gid]){
							if(di == 1){
								ret += cums[gid][id+1];
							}else{
								ret -= cums[gid][id+1];
							}
						}
					}
				}
				for(int r = r1;r <= r2;r++){
					int ind = inds[r*2+1][c1*2+1-1];
					if(ind != -1){
						int id = ind>>>1;
						int di = ind&1;
						int gid = inds[r*2+1][c1*2+1];
						if(garon[gid]){
							if(di == 1){
								ret -= cums[gid][id+1];
							}else{
								ret += cums[gid][id+1];
							}
						}
					}
				}
				for(int r = r1;r <= r2;r++){
					int ind = inds[r*2+1][c2*2+1+1];
					if(ind != -1){
						int id = ind>>>1;
						int di = ind&1;
						int gid = inds[r*2+1][c2*2+1];
						if(garon[gid]){
							if(di == 1){
								ret += cums[gid][id+1];
							}else{
								ret -= cums[gid][id+1];
							}
						}
					}
				}
				for(int j = 0;j < K;j++){
					if(garon[j] && 
							r1 <= lasts[j][0] && lasts[j][0] <= r2 &&
							c1 <= lasts[j][1] && lasts[j][1] <= c2){
						ret += cums[j][cums[j].length-1];
					}
				}
				out.println(ret);
			}else if(com.charAt(0) == 'S'){
				int id = ni()-1;
				garon[id] ^= true;
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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