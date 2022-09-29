//package round658;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class A2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	// 11011
	// 00100
	// 11100
	// 01100
	
	void solve()
	{
		for(int T = ni();T > 0;T--){
			go();
		}
	}
	
	char flip(char c)
	{
		return (char)('0'+'1'-c);
	}
	
	void go()
	{
		int n = ni();
		char[] a = ns(n);
		char[] b = ns(n);
		List<Integer> list = new ArrayList<>();
		boolean rev = false;
		int l = 0, r = n-1;
		for(int i = n-1;i >= 1;i--){
			if(!rev){
				if(a[r] != b[i]){
					if(a[l] == b[i]){
						list.add(0);
					}
					list.add(i);
					rev = true;
					l++;
				}else{
					r--;
				}
			}else{
				if(flip(a[l]) != b[i]){
					if(flip(a[r]) == b[i]){
						list.add(0);
					}
					list.add(i);
					rev = false;
					r--;
				}else{
					l++;
				}
			}
		}
		if(!rev){
			if(a[l] != b[0]){
				list.add(0);
			}
		}else{
			if(flip(a[l]) != b[0]){
				list.add(0);
			}
		}
		out.print(list.size());
		for(int v : list){
			out.print(" " +  (v+1));
		}
		out.println();
		
//		for(int v : list){
//			char[] aa = Arrays.copyOf(a, n);
//			for(int i = 0;i <= v;i++){
//				aa[i] = flip(a[v-i]);
//			}
//			a = aa;
//		}
//		assert Arrays.equals(a, b);
	}
	
	public static char[] rev(char[] a)
	{
		a = Arrays.copyOf(a, a.length);
		for(int i = 0, j = a.length-1;i < j;i++,j--){
			char c = a[i]; a[i] = a[j]; a[j] = c;
		}
		return a;
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
	
	public static void main(String[] args) throws Exception { new A2().run(); }
	
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