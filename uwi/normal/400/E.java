//package round234;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] a = na(n);
		Node[] nazoki = new Node[17];
		long sum = 0;
		for(int d = 16;d >= 0;d--){
			for(int i = 0;i < n;i++){
				if(a[i]<<31-d>=0){
					nazoki[d] = insert(nazoki[d], i);
				}
			}
			int ct = 0;
			for(int i = 0;i < n;i++){
				if(a[i]<<31-d<0){
					ct++;
					sum += (long)ct<<d;
				}else{
					ct = 0;
				}
			}
		}
		
		for(int i = 0;i < m;i++){
			int p = ni()-1, v = ni();
			int old = a[p];
			a[p] = v;
			for(int d = 16;d >= 0;d--){
				if((old^v)<<31-d<0){
//					tr("hey", d, p);
					int bef = findPrev(nazoki[d], p);
					int aft = findNext(nazoki[d], p);
					if(bef == SUP)bef = -1;
					if(aft == INF)aft = n;
//					tr(bef, p, aft);
//					tr(nazoki[d].toString(""));
					if(v<<31-d<0){
						// 0->1
						sum -= s2(p-bef-1)<<d;
						sum -= s2(aft-p-1)<<d;
						sum += s2(aft-bef-1)<<d;
						nazoki[d] = delete(nazoki[d], p);
					}else{
						// 1->0
						sum -= s2(aft-bef-1)<<d;
						sum += s2(p-bef-1)<<d;
						sum += s2(aft-p-1)<<d;
						nazoki[d] = insert(nazoki[d], p);
					}
				}
			}
			out.println(sum);
		}
	}
	
	static long s2(long x)
	{
		return x*(x+1)/2;
	}
	
		public static class Node
		{
			public int esize;
			public int min;
			public int max;
			public Node summary;
			public Node[] children; // 2^esize
			public long set;
			
			public Node(int esize){
				this.esize = esize;
			}
			
			public String toString(String indent) {
				StringBuilder builder = new StringBuilder();
				builder.append("Node [esize=");
				builder.append(esize);
				builder.append(", min=");
				builder.append(min);
				builder.append(", max=");
				builder.append(max);
				builder.append(", set=");
				builder.append(Long.toBinaryString(set));
				builder.append("]\n");
				if(summary != null){
					builder.append(indent);
					builder.append("aux=");
					builder.append(summary.toString(indent + "  "));
				}
				if(children != null){
					for(Node child : children){
						if(child != null){
							builder.append(indent);
							builder.append("ch=");
							builder.append(child.toString(indent + "  "));
						}
					}
				}
				return builder.toString();
			}
		}
		
		public static boolean contains(Node node, int x)
		{
			while(true){
				if(node == null)return false;
				if(x == node.min || x == node.max)return true;
				if(node.esize == 3){
					return node.set<<63-x<0;
				}
				int nx = x&(1<<node.esize)-1;
				if(node.children == null)return false;
				node = node.children[x>>>node.esize];
				x = nx;
			}
		}
		
		public static Node insert(Node node, int x) { return insert(node, x, 12); }
		
		public static Node insert(Node node, int x, int pesize)
		{
			if(node == null){ // #=0
				node = new Node(pesize);
				node.min = node.max = x;
				return node;
			}
			if(x == node.min || x == node.max)return node; // already inserted
			if(x < node.min){
				int d = x; x = node.min; node.min = d;
			}
			if(node.esize > 3){
				int ind = x>>>node.esize;
				if(node.children == null || node.children[ind] == null){
					node.summary = insert(node.summary, ind, pesize/2);
				}
				int low = x&(1<<node.esize)-1;
				if(node.children == null)node.children = new Node[1<<node.esize];
				node.children[ind] = insert(node.children[ind], low, pesize/2);
			}else{
				node.set |= 1L<<x;
			}
			if(x > node.max){
				node.max = x;
			}
			return node;
		}
		
		//
		public static Node delete(Node node, int x)
		{
			if(node == null)return null; // #=0
			if(node.min == node.max){ // #=1
				if(x == node.min)return null; // already deleted
			}else if(node.esize == 3){
				if(x == node.min){
					node.min = Long.numberOfTrailingZeros(node.set);
					node.set &= node.set-1;
				}else if(node.set<<63-x<0){
					node.set ^= 1L<<x;
					if(node.set == 0){
						node.max = node.min;
					}else if(x == node.max){
						node.max = 63-Long.numberOfLeadingZeros(node.set);
					}
				}
			}else{
				if(x == node.min){
					int firstChild = node.summary.min;
					node.min = x = firstChild<<node.esize|node.children[firstChild].min; // next minimum element
				}
				int ind = x>>>node.esize;
				int low = x&(1<<node.esize)-1;
				node.children[ind] = delete(node.children[ind], low);
				if(node.children[ind] == null){ // #ch=0
					node.summary = delete(node.summary, ind);
					if(x == node.max){ // next maximum element
						if(node.summary == null){
							node.max = node.min;
						}else{
							int summaryMax = node.summary.max;
							node.max = summaryMax<<node.esize|node.children[summaryMax].max;
						}
					}
				}else if(x == node.max){ // next maximum element
					node.max = ind<<node.esize|node.children[ind].max;
				}
			}
			return node;
		}
		
		public static int INF = Integer.MIN_VALUE;
		public static int SUP = Integer.MAX_VALUE;
		
		public static int findNext(Node node, int x)
		{
			if(node == null)return INF;
			if(x < node.min){
				return node.min;
			}else if(node.esize == 3){
				if(x == 63)return INF;
				long sh = node.set>>>x+1;
				if(sh == 0)return INF;
				return Long.numberOfTrailingZeros(sh)+x+1;
			}else{
				int ind = x>>>node.esize;
				int low = x&(1<<node.esize)-1;
				if(node.children != null && node.children[ind] != null && low < node.children[ind].max){
					// in this children
					return ind<<node.esize|findNext(node.children[ind], low);
				}else{
					// find next child
					int nextChild = findNext(node.summary, ind);
					if(nextChild == INF)return INF;
					return nextChild<<node.esize|node.children[nextChild].min;
				}
			}
		}
		
		//
		public static int findPrev(Node node, int x)
		{
			if(node == null)return SUP;
			if(x <= node.min){
				return SUP;
			}else if(x > node.max){
				return node.max;
			}else if(node.esize == 3){
				if(x == 0)return SUP;
				long sh = (node.set|1L<<node.min)<<64-x;
				if(sh == 0)return SUP;
				return -Long.numberOfLeadingZeros(sh)+x-1;
			}else{
				int ind = x>>>node.esize;
				int low = x&(1<<node.esize)-1;
				if(node.children != null && node.children[ind] != null && low > node.children[ind].min){
					// in this children
					return ind<<node.esize|findPrev(node.children[ind], low);
				}else{
					// find prev child
					int prevChild = findPrev(node.summary, ind);
					if(prevChild == SUP)return node.min;
					return prevChild<<node.esize|node.children[prevChild].max;
				}
			}
		}
	
	void run() throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append(100000 + " ");
//		}
//		for(int i = 0;i < n;i++){
//			sb.append("1 100000 ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
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