//package neerc2017;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni(), m = ni(), A = ni();
		int[] a = na(A);
		for(int i = 0;i < A;i++)a[i]--;
		int[] f = new int[n];
		int[] last = new int[n];
		Arrays.fill(last, -1);
		for(int i = 0;i < A;i++){
			f[a[i]]++;
			last[a[i]] = i;
		}
		for(int i = 0;i < n;i++){
			int flag = 0;
			{
				int[] lf = Arrays.copyOf(f, n);
				int[] llast = Arrays.copyOf(last, n);
				lf[i] += m-A;
				if(m-A > 0)llast[i] = m-1;
				flag |= ok(lf, llast, K, i) ? 2 : 0;
			}
			{
				int[][] fl = new int[n-1][];
				int p = 0;
				for(int j = 0;j < n;j++){
					if(j == i)continue;
					fl[p++] = new int[]{f[j], last[j], j};
				}
				Arrays.sort(fl, new Comparator<int[]>() {
					public int compare(int[] a, int[] b) {
						if(a[0] != b[0])return -(a[0] - b[0]);
						return a[1] - b[1];
					}
				});

				int[] lf = Arrays.copyOf(f, n);
				int[] llast = Arrays.copyOf(last, n);
				int rem = m-A;
				for(int j = 0;j < n-1;j++){
					int fv = fl[j][0], lv = fl[j][1];
					if(fv > lf[i] || fv == lf[i] && lv < llast[i])continue;
					int up = Math.min(rem, lf[i]+1-fv);
					rem -= up;
					lf[fl[j][2]] += up;
					llast[fl[j][2]] = m-1;
				}
				flag |= ok(lf, llast, K, i) ? 1 : 0;
			}
			if(flag == 3){
				out.print(1 + " ");
			}else if(flag == 2){
				out.print(2 + " ");
			}else if(flag == 0){
				out.print(3 + " ");
			}else{
				throw new RuntimeException();
			}
		}
	}
	
	boolean ok(int[] f, int[] last, int K, int who)
	{
		if(f[who] == 0)return false;
		int n = f.length;
		int rank = 1;
		for(int i = 0;i < n;i++){
			if(i == who)continue;
			if(f[i] > f[who] || f[i] == f[who] && last[i] < last[who])rank++;
		}
		return rank <= K;
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
	
	public static void main(String[] args) throws Exception { new F2().run(); }
	
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