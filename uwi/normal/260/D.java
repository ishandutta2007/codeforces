//package round158;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.PriorityQueue;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		PriorityQueue<int[]> p0 = new PriorityQueue<int[]>(100000, new Comparator<int[]>(){
			public int compare(int[] a, int[] b){
				return a[0] - b[0];
			}
		});
		PriorityQueue<int[]> p1 = new PriorityQueue<int[]>(100000, new Comparator<int[]>(){
			public int compare(int[] a, int[] b){
				return a[0] - b[0];
			}
		});
		int last0 = -1, last1 = -1;
		for(int i = 0;i < n;i++){
			int c = ni(), sum = ni();
			if(c == 1){
				p1.add(new int[]{sum, i+1});
				last1 = i+1;
			}else{
				p0.add(new int[]{sum, i+1});
				last0 = i+1;
			}
		}
		
		for(int i = 0;i < n-1;i++){
			int[] h0 = p0.poll();
			int[] h1 = p1.poll();
			if(h0[0] < h1[0]){
				out.println(h0[1] + " " + h1[1] + " " + h0[0]);
				h1[0] -= h0[0];
				p1.add(h1);
			}else if(h0[0] > h1[0]){
				out.println(h1[1] + " " + h0[1] + " " + h1[0]);
				h0[0] -= h1[0];
				p0.add(h0);
			}else{
				if(p0.isEmpty()){
					out.println(h1[1] + " " + h0[1] + " " + h1[0]);
					h0[0] -= h1[0];
					p0.add(h0);
				}else{
					out.println(h0[1] + " " + h1[1] + " " + h0[0]);
					h1[0] -= h0[0];
					p1.add(h1);
				}
			}
		}
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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