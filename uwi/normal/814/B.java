//package round418;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int[] b = na(n);
		int[] ds = new int[3];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(a[i] != b[i]){
				ds[p++] = i;
			}
		}
		if(p == 2){
			BitSet bs = new BitSet();
			for(int i = 0;i < n;i++){
				if(i != ds[0] && i != ds[1]){
					bs.set(a[i]);
				}
			}
			int[] vals = new int[2];
			int q = 0;
			for(int i = 1;i <= n;i++){
				if(!bs.get(i)){
					vals[q++] = i;
				}
			}
			
			while(true){
				int[] c = Arrays.copyOf(a, n);
				int r = 0;
				for(int i = 0;i < n;i++){
					if(i == ds[0] || i == ds[1]){
						c[i] = vals[r++];
					}
				}
				if(diff(c, a) == 1 && diff(c, b) == 1){
					for(int i = 0;i < n;i++)out.print(c[i] + " ");
					return;
				}
				int u = vals[0]; vals[0] = vals[1]; vals[1] = u;
			}
		}
		if(p == 1){
			BitSet bs = new BitSet();
			for(int i = 0;i < n;i++){
				if(i != ds[0]){
					bs.set(a[i]);
				}
			}
			a[ds[0]] = bs.nextClearBit(1);
			for(int i = 0;i < n;i++)out.print(a[i] + " ");
			return;
		}
		if(p == 0){
			int[] f = new int[n+1];
			for(int i = 0;i < n;i++){
				f[a[i]]++;
			}
			int twice = -1;
			int zero = -1;
			for(int i = 1;i <= n;i++){
				if(f[i] == 2){
					twice = i;
				}else if(f[i] == 0){
					zero = i;
				}
			}
			for(int i = 0;i < n;i++){
				if(a[i] == twice){
					a[i] = zero;
					break;
				}
			}
			for(int i = 0;i < n;i++)out.print(a[i] + " ");
			return;
		}
		throw new RuntimeException();
	}
	
	int diff(int[] a, int[] b)
	{
		int dif = 0;
		for(int i = 0;i < a.length;i++){
			if(a[i] != b[i])dif++;
		}
		return dif;
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
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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