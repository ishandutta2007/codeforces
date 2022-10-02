//package round202;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;


public class C3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), q = ni();
		long[] a = new long[n+1];
		for(int i = 0;i < n;i++)a[i+1] = ni();
		
		int[][] s = new int[m][];
		int Z = 0;
		for(int i = 0;i < m;i++){
			s[i] = na(ni());
			Z += s[i].length;
		}
		int S = (int)Math.sqrt(Z);
		int[] large = new int[n];
		int[] imap = new int[n];
		Arrays.fill(imap, -1);
		int p = 0;
		for(int i = 0;i < m;i++){
			if(s[i].length > S){
				large[p] = i;
				imap[i] = p;
				p++;
			}
		}
		int[][] largeFreq = new int[p][n+1];
		for(int i = 0;i < p;i++){
			for(int v : s[large[i]]){
				largeFreq[i][v]++;
			}
		}
		
		int[][] inter = new int[m][p]; // [clus][large clus]
		for(int i = 0;i < m;i++){
			for(int v : s[i]){
				for(int j = 0;j < p;j++){
					if(large[j] != i){
						inter[i][j] += largeFreq[j][v];
					}
				}
			}
		}
		
		long[] largeSum = new long[p];
		long[] largeShift = new long[p];
		for(int i = 0;i < p;i++){
			for(int v : s[large[i]]){
				largeSum[i] += a[v];
			}
		}
		
		for(int z = 0;z < q;z++){
			char t = nc();
			if(t == '+'){
				int k = ni()-1;
				long x = ni();
				if(imap[k] == -1){
					// small
					for(int v : s[k]){
						a[v] += x;
					}
					for(int i = 0;i < p;i++){
						largeSum[i] += (long)inter[k][i] * x;
					}
				}else{
					largeShift[imap[k]] += x;
				}
			}else if(t == '?'){
				int k = ni()-1;
				if(imap[k] == -1){
					// small
					long sum = 0;
					for(int v : s[k]){
						sum += a[v];
					}
					for(int i = 0;i < p;i++){
						sum += largeShift[i] * inter[k][i];
					}
					out.println(sum);
				}else{
					// large
					long sum = largeSum[imap[k]] + largeShift[imap[k]] * s[k].length;
					for(int i = 0;i < p;i++){
						sum += largeShift[i] * inter[k][i];
					}
					out.println(sum);
				}
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
	
	public static void main(String[] args) throws Exception { new C3().run(); }
	
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