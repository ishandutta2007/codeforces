//package round270;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class G6 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	final int G = 200000+64>>>6;
	
	void solve()
	{
		char[] a = ns().toCharArray();
		char[] b = ns().toCharArray();
		int n = a.length, m = b.length;
		long[] al = new long[64*G];
		long[] bl = new long[64*G];
		for(int j = 0;j < 64;j++){
			for(int i = j;i < n;i++)al[j*G+(i-j>>>6)] |= (long)(a[i]-'0')<<i-j;
			for(int i = j;i < m;i++)bl[j*G+(i-j>>>6)] |= (long)(b[i]-'0')<<i-j;
		}
		int Q = ni();
		HML cache = new HML();
		for(int i = 0;i < Q;i++){
			int p1 = ni(), p2 = ni(), len = ni();
			long code = 0;
			code = code * 1000000007L + p1;
			code = code * 1000000007L + p2;
			code = code * 1000000007L + len;
			if(cache.containsKey(code)){
				out.println(cache.get(code));
			}else{
				int res = hamming(al, bl, p1, p2, len);
				cache.put(code, res);
				out.println(res);
			}
		}
	}
	
	public static class HML {
		public int size;
		private Entry[] table;
		private int threshold;
		
	    private static final int DEFAULT_INITIAL_CAPACITY = 4;
	    
	    public HML() {
	    	this(DEFAULT_INITIAL_CAPACITY);
	    }
	    
	    public HML(int ice)
	    {
	    	int capacity = 1<<ice;
	    	threshold = capacity * 3 / 4;
	    	table = new Entry[capacity];
	    }
	    
		public final int hash(long ln)
		{
			int n = (int)(ln>>>32)^(int)ln;
			n ^= (n>>>20)^(n>>>12);
			return n^(n>>>7)^(n>>>4);
		}
		
		int indexFor(int h, int length){
			return h&length-1;
		}
		
		public Entry getEntry(long k)
		{
			for(Entry e = table[indexFor(hash(k), table.length)]; e != null; e = e.next)if(e.key == k)return e;
			return null;
		}
		
		public int get(long k)
		{
			for(Entry e = table[indexFor(hash(k), table.length)]; e != null; e = e.next)if(e.key == k)return e.value;
			return -1;
		}
		
		public boolean containsKey(long k)
		{
			for(Entry e = table[indexFor(hash(k), table.length)]; e != null; e = e.next)if(e.key == k)return true;
			return false;
		}
		
		public int put(long k, int v)
		{
			int h = hash(k);
			int i = indexFor(h, table.length);
			for(Entry e = table[i]; e != null; e = e.next){
				if(e.key == k){
					int oldValue = e.value;
					e.value = v;
					return oldValue;
				}
			}
			
			addEntry(h, k, v, i);
			return 0;
		}
		
		public int inc(long k)
		{
			int h = hash(k);
			int i = indexFor(h, table.length);
			for(Entry e = table[i]; e != null; e = e.next)if(e.key == k)return ++e.value;
			
			addEntry(h, k, 1, i);
			return 1;
		}
		
		public int dec(long k)
		{
			int h = hash(k);
			int i = indexFor(h, table.length);
			for(Entry e = table[i]; e != null; e = e.next)if(e.key == k){
				int ret = --e.value;
				if(ret == 0)remove(k); // TODO
				return ret;
			}
			return -1;
		}
		
		private void addEntry(int h, long k, int v, int bucketIndex)
		{
			if(size >= threshold && null != table[bucketIndex]){
				resize(2*table.length);
				bucketIndex = indexFor(h, table.length);
			}
			createEntry(k, v, bucketIndex);
		}
		
		private void resize(int nc)
		{
			Entry[] newTable = new Entry[nc];
			transfer(newTable);
			table = newTable;
			threshold = nc*3/4;
		}
		
		private void transfer(Entry[] newTable)
		{
			int nc = newTable.length;
			for(Entry e : table){
				while(e != null){
					Entry next = e.next;
					int i = indexFor(hash(e.key), nc);
					e.next = newTable[i];
					newTable[i] = e;
					e = next;
				}
			}
		}
		
		private void createEntry(long k, int v, int bucketIndex)
		{
			Entry e = table[bucketIndex];
			table[bucketIndex] = new Entry(k, v, e);
			size++;
		}
		
		public final Entry remove(long k)
		{
			int h = hash(k);
			int i = indexFor(h, table.length);
			Entry prev = table[i], e = prev;
			while(e != null){
				Entry next = e.next;
				if(e.key == k){
					size--;
					if(prev == e){
						table[i] = next;
					}else{
						prev.next = next;
					}
					return e;
				}
				prev = e;
				e = next;
			}
			return e;
		}
		
		public static class Entry
		{
			public long key;
			public int value;
			public Entry next;
			
			public Entry(long key, int value, Entry next) {
				this.key = key;
				this.value = value;
				this.next = next;
			}
		}
	}
	
	public int hamming(long[] a, long[] b, int l1, int l2, int len)
	{
		int h = 0;
		int o1 = l1&63, o2 = l2&63;
		int e1 = l1-o1>>>6, e2 = l2-o2>>>6;
		int llen = len>>>6;
		int i = e1, j = e2;
		o1 *= G; o2 *= G;
		for(int k = 0;k < llen;k++,i++,j++){
			h += Long.bitCount(a[o1+i]^b[o2+j]);
		}
		if(len != llen<<6){
			h += Long.bitCount((a[o1+i]^b[o2+j])<<-len);
		}
		return h;
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
	
	public static void main(String[] args) throws Exception { new G6().run(); }
	
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