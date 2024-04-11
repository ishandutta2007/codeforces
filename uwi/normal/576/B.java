//package round319;
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
		int n = ni();
		int[] f = na(n);
		for(int i = 0;i < n;i++)f[i]--;
		int[][] cp = splitIntoCycleProfs(f);
		int[] cs = cp[2];
		int min = 999999;
		for(int v : cs){
			min = Math.min(min, v);
		}
		if(min >= 3){
			out.println("NO");
			return;
		}else if(min == 2){
			for(int v : cs){
				if(v % 2 != 0){
					out.println("NO");
					return;
				}
			}
		}
		out.println("YES");
		int base = -1;
		for(int i = 0;i < cs.length;i++){
			if(cs[i] == min){
				base = i;
				break;
			}
		}
		int[] clus = cp[0], cind = cp[1];
		if(min == 1){
			int cen = -1;
			for(int i = 0;i < n;i++){
				if(clus[i] == base){
					cen = i;
					break;
				}
			}
			
			for(int i = 0;i < n;i++){
				if(i != cen){
					out.println((cen+1) + " " + (i+1));
				}
			}
		}else{
			int[] cen = new int[2];
			Arrays.fill(cen, -1);
			for(int i = 0;i < n;i++){
				if(clus[i] == base){
					cen[cind[i]] = i;
				}
			}
			out.println((cen[0]+1) + " " + (cen[1]+1));
			for(int i = 0;i < n;i++){
				if(clus[i] != base){
					out.println((cen[cind[i]&1]+1) + " " + (i+1));
				}
			}
		}
	}
	
	public static int[][] splitIntoCycleProfs(int[] f)
	{
		int n = f.length;
		int[] ved = new int[n];
		int[] clus = new int[n];
		Arrays.fill(clus, -1);
		int[] ncyc = new int[n];
		int ncy = 0;
		int[] cind = new int[n];
		Arrays.fill(cind, -1);
		for(int i = 0;i < n;i++){
			int cur = i;
			int p = 0;
			while(ved[cur] == 0){
				ved[cur] = i+1; 
				cind[cur] = p++;
				cur = f[cur];
			}
			if(ved[cur] == i+1){
				// cycle
				int o = cur;
				cur = f[cur];
				clus[o] = ncy;
				int cy = 1;
				while(cur != o){
					clus[cur] = ncy;
					cur = f[cur];
					cy++;
				}
				ncyc[ncy] = cy;
				ncy++;
			}
		}
		return new int[][]{clus, cind, Arrays.copyOf(ncyc, ncy)};
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