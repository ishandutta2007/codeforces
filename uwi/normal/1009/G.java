//package educational.round47;
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
		char[] s = ns().toCharArray();
		int[] f = new int[6];
		for(char c : s){
			f[c-'a']++;
		}
		int n = s.length;
		int[] masks = new int[n];
		Arrays.fill(masks, 63);
		int m = ni();
		for(int i = 0;i < m;i++){
			int pos = ni()-1;
			char[] t = ns().toCharArray();
			int q = 0;
			for(char c : t){
				q |= 1<<c-'a';
			}
			masks[pos] = q;
		}
		int[] fm = new int[64];
		for(int ma : masks){
			for(int j = 0;j < 64;j++){
				if((ma&j) != 0){
					fm[j]++;
				}
			}
		}
		
		outer:
		for(int i = 0;i < n;i++){
			for(int j = 0;j < 64;j++){
				if((masks[i]&j) != 0){
					fm[j]--;
				}
			}
//			fm[masks[i]]--;
			for(int j = 0;j < 6;j++){
				if(f[j] == 0)continue;
				if(masks[i]<<~j>=0)continue;
				f[j]--;
				
				if(hasPerfectMatching(f, fm)){
					out.print((char)('a'+j));
					continue outer;
				}
				
				f[j]++;
			}
			fm[masks[i]]++;
			out.println("Impossible");
			return;
		}
	}
	
	boolean hasPerfectMatching(int[] f, int[] fm)
	{
		int n = f.length;
		// ok if all |W| <= |neigh(W)|
		int[] ar = new int[1<<n];
		for(int i = 1;i < 1<<n;i++){
			ar[i] = ar[i&i-1] + f[Integer.numberOfTrailingZeros(i)];
			if(ar[i] > fm[i]){
//				tr(fsum, q[i], i);
				return false;
			}
		}
		return true;
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