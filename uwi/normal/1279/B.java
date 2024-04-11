//package educational.round79;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T > 0;T--){
			int n = ni(), K = ni();
			int[] a = na(n);
			int p = 0;
			int L = K;
			for(int i = 0;i < n;i++){
				if(a[i] <= L){
					L -= a[i];
					p++;
				}else{
					break;
				}
			}
			int op = p;
			int max = -1;
			int arg = -1;
			for(int i = 0;i <= p && i < n;i++){
				if(a[i] > max){
					max = a[i];
					arg = i;
				}
			}
			
			L = K;
			p = 0;
			for(int i = 0;i < n;i++){
				if(arg == i)continue;
				if(a[i] <= L){
					L -= a[i];
					p++;
				}else{
					break;
				}
			}
			int ans = p > op ? arg+1 : 0;
//			check(ans, a, K);
			if(p > op){
				out.println(arg+1);
			}else{
				out.println(0);
			}
		}
	}
	
	void check(int ans, int[] a, int K)
	{
		int n = a.length;
		long rem = K;
		int p = 0;
		for(int j = 0;j < n;j++){
			if(a[j] <= rem){
				rem -= a[j];
				p++;
			}else{
				break;
			}
		}
		int bes = 0;
		int np = p;
		if(ans == 0)bes = np;
		for(int i = 0;i < n;i++){
			rem = K;
			p = 0;
			for(int j = 0;j < n;j++){
				if(i == j)continue;
				if(a[j] <= rem){
					rem -= a[j];
					p++;
				}else{
					break;
				}
			}
			np = Math.max(np, p);
			if(i == ans-1){
				bes = p;
			}
		}
		assert bes == np;
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
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;
	
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