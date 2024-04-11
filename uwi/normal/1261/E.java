//package round602;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.Set;

public class E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		char[][] map = new char[n+1][n];
		for(int i = 0;i < n+1;i++){
			Arrays.fill(map[i], '0');
		}
		int[] con = new int[1];
		con[0] = n+1;
		
		for(int i = 0;i < n;i++){
			int f = a[i];
			int[] fill = new int[con.length];
			for(int j = 0;j < con.length;j++){
				if(con[j] > 1 && f > 0){
					f--;
					fill[j] = 1;
				}
			}
			for(int j = 0;j < con.length;j++){
				if(con[j] == 1 && f > 0){
					f--;
					fill[j] = 1;
				}
			}
			for(int j = 0;j < con.length;j++){
				if(fill[j] < con[j] && f > 0){
					int use = Math.min(con[j]-1-fill[j], f);
					f -= use;
					fill[j] += use;
				}
			}
			for(int j = 0;j < con.length;j++){
				if(fill[j] < con[j] && f > 0){
					f--;
					fill[j]++;
				}
			}
			int[] ncon = new int[con.length*2];
			int p = 0;
			int r = 0;
			for(int j = 0;j < con.length;j++){
				for(int k = r;k < r+fill[j];k++){
					map[k][i] = '1';
				}
				if(fill[j] == 0 || fill[j] == con[j]){
					ncon[p++] = con[j];
				}else{
					ncon[p++] = fill[j];
					ncon[p++] = con[j] - fill[j];
				}
				
				r += con[j];
			}
			con = Arrays.copyOf(ncon, p);
		}
		assert check(map);
		
		char[] zero = new char[n];
		Arrays.fill(zero, '0');
		int ret = n+1;
		for(int i = 0;i < n+1;i++){
			if(Arrays.equals(map[i], zero)){
				ret--;
			}
		}
		out.println(ret);
		for(int i = 0;i < n+1;i++){
			if(!Arrays.equals(map[i], zero)){
				out.println(new String(map[i]));
			}
		}
	}
	
	public static int[] shuffle(int n, Random gen){ int[] a = new int[n]; for(int i = 0;i < n;i++)a[i] = i; for(int i = 0;i < n;i++){ int ind = gen.nextInt(n-i)+i; int d = a[i]; a[i] = a[ind]; a[ind] = d; } return a; }
	
	boolean check(char[][] a)
	{
		int n = a.length;
		int m = a[0].length;
		Set<Long> set = new HashSet<>();
		for(int i = 0;i < n;i++){
			boolean ex = false;
			long h = 0;
			for(int j = 0;j < m;j++){
				if(a[i][j] == '1'){
					ex = true;
				}
				h = h * 1000000009 + a[i][j];
			}
			if(ex){
				if(!set.add(h))return false;
			}
		}
		return true;
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
	
	public static void main(String[] args) throws Exception { new E3().run(); }
	
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