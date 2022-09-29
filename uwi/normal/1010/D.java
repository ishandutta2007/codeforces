//package round499;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Set;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		String[] coms = new String[n];
		int[][] ch = new int[n][];
		int[] vals = new int[n];
		Arrays.fill(vals, -1);
		for(int i = 0;i < n;i++){
			coms[i] = ns();
			if(coms[i].equals("IN")){
				vals[i] = ni();
			}else if(coms[i].equals("NOT")){
				ch[i] = na(1);
				for(int j = 0;j < 1;j++)ch[i][j]--;
			}else{
				ch[i] = na(2);
				for(int j = 0;j < 2;j++)ch[i][j]--;
			}
		}
		
		int[] vs = new int[n];
		Arrays.fill(vs, -1);
		dfs(0, coms, ch, vals, vs);
		int[] anss = new int[n];
		dfs2(0, 1, 0, coms, ch, vals, vs, anss);
		for(int i = 0;i < n;i++){
			if(coms[i].equals("IN")){
				out.print(anss[i]);
			}
		}
	}
	
	// v0:0
	// v1:1
	void dfs2(int v0, int v1, int cur, String[] coms, int[][] ch, int[] vals, int[] vs, int[] anss)
	{
		if(vals[cur] >= 0){
			anss[cur] = vals[cur] == 0 ? v1 : v0;
			return;
		}
		
		if(coms[cur].equals("NOT")){
			dfs2(v1, v0, ch[cur][0], coms, ch, vals, vs, anss);
			return;
		}
		if(coms[cur].equals("XOR")){
			dfs2(vs[ch[cur][1]] == 1 ? v1 : v0, vs[ch[cur][1]] == 1 ? v0 : v1, ch[cur][0], coms, ch, vals, vs, anss);
			dfs2(vs[ch[cur][0]] == 1 ? v1 : v0, vs[ch[cur][0]] == 1 ? v0 : v1, ch[cur][1], coms, ch, vals, vs, anss);
			return;
		}
		if(coms[cur].equals("OR")){
			dfs2(vs[ch[cur][1]] == 1 ? v1 : v0, vs[ch[cur][1]] == 1 ? v1 : v1, ch[cur][0], coms, ch, vals, vs, anss);
			dfs2(vs[ch[cur][0]] == 1 ? v1 : v0, vs[ch[cur][0]] == 1 ? v1 : v1, ch[cur][1], coms, ch, vals, vs, anss);
			return;
		}
		if(coms[cur].equals("AND")){
			dfs2(vs[ch[cur][1]] == 1 ? v0 : v0, vs[ch[cur][1]] == 1 ? v1 : v0, ch[cur][0], coms, ch, vals, vs, anss);
			dfs2(vs[ch[cur][0]] == 1 ? v0 : v0, vs[ch[cur][0]] == 1 ? v1 : v0, ch[cur][1], coms, ch, vals, vs, anss);
			return;
		}
		throw new RuntimeException();
	}
	
	void dfs(int cur, String[] coms, int[][] ch, int[] vals, int[] vs)
	{
		if(vals[cur] >= 0){
			vs[cur] = vals[cur];
			return;
		}
		
		if(coms[cur].equals("NOT")){
			dfs(ch[cur][0], coms, ch, vals, vs);
			vs[cur] = vs[ch[cur][0]] ^ 1;
			return;
		}
		dfs(ch[cur][0], coms, ch, vals, vs);
		dfs(ch[cur][1], coms, ch, vals, vs);
		if(coms[cur].equals("XOR")){
			vs[cur] = vs[ch[cur][1]] ^ vs[ch[cur][0]];
			return;
		}
		if(coms[cur].equals("AND")){
			vs[cur] = vs[ch[cur][1]] & vs[ch[cur][0]];
			return;
		}
		if(coms[cur].equals("OR")){
			vs[cur] = vs[ch[cur][1]] | vs[ch[cur][0]];
			return;
		}
		throw new RuntimeException();
	}
	
	Set<Integer> merge(Set<Integer> a, Set<Integer> b)
	{
		if(a == null)return b;
		if(b == null)return a;
		if(a.size() < b.size()){
			Set<Integer> x = a; a = b; b = x;
		}
		a.addAll(b);
		return a;
	}
	
	void run() throws Exception
	{
//		int n = 1000000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		int i;
//		for (i = 0; i*2+2+1 <= n; i++) {
//			sb.append("XOR " + (i*2+1+1) + " ");
//			sb.append((i*2+2+1) + "\n");
//		}
//		for(;i < n;i++){
//			sb.append("IN 0\n");
//		}
//		tr(sb);
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		Thread t = new Thread(null, null, "~", Runtime.getRuntime().maxMemory()){
			@Override
			public void run() {
				long s = System.currentTimeMillis();
				solve();
				out.flush();
				tr(System.currentTimeMillis()-s+"ms");
			}
		};
		t.start();
		t.join();
//		long s = System.currentTimeMillis();
//		solve();
//		out.flush();
//		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D2().run(); }
	
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