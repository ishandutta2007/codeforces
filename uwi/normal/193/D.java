//package prac;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Round122D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int[] ia = new int[n];
		for(int i = 0;i < n;i++){
			ia[a[i]-1] = i;
		}
//		tr(ia);
		StarrySkyTree sst = new StarrySkyTree(n);
		long ret = 0;
		for(int i = 0;i < n;i++){
			sst.add(i, i+1, -sst.I);
			sst.add(0, i+1, 1);
			if(ia[i]+1 < n){
				int pos = a[ia[i]+1]-1;
				if(pos < i){
//					tr("pos", pos);
					sst.add(0, pos+1, -1);
				}
			}
			if(ia[i]-1 >= 0){
				int pos = a[ia[i]-1]-1;
				if(pos < i){
//					tr("pos", pos);
					sst.add(0, pos+1, -1);
				}
			}
//			tr(sst.toArray());
			if(sst.st[1] <= 2)ret += sst.count[1];
			if(sst.st2[1] <= 2)ret += sst.count2[1];
//			tr(sst.st);
//			tr(sst.count);
//			tr(sst.st2);
//			tr(sst.count2);
			ret--;
//			tr(ret);
		}
		out.println(ret);
	}
	
	public static class StarrySkyTree {
		public int M, H, N;
		public int[] st;
		public int[] st2;
		public int[] plus;
		public int I = Integer.MAX_VALUE/4; // I+plus<int
		public int[] count;
		public int[] count2;
		
		public StarrySkyTree(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(n-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			st2 = new int[M];
			plus = new int[H];
			count = new int[M];
			count2 = new int[M];
			for(int i = 0;i < H;i++)st[H+i] = st2[H+i] = I;
			Arrays.fill(count, 1);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		public StarrySkyTree(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			plus = new int[H];
			Arrays.fill(st, H+N, M, I);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int i)
		{
			int min = I, min2 = I;
			int mcount = 0, mcount2 = 0;
			{
				int v = st[2*i], c = count[2*i];
				if(v < min){
					min2 = min; mcount2 = mcount;
					min = v;
					mcount = c;
				}else if(v == min){
					mcount += c;
				}else if(v < min2){
					min2 = v;
					mcount2 = c;
				}else if(v == min2){
					mcount2 += c;
				}
			}
			{
				int v = st2[2*i], c = count2[2*i];
				if(v < min){
					min2 = min; mcount2 = mcount;
					min = v;
					mcount = c;
				}else if(v == min){
					mcount += c;
				}else if(v < min2){
					min2 = v;
					mcount2 = c;
				}else if(v == min2){
					mcount2 += c;
				}
			}
			{
				int v = st[2*i+1], c = count[2*i+1];
				if(v < min){
					min2 = min; mcount2 = mcount;
					min = v;
					mcount = c;
				}else if(v == min){
					mcount += c;
				}else if(v < min2){
					min2 = v;
					mcount2 = c;
				}else if(v == min2){
					mcount2 += c;
				}
			}
			{
				int v = st2[2*i+1], c = count2[2*i+1];
				if(v < min){
					min2 = min; mcount2 = mcount;
					min = v;
					mcount = c;
				}else if(v == min){
					mcount += c;
				}else if(v < min2){
					min2 = v;
					mcount2 = c;
				}else if(v == min2){
					mcount2 += c;
				}
			}
			st[i] = min + plus[i];
			st2[i] = min2 + plus[i];
			count[i] = mcount;
			count2[i] = mcount2;
//			tr("go", i);
//			tr(st[2*i], st2[2*i], count[2*i], count2[2*i]);
//			tr(st[2*i+1], st2[2*i+1], count[2*i+1], count2[2*i+1]);
//			tr(st[i], st2[i], count[i], count2[i]);
		}
		
		public void add(int l, int r, int v){ if(l < r)add(l, r, v, 0, H, 1); }
		
		private void add(int l, int r, int v, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				if(cur >= H){
					st[cur] += v;
				}else{
					plus[cur] += v;
					propagate(cur);
				}
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					add(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					add(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
		
		
		public int[] toArray() { return toArray(1, 0, H, new int[H]); }
		
		private int[] toArray(int cur, int l, int r, int[] ret)
		{
			if(r-l == 1){
				ret[cur-H] = st[cur];
			}else{
				toArray(2*cur, l, l+r>>>1, ret);
				toArray(2*cur+1, l+r>>>1, r, ret);
				for(int i = l;i < r;i++)ret[i] += plus[cur];
			}
			return ret;
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
	
	public static void main(String[] args) throws Exception { new Round122D2().run(); }
	
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