//package round251;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni(), p = ni();
		int[] a = na(n);
		int[] odds = new int[n];
		int[] evens = new int[n];
		int odd = 0, even = 0;
		for(int i = 0;i < n;i++){
			if(a[i] % 2 == 1){
				odds[odd++] = a[i];
			}else{
				evens[even++] = a[i];
			}
		}
		odds = Arrays.copyOf(odds, odd);
		evens = Arrays.copyOf(evens, even);
		
		if(odd % 2 == (K-p) % 2 && odd >= K-p && (odd-(K-p))/2 + (n-odd) >= p){
			out.println("YES");
			int[][] need = new int[K][];
			for(int i = 0;i < K-p;i++){
				need[i] = new int[]{0, 1};
			}
			int leftodd = odd-(K-p);
			int lefteven = n-odd;
			for(int i = K-p;i < K;i++){
				if(lefteven > 0){
					need[i] = new int[]{1, 0};
					lefteven--;
				}else{
					need[i] = new int[]{0, 2};
					leftodd -= 2;
				}
			}
			need[K-1][0] += lefteven;
			need[K-1][1] += leftodd;
			int op = 0, ep = 0;
			for(int i = 0;i < K;i++){
				out.print(need[i][0] + need[i][1]);
				for(int j = 0;j < need[i][0];j++){
					out.print(" "  + evens[ep++]);
				}
				for(int j = 0;j < need[i][1];j++){
					out.print(" "  + odds[op++]);
				}
				out.println();
			}
		}else{
			out.println("NO");
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
	
	public static void main(String[] args) throws Exception { new C2().run(); }
	
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