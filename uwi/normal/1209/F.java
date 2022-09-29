//package round584;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Queue;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] from = new int[10*m+2];
		int[] to = new int[10*m+2];
		int[] ws = new int[10*m+2];
		int p = 0;
		int gen = n;
		for(int i = 0;i < m;i++){
			int f = ni()-1, t = ni()-1;
			char[] s = ("" + (i+1)).toCharArray();
			int cur = f;
			for(int j = 0;j < s.length;j++){
				char c = s[j];
				from[p] = cur;
				to[p] = j == s.length-1 ? t : gen++;
				ws[p] = c-'0';
				cur = to[p];
				p++;
			}
			cur = t;
			for(int j = 0;j < s.length;j++){
				char c = s[j];
				from[p] = cur;
				to[p] = j == s.length-1 ? f : gen++;
				ws[p] = c-'0';
				cur = to[p];
				p++;
			}
		}
		int[][][] g = packWD(gen, from, to, ws, p);
		
		for(int[][] row : g){
			Arrays.sort(row, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return a[1] - b[1];
				}
			});
		}
		
		int[] ds = new int[gen];
		int I = 99999999;
		Arrays.fill(ds, I);
		ds[0] = 0;
		int mod = 1000000007;
		long[] vals = new long[gen];
		
		Queue<Queue<Integer>> qs = new ArrayDeque<>();
		{
			Queue<Integer> q = new ArrayDeque<>();
			q.add(0);
			qs.add(q);
		}
		
		while(!qs.isEmpty()){
			Queue<Integer> q = qs.poll();
			List<int[]> ns = new ArrayList<>();
			while(!q.isEmpty()){
				int cur = q.poll();
				for(int[] e : g[cur]){
					if(ds[e[0]] == I){
						ns.add(new int[]{e[0], e[1], cur});
					}
				}
			}
			Collections.sort(ns, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return a[1] - b[1];
				}
			});
			int pre = -1;
			Queue<Integer> pack = new ArrayDeque<>();
			for(int[] e : ns){
				if(ds[e[0]] == I){
					if(e[1] != pre && !pack.isEmpty()){
						qs.add(pack);
						pack = new ArrayDeque<>();
					}
					pre = e[1];
					ds[e[0]] = ds[e[2]] + 1;
					vals[e[0]] = (vals[e[2]] * 10 + e[1]) % mod;
					pack.add(e[0]);
				}
			}
			if(!pack.isEmpty()){
				qs.add(pack);
			}
		}
		for(int i = 1;i < n;i++){
			out.println(vals[i]);
		}
	}
	
	public static int[][][] packWD(int n, int[] from, int[] to, int[] w){ return packWD(n, from, to, w, from.length); }
	public static int[][][] packWD(int n, int[] from, int[] to, int[] w, int sup)
	{
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]][2];
		for(int i = 0;i < sup;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
		}
		return g;
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