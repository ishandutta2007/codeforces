//package round653;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.List;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T > 0;T--){
			go();
		}
	}
	
	void go()
	{
		int n = ni();
		int[] a = na(n);
		int[][] as = new int[n][];
		for(int k = 0;k < n;k++){
			as[k] = new int[]{a[k], k};
		}
		Arrays.sort(as, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return a[1] - b[1];
			}
		});
		int[] b = new int[n];
		for(int i = 0;i < n;i++){
			b[as[i][1]] = i;
		}
		int inv = 0;
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				if(b[i] > b[j])inv++;
			}
		}
		
		if(inv % 2 == 1){
			boolean done = false;
			inner:
			for(int i = 0;i < n;i++){
				for(int j = i+1;j < n;j++){
					if(a[i] == a[j]){
						int d = b[i]; b[i] = b[j]; b[j] = d;
						done = true;
						break inner;
					}
				}
			}
			if(!done){
				out.println(-1);
				return;
			}
		}
		
		route = new ArrayList<>();
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(b[j] == i){
					walk(j, i, b);
					break;
				}
			}
		}
		assert route.size() <= n*n;
		out.println(route.size());
		for(int r : route){
			out.print((r+1) + " ");
		}
		out.println();
	}
	
	void walk(int f, int t, int[] b)
	{
		assert t <= f;
		while(f-t >= 2){
			push(f-2, b);
			f -= 2;
		}
		if(f-t == 1){
			push(t, b);
			push(t, b);
		}
	}
	
	void push(int x, int[] b)
	{
		route.add(x);
		int d = b[x+2];
		b[x+2] = b[x+1];
		b[x+1] = b[x];
		b[x] = d;
	}
	
	List<Integer> route;
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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