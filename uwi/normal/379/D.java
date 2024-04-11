//package goodbye2013;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int K = ni(), x = ni(), n = ni(), m = ni();
		// a
		// b
		// ab
		// bab
		// abbab
		// bababbab
		// abbabbababbab
		// bababbab
		long[] a = new long[51];
		long[] b = new long[51];
		long[] ab = new long[51];
		long[] ba = new long[51];
		long[] bb = new long[51];
		a[1] = 1;
		b[2] = 1;
		ab[3] = 1;
		ba[4] = 1;
		bb[5] = 1;
		for(int i = 3;i <= K;i++){
			a[i] = a[i-1] + a[i-2];
			b[i] = b[i-1] + b[i-2];
			if(i >= 4){
				ab[i] = ab[i-1] + ab[i-2];
			}
			if(i >= 5){
				ba[i] = ba[i-1] + ba[i-2] + 1-(i&1);
			}
			if(i >= 6){
				bb[i] = bb[i-1] + bb[i-2] + (i&1);
			}
		}
		
		for(int i = 0;i <= n/2;i++){
			for(int ahc = 0;ahc <= 1;ahc++){
				for(int ata = 0;ata <= 1;ata++){
					if(ata+ahc+i*2 > n)continue;
					for(int j = 0;j <= m/2;j++){
						for(int bhc = 0;bhc <= 1;bhc++){
							for(int bta = 0;bta <= 1;bta++){
								if(bta+bhc+j*2 > m)continue;
								long v = a[K]*i+b[K]*j+ab[K]*ata*bhc+ba[K]*bta*ahc+bb[K]*bta*bhc;
								if(v == x){
//									String[] A = new String[K+1];
									{
										StringBuilder sb = new StringBuilder();
										if(ahc == 1)sb.append("C");
										for(int q = 0;q < i;q++)sb.append("AC");
										for(int q = 0;q < n-(ata+ahc+i*2);q++)sb.append("X");
										if(ata == 1)sb.append("A");
										out.println(sb);
//										A[1] = sb.toString();
									}
									{
										StringBuilder sb = new StringBuilder();
										if(bhc == 1)sb.append("C");
										for(int q = 0;q < j;q++)sb.append("AC");
										for(int q = 0;q < m-(bta+bhc+j*2);q++)sb.append("X");
										if(bta == 1)sb.append("A");
										out.println(sb);
//										A[2] = sb.toString();
									}
//									for(int u = 3;u <= K;u++){
//										A[u] = A[u-2] + A[u-1];
//									}
//									int ct = 0;
//									for(int z = 0;z < A[K].length()-1;z++){
//										if(A[K].charAt(z) == 'A' && A[K].charAt(z+1) == 'C')ct++;
//									}
//									if(ct != x)throw new RuntimeException(A[1] + " " + A[2]);
									return;
								}
							}
						}
					}
				}
			}
		}
		out.println("Happy new year!");
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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