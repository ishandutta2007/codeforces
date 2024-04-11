//package round631;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		// 7 6 3 5 4 2 1
		// 7 6 2 5 4 - 1
		// 7 5 2 - 4 - 1
		// 7 5 1 - 4 - -
		// 5 4 1 - - - -
		
		// 6 5 3 - 4 2 1
		// 5 4 3 - - 2 1
		// 5 4 2 - - - 1

		// 7654321
		// 645-321
		// 542-3-1
		// 432---1
		
		for(int T = ni();T > 0;T--){
			go();
		}
	}
	
	void go()
	{
		int n = ni(), m = ni();
		int[] a = na((1<<n)-1);
		int cur = 1;
		
		int[] route = new int[(1<<n)-(1<<m)];
		for(int rep = 0;rep < (1<<n)-(1<<m);rep++){
			while(true){
				int last = -1;
				for(int i = cur;;){
					if(2*i >= 1<<n){
						last = i;
						break;
					}
					int l = 2*i, r = 2*i+1;
					if(a[l-1] == -1 && a[r-1] == -1){
						last = i;
						break;
					}
					if(a[l-1] > a[r-1]){
						i = l;
					}else{
						i = r;
					}
				}
				if(last >= 1<<m){
					route[rep] = cur;
					for(int i = cur;;){
						if(2*i >= 1<<n){
							break;
						}
						int l = 2*i, r = 2*i+1;
						if(a[l-1] == -1 && a[r-1] == -1){
							break;
						}
						if(a[l-1] > a[r-1]){
							a[i-1] = a[l-1];
							a[l-1] = -1;
							i = l;
						}else{
							a[i-1] = a[r-1];
							a[r-1] = -1;
							i = r;
						}
					}
					break;
				}else{
					cur++;
				}
			}
		}
		
		long s = 0;
		for(int i = 0;i < (1<<m)-1;i++)s += a[i];
		out.println(s);
		for(int i = 0;i < route.length;i++){
			out.print(route[i] + " ");
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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