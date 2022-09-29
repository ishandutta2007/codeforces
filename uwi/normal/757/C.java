//package round391;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.Random;

public class C4 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int mod = 1000000007;
		L[] list = new L[m];
		for(int i = 0;i < m;i++)list[i] = new L(1);
		
		Random gen = new Random();
		for(int i = 0;i < n;i++){
			int L = ni();
			int[] a = na(L);
			a = shuffle(a, gen);
			Arrays.sort(a);
			for(int j = 0;j < a.length;){
				int k = j;
				while(k < a.length && a[k] == a[j])k++;
				
				list[a[j]-1].add(i);
				list[a[j]-1].add(k-j);
				
				j = k;
			}
		}
		
		Comparator<L> comp = (x,y) -> {
			if(x.size() != y.size())return x.size() - y.size();
			for(int i = 0;i < x.size();i++){
				if(x.a[i] != y.a[i])return x.a[i]-y.a[i];
			}
			return 0;
		};
		Arrays.sort(list, comp);
		
		L pre = null;
		int[][] fif = enumFIF(m+1, mod);
		long ret = 1;
		int same = 1;
		for(L item : list){
			if(pre == null || comp.compare(item, pre) != 0){
				ret = ret * fif[0][same] % mod;
				same = 0;
			}
			same++;
			pre = item;
		}
		ret = ret * fif[0][same] % mod;
		out.println(ret);
	}
	
	public static class L {
		public int[] a;
		public int p = 0;
		
		public L(int n) { a = new int[n]; }
		public L add(int n)
		{
			if(p >= a.length)a = Arrays.copyOf(a, a.length*3/2+1);
			a[p++] = n;
			return this;
		}
		public int size() { return p; }
		public L clear() { p = 0; return this; }
		public int[] toArray() { return Arrays.copyOf(a, p); }
		@Override
		public String toString() {return Arrays.toString(toArray());}
	}
	
	public static int[][] enumFIF(int n, int mod) {
		int[] f = new int[n + 1];
		int[] invf = new int[n + 1];
		f[0] = 1;
		for (int i = 1; i <= n; i++) {
			f[i] = (int) ((long) f[i - 1] * i % mod);
		}
		long a = f[n];
		long b = mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d;
			d = a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		invf[n] = (int) (p < 0 ? p + mod : p);
		for (int i = n - 1; i >= 0; i--) {
			invf[i] = (int) ((long) invf[i + 1] * (i + 1) % mod);
		}
		return new int[][] { f, invf };
	}

	
	public static int[] shuffle(int[] a, Random gen){ for(int i = 0, n = a.length;i < n;i++){ int ind = gen.nextInt(n-i)+i; int d = a[i]; a[i] = a[ind]; a[ind] = d; } return a; }

	void run() throws Exception
	{
//		Random gen = new Random(1000000009L);
//		StringBuilder sb = new StringBuilder();
//		int n = 100000;
//		int m = 1000000;
//		sb.append(n + " ");
//		sb.append(m + "\n");
//		for(int i = 0;i < n;i++){
//			sb.append(5 + " ");
//			for(int j = 0;j < 5;j++){
//				sb.append(gen.nextInt(1000000)+1 + "\n");
//			}
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new C4().run(); }
	
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