//package global11;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class D3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		// 4132
		// ABCDEF
		// EFCDAB
		int n = ni();
		int[] a = na(n);
		List<String> ans = new ArrayList<>();
		int dir = n % 2 == 1 ? -1 : 1;
		while(true){
			boolean ok = true;
			for(int i = 0;i < n-1;i++){
				if(a[i+1] - a[i] != 1)ok = false;
			}
			if(ok)break;

			List<Integer> list = new ArrayList<>();
			if(dir == 1) {
				for (int i = 0; i < n - 1; i += 2) {
					if (Integer.signum(a[i + 1] - a[i]) != dir) {
						list.add(2);
					} else {
						list.add(1);
						list.add(1);
					}
				}
				if(n % 2 == 1){
					list.add(1);
				}
			}else {
				if(n % 2 == 0) {
					list.add(1);
				}
				for (int i = 1^(n%2); i < n - 1; i += 2) {
					if (Integer.signum(a[i + 1] - a[i]) != dir) {
						list.add(2);
					} else {
						list.add(1);
						list.add(1);
					}
				}
				list.add(1);
			}
			StringBuilder sb = new StringBuilder();
			sb.append(list.size());
			for(int u : list) {
				sb.append(" " + u);
			}
			if(list.size() > 1) {
				ans.add(sb.toString());
			}
			int[] b = new int[n];
			int p = n;
			int q = 0;
			for(int u : list) {
				for(int k = 0;k < u;k++) {
					b[p-u+k] = a[q+k];
				}
				q += u;
				p -= u;
			}
			a = b;
			dir = -dir;
		}
		assert ans.size() <= n;
		out.println(ans.size());
		for(String line : ans)out.println(line);
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
	
	public static void main(String[] args) throws Exception { new D3().run(); }
	
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