//package round262;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long L = nl(), R = nl();
		int K = ni();
		int n = (int)(R-L+1);
		if(K == 1){
			out.println(L);
			out.println(1);
			out.println(L);
		}else if(K == 2){
			long b = (L+1)/2*2;
			if(b+1 <= R){
				out.println(1);
				out.println(2);
				out.println((b) + " " + (b+1) + " ");
				if((b^b+1) != 1)throw new RuntimeException();
			}else if(L <= (L^R)){
				out.println(L);
				out.println(1);
				out.println(L);
			}else{
				out.println(L^R);
				out.println(2);
				out.println(L + " " + R);
			}
		}else if(K == 3){
			// a^b^c=0?
			if(Long.highestOneBit(L) < Long.highestOneBit(R)){
				long hl = Long.highestOneBit(L);
				if(hl*3 <= R){
					out.println(0);
					out.println(3);
					out.println((hl*2-1) + " " + (hl*3-1) + " " + (hl*3));
					if(((hl*2-1)^(hl*3-1)^(hl*3)) != 0)throw new RuntimeException();
					return;
				}
			}
			long b = (L+1)/2*2;
			out.println(1);
			out.println(2);
			out.println((b) + " " + (b+1) + " ");
			if((b^b+1) != 1)throw new RuntimeException();
		}else if(K >= 4){
			long b = (L+3)/4*4;
			if(b+3 <= R){
				out.println(0);
				out.println(4);
				out.println((b) + " " + (b+1) + " " + (b+2) + " " + (b+3));
				if((b^b+1^b+2^b+3) != 0)throw new RuntimeException();
			}else{
				long ret = Long.MAX_VALUE;
				int reti = -1;
				for(int i = 1;i < 1<<n;i++){
					if(Integer.bitCount(i) > K)continue;
					long x = 0;
					for(int j = 0;j < n;j++){
						if(i<<31-j<0){
							x ^= L+j;
						}
					}
					if(x < ret){
						ret = x;
						reti = i;
					}
				}
				out.println(ret);
				out.println(Integer.bitCount(reti));
				for(int j = 0;j < n;j++){
					if(reti<<31-j<0){
						out.print(L+j+" ");
					}
				}
				out.println();
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