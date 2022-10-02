//package round245;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.InputMismatchException;
import java.util.List;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int[] f = new int[25];
		for(int v : a){
			f[v]++;
		}
		if(n == 1){
			out.println("YES");
			return;
		}
		if(f[1] <= n-f[1]){
			out.println("NO");
			return;
		}
		if(f[n] != 1){
			out.println("NO");
			return;
		}
		
		List<Integer> list = new ArrayList<Integer>();
		for(int v : a){
			if(v != 1)list.add(v);
			if(v == 2){
				out.println("NO");
				return;
			}
		}
		Collections.sort(list);
		Collections.reverse(list);
		int m = list.size();
		int[] il = new int[m];
		for(int i = 0;i < m;i++)il[i] = list.get(i);
		int[] par = new int[m];
		int[] lim = new int[m];
		for(int i = 0;i < m;i++)lim[i] = i;
		int one = n-m;
		outer:
		do{
			int[] tot = new int[m];
			int[] ch = new int[m];
			for(int i = 1;i < m;i++){
				tot[par[i]] += il[i];
				ch[par[i]]++;
			}
			int lone = 0;
			for(int i = 0;i < m;i++){
				if(tot[i] + 1 > il[i])continue outer;
				if(ch[i] + il[i] - (tot[i] + 1) < 2)continue outer;
				lone += il[i] - (tot[i] + 1);
			}
			if(lone != one)continue;
			out.println("YES");
			return;
		}while(inc(par, lim));
		out.println("NO");
		return;
	}
	
	public static boolean inc(int[] b, int[] a)
	{
		for(int i = b.length-1;i >= 0;i--){
			if(++b[i] < a[i])return true;
			b[i] = 0;
		}
		return false;
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