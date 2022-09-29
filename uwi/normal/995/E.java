//package round492;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int u = ni(), v = ni(), P = ni();
		Map<Integer, String> mu = go(u, P);
		Map<Integer, String> mv = go(v, P);
		for(int key : mu.keySet()){
			if(mv.containsKey(key)){
				String A = mu.get(key);
				String B = mv.get(key);
				out.println(A.length() + B.length());
				for(int i = 0;i < A.length();i++){
					out.print(A.charAt(i) + " ");
				}
				for(int i = B.length()-1;i >= 0;i--){
					if(B.charAt(i) == '1'){
						out.print(2 + " ");
					}else if(B.charAt(i) == '2'){
						out.print(1 + " ");
					}else{
						out.print(3 + " ");
					}
				}
				out.println();
				return;
			}
		}
		throw new RuntimeException();
	}
	
	Map<Integer, String> go(int u, int mod)
	{
		Map<Integer, String> ret = new HashMap<>();
		Queue<Integer> q = new ArrayDeque<>();
		q.add(u);
		ret.put(u, "");
		while(!q.isEmpty() && ret.size() < Math.min(mod/2+1, 750000)){
			int cur = q.poll();
			if(ret.get(cur).length() > 100)continue;
			{
				int nex = (cur+1)%mod;
				if(!ret.containsKey(nex)){
					ret.put(nex, ret.get(cur) + "1");
					q.add(nex);
				}
			}
			{
				int nex = (cur+mod-1)%mod;
				if(!ret.containsKey(nex)){
					ret.put(nex, ret.get(cur) + "2");
					q.add(nex);
				}
			}
			{
				int nex = (int)invl(cur, mod);
				if(!ret.containsKey(nex)){
					ret.put(nex, ret.get(cur) + "3");
					q.add(nex);
				}
			}
		}
		return ret;
	}
	
	void dfs(int u, int mod, Set<Integer> set, int n)
	{
		if(set.contains(u))return;
		set.add(u);
		
		if(n > 0){
			dfs((u+1)%mod, mod, set, n-1);
			dfs((u+mod-1)%mod, mod, set, n-1);
			dfs((int)invl(u, mod), mod, set, n-1);
		}
	}
	
	public static long invl(long a, long mod) {
		long b = mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d;
			d = a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		return p < 0 ? p + mod : p;
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