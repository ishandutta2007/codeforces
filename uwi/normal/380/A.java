//package round222;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class A {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] str = new int[n][];
		long[] offset = new long[n+1];
		int[] first = new int[100001];
		int p = 0;
		for(int i = 0;i < n;i++){
			int t = ni();
			if(t == 1){
				str[i] = new int[]{1, ni()};
				offset[i+1] = offset[i] + 1;
				if(p < first.length)first[p++] = str[i][1];
			}else{
				str[i] = new int[]{2, ni(), ni()};
				offset[i+1] = offset[i] + (long)str[i][1] * str[i][2];
				out:
				for(int j = 0;j < str[i][2];j++){
					for(int k = 0;k < str[i][1];k++){
						if(p < first.length){
							first[p++] = first[k];
						}else{
							break out;
						}
					}
				}
			}
		}
		
		int m = ni();
		for(int i = 0;i < m;i++){
			long q = nl()-1;
			int ind = Arrays.binarySearch(offset, q);
			if(ind < 0)ind = -ind-2;
			long loff = q - offset[ind];
			if(str[ind][0] == 1){
				out.print(str[ind][1] + " ");
			}else{
				out.print(first[(int)(loff%str[ind][1])] + " ");
			}
		}
		out.println();
	}
	
	void run() throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		long len = 1;
//		for(int i = 0;i < n;i++){
//			sb.append(2 + " ");
//			int L = (int)Math.min(len, 100000);
//			sb.append(L + " ");
//			int u = gen.nextInt(10000)+1;
//			sb.append(u + " ");
//			len += (long)L*u;
//		}
//		sb.append(m + " ");
//		for(int i = 0;i < m;i++){
//			sb.append((Math.abs(gen.nextLong()) % len + 1));
//			sb.append(" ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new A().run(); }
	
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