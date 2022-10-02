//package round170;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
			
	void solve()
	{
		int n = ni(), m = ni(), K = ni();
		int[][] cut = new int[K][];
		for(int i = 0;i < K;i++){
			cut[i] = new int[]{ni(), ni(), ni(), ni()};
		}
		
		int[][] vert = new int[K][];
		int[][] hori = new int[K][];
		int vp = 0, hp = 0;
		for(int i = 0;i < K;i++){
			if(cut[i][0] == cut[i][2]){
				vert[vp++] = new int[]{
						cut[i][0], 
						Math.min(cut[i][1], cut[i][3]), 
						Math.max(cut[i][1], cut[i][3])
				};
			}else{
				hori[hp++] = new int[]{
						cut[i][1],
						Math.min(cut[i][0], cut[i][2]),
						Math.max(cut[i][0], cut[i][2])
				};
			}
		}
		vert = Arrays.copyOf(vert, vp);
		hori = Arrays.copyOf(hori, hp);
		
		int nimv = process(vert, n, m);
		int nimh = process(hori, m, n);
		if((nimv^nimh) == 0){
			out.println("SECOND");
		}else{
			out.println("FIRST");
			int need = nimv^nimh;
			int[] ret = search(need, vert, n, m);
			if(ret != null){
				out.println(ret[0] + " " + ret[1] + " " + ret[0] + " " + ret[2]);
			}else{
				ret = search(need, hori, m, n);
				if(ret != null){
					out.println(ret[1] + " " + ret[0] + " " + ret[2] + " " + ret[0]);
				}else{
					throw new AssertionError();
				}
			}
		}
	}
	
	int[] search(int need, int[][] cut, int n, int m)
	{
		int u = cut.length;
		int pf = 0;
		for(int i = 0;i < u;){
			int j;
			for(j = i+1;j < u && cut[i][0] == cut[j][0];j++);
			int len = 0;
			{
				int prev = 0;
				for(int k = i;k < j;k++){
					if(cut[k][1] > prev){
						len += cut[k][1]-prev;
	//					if((len^need) <= len){
	//						return new int[]{cut[i][0], prev, prev+len-(len^need)};
	//					}
					}
					prev = Math.max(prev, cut[k][2]);
				}
				len += m-prev;
			}
			if(len > 0 && (len^need) < len){
				int del = len-(len^need);
				int len2 = 0;
				int prev = 0;
				for(int k = i;k < j;k++){
					if(cut[k][1] > prev){
						if(len2 + (cut[k][1]-prev) >= del){
							return new int[]{cut[i][0], 0, del-len2+prev};
						}
						len2 += cut[k][1]-prev;
					}
					prev = Math.max(prev, cut[k][2]);
				}
				if(len2 + (m-prev) >= del){
					return new int[]{cut[i][0], 0, del-len2+prev};
				}
				len2 += m-prev;
			}
			
//			{
//				int len = m-prev;
//				if(len > 0 && (len^need) <= len){
//					return new int[]{cut[i][0], prev, prev+len-(len^need)};
//				}
//			}
			
			// m^(m-x)=need
			// m-(m^need)
			if(cut[i][0]-pf > 1 && (m^need) <= m){
				return new int[]{cut[i][0]-1, 0, m-(m^need)};
			}else{
				pf = cut[i][0];
			}
			i = j;
		}
		if(pf < n-1 && (m^need) <= m){
			return new int[]{n-1, 0, m-(m^need)};
		}
		return null;
	}
	
	// x y
	int process(int[][] cut, int n, int m)
	{
		int u = cut.length;
		Arrays.sort(cut, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return a[1] - b[1];
			}
		});
		
		int row = 0;
		int nim = 0;
		for(int i = 0;i < u;){
			int j;
			for(j = i+1;j < u && cut[i][0] == cut[j][0];j++);
			int prev = 0;
			int len = 0;
			for(int k = i;k < j;k++){
				if(cut[k][1] > prev){
					len += cut[k][1]-prev;
//					nim ^= cut[k][1]-prev;
				}
				prev = Math.max(prev, cut[k][2]);
			}
			len += m-prev;
			nim ^= len;
//			nim ^= m-prev;
			
			i = j;
			row++;
		}
		
		if((n-1-row)%2 != 0){
			nim ^= m;
		}
		return nim;
	}
	
	void run() throws Exception
	{
//		int n = 1000000000, m = 1000000000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		int K = 100000;
//		sb.append(K + " ");
//		for(int i = 0;i < K/2;i++){
//			int x = gen.nextInt(n-1)+1;
//			sb.append(x + " ");
//			sb.append(gen.nextInt(m) + " ");
//			sb.append(x + " ");
//			sb.append(gen.nextInt(m) + " ");
//		}
//		for(int i = 0;i < K-K/2;i++){
//			int x = gen.nextInt(m-1)+1;
//			sb.append(gen.nextInt(n) + " ");
//			sb.append(x + " ");
//			sb.append(gen.nextInt(n) + " ");
//			sb.append(x + " ");
//		}
//		INPUT = sb.toString();
		
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