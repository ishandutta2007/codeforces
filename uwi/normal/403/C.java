//package round236;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.BitSet;
import java.util.InputMismatchException;
import java.util.Queue;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		boolean[][] g = new boolean[n][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				g[i][j] = ni() >= 1;
			}
		}
		int[] clus = decomposeToSCC(g);
		for(int i = 0;i < n;i++){
			if(clus[i] != 0){
				out.println("NO");
				return;
			}
		}
		out.println("YES");
	}
	
	public static int[] decomposeToSCC(boolean[][] g)
	{
		int n = g.length;
		BitSet visited = new BitSet();
		int[] po = new int[n];
		int pop = 0;
		
		for(int i = visited.nextClearBit(0);i < n;i = visited.nextClearBit(i+1)){
			pop = dfsPostOrder(i, g, visited, po, pop);
		}
		
		int[] ret = new int[n];
		visited.clear();
		int clus = 0;
		for(int i = n - 1;i >= 0;i--){
			if(!visited.get(po[i])){
				Queue<Integer> q = new ArrayDeque<Integer>();
				q.add(po[i]);
				visited.set(po[i]);
				while(!q.isEmpty()){
					int cur = q.poll();
					ret[cur] = clus;
					for(int k = visited.nextClearBit(0);k < n;k = visited.nextClearBit(k+1)){
						if(g[k][cur]){
							q.add(k);
							visited.set(k);
						}
					}
				}
				clus++;
			}
		}
		
		return ret;
	}
	
	public static int dfsPostOrder(int cur, boolean[][] g, BitSet visited, int[] po, int pop)
	{
		visited.set(cur);
		int n = g.length;
		for(int i = visited.nextClearBit(0);i < n;i = visited.nextClearBit(i+1)){
			if(g[cur][i]){
				pop = dfsPostOrder(i, g, visited, po, pop);
			}
		}
		po[pop++] = cur;
		return pop;
	}
	
	void run() throws Exception
	{
//		int n = 2000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			for(int j = 0;j < n;j++){
//				sb.append((i == j ? 1 : gen.nextInt(2)) + " ");
//			}
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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