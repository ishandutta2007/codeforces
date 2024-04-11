//package educational.round13;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int Q = ni();
		int[][] qs = new int[Q][];
		for(int i = 0;i < Q;i++){
			int t = ni();
			if(t == 1){
				qs[i] = new int[]{t, ni(), ni(), i};
			}else if(t == 2){
				qs[i] = new int[]{t, ni()-1};
			}else{
				qs[i] = new int[]{t, ni()};
			}
		}
		
		int[][] as = new int[Q][];
		int r = 0;
		for(int i = 0;i < Q;i++){
			if(qs[i][0] == 1){
				as[r++] = qs[i];
			}
		}
		Arrays.sort(as, 0, r, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[1] - b[1];
			}
		});
		
		int S = (int)Math.sqrt(Q)*6;
		boolean[] del = new boolean[Q];
		EnvelopeLinear el = new EnvelopeLinear(r);
		for(int i = 0;i < Q;i+=S){
			for(int j = i;j < i+S && j < Q;j++){
				if(qs[j][0] == 2){
					del[qs[j][1]] = true;
				}
			}
			el.clear();
			for(int j = 0;j < r;j++){
				if(as[j][3] < i && !del[as[j][3]]){
					el.add(-as[j][1], -as[j][2]);
				}
			};
			
			boolean[] ldel = new boolean[S];
			
			for(int j = i;j < i+S && j < Q;j++){
				if(qs[j][0] == 2 && qs[j][1] >= i){
					ldel[qs[j][1]-i] = true;
				}else if(qs[j][0] == 3){
					long x = qs[j][1];
					long max = -el.min(x);
					boolean ins = el.p > 0;
					for(int k = i;k < j;k++){
						if(qs[k][0] == 1 && !ldel[k-i]){
							max = Math.max(max, qs[k][1]*x+qs[k][2]);
							ins = true;
						}
					}
					for(int k = j+1;k < i+S && k < Q;k++){
						if(qs[k][0] == 2 && qs[k][1] < i){
							int ind = qs[k][1];
							max = Math.max(max, qs[ind][1]*x+qs[ind][2]);
							ins = true;
						}
					}
					if(ins){
						out.println(max);
					}else{
						out.println("EMPTY SET");
					}
				}
			}
		}
	}
	
	public static class EnvelopeLinear {
		public static final long INF = Integer.MIN_VALUE;
		
		public long[] xs;
		public long[] intercepts, slopes;
		public int p;
		
		public EnvelopeLinear(int n)
		{
			xs = new long[n];
			intercepts = new long[n];
			slopes = new long[n];
			p = 0;
		}
		
		public void clear()
		{
			p = 0;
		}
		
		public void add(long slope, long intercept)
		{
			assert p == 0 || slopes[p-1] >= slope;
			while(p > 0){
				int i = p-1;
				if(intercept+xs[i]*slope <= intercepts[i]+xs[i]*slopes[i]){ // x=xs[i]
					p--;
					continue;
				}
				if(slope == slopes[i]){
					if(intercept >= intercepts[i]){
						return;
					}else{
						p--;
						continue;
					}
				}
				// y=sx+i vs y=Sx+I
				// sx+i=Sx+I
				// x=(i-I)/(S-s)
				long num = intercept-intercepts[i];
				long den = slopes[i]-slope;
				long nx = num < 0 ? num/den : (num+den-1)/den;
				xs[p] = nx;
				intercepts[p] = intercept;
				slopes[p] = slope;
				p++;
				return;
			}
			
			xs[p] = INF;
			intercepts[p] = intercept;
			slopes[p] = slope;
			p++;
		}
		
		public int argmin(int x)
		{
			if(p <= 0)return -1;
			int ind = Arrays.binarySearch(xs, 0, p, x);
			if(ind < 0)ind = -ind-2;
			return ind;
		}
		
		public long min(long x)
		{
			if(p <= 0)return Long.MAX_VALUE / 3;
			int ind = Arrays.binarySearch(xs, 0, p, x);
			if(ind < 0)ind = -ind-2;
			return slopes[ind]*x + intercepts[ind];
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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