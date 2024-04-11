//package round166;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), k = ni();
		if(n / k <= 2){
			out.println(-1);
			return;
		}
		if(n == 3*k){
//			int[] a = new int[n];
//			for(int i = 0;i < k;i++){
//				a[i] = i+1;
//				a[i+k] = i+1;
//				a[2*k+(i+1)%k] = i+1;
//			}
//			if(!check(a, k)){
//				throw new AssertionError();
//			}
			
			for(int i = 0;i < k;i++){
				if(i > 0)out.print(" ");
				out.print(i+1);
			}
			for(int i = 0;i < k;i++){
				out.print(" ");
				out.print(i+1);
			}
			for(int i = 0;i < k;i++){
				out.print(" ");
				out.print((i+1)%k+1);
			}
			out.println();
			return;
		}
		
//		{
//			int[] a = new int[n];
//			Arrays.fill(a, k);
//			int pa = k;
//			for(int i = 0;i < k;i++){
//				if(i+2*k==n-1-i){
//					pa = i+1;
//					Arrays.fill(a, i+1);
//				}
//			}
//			for(int i = 0;i < k;i++){
//				a[i] = i+1;
//				a[i+k] = i+1;
//				a[n-1-i] = i+1;
//			}
//			if(!check(a, k)){
//				tr(a);
//				throw new AssertionError();
//			}
//		}
		
		int pa = k;
		for(int i = 0;i < k;i++){
			if(i+2*k==n-1-i){
				pa = i+1;
			}
		}
		for(int i = 0;i < k;i++){
			if(i > 0)out.print(" ");
			out.print(i+1);
		}
		for(int i = 0;i < k;i++){
			out.print(" ");
			out.print(i+1);
		}
		for(int i = 0;i < n-3*k;i++){
			out.print(" ");
			out.print(pa);
		}
		for(int i = 0;i < k;i++){
			out.print(" ");
			out.print(k-i);
		}
		out.println();
	}
	
	boolean check(int[] a, int k)
	{
		List<List<Integer>> l = new ArrayList<List<Integer>>();
		for(int i = 0;i < k;i++)l.add(new ArrayList<Integer>());
		for(int i = 0;i < a.length;i++){
			l.get(a[i]-1).add(i);
		}
		for(int i = 0;i < k;i++){
			if(l.get(i).size() <= 2){
				tr("nosize", i, l.get(i).size());
				return false;
			}
			boolean ap = true;
			for(int j = 0;j < l.get(i).size()-2;j++){
				if(l.get(i).get(j+1)*2 != l.get(i).get(j)+l.get(i).get(j+2)){
					ap = false;
				}
			}
			if(ap){
				tr("ap", i, l.get(i));
				return false;
			}
		}
		return true;
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