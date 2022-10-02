//package round260;
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
		int n = ni(), K = ni();
		String[] ss = new String[n];
		for(int i = 0;i < n;i++){
			ss[i] = ns();
		}
		Arrays.sort(ss);
		boolean[][] win = new boolean[n][];
		boolean[][] lose = new boolean[n][];
		boolean[][] unknown = new boolean[n][];
		for(int i = 0;i < n;i++){
			win[i] = new boolean[ss[i].length()];
			lose[i] = new boolean[ss[i].length()];
			unknown[i] = new boolean[ss[i].length()];
		}
		int[][] watch = new int[100001][];
		int p = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < ss[i].length();j++){
				watch[p++] = new int[]{i, j};
			}
		}
		Arrays.sort(watch, 0, p, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[1] != b[1])return -(a[1] - b[1]);
				return a[0] - b[0];
			}
		});
		for(int i = 0;i < p;i++){
			int x = watch[i][0], y = watch[i][1];
			if(win[x][y] || lose[x][y])continue;
			int j;
			for(j = x;j < n && y < ss[j].length() && ss[x].charAt(y) == ss[j].charAt(y);j++);
			boolean canwin = false;
			boolean canlose = false;
			boolean noend = false;
			for(int k = x;k < j;k++){
				if(y+1 >= ss[k].length()){
				}else{
					noend = true;
					if(lose[k][y+1] && !win[k][y+1]){
						canwin = true;
					}
					if(win[k][y+1] && !lose[k][y+1]){
						canlose = true;
					}
					if(win[k][y+1] && lose[k][y+1]){
					}
					if(!win[k][y+1] && !lose[k][y+1]){
						canwin = true;
						canlose = true;
					}
				}
			}
			
			if(!noend){
				canlose = true;
			}
			
			for(int k = x;k < j;k++){
				win[k][y] = canwin;
				lose[k][y] = canlose;
			}
		}
		
		boolean canwin = false;
		boolean canlose = false;
		for(int k = 0;k < n;k++){
			if(lose[k][0] && !win[k][0]){
				canwin = true;
			}
			if(win[k][0] && !lose[k][0]){
				canlose = true;
			}
			if(!win[k][0] && !lose[k][0]){
				canwin = canlose = true;
			}
		}
		
		if(canwin && canlose){
			out.println("First");
		}else if(canwin && !canlose){
			if(K % 2 == 1){
				out.println("First");
			}else{
				out.println("Second");
			}
		}else if(!canwin && canlose){
			out.println("Second");
		}else{
			out.println("Second");
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