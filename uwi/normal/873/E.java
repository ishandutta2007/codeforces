//package educational.round30;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int[][] ai = new int[n][];
		for(int i = 0;i < n;i++){
			ai[i] = new int[]{a[i], i};
		}
		Arrays.sort(ai, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return -(a[0] - b[0]);
			}
		});

		int[] diffs = new int[n];
		diffs[n-1] = -ai[n-1][0];
		for(int i = 0;i < n-1;i++){
			diffs[i] = -(ai[i][0] - ai[i+1][0]);
		}
		int[][][] st = buildP(diffs);
		int argi = -1, argj = -1, argk = -1;
		int di = -1, dj = -1, dk = -1;
//		tr(diffs);
		for(int i = 1;i <= n;i++){
			if(-diffs[i-1] >= di){
				for(int j = 1;i+j <= n-1;j++){
					if(-diffs[i-1] > di ||
							-diffs[i-1] == di && -diffs[i+j-1] >= dj){
						if(j <= 2*i && i <= 2*j){
							int kinf = Math.max((i+1)/2, (j+1)/2);
							int ksup = Math.min(n-i-j, Math.min(i*2, j*2));
//							tr(i, j, kinf, ksup);
							if(kinf <= ksup){
								int valk = rmqval(st, i+j+kinf-1, i+j+ksup);
								if(-diffs[i-1] > di ||
										-diffs[i-1] == di && -diffs[i+j-1] > dj ||
										-diffs[i-1] == di && -diffs[i+j-1] == dj && -valk > dk){
									int pos = rmqpos(st, i+j+kinf-1, i+j+ksup);
									di = -diffs[i-1]; dj = -diffs[i+j-1]; dk = -valk;
									argi = i; argj = j; argk = pos+1 - i - j;
//									tr(di, dj, dk, argi, argj, argk);
								}
							}
						}
					}
				}
			}
		}
		
//		out.println(di + " "+  dj + " " + dk);
		
		int[] ans = new int[n];
		Arrays.fill(ans, -1);
		for(int l = 0;l < argi;l++){
			ans[ai[l][1]] = 1;
		}
		for(int l = argi;l < argi+argj;l++){
			ans[ai[l][1]] = 2;
		}
		for(int l = argi+argj;l < argi+argj+argk;l++){
			ans[ai[l][1]] = 3;
		}
		for(int v : ans)out.print(v + " ");
	}
	
	public static int[][][] buildP(int[] a)
	{
		int n = a.length;
		int b = 32-Integer.numberOfLeadingZeros(n);
		int[][] ret = new int[b][];
		int[][] pos = new int[b][];
		for(int i = 0, l = 1;i < b;i++, l*=2) {
			if(i == 0) {
				ret[i] = a;
				pos[i] = new int[n];
				for(int j = 0;j < n;j++)pos[i][j] = j;
			}else {
				ret[i] = new int[n-l+1];
				pos[i] = new int[n-l+1];
				for(int j = 0;j < n-l+1;j++) {
					if(ret[i-1][j] < ret[i-1][j+l/2]){
						ret[i][j] = ret[i-1][j];
						pos[i][j] = pos[i-1][j];
					}else{
						ret[i][j] = ret[i-1][j+l/2];
						pos[i][j] = pos[i-1][j+l/2];
					}
				}
			}
		}
		return new int[][][]{ret, pos};
	}
	
	public static int[][][] buildP(int[] a, int[] ord)
	{
		int n = a.length;
		int b = 32-Integer.numberOfLeadingZeros(n);
		int[][] ret = new int[b][];
		int[][] pos = new int[b][];
		for(int i = 0, l = 1;i < b;i++, l*=2) {
			if(i == 0) {
				ret[i] = a;
				pos[i] = ord;
			}else {
				ret[i] = new int[n-l+1];
				pos[i] = new int[n-l+1];
				for(int j = 0;j < n-l+1;j++) {
					if(ret[i-1][j] < ret[i-1][j+l/2]){
						ret[i][j] = ret[i-1][j];
						pos[i][j] = pos[i-1][j];
					}else{
						ret[i][j] = ret[i-1][j+l/2];
						pos[i][j] = pos[i-1][j+l/2];
					}
				}
			}
		}
		return new int[][][]{ret, pos};
	}
	
	public static int rmqpos(int[][][] st, int a, int b)
	{
		int t = 31-Integer.numberOfLeadingZeros(b-a);
		if(st[0][t][a] < st[0][t][b-(1<<t)]){
			return st[1][t][a];
		}else{
			return st[1][t][b-(1<<t)];
		}
	}
	
	public static int rmqval(int[][][] st, int a, int b)
	{
		int t = 31-Integer.numberOfLeadingZeros(b-a);
		if(st[0][t][a] < st[0][t][b-(1<<t)]){
			return st[0][t][a];
		}else{
			return st[0][t][b-(1<<t)];
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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