//package round256;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Map;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long x = nl(), K = nl();
		if(K >= 100000){
			if(x > 1){
				for(int i = 0;i < 100000;i++){
					out.print(1 + " ");
				}
				out.println();
			}else{
				out.println(1);
			}
			return;
		}
		
		q = 0;
		cache = new HashMap<Long, List<Integer>>();
		dfs(x, (int)K);
		out.println();
	}
	
	int q;
	Map<Long, List<Integer>> cache;
	
	void dfs(long x, int k)
	{
		if(q >= 100000)return;
		if(x == 1 || k == 0){
			out.print(x + " ");
			q++;
			return;
		}
		
		if(cache.containsKey(x)){
			List<Integer> tm = cache.get(x);
			for(int t : tm){
				dfs(t, k-1);
				if(q >= 100000)return;
			}
			long sq = (long)Math.sqrt(x);
			if(sq*sq == x){
				dfs(sq, k-1);
				if(q >= 100000)return;
			}
			for(int i = tm.size()-1;i >= 0;i--){
				int t = tm.get(i);
				dfs(x/t, k-1);
				if(q >= 100000)return;
			}
		}else{
			List<Integer> tm = new ArrayList<Integer>();
			for(long d = 1;d * d <= x;d++){
				if(x % d == 0){
					dfs(d, k-1);
					if(q >= 100000)return;
					if(d * d < x)tm.add((int)d);
				}
			}
			cache.put(x, tm);
			for(int i = tm.size()-1;i >= 0;i--){
				dfs(x/tm.get(i), k-1);
				if(q >= 100000)return;
			}
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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