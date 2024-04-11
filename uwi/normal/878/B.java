//package round443;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class B2 {
	InputStream is;
	PrintWriter out;
//	String INPUT = "3 2 2 2 3 2";
//	String INPUT = "4 2 3 1 2 3 1";
//	String INPUT = "1 2 2 3";
//	String INPUT = "4 3 3 3 3 2 3";
//	String INPUT = "5 3 2 2 2 1 3 2";
	String INPUT = "";
	
	int[] clear(int[] a, int K)
	{
		int n = a.length;
		LST lst = new LST(n);
		lst.setRange(n);
		int val = -1;
		int len = 0;
		for(int i = 0;i != -1 && i < n;i = lst.next(i+1)){
			int lval = a[i];
			if(val == lval){
				len++;
			}else{
				val = lval;
				len = 1;
			}
			if(len == K){
				for(int j = i, t = 0;t < K;t++, j = lst.prev(j)){
					lst.unset(j);
				}
				int j, t;
				for(j = lst.prev(i), t = 0;t < K && j != -1;t++, j = lst.prev(j-1));
				i = j;
				val = -1;
				len = 0;
			}
		}
		int p = 0;
		for(int i = lst.next(0);i < n && i != -1;i = lst.next(i+1)){
			a[p++] = a[i];
		}
		a = Arrays.copyOf(a, p);
		return a;
	}
	
	public static class LST {
		public long[][] set;
		public int n;
//		public int size;
		
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

	
	void solve()
	{
		int n = ni(), K = ni(), m = ni();
		int[] a = na(n);
		
		a = clear(a, K);
		n = a.length;
		if(a.length == 0){
			out.println(0);
			return;
		}
		if(m == 1){
			out.println(a.length);
			return;
		}
		
		List<Integer> prefix = new ArrayList<>();
		List<Integer> suffix = new ArrayList<>();
		int t = 0, h = n-1;
		while(true){
			if(t > h){
				int[] b = new int[2*n];
				int bp = 0;
				for(int i = 0;i < prefix.size();i++){
					b[bp++] = prefix.get(i);
				}
				for(int i = suffix.size()-1;i >= 0;i--){
					b[bp++] = suffix.get(i);
				}
				out.println(clear(Arrays.copyOf(b, bp), K).length);
				return;
			}
			int nt = 0, nh = 0;
			for(int i = t;i <= h;i++){
				if(a[i] == a[h]){
					nt++;
				}else{
					break;
				}
			}
			for(int i = h;i >= t;i--){
				if(a[i] == a[h]){
					nh++;
				}else{
					break;
				}
			}
			if(nt == h-t+1){
				// all the same
				long rem = (long)(h-t+1)*m;//(prefix.isEmpty() && suffix.isEmpty() ? m : m-1);
				while(suffix.size() > 0 && suffix.get(suffix.size()-1) == a[h]){
					suffix.remove(suffix.size()-1);
					rem++;
				}
				if(rem % K == 0){
					int[] b = new int[2*n];
					int bp = 0;
					for(int i = 0;i < prefix.size();i++){
						b[bp++] = prefix.get(i);
					}
					for(int i = suffix.size()-1;i >= 0;i--){
						b[bp++] = suffix.get(i);
					}
					out.println(clear(Arrays.copyOf(b, bp), K).length);
					return;
				}else{
					out.println(rem % K + prefix.size() + suffix.size());
					return;
				}
			}else if(nt + nh == K){
				for(int i = t;i < t+nt;i++){
					prefix.add(a[i]);
				}
				for(int i = h;i > h-nh;i--){
					suffix.add(a[i]);
				}
				t += nt; h -= nh;
			}else if(nt + nh > K){
				// aabaaaabaaaabaa
				out.println(((long)h-t+1)*m-(long)K*(m-1) + prefix.size() + suffix.size());
				return;
			}else{
				out.println(((long)h-t+1)*m + prefix.size() + suffix.size());
				return;
			}
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
	
	public static void main(String[] args) throws Exception { new B2().run(); }
	
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