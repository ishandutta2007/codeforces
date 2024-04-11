//package round277;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int[] b = new int[n];
		for(int i = 0;i < n;i++){
			b[i] = 100001-a[n-1-i];
		}
		int[] fo = lisroute(a);
		int[] ba = lisroute(b);
		int[] f = new int[n];
		for(int x : fo)f[x]++;
		for(int x : ba)f[n-1-x]++;
		
		int[] left = new int[n];
		int[] right = new int[n];
		{
			int ret = 0;
			int[] h = new int[n + 1];
			Arrays.fill(h, Integer.MIN_VALUE / 2);
			for(int i = 0;i < n;i++){
				int ind = Arrays.binarySearch(h, 0, ret + 1, a[i]);
				if(ind < 0){
					ind = -ind-2;
					h[ind+1] = a[i];
					left[i] = ind;
					if(ind >= ret)ret++;
				}else{
					left[i] = ind-1;
				}
			}
		}
		int lis = 0;
		{
			int ret = 0;
			int[] h = new int[n + 1];
			Arrays.fill(h, Integer.MIN_VALUE / 2);
			for(int i = 0;i < n;i++){
				int ind = Arrays.binarySearch(h, 0, ret + 1, b[i]);
				if(ind < 0){
					ind = -ind-2;
					h[ind+1] = b[i];
					right[n-1-i] = ind;
					if(ind >= ret)ret++;
				}else{
					right[n-1-i] = ind-1;
				}
			}
			lis = ret;
		}
		for(int i = 0;i < n;i++){
			if(left[i] + right[i] + 1 != lis){
				f[i] = -1;
			}
		}
		for(int i = 0;i < n;i++){
			out.print(f[i] == 2 ? 3 : f[i] == -1 ? 1 : 2);
		}
		out.println();
	}
	
	public int[] lisroute(int[] a)
	{
		int n = a.length;
		int ret = 0;
		int[] h = new int[n + 1];
		Arrays.fill(h, Integer.MIN_VALUE / 2);
		int[] argh = new int[n+1];
		Arrays.fill(argh, -1);
		int[] prev = new int[n];
		Arrays.fill(prev, -1);
		for(int i = 0;i < n;i++){
			int ind = Arrays.binarySearch(h, 0, ret + 1, a[i]);
			if(ind < 0){
				ind = -ind-2;
				h[ind+1] = a[i];
				prev[i] = argh[ind];
				argh[ind+1] = i;
				if(ind >= ret)ret++;
			}else{
				h[ind] = a[i];
				prev[i] = argh[ind-1];
				argh[ind] = i;
			}
		}
		int[] route = new int[ret];
		for(int x = argh[ret], k = 0;x != -1;x = prev[x], k++){
			route[k] = x;
		}
		return route;
	}
	
	public static int lis(int[] in)
	{
		int n = in.length;
		int ret = 0;
		int[] h = new int[n + 1];
		Arrays.fill(h, Integer.MIN_VALUE / 2);
		for(int i = 0;i < n;i++){
			int ind = Arrays.binarySearch(h, 0, ret + 1, in[i]);
			if(ind < 0){
				ind = -ind-2;
				h[ind+1] = in[i];
				if(ind >= ret)ret++;
			}
		}
		return ret;
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