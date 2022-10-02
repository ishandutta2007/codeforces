//package round260;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D5 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int s = (int)Math.sqrt(n);
		s = Math.max(s, 1);
		int z = n/s+1;
		DQ[] dqs = new DQ[z];
		for(int i = 0;i < z;i++){
			dqs[i] = new DQ(s+3);
		}
		short[][] f = new short[z][n+1];
		for(int i = 0;i < n;i++){
			f[i/s][a[i]]++;
			dqs[i/s].addLast(a[i]);
		}
		
		int Q = ni();
		int lastans = 0;
		DQ temp = new DQ(1000);
		for(int y = 0;y < Q;y++){
			int t = ni();
			if(t == 1){
				int ll = ni(), rr = ni();
				int l = (ll-1+lastans)%n;
				int r = (rr-1+lastans)%n;
				if(l > r){
					int d = l; l = r; r = d;
				}
				for(int i = 0;i < r-r/s*s;i++){
					temp.addLast(dqs[r/s].pollFirst());
				}
				int right = dqs[r/s].pollFirst();
				while(!temp.isEmpty()){
					dqs[r/s].addFirst(temp.pollLast());
				}
				f[r/s][right]--;
				
				for(int i = 0;i < l-l/s*s;i++){
					temp.addLast(dqs[l/s].pollFirst());
				}
				dqs[l/s].addFirst(right);
				while(!temp.isEmpty()){
					dqs[l/s].addFirst(temp.pollLast());
				}
				f[l/s][right]++;
				
				for(int i = l/s;i < r/s;i++){
					int v = dqs[i].pollLast();
					dqs[i+1].addFirst(v);
					f[i][v]--;
					f[i+1][v]++;
				}
			}else{
				int ll = ni(), rr = ni(), kk = ni();
				int l = (ll-1+lastans)%n;
				int r = (rr-1+lastans)%n;
				int k = (kk-1+lastans)%n + 1;
				if(l > r){
					int d = l; l = r; r = d;
				}
				int ret = 0;
				if(l/s < r/s){
					for(int i = (l+s-1)/s;i < r/s;i++){
						ret += f[i][k];
					}
					
					for(int i = l;i < (l+s-1)/s*s;i++){
						int v = dqs[l/s].pollLast();
						if(v == k)ret++;
						temp.addFirst(v);
					}
					for(int i = l;i < (l+s-1)/s*s;i++){
						dqs[l/s].addLast(temp.pollFirst());
					}
					
					for(int i = r/s*s;i <= r;i++){
						int v = dqs[r/s].pollFirst();
						if(v == k)ret++;
						temp.addLast(v);
					}
					for(int i = r/s*s;i <= r;i++){
						dqs[r/s].addFirst(temp.pollLast());
					}
				}else{
					for(int i = l/s*s;i <= r;i++){
						int v = dqs[r/s].pollFirst();
						if(i >= l && v == k)ret++;
						temp.addLast(v);
					}
					for(int i = l/s*s;i <= r;i++){
						dqs[r/s].addFirst(temp.pollLast());
					}
				}
				out.println(ret);
				lastans = ret;
			}
		}
	}
	
	public static class DQ {
		public int[] q;
		public int n;
		protected int pt, ph;
		
		public DQ(int n){ this.n = Integer.highestOneBit(n)<<1; q = new int[this.n]; pt = ph = 0; }
		
		public void addLast(int x){ q[ph] = x; ph = ph+1&n-1; }
		public void addFirst(int x){ pt = pt+n-1&n-1; q[pt] = x; }
		public int pollFirst(){ int ret = q[pt]; pt = pt+1&n-1; return ret; }
		public int pollLast(){ ph = ph+n-1&n-1; int ret = q[ph]; return ret; }
		public int getFirst(){ return q[pt]; }
		public int getFirst(int k){ return q[pt+k&n-1]; }
		public int getLast(){ return q[ph+n-1&n-1]; }
		public int getLast(int k){ return q[ph+n-k-1&n-1]; }
		public void clear(){ pt = ph = 0; }
		public int size(){ return ph-pt+n&n-1; }
		public boolean isEmpty(){ return ph==pt; }
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
	
	public static void main(String[] args) throws Exception { new D5().run(); }
	
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