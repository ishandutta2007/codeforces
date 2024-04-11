//package round184;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] s = ns(6000);
		int n = s.length;
		int[] nim = new int[n+1];
		nim[1] = 1;
		for(int i = 2;i <= n;i++){
			BitSet bs = new BitSet();
			bs.set(nim[i-2]);
			for(int j = 1;j < i-1;j++){
				bs.set(nim[j-1]^nim[i-j-2]);
			}
			nim[i] = bs.nextClearBit(0);
		}
		
		int[][] pos = new int[n][];
		int p = 0;
		
		int con = 0;
		int gnim = 0;
		for(int i = 0;i < n;i++){
			boolean pa = false;
			if(i >= 1 && i < n-1 && s[i-1] == s[i+1]){
				pa = true;
			}
			if(pa){
				con++;
			}else{
				if(con > 0){
					pos[p++] = new int[]{i-con, con};
					gnim ^= nim[con];
				}
				con = 0;
			}
		}
		if(con > 0){
			pos[p++] = new int[]{n-con, con};
			gnim ^= nim[con];
		}
		
		if(gnim == 0){
			out.println("Second");
		}else{
			out.println("First");
			for(int i = 0;i < p;i++){
				if(pos[i][1]-2 >= 0){
					if((nim[pos[i][1]-2]^nim[pos[i][1]]) == gnim){
						out.println(pos[i][0]+1);
						return;
					}
				}else{
					if((0^nim[pos[i][1]]) == gnim){
						out.println(pos[i][0]+1);
						return;
					}
				}
				for(int j = 1;j < pos[i][1]-1;j++){
					if((nim[j-1]^nim[pos[i][1]-2-j]^nim[pos[i][1]]) == gnim){
						out.println(pos[i][0]+j+1);
						return;
					}
				}
			}
		}
	}
	
	void run() throws Exception
	{
//		int n = 500, m = 99999;
//		Random gen = new Random(2);
//		StringBuilder sb = new StringBuilder();
//		for(int i = 0;i < n;i++){
//			sb.append((char)(gen.nextInt(2)+'a'));
//		}
//		INPUT = sb.toString();
//		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
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