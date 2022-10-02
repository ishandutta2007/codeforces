//package round153;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.InputMismatchException;

public class D3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		long[] a = new long[n];
		for(int i = 0;i < n;i++){
			a[i] = nl();
		}
		
		long allx = 0;
		for(int i = 0;i < n;i++){
			allx ^= a[i];
		}
		
		long[] b = new long[n];
		long x1 = 0;
		
		int h = 61;
		for(int i = 61;i >= 0;i--){
			if(allx<<63-i>=0){
				for(int j = 0;j < n;j++){
//					b[j] = b[j] * 2 + (a[j]>>>i&1);
					b[j] |= (a[j]>>>i&1)<<h;
				}
				h--;
			}
		}
		for(int i = 61;i >= 0;i--){
			if(allx<<63-i<0){
				for(int j = 0;j < n;j++){
//					b[j] = b[j] * 2 + (a[j]>>>i&1);
					b[j] |= (a[j]>>>i&1)<<h;
				}
				h--;
			}
		}
		BasisAndCause bac = basisEx(b);
		
		int sh = 61;
		for(int i = 61;i >= 0;i--){
			if(allx<<63-i>=0){
				if(hasSolution(x1*2+1, sh--, bac.bas)){
					x1 = x1 * 2 + 1;
				}else{
					x1 = x1 * 2;
				}
			}
		}
		for(int i = 61;i >= 0;i--){
			if(allx<<63-i<0){
				if(hasSolution(x1*2, sh--, bac.bas)){
					x1 = x1 * 2;
				}else{
					x1 = x1 * 2 + 1;
				}
			}
		}
		
		BitSet bs = solution(x1, bac);
		for(int i = 0;i < n;i++){
			if(i > 0)out.print(" ");
			out.print(bs.get(i) ? 1 : 2);
		}
		out.println();
	}
	
	public static BitSet solution(long x, BasisAndCause bac)
	{
		int h = 63-Long.numberOfLeadingZeros(x);
		BitSet ret = new BitSet();
		while(x != 0){
			if(bac.bas[h] != 0){
				x ^= bac.bas[h];
				ret.xor(bac.cause[h]); // 
				h = 63-Long.numberOfLeadingZeros(x);
			}else{
				return null;
			}
		}
		return ret;
	}
	
	public static long[] basis(long[] a)
	{
		long[] bas = new long[64];
		for(long x : a){
			int h = 63-Long.numberOfLeadingZeros(x);
			while(x != 0){
				if(bas[h] != 0){
					x ^= bas[h];
					h = 63-Long.numberOfLeadingZeros(x);
				}else{
					bas[h] = x;
				}
			}
		}
		return bas;
	}
	
	public static BasisAndCause basisEx(long[] a)
	{
		long[] bas = new long[64];
		BitSet[] cause = new BitSet[64];
		int[] hist = new int[64];
		
		for(int i = 0;i < a.length;i++){
			long x = a[i];
			int h = 63-Long.numberOfLeadingZeros(x);
			int hp = 0;
			while(x != 0){
				if(bas[h] != 0){
					x ^= bas[h];
					hist[hp++] = h;
					h = 63-Long.numberOfLeadingZeros(x);
				}else{
					bas[h] = x;
					cause[h] = new BitSet();
					cause[h].set(i);
					for(int j = 0;j < hp;j++){
						cause[h].xor(cause[hist[j]]);
					}
				}
			}
		}
		BasisAndCause bac = new BasisAndCause();
		bac.bas = bas;
		bac.cause = cause;
		return bac;
	}
	
	public static class BasisAndCause
	{
		public long[] bas;
		public BitSet[] cause;
	}
	
	public static boolean hasSolution(long x, int shift, long[] bas)
	{
		int h = 63-Long.numberOfLeadingZeros(x);
		while(x != 0){
			if(bas[h+shift]>>>shift != 0){
				x ^= bas[h+shift]>>>shift;
				h = 63-Long.numberOfLeadingZeros(x);
			}else{
				return false;
			}
		}
		return true;
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
	
	public static void main(String[] args) throws Exception { new D3().run(); }
	
	byte[] inbuf = new byte[1024];
	int lenbuf = 0, ptrbuf = 0;
	
	int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	double nd() { return Double.parseDouble(ns()); }
	char nc() { return (char)readByte(); }
	
	String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	int ni()
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
	
	long nl()
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
	
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}