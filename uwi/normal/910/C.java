//package test14;
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
	
	static class Datum
	{
		public int c;
		public int[] f;
		public Datum(int c, int[] f) {
			this.c = c;
			this.f = f;
		}
	}
	
	void solve()
	{
		int n = ni();
		char[][] ss = new char[n][];
		for(int i = 0;i < n;i++){
			ss[i] = ns().toCharArray();
		}
		int[][] f = new int[10][1100];
		int first = 0;
		for(char[] s : ss){
			int len = s.length;
			first |= 1<<s[0]-'a';
			for(char c : s){
				f[c-'a'][--len]++;
			}
		}
		for(int j = 0;j < 10;j++){
			for(int i = 0;i < f[0].length-1;i++){
				f[j][i+1] += f[j][i] / 10;
				f[j][i] %= 10;
			}
		}
		
		Datum[] cs = new Datum[10];
		for(int i = 0;i < 10;i++){
			cs[i] = new Datum(i, f[i]);
		}
		Arrays.sort(cs, new Comparator<Datum>() {
			public int compare(Datum a, Datum b) {
				for(int i = a.f.length-1;i >= 0;i--){
					if(a.f[i] != b.f[i])return -(a.f[i] - b.f[i]);
				}
				return 0;
			}
		});
		
		int rem = (1<<10)-1;
		long[] ans = new long[1100];
		for(int i = 0;i < 10;i++){
			int lrem = first<<~cs[i].c<0 ? rem&~1 : rem;
			int bot = Integer.numberOfTrailingZeros(lrem);
			for(int j = 0;j < 1100;j++){
				ans[j] += cs[i].f[j] * bot;
			}
			rem ^= 1<<bot;
		}
		
		for(int i = 0;i < f[0].length-1;i++){
			ans[i+1] += ans[i] / 10;
			ans[i] %= 10;
		}
		
		boolean pr = false;
		for(int i = 1099;i >= 0;i--){
			if(ans[i] != 0)pr = true;
			if(pr){
				out.print(ans[i]);
			}
		}
		out.println();
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