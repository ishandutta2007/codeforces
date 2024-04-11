//package round426;
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
	
	long L, R;
	int[] r = new int[18];
	boolean ex = false;
	
	void solve()
	{
		L = nl(); R = nl();
		if(R == 1000000000000000000L){
			if(L == R){
				out.println(1);
				return;
			}
			R = 999999999999999999L;
			ex = true;
		}
		String zr = ("0000000000000000000" + Long.toString(R));
		zr = zr.substring(zr.length()-18);
		char[] zrc = zr.toCharArray();
		for(int i = 0;i < 18;i++){
			r[i] = zrc[i]-'0';
		}
		pten[0] = 1;
		for(int i = 1;i <= 18;i++){
			pten[i] = pten[i-1] * 10;
		}
		
		dfs(18, 0, new int[10]);
		out.println(ct);
	}
	
	int ct = 0;
	int[] hist = new int[18];
	int[] hist2 = new int[18];
	long[] pten = new long[19];
	
	void check(int[] f)
	{
		if(f[0] == 17 && f[1] == 1 && ex){
			ct++;
			return;
		}
		int xp = 0;
//		System.arraycopy(f, 0, g, 0, 10);
		boolean edge = true;
		long num = 0;
		int min = 9;
		outer:
		for(int i = 0;i < 18;i++){
			inner:
			for(int j = edge?r[i]:min;j >= 0;j--){
				if(f[j] > 0){
					if(edge && j == r[i]){
						int hp = 0;
//						System.arraycopy(f, 0, temp, 0, 10);
						f[j]--;
						hist[hp++] = j;
						int p = 0;
						for(int k = i+1;k < 18;k++){
							while(p < 9 && f[p] == 0)p++;
							if(p < r[k]){
								// ok
								break;
							}else if(p > r[k]){
								while(hp > 0)f[hist[--hp]]++;
//								System.arraycopy(temp, 0, f, 0, 10);
								continue inner;
							}
							f[p]--;
							hist[hp++] = p;
						}
						while(hp > 0)f[hist[--hp]]++;
//						System.arraycopy(temp, 0, f, 0, 10);
					}
					if(!edge)min = j;
					num += j * pten[17-i];
					if(num >= L){ct++; 
					while(xp > 0)f[hist2[--xp]]++;
					return;}
					if(num+pten[17-i] <= L){ 
					while(xp > 0)f[hist2[--xp]]++;
					return;}
					
					f[j]--;
					hist2[xp++] = j;
//					num = num * 10 + j;
					if(j < r[i])edge = false;
					continue outer;
				}
			}
			while(xp > 0)f[hist2[--xp]]++;
//			System.arraycopy(g, 0, f, 0, 10);
			return;
		}
		if(num >= L)ct++;
		while(xp > 0)f[hist2[--xp]]++;
	}
	
	void dfs(int rem, int cur, int[] f)
	{
		if(cur == 9){
			f[cur] = rem;
			check(f);
			return;
		}
		
		for(int i = 0;i <= rem && i <= 18;i++){
			f[cur] = i;
			dfs(rem-i, cur+1, f);
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