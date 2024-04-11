//package round155;
import java.io.ByteArrayInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class A3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni()*2;
		int[] a = new int[n];
		int[] pre = new int[5001];
		Arrays.fill(pre, -1);
		int[] ct = new int[5001];
		for(int i = 0;i < n;i++){
			a[i] = ni();
			ct[a[i]]++;
		}
		for(int i = 0;i <= 5000;i++){
			if(ct[i] % 2 != 0){
				out.println(-1);
				return;
			}
		}
		
		for(int i = 0;i < n;i++){
			if(pre[a[i]] == -1){
				pre[a[i]] = i;
			}else{
				out.print(pre[a[i]]+1);
				out.print(" ");
				out.println(i+1);
//				out.println((pre[a[i]]+1) + " " + (i+1));
				pre[a[i]] = -1;
			}
		}
	}
	
	void run() throws Exception
	{
//		int n = 300000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		int[] a = new int[n];
//		for(int i = 0;i < n;i++){
//			a[i] = gen.nextInt(5000)+1;
//		}
//		for(int i = 0;i < n;i++){
//			sb.append(a[i] + " ");
//			sb.append(a[i] + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? new FileInputStream("input.txt") : new ByteArrayInputStream(INPUT.getBytes());
		out = oj ? new PrintWriter("output.txt") : new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new A3().run(); }
	
	byte[] inbuf = new byte[1<<12];
	int lenbuf = 0, ptrbuf = 0;
	
	int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	double nd() { return Double.parseDouble(ns()); }
	char nc() { return (char)readByte(); }
	
	String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(true){ // when nextLine, (isSpaceChar(b) && b != ' ')
			if(isSpaceChar(b))return sb.toString();
			sb.appendCodePoint(b);
			b = readByte();
		}
	}
	
	char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n){
			if(isSpaceChar(b))break;
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	int ni()
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
	
	long nl()
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
	
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}