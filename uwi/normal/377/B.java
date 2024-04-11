//package round222;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.PriorityQueue;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), s = ni();
		int[][] a = new int[m][];
		for(int i = 0;i < m;i++){
			a[i] = new int[]{ni(), i};
		}
		int[] b = na(n);
		int[] c = na(n);
		Arrays.sort(a, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		
		int amax = 0;
		for(int[] u : a)amax = Math.max(amax, u[0]);
		boolean ok = false;
		for(int i = 0;i < n;i++){
			if(b[i] >= amax && c[i] <= s){
				ok = true;
				break;
			}
		}
		if(!ok){
			out.println("NO");
			return;
		}
		out.println("YES");
		
		int[][] bc = new int[n][];
		for(int i = 0;i < n;i++){
			bc[i] = new int[]{b[i], c[i], i};
		}
		Arrays.sort(bc, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		
		int low = 0, high = 1000000007;
		while(high - low > 1){
			int day = high+low>>>1;
			if(ok(day, a, bc, s)){
				high = day;
			}else{
				low = day;
			}
		}
		
		int[] ret = new int[m];
		{
			int p = n-1;
			PriorityQueue<int[]> pq = new PriorityQueue<int[]>(100001, new Comparator<int[]>(){
				public int compare(int[] a, int[] b){
					return a[1] - b[1];
				}
			});
			for(int i = m-1;i >= 0;i-=high){
				while(p >= 0 && bc[p][0] >= a[i][0]){
					pq.add(new int[]{p, bc[p][1]});
					p--;
				}
				int[] min = pq.poll();
				for(int j = i;j > i-high && j >= 0;j--){
					ret[a[j][1]] = bc[min[0]][2] + 1;
				}
			}
		}
		for(int i = 0;i < m;i++){
			out.print(ret[i] + " ");
		}
		out.println();
	}
	
	boolean ok(int day, int[][] a, int[][] bc, int S)
	{
		int n = bc.length, m = a.length;
		int p = n-1;
		long T = 0;
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>(100001);
		for(int i = m-1;i >= 0;i-=day){
			while(p >= 0 && bc[p][0] >= a[i][0]){
//				pq.add(new int[]{p, bc[p][1]});
				pq.add(bc[p][1]);
				p--;
			}
			Integer min = pq.poll();
			if(min == null){
				return false;
			}
			T += min;
		}
		return T <= S;
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