//package round676;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";

	void solve()
	{
		int n = ni();
		int[] a = na(n);
		if(n == 1){
			out.println(a[0]);
			return;
		}
		// 3:1
		// 4:0,3
		// 5:2:5
		// 6:1,4
		long sp = 0;
		for(int i = 0;i < n;i++){
			sp += a[i] * (i % 2 == 0 ? 1 : -1);
		}

		long[] cum = new long[n+1];
		radixSort2(a);
		for(int i = 0;i < n;i++){
			cum[i+1] = cum[i] + a[i];
		}
		long ans = Long.MIN_VALUE;
		int u = (4 - n % 3) % 3;
		for(int i = u;i <= n;i+=3){
			long v = -cum[i] + (cum[n] - cum[i]);
			if(n/2 == i && v == sp) {
				v = -cum[i] + (cum[n] - cum[i]) + a[i] * -2 + a[i-1] * 2;
			}
			ans = Math.max(ans, v);
		}
		out.println(ans);
	}

	public static int[] radixSort2(int[] a)
	{
		int n = a.length;
		int[] c0 = new int[0x101];
		int[] c1 = new int[0x101];
		int[] c2 = new int[0x101];
		int[] c3 = new int[0x101];
		for(int v : a) {
			c0[(v&0xff)+1]++;
			c1[(v>>>8&0xff)+1]++;
			c2[(v>>>16&0xff)+1]++;
			c3[(v>>>24^0x80)+1]++;
		}
		for(int i = 0;i < 0xff;i++) {
			c0[i+1] += c0[i];
			c1[i+1] += c1[i];
			c2[i+1] += c2[i];
			c3[i+1] += c3[i];
		}
		int[] t = new int[n];
		for(int v : a)t[c0[v&0xff]++] = v;
		for(int v : t)a[c1[v>>>8&0xff]++] = v;
		for(int v : a)t[c2[v>>>16&0xff]++] = v;
		for(int v : t)a[c3[v>>>24^0x80]++] = v;
		return a;
	}



	void dfs(List<Deque<Integer>> a)
	{
		if(a.size() == 1){
//			t.add(a.get(0));
			int ptn = 0;
			char[] s = new char[a.get(0).size()];
			for(int v : a.get(0)){
				if(v < 0){
					s[-v-1] = '1';
				}else{
					s[v-1] = '0';
				}
			}
			return;
		}
		int n = a.size();
		for(int i = 0;i < a.size()-1;i++){
			List<Deque<Integer>> b = new ArrayList<>();
			for(int j = 0;j < i;j++){
				b.add(a.get(j));
			}
			Deque<Integer> y = new ArrayDeque<>();
			for(int u : a.get(i)){
				y.add(-u);
			}
			for(int u : a.get(i+1)){
				y.add(-u);
			}
			b.add(y);
			for(int j = i+2;j < n;j++){
				b.add(a.get(j));
			}
			dfs(b);
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