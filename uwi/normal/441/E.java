//package round252;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int x = ni(), K = ni();
		double P = (double)ni() / 100.;
		double[][] pre = new double[256][500];
		double[][] cur = new double[256][500];
		int o = 250;
		if(x<<31-8<0){
			pre[x&255][Integer.numberOfTrailingZeros((x>>>8)+1)+o] = 1;
		}else{
			pre[x&255][Integer.numberOfTrailingZeros(x>>>8)] = 1;
		}
		for(int i = 0;i < K;i++){
			for(int j = 0;j < 256;j++){
				Arrays.fill(cur[j], 0.);
			}
			for(int j = 0;j < 256;j++){
				for(int k = 0;k < 500;k++){
					if(pre[j][k] == 0)continue;
					if(j < 128){
						int nk = k >= o ? 1 : k+1;
						cur[j*2&255][nk] += pre[j][k] * P;
					}else{
						int nk = k >= o ? k+1 : o+1;
						cur[j*2&255][nk] += pre[j][k] * P;
					}
					if((j+1&255) == 0){
						if(k >= o){
							cur[0][k-o] += pre[j][k] * (1-P);
						}else{
							cur[0][o+1] += pre[j][k] * (1-P);
						}
					}else{
						cur[j+1&255][k] += pre[j][k] * (1-P);
					}
				}
			}
			double[][] dum = pre; pre = cur; cur = dum;
		}
		double e = 0;
		for(int j = 0;j < 256;j++){
			for(int k = 0;k < 500;k++){
				if(j != 0){
					e += Integer.numberOfTrailingZeros(j) * pre[j][k];
				}else if(k >= o){
					e += 8 * pre[j][k];
				}else{
					e += (8+k) * pre[j][k];
				}
			}
		}
		out.printf("%.13f\n", e);
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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