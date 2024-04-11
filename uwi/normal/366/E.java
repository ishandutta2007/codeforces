import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int K = ni(), S = ni();
		
		int[] minx = new int[K+1];
		int[] maxx = new int[K+1];
		int[] miny = new int[K+1];
		int[] maxy = new int[K+1];
		Arrays.fill(minx, 99999);
		Arrays.fill(maxx, -1);
		Arrays.fill(miny, 99999);
		Arrays.fill(maxy, -1);
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				int v = ni();
				minx[v] = Math.min(minx[v], j+i);
				maxx[v] = Math.max(maxx[v], j+i);
				miny[v] = Math.min(miny[v], j-i);
				maxy[v] = Math.max(maxy[v], j-i);
			}
		}
		
		int[] s = na(S);
		int gmax = 0;
		for(int i = 0;i < S-1;i++){
			gmax = Math.max(gmax, Math.abs(maxx[s[i]]-maxx[s[i+1]]));
			gmax = Math.max(gmax, Math.abs(maxx[s[i]]-minx[s[i+1]]));
			gmax = Math.max(gmax, Math.abs(minx[s[i]]-maxx[s[i+1]]));
			gmax = Math.max(gmax, Math.abs(minx[s[i]]-minx[s[i+1]]));
			gmax = Math.max(gmax, Math.abs(maxy[s[i]]-maxy[s[i+1]]));
			gmax = Math.max(gmax, Math.abs(maxy[s[i]]-miny[s[i+1]]));
			gmax = Math.max(gmax, Math.abs(miny[s[i]]-maxy[s[i+1]]));
			gmax = Math.max(gmax, Math.abs(miny[s[i]]-miny[s[i+1]]));
		}
		out.println(gmax);
	}
	
	void run() throws Exception
	{
//		int n = 2000, m = 9, ss = 100000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(n + " ");
//		sb.append(m + " ");
//		sb.append(ss + " ");
//		for(int j = 0;j < n;j++){
//			for(int k = 0;k < n;k++){
//				sb.append(gen.nextInt(9)+1 + " ");
//			}
//		}
//		for(int i = 0;i < ss;i++){
//			sb.append(gen.nextInt(9)+1 + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
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