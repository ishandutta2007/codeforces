//package round374;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.PriorityQueue;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(),  K = ni(), x = ni();
		long[] a = new long[n];
		for(int i = 0;i < n;i++)a[i] = nl();
		int prod = 1;
		int sg = 1;
		for(long v : a){
			if(v < 0){
				prod = -prod;
				sg = -sg;
			}else if(v == 0){
				prod = 0;
			}
		}
		if(prod > 0){
			int arg = 0;
			for(int i = 0;i < n;i++){
				if(Math.abs(a[i]) < Math.abs(a[arg])){
					arg = i;
				}
			}
			int first = Long.signum(a[arg]);
			while(K > 0 && Long.signum(a[arg]) == first){
				if(first > 0){
					a[arg] -= x;
				}else{
					a[arg] += x;
				}
				K--;
			}
			
			prod = 1;
			sg = 1;
			for(long v : a){
				if(v < 0){
					prod = -prod;
					sg = -sg;
				}else if(v == 0){
					prod = 0;
				}
			}
		}
		
		PriorityQueue<long[]> pq = new PriorityQueue<>(100000, (u,v) -> Long.compare(Math.abs(u[0]), Math.abs(v[0])));
		for(int i = 0;i < n;i++){
			pq.add(new long[]{a[i], i});
		}
		for(int i = 0;i < K;i++){
			long[] cur = pq.poll();
			if(cur[0] > 0){
				cur[0] += x;
			}else if(cur[0] < 0){
				cur[0] -= x;
			}else if(sg == 1){
				cur[0] -= x;
				sg = -sg;
			}else{
				cur[0] += x;
			}
			pq.add(cur);
		}
		for(long[] cur : pq){
			a[(int)cur[1]] = cur[0];
		}
		for(int i = 0;i < n;i++){
			out.print(a[i] + " ");
		}
		out.println();
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