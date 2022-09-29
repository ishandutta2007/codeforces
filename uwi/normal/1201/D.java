//package round577;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), K = ni(), Q = ni();
		int[][] co = new int[K][];
		for(int i = 0;i < K;i++){
			co[i] = new int[]{ni(), ni()};
		}
		Arrays.sort(co, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return a[1] - b[1];
			}
		});
		int[] b = na(Q);
		b = radixSort(b);
		
		long base = co[K-1][0]-1;
		int pitl = 1;
		long vall = base;
		int pitr = 1;
		long valr = base;
		// max(|c-pitl|+vall, |c-pitr|+valr)
		
		for(int i = 0;i < K;){
			int j = i;
			while(j < K && co[j][0] == co[i][0])j++;
			
			if(co[i][0] == 1){
				pitl = pitr = co[j-1][1];
				vall = valr = base + co[j-1][1]-1;
			}else{
				int L = co[i][1], R = co[j-1][1];
				// |c-pit|+val+|c-L| for each c in b
				long lmin = Long.MAX_VALUE;
				for(int C : new int[]{pitl, L}){
					lmin = Math.min(lmin, min(b, C, pitl, vall, L));
				}
				for(int C : new int[]{pitr, L}){
					lmin = Math.min(lmin, min(b, C, pitr, valr, L));
				}
				long rmin = Long.MAX_VALUE;
				for(int C : new int[]{pitl, R}){
					rmin = Math.min(rmin, min(b, C, pitl, vall, R));
				}
				for(int C : new int[]{pitr, R}){
					rmin = Math.min(rmin, min(b, C, pitr, valr, R));
				}
				pitl = L; pitr = R;
				vall = rmin + (R-L);
				valr = lmin + (R-L);
			}
			
			i = j;
		}
		out.println(Math.min(vall, valr));
	}
	
	long min(int[] b, int C, int pit, long val, long L)
	{
		long lmin = Long.MAX_VALUE;
		int ind = Arrays.binarySearch(b, C);
		if(ind >= 0){
			lmin = Math.min(lmin, f(b[ind], pit, val, L));
		}else if(ind < 0){
			if(-ind-2 >= 0)lmin = Math.min(lmin, f(b[-ind-2], pit, val, L));
			if(-ind-1 < b.length)lmin = Math.min(lmin, f(b[-ind-1], pit, val, L));
		}
		return lmin;
	}
	
	long f(long c, int pit, long val, long L)
	{
		return Math.abs(c-pit) + val + Math.abs(c-L);
	}
	
	public static int[] radixSort(int[] f){ return radixSort(f, f.length); }
	public static int[] radixSort(int[] f, int n)
	{
		int[] to = new int[n];
		{
			int[] b = new int[65537];
			for(int i = 0;i < n;i++)b[1+(f[i]&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < n;i++)to[b[f[i]&0xffff]++] = f[i];
			int[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < n;i++)b[1+(f[i]>>>16)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < n;i++)to[b[f[i]>>>16]++] = f[i];
			int[] d = f; f = to;to = d;
		}
		return f;
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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