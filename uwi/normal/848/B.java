//package round431;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), W = ni(), H = ni();
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++){
			int g = ni();
			int x = ni(), t = ni();
			// x-t
			co[i] = new int[]{g, x, t, i};
		}
		Arrays.sort(co, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[1]-a[2] != b[1]-b[2])return (a[1]-a[2]) - (b[1]-b[2]);
				if(a[0] != b[0])return a[0] - b[0];
				if(a[0] == 1){
					return a[1] - b[1];
				}else{
					return -(a[1] - b[1]);
				}
			}
		});
		int[][] ans = new int[n][];
		for(int i = 0;i < n;){
			int j = i;
			while(j < n && (co[i][1]-co[i][2]) == (co[j][1]-co[j][2]))j++;
			
			// [i,k), [k,j)
			int[][] goals = new int[j-i][];
			for(int k = i;k < j;k++){
				if(co[k][0] == 1){
					goals[k-i] = new int[]{co[k][1], H};
				}else{
					goals[k-i] = new int[]{W, co[k][1]};
				}
			}
			
			Arrays.sort(co, i, j, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					if(a[0] != b[0])return -(a[0] - b[0]);
					if(a[0] == 1){
						return a[1] - b[1];
					}else{
						return -(a[1] - b[1]);
					}
				}
			});
			
			for(int k = i;k < j;k++){
				ans[co[k][3]] = goals[k-i];
			}
			
			i = j;
		}
		
		for(int[] a : ans){
			out.println(a[0] + " " + a[1]);
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
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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