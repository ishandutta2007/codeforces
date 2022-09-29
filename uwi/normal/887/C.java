//package round444;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int[][][] duals = {
				{
				{1, 3, 6, 8},
				{2, 4, 22, 24},
				{5, 7, 10, 12},
				{9, 11, 21, 23},
				{13, 14, 15, 16},
				{17, 18, 19, 20}
				},
				{
				{1, 3, 21, 23},
				{10, 12, 22, 24},
				{5, 7, 2, 4},
				{9, 11, 6, 8},
				{13, 14, 15, 16},
				{17, 18, 19, 20}
				},
				{
				{1, 2, 3, 4},
				{9, 10, 11, 12},
				{13, 14, 7, 8},
				{5, 6, 19, 20},
				{17, 18, 23, 24},
				{21, 22, 15, 16},
				},
				{
				{1, 2, 3, 4},
				{9, 10, 11, 12},
				{13, 14, 23, 24},
				{5, 6, 15, 16},
				{17, 18, 7, 8},
				{21, 22, 19, 20},
				},
				{
				{5, 6, 7, 8},
				{21, 22, 23, 24},
				{3, 4, 18, 20},
				{17, 19, 11, 12},
				{9, 10, 13, 15},
				{14, 16, 1, 2},
				},
				{
				{5, 6, 7, 8},
				{21, 22, 23, 24},
				{3, 4, 13, 15},
				{17, 19, 1, 2},
				{9, 10, 18, 20},
				{14, 16, 11, 12},
				}
		};
		
		int[] a = na(24);
		outer:
		for(int[][] d : duals){
			for(int[] c : d){
				for(int v : c){
					for(int w : c){
						if(a[v-1] != a[w-1])continue outer;
					}
				}
			}
			out.println("YES");
			return;
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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