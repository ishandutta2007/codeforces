//package educational.round39;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class G2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		// 12211
		int n = ni();
		int[] a = na(n);
		for(int i = 0;i < n;i++)a[i] -= i;
		long[] b = new long[n];
		for(int i = 0;i < n;i++){
			b[i] = a[i]*1000000L+i;
		}
		
		int lis = lis(b);
		long[][] esf = lise(b);
		long[][] esb = lise(rev_(b));
		
		long[] hf = new long[n+1];
		long[] hb = new long[n+1];
		Arrays.fill(hf, Long.MAX_VALUE / 2);
		Arrays.fill(hb, Long.MAX_VALUE / 2);
		hf[0] = Long.MIN_VALUE / 2;
		hb[0] = Long.MIN_VALUE / 2;
		for(long[] e : esb){
			hb[(int)e[1]] = e[2];
		}
		int max = lis;
		
		int p = 0, q = esb.length-1;
		long[] temp = new long[n];
		for(int i = 0;i < n;i++){
			int tp = 0;
			while(q >= 0 && esb[q][0] >= n-1-i){
				hb[(int)esb[q][1]] = esb[q][3];
				temp[tp++] = 1L<<32|(int)esb[q][1];
				q--;
			}
			while(p < esf.length && esf[p][0] < i){
				hf[(int)esf[p][1]] = esf[p][2];
				temp[tp++] = (int)esf[p][1];
				p++;
			}
//			if(i == 4){
//				tr("OOO");
//				tr(hf);
//				tr(hb);
//			}
			for(int j = 0;j < tp;j++){
				long t = temp[j];
//				tr(i, t);
				if(t < 1L<<32){
					int len = (int)t;
					if(hf[len] > Long.MIN_VALUE / 2 + 100 && hf[len] < Long.MAX_VALUE / 2 - 100){
						int ind = Arrays.binarySearch(hb, 10000000000000000L - hf[len]+ 1000000L);
						if(ind < 0)ind = -ind-2;
//						tr(i, "come", len, ind);
						if(hb[ind] > Long.MIN_VALUE / 2 + 100 && hb[ind] < Long.MAX_VALUE / 2 - 100){
//							tr(len, ind);
							if(len+ind > max){
								max = len+ind;
							}
						}
					}
//					int olen = lis + 1 - len;
//					if(len > n)continue;
//					if(olen > n)continue;
//					if(hf[len] <= Long.MIN_VALUE / 2 + 100 || hb[olen] <= Long.MIN_VALUE / 2 + 100)continue;
//					tr(i, len, olen, hf[len], hb[olen]);
//					if(hf[len] <= 10000000000000000L - hb[olen] + 1000000L){
//						out.println(Math.max(0, n-lis-2));
//						return;
//					}
				}else{
					int olen = (int)t;
					if(hb[olen] > Long.MIN_VALUE / 2 + 100 && hb[olen] < Long.MAX_VALUE / 2 - 100){
						int ind = Arrays.binarySearch(hf, 10000000000000000L - hb[olen] + 1000000L);
						if(ind < 0)ind = -ind-2;
						if(hf[ind] > Long.MIN_VALUE / 2 + 100 && hf[ind] < Long.MAX_VALUE / 2 - 100){
//							tr(olen, ind);
							if(olen+ind > max){
								max = olen+ind;
							}
						}
					}
				}
			}
		}
		
		out.println(Math.max(0, n-max-1));
	}
	
	public static long[] rev_(long[] a)
	{
		for(int i = 0, j = a.length-1;i < j;i++,j--){
			long c = a[i]; a[i] = a[j]; a[j] = c;
		}
		for(int i = 0;i < a.length;i++){
			a[i] = 10000000000000000L - a[i];
		}
		return a;
	}

	public static int lis(long[] in)
	{
		int n = in.length;
		int ret = 0;
		long[] h = new long[n + 1];
		Arrays.fill(h, Long.MIN_VALUE / 2);
		for(int i = 0;i < n;i++){
			int ind = Arrays.binarySearch(h, 0, ret + 1, in[i]);
			if(ind < 0){
				ind = -ind-2;
				h[ind+1] = in[i];
				if(ind >= ret)ret++;
			}
		}
		return ret;
	}

	
	public static long[][] lise(long[] in)
	{
		int n = in.length;
		int ret = 0;
		long[] h = new long[n + 1];
		Arrays.fill(h, Long.MAX_VALUE / 2);
		h[0] = Long.MIN_VALUE / 2;
		long[][] es = new long[n+1][];
		int p = 0;
		for(int i = 0;i < n;i++){
			int ind = Arrays.binarySearch(h, 0, ret + 1, in[i]);
			if(ind < 0){
				ind = -ind-2;
				es[p++] = new long[]{i, ind+1, in[i], h[ind+1]};
				h[ind+1] = in[i];
				if(ind >= ret)ret++;
			}
		}
		return Arrays.copyOf(es, p);
	}

//	
//	public static int lis(long[] in)
//	{
//		int n = in.length;
//		int ret = 0;
//		long[] h = new long[n + 1];
//		Arrays.fill(h, Long.MIN_VALUE / 2);
//		long[] h = new long[n + 1];
//		Arrays.fill(h, Long.MIN_VALUE / 2);
//		long[] h = new long[n + 1];
//		Arrays.fill(h, Long.MIN_VALUE / 2);
//		for(int i = 0;i < n;i++){
//			int ind = Arrays.binarySearch(h, 0, ret + 1, in[i]);
//			if(ind < 0){
//				ind = -ind-2;
//				h[ind+1] = in[i];
//				if(ind >= ret)ret++;
//			}
//		}
//		return ret;
//	}

	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new G2().run(); }
	
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