//package round378;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] cs = new int[n][];
		for(int i = 0;i < n;i++){
			cs[i] = na(3);
		}
		
		int maxr = 0;
		int arg1 = -1, arg2 = -1;
		for(int i = 0;i < n;i++){
			int r = Math.min(Math.min(cs[i][0], cs[i][1]), cs[i][2]);
			if(r > maxr){
				maxr = r;
				arg1 = i;
			}
		}
		
		int[][] rs = new int[3*n][];
		int p = 0;
		for(int i = 0;i < n;i++){
			int[] c = cs[i];
			rs[p++] = new int[]{Math.min(c[0], c[1]), Math.max(c[0], c[1]), c[2], i};
			rs[p++] = new int[]{Math.min(c[1], c[2]), Math.max(c[1], c[2]), c[0], i};
			rs[p++] = new int[]{Math.min(c[0], c[2]), Math.max(c[0], c[2]), c[1], i};
		}
		Arrays.sort(rs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return a[1] - b[1];
			}
		});
		for(int i = 0;i < 3*n;){
			int j = i;
			while(j < 3*n && rs[i][0] == rs[j][0] && rs[i][1] == rs[j][1])j++;
			
			int best1 = 0, who1 = -1;
			int best2 = 0, who2 = -1;
			for(int k = i;k < j;k++){
				if(rs[k][2] > best1){
					best2 = best1; who2 = who1;
					best1 = rs[k][2]; who1 = rs[k][3];
				}else if(rs[k][2] == best1 && who1 == rs[k][3]){
					continue;
				}else if(rs[k][2] > best2){
					best2 = rs[k][2]; who2 = rs[k][3];
				}
			}
			assert who1 != who2;
			if(who2 != -1){
				int r = Math.min(Math.min(rs[i][0], rs[i][1]), best1+best2);
				if(r > maxr){
					maxr = r;
					arg1 = who1;
					arg2 = who2;
				}
			}
			
			i = j;
		}
		if(arg2 == -1){
			out.println(1);
			out.println(arg1 + 1);
		}else{
			out.println(2);
			if(arg1 > arg2){
				int u = arg1; arg1 = arg2; arg2 = u;
			}
			out.print(arg1 + 1);
			out.print(" ");
			out.println(arg2 + 1);
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