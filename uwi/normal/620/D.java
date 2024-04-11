//package educational.round06;
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
		int n = ni();
		int[] a = na(n);
		int m = ni();
		int[] b = na(m);
		long asum = Arrays.stream(a).asLongStream().sum();
		long bsum = Arrays.stream(b).asLongStream().sum();
		long min = Math.abs(asum-bsum);
		long[] args = new long[]{0};
		
		// K=1
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				long v = Math.abs(asum-bsum-2L*a[i]+2L*b[j]);
				if(v < min){
					min = v;
					args = new long[]{1, i, j};
				}
			}
		}
		
		// K=2
		long[] a2 = new long[n*(n-1)/2];
		int p = 0;
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				a2[p++] = 2L*(a[i] + a[j]);
			}
		}
		Arrays.sort(a2);
		for(int i = 0;i < m;i++){
			for(int j = i+1;j < m;j++){
				long b2 = b[i] + b[j];
				// asum - bsum - a2 + b2
				int ind = Arrays.binarySearch(a2, asum - bsum + 2L*b2);
				if(ind >= 0){
					min = 0;
					args = new long[]{2, a2[ind], i, j};
				}else{
					{
						int l = -ind-2;
						if(l >= 0){
							long v = Math.abs(asum-bsum+2L*b2-a2[l]);
							if(v < min){
								min = v;
								args = new long[]{2, a2[l], i, j};
							}
						}
					}
					{
						int l = -ind-1;
						if(l < a2.length){
							long v = Math.abs(asum-bsum+2L*b2-a2[l]);
							if(v < min){
								min = v;
								args = new long[]{2, a2[l], i, j};
							}
						}
					}
				}
			}
		}
		
		if(args[0] == 2){
			for(int i = 0;i < n;i++){
				for(int j = i+1;j < n;j++){
					if(2L*(a[i] + a[j]) == args[1]){
						out.println(min);
						out.println(2);
						out.println((i+1) + " " + (args[2]+1));
						out.println((j+1) + " " + (args[3]+1));
						return;
					}
				}
			}
		}else if(args[0] == 1){
			out.println(min);
			out.println(1);
			out.println((args[1]+1) + " " + (args[2]+1));
		}else{
			out.println(min);
			out.println(0);
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