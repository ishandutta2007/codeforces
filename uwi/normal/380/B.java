//package round222;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.InputMismatchException;
import java.util.List;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	public static int[] shrink(int[] a)
	{
		int n = a.length;
		long[] b = new long[n];
		for(int i = 0;i < n;i++)b[i] = (long)a[i]<<32|i;
		Arrays.sort(b);
		int[] ret = new int[n];
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i>0 && (b[i]^b[i-1])>>32!=0)p++;
			ret[(int)b[i]] = p;
		}
		return ret;
	}
	
	void solve()
	{
		int[] map = new int[200001];
		for(int i = 1;i <= 200000;i++){
			map[i] = map[i-1] + ((i&i-1) == 0 ? 2 : 1);
		}
		
		int n = ni(), m = ni();
		int[][] q = new int[m][];
		int[] xs = new int[m];
		int p = 0;
		for(int i = 0;i < m;i++){
			int t = ni();
			if(t == 1){
				q[i] = new int[]{1, ni(), ni(), ni(), ni()};
				xs[p++] = q[i][4];
			}else{
				q[i] = new int[]{2, ni(), ni()};
			}
		}
		xs = shrink(xs);
		p = 0;
		for(int i = 0;i < m;i++){
			if(q[i][0] == 1){
				q[i][4] = xs[p++];
			}
		}
		
		List<List<int[]>> list = new ArrayList<List<int[]>>();
		for(int i = 0;i <= n;i++)list.add(new ArrayList<int[]>());
		for(int i = 0;i < m;i++){
			if(q[i][0] == 2){
				BitSet bs = new BitSet();
				int L = q[i][2]-1, R = q[i][2];
				for(int j = q[i][1];j <= n;j++){
					for(int[] r : list.get(j)){
//						tr(r, L, R);
						if(Math.max(r[0], L) < Math.min(r[1], R)){
							bs.set(r[2]);
						}
					}
					L = map[L]; R = map[R];
				}
				out.println(bs.cardinality());
			}else if(q[i][0] == 1){
				list.get(q[i][1]).add(new int[]{q[i][2]-1, q[i][3], q[i][4]});
			}
		}
	}
	
	void run() throws Exception
	{
//		int n = 7000, m = 7000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for(int i = 0;i < n;i++){
//			if(gen.nextInt(2) == 0){
//				sb.append(1 + " ");
//				sb.append(gen.nextInt(n)+1 + " ");
//				int a = gen.nextInt(n)+1;
//				int b = gen.nextInt(n)+1;
//				sb.append(Math.min(a, b) + " ");
//				sb.append(Math.max(a, b) + " ");
//				sb.append(gen.nextInt(1000000)+1 + " ");
//			}else{
//				sb.append(2 + " ");
//				sb.append(gen.nextInt(n)+1 + " ");
//				sb.append(gen.nextInt(n)+1 + " ");
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