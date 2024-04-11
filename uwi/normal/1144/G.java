//package round550;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class G {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		
		int[] res = null;
		boolean dec = true;
		for(int i = 1;i < n;i++){
			if(a[i-1] <= a[i]){
				if(res == null)res = check(a, 0, i);
				if(res == null)res = check(a, 0, i-1);
				dec = false;
				break;
			}
		}
		if(dec){
			res = new int[n];
			Arrays.fill(res, 1);
		}
		
		boolean inc = true;
		for(int i = 1;i < n;i++){
			if(a[i-1] >= a[i]){
				if(res == null)res = check(a, i, 0);
				if(res == null)res = check(a, i-1, 0);
				inc = false;
				break;
			}
		}
		if(inc && res == null){
			res = new int[n];
			Arrays.fill(res, 0);
		}
		if(res == null){
			out.println("NO");
		}else{
			out.println("YES");
			
//			check(a, res);
			for(int v : res){
				out.print(v + " " );
			}
			out.println();
		}
	}
	
	void check(int[] a, int[] res)
	{
		int inc = -1, dec = Integer.MAX_VALUE;
		for(int i = 0;i < a.length;i++){
			if(res[i] == 1){
				if(dec > a[i]){
					dec = a[i];
				}else{
					throw new RuntimeException("" + i);
				}
			}else{
				if(inc < a[i]){
					inc = a[i];
				}else{
					throw new RuntimeException("" + i);
				}
			}
		}
	}
	
	int[] check(int[] a, int ds, int is)
	{
		if(is == ds || is < 0 || ds < 0)return null;
		int inc = 0, dec = 0;
		int n = a.length;
		int[] res = new int[n];
		if(is < ds){
			for(int i = 0;i < ds-1;i++){
				assert a[i] < a[i+1];
			}
			res[ds] = 1;
			inc = a[ds-1];
			dec = a[ds];
		}else{
			for(int i = 0;i < is-1;i++){
				assert a[i] > a[i+1];
			}
			for(int i = 0;i < is;i++)res[i] = 1;
			dec = a[is-1];
			inc = a[is];
		}
		int temp = -1;
//		tr(a, is, ds, inc, dec);
		for(int i = Math.max(is, ds)+1;i < n;i++){
			if(inc < a[i] && a[i] < dec){
				if(temp == -1){
					temp = i;
				}else{
					if(a[temp] < a[i]){
						inc = a[temp];
						temp = i;
					}else if(a[temp] > a[i]){
						dec = a[temp];
						res[temp] = 1;
						temp = i;
					}else{
						res[temp] = 1;
						inc = dec = a[i];
						temp = -1;
					}
				}
				continue;
			}
			if(a[i] > inc){
				inc = a[i];
				temp = -1;
			}else if(a[i] < dec){
				dec = a[i];
				if(temp != -1)res[temp] = 1;
				res[i] = 1;
				temp = -1;
			}else{
				return null;
			}
		}
		return res;
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
	
	public static void main(String[] args) throws Exception { new G().run(); }
	
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