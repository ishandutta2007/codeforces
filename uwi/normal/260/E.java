//package round158;
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
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++){
			co[i] = new int[]{ni(), ni()};
		}
		double I = -999999999999.;
		double[] ycum = new double[n+1];
		{
			Arrays.sort(co, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return a[1] - b[1];
				}
			});
			ycum[0] = -1000000001;
			ycum[n] = 1000000001;
			for(int i = 1;i < n;i++){
				if(co[i][1] > co[i-1][1]){
					ycum[i] = (double)(co[i][1] + co[i-1][1]) / 2;
				}else{
					ycum[i] = I;
				}
			}
		}
		double[] xcum = new double[n+1];
		{
			Arrays.sort(co, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return a[0] - b[0];
				}
			});
			xcum[0] = -1000000001;
			xcum[n] = 1000000001;
			for(int i = 1;i < n;i++){
				if(co[i][0] > co[i-1][0]){
					xcum[i] = (double)(co[i][0] + co[i-1][0]) / 2;
				}else{
					xcum[i] = I;
				}
			}
		}
		
		int[] a = na(9);
		int[] ord = new int[9];
		for(int i = 0;i < 9;i++)ord[i] = i;
		int[] b = new int[9];
		int step = 0;
		int[][] q = new int[362880*2][]; // {step, x, y1, y2}
		int p = 0;
		int[][] data = new int[362880][];
		do{
			for(int i = 0;i < 9;i++)b[i] = a[ord[i]];
			if(xcum[b[0] + b[3] + b[6]] != I && xcum[b[0]+b[3]+b[6]+b[1]+b[4]+b[7]] != I &&
				ycum[b[0] + b[1] + b[2]] != I && ycum[b[0]+b[1]+b[2]+b[3]+b[4]+b[5]] != I){
				q[p++] = new int[]{step, b[0]+b[3]+b[6], b[0] + b[1] + b[2], b[0]+b[1]+b[2]+b[3]+b[4]+b[5], b[0], b[0]+b[3]};
				q[p++] = new int[]{step, b[0]+b[3]+b[6]+b[1]+b[4]+b[7], b[0] + b[1] + b[2], b[0]+b[1]+b[2]+b[3]+b[4]+b[5], b[0]+b[1], b[0]+b[1]+b[3]+b[4]};
				data[step] = new int[]{b[0] + b[3] + b[6], b[0]+b[3]+b[6]+b[1]+b[4]+b[7], b[0] + b[1] + b[2], b[0]+b[1]+b[2]+b[3]+b[4]+b[5]};
			}
			step++;
		}while(nextPermutation(ord));
		q = Arrays.copyOf(q, p);
		
		Arrays.sort(q, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[1] - b[1];
			}
		});
		
//		Arrays.sort(co, new Comparator<int[]>() {
//			public int compare(int[] a, int[] b) {
//				return a[0] - b[0];
//			}
//		});
		
		int[] ys = new int[n];
		int O = 1000000000;
		for(int i = 0;i < n;i++){
			ys[i] = co[i][1]+O;
		}
		double[] imap = shrinkX(ys);
		
		int[] ft = new int[n+1];
		int pp = 0;
		int[] ok = new int[362880];
		for(int i = 0;i < n;i++){
			while(pp < p && xcum[q[pp][1]] < co[i][0]){
				int low = sumFenwick(ft, -Arrays.binarySearch(imap, ycum[q[pp][2]]+O)-2);
				int high = sumFenwick(ft, -Arrays.binarySearch(imap, ycum[q[pp][3]]+O)-2);
				if(low == q[pp][4] && high == q[pp][5]){
					ok[q[pp][0]]++;
				}
				pp++;
			}
			addFenwick(ft, ys[i], 1);
		}
		for(int i = 0;i < 362880;i++){
			if(ok[i] == 2){
				out.printf("%.10f %.10f\n", xcum[data[i][0]], xcum[data[i][1]]);
				out.printf("%.10f %.10f\n", ycum[data[i][2]], ycum[data[i][3]]);
				return;
			}
		}
		out.println(-1);
	}
	
	public static double[] shrinkX(int[] a)
	{
		int n = a.length;
		long[] b = new long[n];
		for(int i = 0;i < n;i++)b[i] = (long)a[i]<<32|i;
		Arrays.sort(b);
		double[] ret = new double[n];
		int p = 0;
		ret[0] = (int)(b[0]>>32);
		for(int i = 0;i < n;i++) {
			if(i>0 && (b[i]^b[i-1])>>32!=0) {
				p++;
				ret[p] = (int)(b[i]>>32);
			}
			a[(int)b[i]] = p;
		}
		return Arrays.copyOf(ret, p+1);
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
	
	
	public static boolean nextPermutation(int[] a)
	{
		int n = a.length;
		int i;
		for(i = n - 2;i >= 0 && a[i] > a[i+1];i--);
		if(i == -1)return false;
		int j;
		for(j = i + 1;j < n && a[i] < a[j];j++);
		int d = a[i]; a[i] = a[j - 1]; a[j - 1] = d;
		for(int p = i + 1, q = n - 1;p < q;p++,q--){
			d = a[p]; a[p] = a[q]; a[q] = d;
		}
		return true;
	}
	
	void run() throws Exception
	{
//		int n = 99999, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for(int i = 0;i < 3;i++){
//			for(int j = 0;j < 3;j++){
//				for(int k = 0;k < 11111;k++){
//					sb.append(gen.nextInt(1000000)-1000000000+1000000000L*i + " ");
//					sb.append(gen.nextInt(1000000)-1000000000+1000000000L*j + " ");
//				}
//			}
//		}
////		for(int i = 0;i < n;i++){
////			sb.append(gen.nextInt(2000000000)-1000000000 + " ");
////			sb.append(gen.nextInt(2000000000)-1000000000 + " ");
////		}
//		for(int i = 0;i < 9;i++){
//			sb.append(11111);
//			sb.append(" ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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