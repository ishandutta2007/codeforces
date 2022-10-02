//package round293;
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
		int Q = 1999999999;
		int L = -1100000000;
		int H = 1100000000;
		int n = ni(), K = ni();
		int[] a = new int[n+2*K];
		for(int i = 0;i < K;i++)a[i] = L;
		for(int i = 0;i < K;i++)a[i+n+K] = H;
		for(int i = 0;i < n;i++){
			String s = ns();
			if(s.equals("?")){
				a[i+K] = Q;
			}else{
				a[i+K] = Integer.parseInt(s);
			}
		}
		String IS = "Incorrect sequence";
		for(int i = 0;i < K;i++){
			for(int j = i;j < n+K;){
				int k = j+K;
				assert a[j] != Q;
				for(;k < n+2*K && a[k] == Q;k+=K);
				int qc = (k-j)/K-1;
				int ql = a[j];
				int qr = a[k];
				if(ql+qc >= qr){
					out.println(IS);
					return;
				}
				
				if(qc > 0){
					// count
					if(ql < -qc/2 && -qc/2+qc-1 < qr){
						// [-qc/2, -qc/2+qc-1]
						for(int u = j+K, v = -qc/2;u < k;u += K, v++){
							a[u] = v;
						}
					}else if(qc % 2 == 0 && ql < -qc/2+1 && -qc/2+qc < qr){
						for(int u = j+K, v = -qc/2+1;u < k;u += K, v++){
							a[u] = v;
						}
					}else{
						// L
						long lsum = 0;
						for(int t = 1;t <= qc;t++)lsum += Math.abs(ql+t);
						long rsum = 0;
						for(int t = 1;t <= qc;t++)rsum += Math.abs(qr-t);
						if(lsum < rsum){
							for(int u = j+K, v = ql+1;u < k;u += K, v++){
								a[u] = v;
							}
						}else{
							for(int u = j+K, v = qr-qc;u < k;u += K, v++){
								a[u] = v;
							}
						}
					}
				}
				j = k;
			}
		}
		
		for(int i = 0;i < n;i++){
			assert a[K+i] != Q;
			out.print(a[K+i] + " ");
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