//package round412;
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
		// 500b-2b*mins
		int n = ni();
		int[][] time = new int[n][];
		for(int i = 0;i < n;i++){
			time[i] = na(5);
		}
		int[][] sd = new int[5][7];
		int L = 120*33;
		boolean[][][] needs = new boolean[5][7][120*33];
		for(int i = 0;i < 5;i++){
			int solved = 0;
			for(int j = 0;j < n;j++){
				if(time[j][i] != -1)solved++;
			}
			
			for(int b = 1;b <= 6;b++){
				int s1 = time[0][i] == -1 ? 0 : 500*b-2*b*time[0][i];
				int s2 = time[1][i] == -1 ? 0 : 500*b-2*b*time[1][i];
				sd[i][b] = s1-s2;
				long N1 = b == 6 ? 0 : 1, D1 = b == 6 ? 1 : 1<<b;
				long N2 = 1, D2 = 1<<b-1;
				if(time[0][i] != -1){
					// N1/D1 < (solved+k)/(n+l) <= N2/D2
					for(int l = 0;l < L;l++){
						long kinf = b == 6 ? 0 : Math.max(0, N1*(n+l)/D1 - solved + 1);
						long ksup = Math.min(l, N2*(n+l)/D2 - solved);
						needs[i][b][l] = kinf <= ksup;
					}
				}else{
					// N1/D1 < solved/(n+l) <= N2/D2
					for(int l = 0;l < L;l++){
						needs[i][b][l] = 
								(b == 6 || N1*(n+l) < solved*D1) &&
								solved*D2 <= N2*(n+l);
					}
				}
			}
		}
		
		int[] to = new int[5];
		int min = Integer.MAX_VALUE;
		do{
			int sdsum = 0;
			boolean[] temp = new boolean[L];
			Arrays.fill(temp, true);
			for(int i = 0;i < 5;i++){
				sdsum += sd[i][to[i]+1];
				for(int j = 0;j < L;j++){
					temp[j] &= needs[i][to[i]+1][j];
				}
			}
			if(sdsum > 0){
				for(int j = 0;j < L;j++){
					if(temp[j]){
						min = Math.min(min, j);
						break;
					}
				}
			}
		}while(inc(to, 6));
		if(min > 1000000007){
			out.println(-1);
		}else{
			out.println(min);
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