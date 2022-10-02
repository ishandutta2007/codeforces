//package round243;
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
		int[][] co = new int[n][];
		long[] dic = new long[n];
		for(int i = 0;i < n;i++){
			co[i] = new int[]{ni(), ni(), i};
			dic[i] = (long)co[i][0]<<32|co[i][1];
		}
		dic = radixSort(dic);
		int[][] cor = Arrays.copyOf(co, n);
		Arrays.sort(cor, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return a[1] - b[1];
			}
		});
		int[][] coc = Arrays.copyOf(co, n);
		Arrays.sort(coc, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[1] != b[1])return a[1] - b[1];
				return a[0] - b[0];
			}
		});
		
		int[] icor = new int[n];
		int[] icoc = new int[n];
		for(int i = 0;i < n;i++)icor[cor[i][2]] = i;
		for(int i = 0;i < n;i++)icoc[coc[i][2]] = i;
		int[] dor = new int[n];
		int[] doc = new int[n];
		int[] eor = new int[n];
		int[] eoc = new int[n];
		for(int i = 0;i < n;i++)dor[i] = cor[i][0]*2;
		for(int i = 0;i < n;i++)doc[i] = coc[i][1]*2;
		for(int i = 0;i < n;i++)eor[i] = cor[i][1];
		for(int i = 0;i < n;i++)eoc[i] = coc[i][0];
		
		int ct = 0;
		for(int i = 0;i < n;i++){
			int indrs = icor[i];
			int indcs = icoc[i];
			int indrt = -Arrays.binarySearch(dor, co[i][0]*2+1)-1;
			int indct = -Arrays.binarySearch(doc, co[i][1]*2+1)-1;
//			tr(co[i][0], co[i][1], indrs, indrt, indcs, indct);
			if(indrt - indrs < indct - indcs){
				for(int j = indrs+1;j < indrt;j++){
					int e = eor[j] - co[i][1];
					int ind = Arrays.binarySearch(eoc, indcs, indct, co[i][0] + e);
					if(ind > -1 && Arrays.binarySearch(dic, (long)co[i][0]+e<<32|co[i][1]+e) >= 0){
						ct++;
					}
				}
			}else{
				for(int j = indcs+1;j < indct;j++){
					int e = eoc[j] - co[i][0];
					int ind = Arrays.binarySearch(eor, indrs, indrt, co[i][1] + e);
					if(ind > -1 && Arrays.binarySearch(dic, (long)co[i][0]+e<<32|co[i][1]+e) >= 0){
						ct++;
					}
				}
			}
		}
		out.println(ct);
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
//		int n = 99856, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for(int i = 0;i < 1;i++){
//			for(int j = 0;j < 99856;j++){
//				sb.append(i + " ");
//				sb.append(j + " ");
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