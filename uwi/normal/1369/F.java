//package round652;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		// e s
//		for(int i = 10;i < 1000;i++){
//			boolean[] win = new boolean[i+1];
//			for(int j = i;j >= 0;j--){
//				win[j] = !((j*2 > i ? true : win[j*2]) && (j+1 > i ? true : win[j+1]));
//			}
//			boolean[] aa = new boolean[i+1];
//			for(int j = i;j > 0;j--){
//				aa[j] = fw(j, i);
//			}
//			tr(i);
//			tf(win);
//			tf(aa);
//			for(int j = 1;j <= i;j++){
//				assert aa[j] == win[j];
//			}
//		}
//		for(int i = 1;i < 120;i++){
//			boolean[] win = new boolean[i+1];
//			for(int j = i;j >= 0;j--){
//				win[j] = !((j*2 > i ? false : win[j*2]) && (j+1 > i ? false : win[j+1]));
//				tr(i, j);
//				if(j > 0)assert win[j] == fl(j, i);
//			}
//			boolean[] aa = new boolean[i+1];
//			for(int j = i;j > 0;j--){
//				aa[j] = fl(j, i);
//			}
//			tr(i);
//			tf(win);
//			tf(aa);
//		}
		int n = ni();
		boolean[] fw = new boolean[n];
		boolean[] fl = new boolean[n];
		for(int i = 0;i < n;i++){
			long S = nl(), E = nl();
			fw[i] = fw(S, E);
			fl[i] = fl(S, E);
		}
		
		{
			boolean win = true, lose = false;
			for(int i = n-1;i >= 0;i--){
				boolean plose = false;
				boolean pwin = false;
				if(fw[i] && win){
					plose = true;
				}
				if(!fw[i] && win){
					pwin = true;
				}
				if(fl[i] && lose){
					plose = true;
				}
				if(!fl[i] && lose){
					pwin = true;
				}
				lose = plose;
				win = pwin;
			}
			if(lose){
				out.print(1);
			}else{
				out.print(0);
			}
		}
		
		out.print(" ");
		
		{
			boolean win = false, lose = true;
			for(int i = n-1;i >= 0;i--){
				boolean plose = false;
				boolean pwin = false;
				if(fw[i] && win){
					plose = true;
				}
				if(!fw[i] && win){
					pwin = true;
				}
				if(fl[i] && lose){
					plose = true;
				}
				if(!fl[i] && lose){
					pwin = true;
				}
				lose = plose;
				win = pwin;
			}
			if(lose){
				out.print(1);
			}else{
				out.print(0);
			}
		}
		out.println();
	}
	
	boolean fw(long S, long E)
	{
		int p = 0;
		for(;;p ^= 1, E/=2){
			if(p == 0 && E % 2 == 1){
				return (E-S) % 2 == 1;
			}
			if(S >= E/2+1){
				return p == 1 || (E-S) % 2 == 1;
			}
		}
	}
	
	boolean fl(long S, long E)
	{
		for(int p = 0;;p ^= 1, E/=2){
			if(p == 1 && E % 2 == 1){
				return (E-S) % 2 == 1;
			}
			if(S >= E/2+1){
				return p == 0 || (E-S) % 2 == 1;
			}
		}
	}
	
	public static void tf(boolean... r)
	{
		for(boolean x : r)System.out.print(x?'#':'.');
		System.out.println();
	}
	
	public static void tf(boolean[]... b)
	{
		for(boolean[] r : b) {
			for(boolean x : r)System.out.print(x?'#':'.');
			System.out.println();
		}
		System.out.println();
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