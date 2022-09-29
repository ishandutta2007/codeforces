//package round371;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class D3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] a = new int[n][];
		for(int i = 0;i < n;i++){
			a[i] = na(m);
		}
		for(int i = n-2;i >= 0;i--){
			for(int j = m-2;j >= 0;j--){
				if(a[i][j] == 1){
					a[i][j] = Math.min(Math.min(a[i+1][j], a[i][j+1]), a[i+1][j+1]) + 1;
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				a[i][j] = -a[i][j];
			}
		}
		int[][][] st = build(a);
		
		for(int Q = ni();Q > 0;Q--){
			int r1 = ni()-1, c1 = ni()-1, r2 = ni()-1, c2 = ni()-1;
			
			int H = st.length/2;
			int low = 0, high = Math.min(n,m)+1;
			while(high-low > 1){
				int h = high+low>>1;
				if(r1 >= r2+1-(h-1) || c1 >= c2+1-(h-1)){
					high = h;
					continue;
				}
				int l = r1, r = r2+1-(h-1);
				int min = Integer.MAX_VALUE;
				while(l != 0){
					int f = l&-l;
					if(l+f > r)break;
					int v = rmq(st[(H+l)/f], c1, c2+1-(h-1));
					if(v < min)min = v;
					l += f;
				}
				
				while(l < r){
					int f = r&-r;
					int v = rmq(st[(H+r)/f-1], c1, c2+1-(h-1));
					if(v < min)min = v;
					r -= f;
				}
				
				if(-min >= h){
					low = h;
				}else{
					high = h;
				}
			}
			out.println(low);
		}
	}
	
	public static int[][][] build(int[][] a)
	{
		int n = a.length;
		int M = Integer.highestOneBit(n)<<2;
		int H = M>>>1;
		int[][][] ret = new int[M][][];
		for(int i = 0;i < n;i++)ret[H+i] = build(a[i]);
		for(int i = H-1;i >= 1;i--){
			if(ret[i*2] == null){
			}else if(ret[i*2+1] == null){
				ret[i] = ret[i*2];
			}else{
				int[][] b = new int[ret[2*i].length][];
				for(int j = 0;j < ret[2*i].length;j++){
					b[j] = new int[ret[2*i][j].length];
					for(int k = 0;k < b[j].length;k++){
						b[j][k] = Math.min(ret[2*i][j][k], ret[2*i+1][j][k]);
					}
				}
				ret[i] = b;
			}
		}
		return ret;
	}
	
	public static int[][] build(int[] a)
	{
		int n = a.length;
		int b = 32-Integer.numberOfLeadingZeros(n);
		int[][] ret = new int[b][];
		for(int i = 0, l = 1;i < b;i++, l*=2) {
			if(i == 0) {
				ret[i] = a;
			}else {
				ret[i] = new int[n-l+1];
				for(int j = 0;j < n-l+1;j++) {
					ret[i][j] = Math.min(ret[i-1][j], ret[i-1][j+l/2]);
				}
			}
		}
		return ret;
	}
	
	// [a,b)
	public static int rmq(int[][] or, int a, int b)
	{
		if(a >= b)return 0;
		// 1:0, 2:1, 3:1, 4:2, 5:2, 6:2, 7:2, 8:3
		int t = 31-Integer.numberOfLeadingZeros(b-a);
		return Math.min(or[t][a], or[t][b-(1<<t)]);
	}
	
	public static class LST {
		public long[][] set;
		public int n;
//		public int size;
		
		public LST(LST a, LST b)
		{
			this.n = a.n;
			int d = 1;
			for(int m = n;m > 1;m>>>=6, d++);
			set = new long[d][];
			for(int i = 0, m = n>>>6;i < d;i++, m>>>=6){
				set[i] = new long[Math.min(a.set[i].length, b.set[i].length)];
				for(int j = 0;j < set[i].length;j++){
					set[i][j] = a.set[i][j] | b.set[i][j];
				}
			}
		}
//		private void tr(Object... o) { System.out.println(Arrays.deepToString(o)); }
		
		public LST(long[] a)
		{
			this.n = a.length<<6;
			int d = 1;
			for(int m = n;m > 1;m>>>=6, d++);
			set = new long[d][];
			for(int i = 0, m = n>>>6;i < d;i++, m>>>=6){
				if(i == 0){
					set[i] = a;
				}else{
					set[i] = new long[m+1];
					for(int j = 0;j < set[i-1].length;j++){
						if(set[i-1][j] != 0)set[i][j>>>6] |= 1L<<j;
					}
				}
			}
		}
		
		public LST(int n) {
			this.n = n;
			int d = 1;
			for(int m = n;m > 1;m>>>=6, d++);
			
			set = new long[d][];
			for(int i = 0, m = n>>>6;i < d;i++, m>>>=6){
				set[i] = new long[m+1];
			}
//			size = 0;
		}
		
		// [0,r)
		public LST setRange(int r)
		{
			for(int i = 0;i < set.length;i++, r=r+63>>>6){
				for(int j = 0;j < r>>>6;j++){
					set[i][j] = -1L;
				}
				if((r&63) != 0)set[i][r>>>6] |= (1L<<r)-1;
			}
			return this;
		}
		
		// [0,r)
		public LST unsetRange(int r)
		{
			if(r >= 0){
				for(int i = 0;i < set.length;i++, r=r+63>>>6){
					for(int j = 0;j < r+63>>>6;j++){
						set[i][j] = 0;
					}
					if((r&63) != 0)set[i][r>>>6] &= ~((1L<<r)-1);
				}
			}
			return this;
		}
		
		public LST set(int pos)
		{
			if(pos >= 0 && pos < n){
//				if(!get(pos))size++;
				for(int i = 0;i < set.length;i++, pos>>>=6){
					set[i][pos>>>6] |= 1L<<pos;
				}
			}
			return this;
		}
		
		public LST unset(int pos)
		{
			if(pos >= 0 && pos < n){
//				if(get(pos))size--;
				for(int i = 0;i < set.length && (i == 0 || set[i-1][pos] == 0L);i++, pos>>>=6){
					set[i][pos>>>6] &= ~(1L<<pos);
				}
			}
			return this;
		}
		
		public boolean get(int pos)
		{
			return pos >= 0 && pos < n && set[0][pos>>>6]<<~pos<0;
		}
		
		public int prev(int pos)
		{
			for(int i = 0;i < set.length && pos >= 0;i++, pos>>>=6, pos--){
				int pre = prev(set[i][pos>>>6], pos&63);
				if(pre != -1){
					pos = pos>>>6<<6|pre;
					while(i > 0)pos = pos<<6|63-Long.numberOfLeadingZeros(set[--i][pos]);
					return pos;
				}
			}
			return -1;
		}
		
		public int next(int pos)
		{
			for(int i = 0;i < set.length && pos>>>6 < set[i].length;i++, pos>>>=6, pos++){
				int nex = next(set[i][pos>>>6], pos&63);
				if(nex != -1){
					pos = pos>>>6<<6|nex;
					while(i > 0)pos = pos<<6|Long.numberOfTrailingZeros(set[--i][pos]);
					return pos;
				}
			}
			return -1;
		}
		
		private static int prev(long set, int n)
		{
			long h = Long.highestOneBit(set<<~n);
			if(h == 0L)return -1;
			return Long.numberOfTrailingZeros(h)-(63-n);
		}
		
		private static int next(long set, int n)
		{
			long h = Long.lowestOneBit(set>>>n);
			if(h == 0L)return -1;
			return Long.numberOfTrailingZeros(h)+n;
		}
		
		@Override
		public String toString()
		{
			List<Integer> list = new ArrayList<Integer>();
			for(int pos = next(0);pos != -1;pos = next(pos+1)){
				list.add(pos);
			}
			return list.toString();
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
	
	public static void main(String[] args) throws Exception { new D3().run(); }
	
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