//package round475;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		ps = new long[n][];
		for(int i = 0;i < n;i++){
			ps[i] = new long[]{nl(), nl(), nl()};
		}
		W = 0;
		{
			Arrays.sort(ps, new Comparator<long[]>() {
				public int compare(long[] a, long[] b) {
					return Long.compare(a[0], b[0]);
				}
			});
			int same = 0;
			for(int i = 0;i < n;){
				int j = i;
				while(j < n && ps[i][0] == ps[j][0])j++;
				if(same == 0){
					same = j-i;
				}else if(same != j-i){
					out.println(0);
					return;
				}
				i = j;
			}
			W = same;
		}
		H = 0;
		{
			Arrays.sort(ps, new Comparator<long[]>() {
				public int compare(long[] a, long[] b) {
					return Long.compare(a[1], b[1]);
				}
			});
			int same = 0;
			for(int i = 0;i < n;){
				int j = i;
				while(j < n && ps[i][1] == ps[j][1])j++;
				if(same == 0){
					same = j-i;
				}else if(same != j-i){
					out.println(0);
					return;
				}
				i = j;
			}
			H = same;
		}
		if((long)H*W != n){
			out.println(0);
			return;
		}
		
		Arrays.sort(ps, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				if(a[0] != b[0])return Long.compare(a[0], b[0]);
				return Long.compare(a[1], b[1]);
			}
		});
		
		long[] mods = {1000000007, 1000000009, 998244353};
		for(int i = 0;i < H;i++){
			for(int j = 0;j < W;j++){
				for(long mod : mods){
					if(((ps[i*W+j][2]%mod) * (ps[0][2]%mod) - (ps[i*W+0][2]%mod) * (ps[j][2]%mod)) % mod != 0){
						out.println(0);
						return;
					}
				}
			}
		}
		
		long h = 0;
		for(int i = 0;i < W;i++)h = gcd(h, ps[i][2]);
		long w = 0;
		for(int i = 0;i < H;i++)w = gcd(w, ps[i*W][2]);
		
		int ans = 0;
		long q = ps[0][2];
		for(long d = 1;d*d <= q;d++){
			if(q % d == 0){
				if(h % d == 0 && w % (q/d) == 0)ans++;
				if(d*d < q){
					if(w % d == 0 && h % (q/d) == 0)ans++;
				}
			}
		}
		out.println(ans);
	}
	
	public static long gcd(long a, long b) {
		while (b > 0) {
			long c = a;
			a = b;
			b = c % b;
		}
		return a;
	}
	
	
	int H, W;
	long[][] ps;
	
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