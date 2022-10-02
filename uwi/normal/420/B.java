//package codestrike2014.finals;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] co = new int[m][];
		for(int i = 0;i < m;i++){
			co[i] = new int[]{nc(), ni()-1};
		}
		char[] fs = new char[n];
		for(int i = m-1;i >= 0;i--){
			fs[co[i][1]] = (char)co[i][0];
		}
		boolean[] can = new boolean[n];
		Arrays.fill(can, true);
		
		boolean[] alive = new boolean[n];
		int num = 0;
		for(int i = 0;i < n;i++){
			if(fs[i] == '-'){
				alive[i] = true;
				num++;
			}
		}
		
		if(num > 0){
			for(int i = 0;i < n;i++){
				if(fs[i] == '+'){
					alive[i] = false;
					can[i] = false;
				}
			}
		}
		int solit = -1;
		for(int i = 0;i < m;i++){
			if(co[i][0] == '+'){
				num++;
				alive[co[i][1]] = true;
				if(num == 1){
					if(solit == -1){
						solit = co[i][1];
					}else if(solit != co[i][1]){
						solit = -2;
					}
				}
			}else{
				num--;
				alive[co[i][1]] = false;
				if(num > 0){
					can[co[i][1]] = false;
				}
			}
		}
		if(num > 0){
			for(int i = 0;i < n;i++){
				if(!alive[i] && fs[i] != 0)can[i] = false;
			}
		}
		if(solit == -2){
			for(int i = 0;i < n;i++){
				if(fs[i] != 0)can[i] = false;
			}
		}else if(solit >= 0){
			for(int i = 0;i < n;i++){
				if(fs[i] != 0 && solit != i)can[i] = false;
			}
		}
		
		int ret = 0;
		for(int i = 0;i < n;i++){
			if(can[i])ret++;
		}
		out.println(ret);
		if(ret > 0){
			for(int i = 0;i < n;i++){
				if(can[i]){
					out.print((i+1) + " ");
				}
			}
			out.println();
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
	
	public static void main(String[] args) throws Exception { new B2().run(); }
	
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