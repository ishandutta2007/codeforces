//package lyft2018;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int w = ni(), n = ni(), m = ni();
		int[] a = na(n);
		int[] f = new int[1<<w];
		for(int v : a)f[v]++;
		
		// and,or,xor
		// 00 11 01or10
		// 2^12
		
		int[] p3 = new int[w+1];
		p3[0] = 1;
		for(int i = 0;i < w;i++){
			p3[i+1] = p3[i] * 3;
		}
		int[] gf = new int[p3[w]];
		
		int[] plus3 = new int[1<<w];
		for(int i = 0;i < 1<<w;i++){
			int h = 0;
			for(int j = w-1;j >= 0;j--){
				h = h * 3 + (i>>>j&1);
			}
			gf[h] += f[i];
			plus3[i] = h;
		}
		
		for(int k = 0;k < w;k++){
			int[] b = new int[w];
			int p = 0;
			do{
				if(b[w-1-k] < 2){
					gf[p+p3[k] * (2-b[w-1-k])] += gf[p];
				}
				p++;
			}while(inc(b, 3));
		}
		
		for(int z = 0;z < m;z++){
			char[] s = ns(w);
			int amask = 0, omask = 0, xmask = 0;
			int tar = 0;
			for(int i = w-1;i >= 0;i--){
				if(s[i] >= 'a' && s[i] <= 'z'){
					tar |= 1<<w-i-1;
				}
				if(s[i] == 'A' || s[i] == 'a')amask |= 1<<w-1-i;
				if(s[i] == 'O' || s[i] == 'o')omask |= 1<<w-1-i;
				if(s[i] == 'X' || s[i] == 'x')xmask |= 1<<w-1-i;
			}
			int must0 = 0;
			int must1 = 0;
			for(int i = 0;i < w;i++){
				if(amask<<~i<0 && tar<<~i<0)must1 |= 1<<i;
				if(omask<<~i<0 && tar<<~i>=0)must0 |= 1<<i;
			}
			int must = must0|must1;
			
			// a
			// L res R
			// 0 0 2
			// 1 0 0
			// 1 1 1
			
			// o
			// L res R
			// 0 0 0
			// 0 1 1
			// 1 1 2
			
			long ans = 0;
			for(int i = 0;i < 1<<w;i++){
				if((i&must) != must1)continue;
				int x = plus3[(i^tar)&xmask];
				int o = plus3[i&omask] + plus3[tar&omask];
				int A = plus3[i&amask&tar] // L = 1
						+ plus3[amask^i&amask]*2;
				ans += f[i] * gf[A+o+x];
			}
//			for(int i = 0;i < 1<<w;i++){
//				int t = i&~xmask;
//				if(t == tar){
//					ans -=f[i] * f[i];
//					
//				}
//			}
			out.println(ans);
		}
	}
	
	public static boolean inc(int[] a, int base) {
		int n = a.length;
		int i;
		for (i = n - 1; i >= 0 && a[i] == base - 1; i--)
			;
		if (i == -1)
			return false;

		a[i]++;
		Arrays.fill(a, i + 1, n, 0);
		return true;
	}

	
	public static int[] zetaTransform(int[] f)
	{
		int H = Integer.numberOfTrailingZeros(f.length);
		for(int i = 0;i < H;i++){
			for(int j = 0;j < 1<<H;j++){
				if(j<<~i>=0){
					f[j] += f[j|1<<i];
				}
			}
		}
		return f;
	}

	
	void run() throws Exception
	{
//		int n = 30000, m = 50000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(12 + " ");
//		sb.append(n + " ");
//		sb.append(m + "\n");
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(1<<12) + " ");
//		}
//		sb.append("\n");
//		for (int i = 0; i < m; i++) {
//			char[] x = "AOXaox".toCharArray();
//			for(int j = 0;j < 12;j++){
//				sb.append(x[gen.nextInt(6)]);
//			}
//			sb.append("\n");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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