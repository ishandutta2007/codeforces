//package round221;
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
		char[] s = ns().toCharArray();
		StringBuilder sb = new StringBuilder();
		int n = s.length;
		boolean[] flag = new boolean[10];
		int[] O = {1, 6, 8, 9};
		outer:
		for(int i = 0;i < n;i++){
			for(int u : O){
				if(s[i] == '0' + u && !flag[u]){
					flag[u] = true;
					continue outer;
				}
			}
			sb.append(s[i]);
		}
		
		int d = 1;
		long x = 0;
		for(int i = sb.length()-1;i >= 0;i--){
			x = x + (sb.charAt(i)-'0') * d;
			d = d * 10 % 7;
		}
		int[] ord = {1, 6, 8, 9};
		do{
			int u = 0;
			for(int i = 0;i <= 3;i++){
				u = (u * 10 + ord[i]);
			}
			if((u*d+x)%7 == 0){
				out.print(ord[0]);
				out.print(ord[1]);
				out.print(ord[2]);
				out.print(ord[3]);
				out.println(sb);
//				sb.insert(0, ord[3]);
//				sb.insert(0, ord[2]);
//				sb.insert(0, ord[1]);
//				sb.insert(0, ord[0]);
//				if(new BigInteger(sb.toString()).mod(BigInteger.valueOf(7)).signum() != 0){
//					throw new RuntimeException();
//				}
				return;
			}
		}while(nextPermutation(ord));
		
		out.println(0);
	}
	
	static boolean nextPermutation(int[] src) {
		int i;
		for(i = src.length - 2;i >= 0 && src[i] > src[i + 1];i--)
			;
		if(i == -1)
			return false;
		int j;
		for(j = i + 1;j < src.length && src[i] < src[j];j++)
			;
		int d = src[i];
		src[i] = src[j - 1];
		src[j - 1] = d;
		for(int p = i + 1, q = src.length - 1;p < q;p++, q--){
			d = src[p];
			src[p] = src[q];
			src[q] = d;
		}
		return true;
	}
	
	void run() throws Exception
	{
//		int n = 1000000, m = 99999;
//		Random gen = new Random(1);
//		StringBuilder sb = new StringBuilder();
//		sb.append(1689);
//		for(int i = 0;i < n-4;i++){
//			sb.append(gen.nextInt(10));
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