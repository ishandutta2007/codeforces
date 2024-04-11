//package round190;
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
		int n = ni(), m = ni();
		int[] atk = new int[n];
		int[] def = new int[n];
		int ap = 0, dp = 0;
		for(int i = 0;i < n;i++){
			char ad = nc();
			if(ad == 'A'){
				atk[ap++] = ni();
			}else{
				def[dp++] = ni();
			}
		}
		
		int[] my = na(m);
		Arrays.sort(atk, 0, ap);
		Arrays.sort(def, 0, dp);
		Arrays.sort(my);
		boolean[] used = new boolean[m];
		int p = 0;
		boolean canbeat = true;
		for(int i = 0;i < dp;i++){
			while(p < m && def[i] >= my[p])p++;
			if(p == m){
				canbeat = false;
				Arrays.fill(used, false);
				break;
			}
			used[p++] = true;
		}
		
		int max = 0;
		if(canbeat){
			outer:
			for(int i = ap;i >= 0;i--){ // canbeat #i
				boolean[] lused = Arrays.copyOf(used, m);
				p = m-1;
				int dmg = 0;
				for(int j = i-1;j >= 0;j--){
					while(p >= 0 && lused[p])p--;
					if(p < 0 || my[p] < atk[j]){
						continue outer;
					}
					dmg += my[p]-atk[j];
					lused[p] = true;
				}
				
				if(i == ap){
					for(int j = 0;j < m;j++){
						if(!lused[j]){
							dmg += my[j];
						}
					}
				}
				max = Math.max(max, dmg);
			}
		}
		
		outer:
		for(int i = ap;i >= 0;i--){ // canbeat #i
			boolean[] lused = new boolean[m];
			p = m-1;
			int dmg = 0;
			for(int j = i-1;j >= 0;j--){
				while(p >= 0 && lused[p])p--;
				if(p < 0 || my[p] < atk[j]){
					continue outer;
				}
				dmg += my[p]-atk[j];
				lused[p] = true;
			}
			max = Math.max(max, dmg);
		}
		
		out.println(max);
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