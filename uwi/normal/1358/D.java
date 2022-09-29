//package round645;
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
		long x = nl();
		int[] d = na(n);
		
		int tm = 0;
		long td = 0;
		int hm = 0;
		long hd = 0;
		long rem = x;
		long val = 0;
		while(rem > 0){
			if(rem >= d[hm]){
				rem -= d[hm];
				val += (long)d[hm]*(d[hm]+1)/2;
				hm++;
			}else{
				val += rem*(rem+1)/2;
				hd = rem;
				rem = 0;
				break;
			}
		}
		if(hm >= n)hm = 0;
		long ans = val;
		while(tm < n){
			long hn = d[hm] - hd;
			long tn = d[tm] - td;
			long spent = Math.min(hn, tn);
			if(spent == 0)spent = 1;
			
			{
				long lrem = spent;
				while(lrem > 0){
					if(lrem >= d[hm] - hd){
						lrem -= d[hm] - hd;
						val += (long)d[hm] * (d[hm] + 1) / 2 - hd*(hd+1)/2;
						if(++hm >= n)hm = 0;
						hd = 0;
					}else{
						long nd = hd + lrem;
						val += (long)nd * (nd+1) / 2 - hd*(hd+1)/2;
						lrem = 0;
						hd = nd;
					}
				}
			}
			{
				long lrem = spent;
				while(lrem > 0){
					if(lrem >= d[tm] - td){
						lrem -= d[tm] - td;
						val -= (long)d[tm] * (d[tm] + 1) / 2 - td*(td+1)/2;
						++tm;
//						if(++tm >= n)tm = 0;
						td = 0;
					}else{
						long nd = td + lrem;
						val -= (long)nd * (nd+1) / 2 - td*(td+1)/2;
						lrem = 0;
						td = nd;
					}
				}
			}
			ans = Math.max(ans, val);
		}
		out.println(ans);
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