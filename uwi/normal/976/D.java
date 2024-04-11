//package educational.round43;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] d = na(n);
		
		for(int z = 0;z < n;z++){
			int[] dd = Arrays.copyOf(d, d[n-1]+1);
			for(int i = n;i < dd.length;i++){
				dd[i] = dd[z];
			}
			int s = 0;
			for(int v : dd)s += v;
			if(s % 2 == 1){
				for(int i = n-1;i >= 0;i--){
					if((dd[i]+dd[z]) % 2 == 1){
						dd[dd.length-1] = dd[i];
						if(simpleGraphic(Arrays.copyOf(dd, dd.length))){
							output(dd);
							return;
						}
					}
				}
			}else{
				if(simpleGraphic(Arrays.copyOf(dd, dd.length))){
					output(dd);
					return;
				}
			}
		}
		throw new RuntimeException();
	}
	
	void output(int[] dd)
	{
		int[] d = Arrays.copyOf(dd, dd.length);
		Arrays.sort(d);
		d = rev_(d);
		int[][] es = giveSimpleGraph(d);
		out.println(es.length);
		for(int[] e : es){
			out.println((e[0]+1) + " " + (e[1]+1));
		}
	}
	
	public static boolean simpleGraphic(int[] d)
	{
		int parity = 0;
		for(int v : d)parity ^= v;
		if(parity<<31<0)return false;
		
		Arrays.sort(d);
		for(int p = 0, q = d.length-1;p < q;p++,q--){
			int u = d[p]; d[p] = d[q]; d[q] = u;
		}
		int n = d.length;
		
		int[] cum = new int[n+1];
		for(int i = 0;i < n;i++){
			cum[i+1] = cum[i] + d[i];
		}
		
		int p = n-1;
		for(int k = 1;k <= n;k++){
			while(p >= 0 && d[p] < k)p--;
			int right = k*(k-1);
			if(k < p+1){
				right += cum[n] - cum[p+1] + k * (p-k+1);
			}else{
				right += cum[n] - cum[k];
			}
			int left = cum[k];
			if(left > right)return false;
		}
		return true;
	}
	
	public static int[][] giveSimpleGraph(int[] d)
	{
		int n = d.length;
		int dsum = 0;
		for(int v : d)dsum += v;
		if((dsum&1) == 1)return null;
		int[][] es = new int[dsum/2][];
		int p = 0;
		
		int[][] dr = new int[n][];
		for(int i = 0;i < n;i++){
			dr[i] = new int[]{d[i], i};
		}
		Arrays.sort(dr, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		int[][] temp = new int[n][];
		for(int i = n-1;i >= 0;i--){
			if(dr[i][0] > i)return null;
			int j;
			for(j = i-1;dr[i][0] > 0 && j >= 0 && dr[j][0] > 0;j--){
				dr[j][0]--; dr[i][0]--;
				es[p++] = new int[]{dr[i][1], dr[j][1]};
			}
			if(dr[i][0] > 0)return null;
			
			j++;
			int q = 0;
			int r = 0;
			for(int k = j;k < i;k++){
				while(q < j && dr[q][0] < dr[k][0])temp[r++] = dr[q++];
				temp[r++] = dr[k];
			}
			while(q < j)temp[r++] = dr[q++];
			for(int k = 0;k < i;k++)dr[k] = temp[k];
		}
		return es;
	}
	
	public static int[] rev_(int[] a)
	{
		for(int i = 0, j = a.length-1;i < j;i++,j--){
			int c = a[i]; a[i] = a[j]; a[j] = c;
		}
		return a;
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
	
	public static void main(String[] args) throws Exception { new D2().run(); }
	
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