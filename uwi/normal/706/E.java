//package round367;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), Q = ni();
		int[][] map = new int[n][];
		for(int i = 0;i < n;i++)map[i] = na(m);
		
		DancingNode[][] dns = new DancingNode[n+2][m+2];
		for(int i = 0;i < n+2;i++){
			for(int j = 0;j < m+2;j++){
				dns[i][j] = new DancingNode();
				if(i > 0 && i < n+1 && j > 0 && j < m+1){
					dns[i][j].v = map[i-1][j-1];
				}
			}
		}
		
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		for(int i = 0;i < n+2;i++){
			for(int j = 0;j < m+2;j++){
				for(int k = 0;k < 2;k++){
					int ni = i + dr[k], nj = j + dc[k];
					if(ni >= 0 && ni < n+2 && nj >= 0 && nj < m+2){
						if(k == 0){
							dns[i][j].d = dns[ni][nj];
						}else{
							dns[i][j].r = dns[ni][nj];
						}
					}
				}
			}
		}
		for(int z = 0;z < Q;z++){
			int a = ni(), b = ni(), c = ni(), d = ni();
			int h = ni(), w = ni();
			DancingNode[] ad = make(dns, a, b, h, w);
			DancingNode[] cd = make(dns, c, d, h, w);
			for(int i = 0;i < 2*w;i++){
				DancingNode A = ad[i], B = ad[i].d, C = cd[i], D = cd[i].d;
				A.d = D;
				C.d = B;
			}
			for(int i = 2*w;i < 2*w+2*h;i++){
				DancingNode A = ad[i], B = ad[i].r, C = cd[i], D = cd[i].r;
				A.r = D;
				C.r = B;
			}
		}
		for(int i = 1;i < n+1;i++){
			DancingNode cur = dns[i][0];
			for(int j = 0;j < m;j++){
				cur = cur.r;
				out.print(cur.v + " ");
			}
			out.println();
		}
	}
	
	DancingNode[] make(DancingNode[][] dns, int a, int b, int h, int w)
	{
		DancingNode[] ad = new DancingNode[2*h+2*w];
		int p = 0;
		DancingNode cur = dns[0][b];
		for(int i = 0;i < a-1;i++)cur = cur.d;
		for(int i = 0;i < w;i++){
			ad[p++] = cur;
			cur = cur.r;
		}
		cur = dns[0][b];
		for(int i = 0;i < a+h-1;i++)cur = cur.d;
		for(int i = 0;i < w;i++){
			ad[p++] = cur;
			cur = cur.r;
		}
		cur = dns[a][0];
		for(int i = 0;i < b-1;i++)cur = cur.r;
		for(int i = 0;i < h;i++){
			ad[p++] = cur;
			cur = cur.d;
		}
		cur = dns[a][0];
		for(int i = 0;i < b+w-1;i++)cur = cur.r;
		for(int i = 0;i < h;i++){
			ad[p++] = cur;
			cur = cur.d;
		}
		assert p == ad.length;
		return ad;
	}
	
	static class DancingNode
	{
		int v;
		DancingNode d, r;
	}
	
	void run() throws Exception
	{
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		int n = 1000;//gen.nextInt(50)+3;
//		int m = 1000;//gen.nextInt(50)+3;
//		int Q = 10000;//gen.nextInt(50)+1;
//		sb.append(n + " ");
//		sb.append(m + " ");
//		sb.append(Q + "\n");
//		for(int i = 0;i < n*m;i++){
//			sb.append(gen.nextInt(1000) + 1 + " ");
//		}
//		for(int i = 0;i < Q;i++){
//			outer:
//			while(true){
//				int a = gen.nextInt(n)+1;
//				int b = gen.nextInt(m)+1;
//				int c = gen.nextInt(n)+1;
//				int d = gen.nextInt(m)+1;
//				int h = gen.nextInt(n/2)+1;
//				int w = gen.nextInt(m/2)+1;
//				if(a+h <= n+1 && c+h <= n+1 && b+w <= m+1 && d+w <= m+1){
//					boolean[][] x = new boolean[n][m];
//					for(int j = -1;j <= h;j++){
//						for(int k = -1;k <= w;k++){
//							if((j == -1 || j == h) && (k == -1 || k == w))continue;
//							if(a+j-1 >= 0 && a+j-1 < n && b+k-1 >= 0 && b+k-1 < m){
//								x[a+j-1][b+k-1] = true;
//							}
//						}
//					}
//					for(int j = 0;j < h;j++){
//						for(int k = 0;k < w;k++){
//							if(x[c+j-1][d+k-1])continue outer;
//						}
//					}
//					sb.append(a + " ");
//					sb.append(b + " ");
//					sb.append(c + " ");
//					sb.append(d + " ");
//					sb.append(h + " ");
//					sb.append(w + "\n");
//					break outer;
//				}
//			}
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E3().run(); }
	
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