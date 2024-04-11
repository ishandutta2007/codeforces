//package mailru2018.r2;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		char[][] ss = new char[n][];
		char[][] ts = new char[n][];
		for(int i = 0;i < n;i++){
			ss[i] = ns().toCharArray();
		}
		for(int i = 0;i < n;i++){
			ts[i] = ns().toCharArray();
		}
		
		char[] from = null;
		char[] to = null;
		int[] ls = new int[n];
		int[] rs = new int[n];
		Arrays.fill(ls, -1);
		Arrays.fill(rs, -1);
		for(int i = 0;i < n;i++){
			int L = -1, R = -1;
			for(int j = 0;j < ss[i].length;j++){
				if(ss[i][j] != ts[i][j]){
					L = j;
					break;
				}
			}
			for(int j = ts[i].length-1;j >= 0;j--){
				if(ss[i][j] != ts[i][j]){
					R = j;
					break;
				}
			}
			if(L == -1)continue;
			ls[i] = L;
			rs[i] = R;
			char[] lfrom = Arrays.copyOfRange(ss[i], L, R+1);
			char[] lto = Arrays.copyOfRange(ts[i], L, R+1);
			if(from == null){
				from = lfrom; to = lto;
			}else if(Arrays.equals(from, lfrom) && Arrays.equals(to, lto)){
				continue;
			}else{
				out.println("NO");
				return;
			}
		}
		
		out:
		while(true){
			char lcan = 0;
			for(int i = 0;i < n;i++){
				if(ls[i] < 0)continue;
				if(ls[i] == 0)break out;
				char lc = ss[i][ls[i]-1];
				if(lcan == 0){
					lcan = lc;
				}else if(lcan != lc){
					break out;
				}
			}
			for(int i = 0;i < n;i++){
				if(ls[i] > 0){
					ls[i]--;
				}
			}
		}
		out:
		while(true){
			char lcan = 0;
			for(int i = 0;i < n;i++){
				if(rs[i] < 0)continue;
				if(rs[i] == ss[i].length-1)break out;
				char lc = ss[i][rs[i]+1];
				if(lcan == 0){
					lcan = lc;
				}else if(lcan != lc){
					break out;
				}
			}
			for(int i = 0;i < n;i++){
				if(rs[i] >= 0){
					rs[i]++;
				}
			}
		}
		char[] hey = null;
		for(int i = 0;i < n;i++){
			if(ls[i] >= 0){
				hey = Arrays.copyOfRange(ss[i], ls[i], rs[i]+1);
				break;
			}
		}
		int[] mp = mpTable(hey);
		
		for(int i = 0;i < n;i++){
			int p = 0;
			for(int j = 0;j < ss[i].length;j++){
				while(p >= 0 && hey[p] != ss[i][j])p = mp[p];
				if(++p == hey.length){
					if(rs[i] != j){
						out.println("NO");
						return;
					}
					break;
				}
			}
		}
		out.println("YES");
		
		char[] yo = null;
		for(int i = 0;i < n;i++){
			if(ls[i] >= 0){
				yo = Arrays.copyOfRange(ts[i], ls[i], rs[i]+1);
				break;
			}
		}
		
		out.println(new String(hey));
		out.println(new String(yo));
	}
	
	public static int[] mpTable(char[] str)
	{
		int n = str.length;
		int[] mp = new int[n+1];
		mp[0] = -1;
		for(int i = 1, j = 0;i < n;i++){
			while(j >= 0 && str[i] != str[j])j = mp[j];
			mp[i+1] = ++j;
		}
		return mp;
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