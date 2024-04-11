//package round624;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T > 0;T--){
			int n = ni(), d = ni();
			int low = 0;
			for(int i = 0;i < n;i++){
				low += Integer.numberOfTrailingZeros(Integer.highestOneBit(i+1));
			}
			if(d < low || d > n*(n-1)/2){
				out.println("NO");
			}else{
				out.println("YES");
				int x = n*(n-1)/2;
				int[] par = new int[n];
				for(int i = 1;i < n;i++){
					par[i] = i-1;
				}
				int[] dep = new int[n];
				int[] ch = new int[n];
				for(int i = 0;i < n;i++){
					ch[i] = i < n-1 ? 1 : 0;
					dep[i] = i;
				}
				out:
				for(int i = n-1;i >= 2 && x > d;i--){
					int j = i-1;
					ch[par[i]]--;
					ch[i] = 0;
					while(x > d && j >= 1){
						if(ch[j-1] == 2){
//							tr("i", i, ch[n-1], dep[j-1]);
							for(int k = 0;k < n;k++){
								if(k == i)continue;
								if(dep[k] == dep[j-1] && ch[k] < 2){
//									tr("K", k);
									ch[j]--;
									par[i] = k;
									dep[i] = dep[k] + 1;
									x--;
									ch[k]++;
									continue out;
								}
							}
							break;
						}
						ch[j]--;
						j--;
						par[i] = j;
						ch[j]++;
						dep[i]--;
						x--;
//						tr(par, x, dep);
					}
				}
				assert x == d;
				for(int j = 1;j < n;j++){
					out.print(par[j]+1 + " ");
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
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
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