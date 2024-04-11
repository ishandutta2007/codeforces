//package educational.round73;
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
	
	void pyn(boolean x)
	{
		out.println(x ? "YES" : "NO");
	}
	
	void solve()
	{
		for(int T = ni();T > 0;T--){
			int a = ni(), b = ni();
			char[] s = ns().toCharArray();
			int[][] uc = uniqcount(s);
			int bw = 0;
			int aw = 0;
			for(int[] u : uc){
				if(u[0] == '.' && u[1] >= b){
					bw++;
					if(u[1] >= a){
						aw++;
					}
				}
			}
			// 4 6 4
			
			if(bw - aw > 0 || aw == 0){
				out.println("NO");
				continue;
			}
			
			int[] q = new int[uc.length];
			int p = 0;
			for(int[] u : uc){
				if(u[0] == '.' && u[1] >= a){
					q[p++] = u[1];
				}
			}
			q = Arrays.copyOf(q, p);
			Arrays.sort(q);
			
			if(aw % 2 == 0){
//				// (4,8)-(5,11) 4,3
//				// (5,10)-(7,15) 5,4
//				// (5,10)-(5,12) 5,3
				int v = q[q.length-1];
				int win = 0;
				if(a*2 <= v && v <= a+b*3-2){
					win++;
				}
				for(int i = 0;i < q.length-1;i++){
					if(a <= q[i] && q[i] <= 2*b-1){
						win++;
					}
				}
				pyn(win == p);
			}else{
				int v = q[q.length-1];
				int win = 0;
				if(a <= v && v <= a+2*b-2){
					win++;
				}
				if(a*3 <= v && v <= a+b*4-2){
					win++;
				}
				for(int i = 0;i < q.length-1;i++){
					if(a <= q[i] && q[i] <= 2*b-1){
						win++;
					}
				}
				pyn(win == p);
			}
		}
	}
	
	boolean win(int n, int a, int b)
	{
		if(a <= n && n <= a+2*b-2)return true;
		if(a*3 <= n && n <= a+b*4-2)return true;
		return false;
	}
	
	public static int[][] uniqcount(char[] a)
	{
		int n = a.length;
		int p = 0;
		int[][] b = new int[n][];
		for(int i = 0;i < n;i++){
			if(i == 0 || a[i] != a[i-1])b[p++] = new int[]{a[i], 0};
			b[p-1][1]++;
		}
		return Arrays.copyOf(b, p);
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