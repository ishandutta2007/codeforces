//package memsql2017.f;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), S = ni();
		int[][] mems = new int[n][];
		long ssum = 0;
		for(int i = 0;i < n;i++){
			mems[i] = new int[]{ni(), ni(), ni(), 0};
			mems[i][3] = mems[i][0];
			ssum += mems[i][0];
		}
		ssum = (ssum+S-1)/S;
		Arrays.sort(mems, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return (a[1]-a[2]) - (b[1]-b[2]);
			}
		});
		long low = 0, high = ssum+1;
		while(high - low > 2){
			long nl = low + (high - low)/3;
			long nh = high + (low - high)/3;
			long vl = f(nl, S, ssum, mems);
			long vh = f(nh, S, ssum, mems);
			if(vl > vh){
				high = nh;
			}else{
				low = nl;
			}
		}
		long ans = 0;
		for(long h = Math.max(0, low-3);h <= Math.min(high+3, ssum);h++){
			long v = f(h, S, ssum, mems);
			ans = Math.max(ans, v);
		}
		out.println(ans);
	}
	
	long f(long h, long S, long all, int[][] mems)
	{
		long x = h*S, y = all*S-h*S;
		long ret = 0;
		for(int i = 0;i < mems.length;i++){
			int[] mem = mems[i];
			if(mem[1] < mem[2]){
				long num = Math.min(mem[3], y);
				ret += mem[2] * num;
				y -= num;
				mem[3] -= num;
			}
		}
		for(int i = mems.length-1;i >= 0;i--){
			int[] mem = mems[i];
			if(mem[1] > mem[2]){
				long num = Math.min(mem[3], x);
				ret += mem[1] * num;
				x -= num;
				mem[3] -= num;
			}
		}
		for(int i = 0;i < mems.length;i++){
			int[] mem = mems[i];
			long num = Math.min(mem[3], y);
			ret += mem[2] * num;
			y -= num;
			mem[3] -= num;
		}
		for(int i = mems.length-1;i >= 0;i--){
			int[] mem = mems[i];
			long num = Math.min(mem[3], x);
			ret += mem[1] * num;
			x -= num;
			mem[3] -= num;
		}
		for(int[] mem : mems){
			mem[3] = mem[0];
		}
		return ret;
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