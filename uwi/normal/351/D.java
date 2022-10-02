//package round204;
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
		int n = ni();
		int[] a = na(n);
		a = shrink(a);
		int[] freq = new int[n];
		int dist = 0;
		for(int i = 0;i < n;i++){
			freq[a[i]]++;
			dist = Math.max(dist, a[i]);
		}
		dist++;
		
		int[][] g = new int[n][];
		for(int i = 0;i < n;i++){
			g[i] = new int[freq[i]];
		}
		int[] gp = new int[n];
		for(int i = 0;i < n;i++){
			g[a[i]][gp[a[i]]++] = i;
		}
		int Q = ni();
		
		int[][] es = new int[3*n+Q][];
		int p = 0;
		for(int i = 0;i < n;i++){
			int[] row = g[i];
			if(row.length == 0)continue;
			for(int j = 0;j < gp[i];){
				if(j+1 < gp[i]){
					int d = row[j+1]-row[j];
					int k;
					for(k = j+1;k < gp[i] && row[k]-row[k-1] == d;k++);
					int prev = j-1 >= 0 ? row[j-1]+1 : 0;
					int next = k == gp[i] ? n-1 : row[k]-1;
					es[p++] = new int[]{prev, next, -10-i};
					j = k-1;
				}else{
					int prev = j-1 >= 0 ? row[j-1]+1 : 0;
					int next = n-1;
					es[p++] = new int[]{prev, next, -10-i};
					j++;
				}
			}
			if(0 <= row[0]-1)es[p++] = new int[]{0, row[0]-1, -1000000-i};
			for(int j = 0;j < gp[i]-1;j++){
				if(row[j]+1 <= row[j+1]-1)es[p++] = new int[]{row[j]+1, row[j+1]-1, -1000000-i};
			}
			if(row[gp[i]-1]+1 <= n-1)es[p++] = new int[]{row[gp[i]-1]+1, n-1, -1000000-i};
		}
		
		for(int z = 0;z < Q;z++){
			es[p++] = new int[]{ni()-1, ni()-1, z};
		}
		
		Arrays.sort(es, 0, p, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return a[2] - b[2];
			}
		});
		
		int[] ft = new int[n+3];
		int[] okmaxs = new int[n];
		int[] ngmaxs = new int[n];
		Arrays.fill(okmaxs, -1);
		Arrays.fill(ngmaxs, -1);
//		int maxy = -1;
		int all = 0;
		int[] ret = new int[Q];
		int[] ngok = new int[n+10];
		for(int i = 0;i < p;i++){
			int[] e = es[i];
			if(e[2] <= -1000000){
				int ind = -(e[2]+1000000);
				addFenwick(ft, e[1]+1, 1);
				all++;
				addFenwick(ngok, ngmaxs[ind]+1, -1);
				addFenwick(ngok, e[1]+1, 1);
				ngmaxs[ind] = e[1];
			}else if(e[2] <= -10){
				int ind = -(e[2]+10);
				addFenwick(ngok, okmaxs[ind]+1, 1);
				addFenwick(ngok, e[1]+1, -1);
				okmaxs[ind] = e[1];
			}else{
				int val = dist - (all - sumFenwick(ft, e[1]));
				if(sumFenwick(ngok, e[1]) > 0)val--;
				ret[e[2]] = val+1;
			}
		}
		
		for(int i = 0;i < Q;i++){
			out.println(ret[i]);
		}
	}
	
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}
	
	public static int[] shrink(int[] a)
	{
		int n = a.length;
		long[] b = new long[n];
		for(int i = 0;i < n;i++)b[i] = (long)a[i]<<32|i;
		b = radixSort(b);
//		Arrays.sort(b);
		int[] ret = new int[n];
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i>0 && (b[i]^b[i-1])>>32!=0)p++;
			ret[(int)b[i]] = p;
		}
		return ret;
	}
	
	public static long[] radixSort(long[] f)
	{
		long[] to = new long[f.length];
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>16&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>16&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>32&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>32&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>48&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>48&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
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