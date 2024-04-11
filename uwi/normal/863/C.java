//package educational.round29;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long K = nl();
		int af = ni(), bf = ni();
		int[][] a = new int[3][];
		for(int i = 0;i < 3;i++){
			a[i] = na(3);
		}
		int[][] b = new int[3][];
		for(int i = 0;i < 3;i++){
			b[i] = na(3);
		}
		int[] f = new int[9];
		for(int i = 0;i < 3;i++){
			for(int j = 0;j < 3;j++){
				f[i*3+j] = a[i][j]*3+b[i][j]-4;
			}
		}
		int ini = af*3+bf-4;
		int[] ascore = new int[9];
		int[] bscore = new int[9];
		for(int i =0;i < 3;i++){
			for(int j = 0;j < 3;j++){
				if((i-j+3) % 3 == 1){
					ascore[i*3+j]++;
				}else if((j-i+3)%3 == 1){
					bscore[i*3+j]++;
				}
			}
		}
		
		int[] hist = new int[30];
		int cur = ini;
		long as = 0, bs = 0;
		long rem = K;
		out:
		for(int i = 0;rem > 0;i++, rem--){
			for(int j = 0;j < i;j++){
				if(hist[j] == cur){
					int pe = i-j;
					int als = 0, bls = 0;
					for(int k = j;k < i;k++){
						als += ascore[hist[k]];
						bls += bscore[hist[k]];
					}
					long mul = rem/pe;
					as += als * mul;
					bs += bls * mul;
					rem -= mul * pe;
					for(int k = j;rem > 0;rem--,k++){
						as += ascore[hist[k]];
						bs += bscore[hist[k]];
					}
					break out;
				}
			}
			hist[i] = cur;
			as += ascore[hist[i]];
			bs += bscore[hist[i]];
			cur = f[cur];
		}
		out.println(as + " " + bs);
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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