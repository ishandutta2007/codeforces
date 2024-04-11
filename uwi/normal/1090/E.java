import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Queue;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	int[] dec(String s)
	{
		return new int[]{
				s.charAt(1)-'1',
				s.charAt(0)-'a',
		};
	}
	
	String enc(int[] a)
	{
		return "" + (char)('a'+a[1]) + (char)('1'+a[0]);
	}
	
	void solve()
	{
		int n = ni();
		int[][] b = new int[8][8];
		for(int i = 0;i < n;i++){
			int[] rc = dec(ns());
			b[rc[0]][rc[1]] = 1;
		}
		
		// .ooo
		// oo.o
		// ##oo
		
		List<String> ret = new ArrayList<>();
		for(int i = 0;i < 45 && i < n;i++){
			int tor = i/8;
			int toc = i%8;
			go(tor, toc, b, ret);
		}
		
		if(n >= 46){
			int ptn = 0;
			for(int i = 45;i < 64;i++){
				int r = i/8;
				int c = i%8;
				if(b[r][c] == 1){
					ptn |= 1<<i-45;
				}
				assert b[r][c] != 2;
			}
			
			int[] d = new int[1<<19];
			int[] prev = new int[1<<19];
			Arrays.fill(prev, -1);
			Arrays.fill(d, 99999999);
			d[(1<<n-45)-1] = 0;
			Queue<Integer> q = new ArrayDeque<>();
			q.add((1<<n-45)-1);
//			tr(Integer.bitCount(ptn), Integer.bitCount((1<<n-45)-1));
			outer:
			{
				while(!q.isEmpty()){
					int cur = q.poll();
					if(cur == ptn){
						while(true){
							int pre = prev[cur];
							if(pre == -1)break;
							// prev -> cur
							int ap = Integer.numberOfTrailingZeros(cur&~pre)+45;
							int da = Integer.numberOfTrailingZeros(pre&~cur)+45;
							
							assert b[ap/8][ap%8] == 1;
							assert b[da/8][da%8] == 0;
							b[ap/8][ap%8] = 0;
							b[da/8][da%8] = 1;
							ret.add(enc(new int[]{ap/8, ap%8}) + "-" + enc(new int[]{da/8, da%8}));
							cur = pre;
						}
						break outer;
					}
					for(int l = 0;l < 19;l++){
						if(cur<<~l<0){
							int r = (l+45)/8;
							int c = (l+45)%8;
							for(int k = 0;k < 8;k++){
								int nr = r + DRK[k], nc = c + DCK[k];
								if(nr >= 0 && nr < 8 && nc >= 0 && nc < 8 && nr*8+nc >= 45 && cur<<~(nr*8+nc-45)>=0){
									int ne = cur ^ 1<<l ^ 1<<nr*8+nc-45;
									if(d[ne] > d[cur] + 1){
										d[ne] = d[cur] + 1;
										prev[ne] = cur;
										q.add(ne);
									}
								}
							}
						}
					}
				}
				throw new RuntimeException();
			}
		}
		
//		for(int i = 0;i < n;i++){
//			int r = i / 8, c = i % 8;
//			assert b[r][c] >= 1;
//		}
		
//		tr(ret.size());
		assert ret.size() <= 1500;
		out.println(ret.size());
		for(String line : ret)out.println(line);
	}
	
	void go(int tor, int toc, int[][] b, List<String> ret)
	{
		Queue<int[]> q = new ArrayDeque<>();
		int[][] d = new int[8][8];
		int[][][] prev = new int[8][8][];
		for(int j = 0;j < 8;j++){
			Arrays.fill(d[j], 99999);
		}
		d[tor][toc] = 0;
		q.add(new int[]{tor, toc});
		while(!q.isEmpty()){
			int[] cur = q.poll();
			int r = cur[0], c = cur[1];
			if(b[r][c] == 1){
				b[r][c] = 0;
				b[tor][toc] = 2;
				while(true){
					int[] pre = prev[cur[0]][cur[1]];
					if(pre == null)break;
					
					ret.add(enc(cur) + "-" + enc(pre));
					cur = pre;
				}
				return;
			}
			for(int k = 0;k < 8;k++){
				int nr = r + DRK[k], nc = c + DCK[k];
				if(nr >= 0 && nr < 8 && nc >= 0 && nc < 8 &&
						b[nr][nc] != 2 && d[nr][nc] > d[r][c] + 1){
					d[nr][nc] = d[r][c] + 1;
					prev[nr][nc] = cur;
					q.add(new int[]{nr, nc});
				}
			}
		}
		throw new RuntimeException();
	}
	
	static int[] DRK = {-2,-2,-1,-1,1,1,2,2};
	static int[] DCK = {-1,1,-2,2,-2,2,-1,1};
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
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