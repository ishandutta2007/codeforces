//package round464;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		int[][] ts = new int[K][];
		long all = 0;
		for(int i = 0;i < K;i++){
			ts[i] = na(2);
			all += ts[i][1] - ts[i][0];
		}
		int[] dpe = new int[n+1];
		int[] dpo = new int[n+1];
		Arrays.fill(dpe, 99999999);
		Arrays.fill(dpo, 99999999);
		if(ts[0][0] > n){
			out.println("Hungry");
			return;
		}
		dpe[ts[0][0]] = 0;
		for(int i = 0;i < K;i++){
			int[] ndpo = new int[n+1];
			int[] ndpe = new int[n+1];
			Arrays.fill(ndpo, 99999999);
			Arrays.fill(ndpe, 99999999);
			Deque<Integer> dq = new ArrayDeque<>();
			int w = ts[i][1] - ts[i][0];
			for(int j = 0;j <= n;j++){
				while(dq.size() > 0 && dpe[dq.peekLast()] >= dpe[j]){
					dq.pollLast();
				}
				while(dq.size() > 0 && dq.peekFirst() < j-w)dq.pollFirst();
				dq.add(j);
				ndpo[j] = Math.min(ndpo[j], dpe[dq.peekFirst()] + 1);
				if(j+w <= n)ndpe[j+w] = Math.min(ndpe[j+w], dpe[j]);
			}
			dq.clear();
			for(int j = 0;j <= n;j++){
				while(dq.size() > 0 && dpo[dq.peekLast()] >= dpo[j]){
					dq.pollLast();
				}
				while(dq.size() > 0 && dq.peekFirst() < j-w)dq.pollFirst();
				dq.add(j);
				ndpe[j] = Math.min(ndpe[j], dpo[dq.peekFirst()] + 1);
				ndpo[j] = Math.min(ndpo[j], dpo[j]);
			}
			dpo = ndpo;
			dpe = ndpe;
			
			for(int j = 0;j <= n;j++){
				dpe[j] = Math.min(dpe[j], dpo[j] + 1);
				dpo[j] = Math.min(dpo[j], dpe[j] + 1);
			}
			
			int s = (i == K-1 ? 2*n : ts[i+1][0]) - ts[i][1];
			for(int j = n;j >= s;j--){
				dpe[j] = dpe[j-s];
			}
			for(int j = Math.min(n, s-1);j >= 0;j--)dpe[j] = 99999999;
			
		}
		int ans = Math.min(dpe[n], dpo[n]);
		if(ans >= 9999999){
			out.println("Hungry");
		}else{
			out.println("Full");
			out.println(ans);
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