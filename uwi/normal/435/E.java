//package round249;
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
		int n = ni(), m = ni();
		char[][] map = nm(n,m);
		if(check(map)){
			for(char[] row : map){
				out.println(new String(row));
			}
		}else{
			map = trans(map);
			if(check(map)){
				map = trans(map);
				for(char[] row : map){
					out.println(new String(row));
				}
			}else{
				out.println(0);
			}
		}
	}
	
	char[][] trans(char[][] a)
	{
		int n = a.length, m = a[0].length;
		char[][] t = new char[m][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				t[j][i] = a[i][j];
			}
		}
		return t;
	}
	
	boolean check(char[][] map)
	{
		int n = map.length, m = map[0].length;
		int[] code = new int[n];
		int[] even = new int[n];
		int[] odd = new int[n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] != '0'){
					code[i] |= 1<<map[i][j]-'1';
					if(j % 2 == 0){
						even[i] |= 1<<map[i][j]-'1';
					}else{
						odd[i] |= 1<<map[i][j]-'1';
					}
				}
			}
			if(Integer.bitCount(code[i]) >= 3 ||
					Integer.bitCount(even[i]) >= 2 ||
					Integer.bitCount(odd[i]) >= 2 ||
				(even[i]&odd[i]) != 0){
				return false;
			}
		}
		
		outer:
		for(int ptn = 0;ptn < 16;ptn++){
			if(Integer.bitCount(ptn) == 2){
				for(int i = 0;i < n;i++){
					if(i % 2 == 0){
						if((code[i]&ptn) != code[i])continue outer;
					}else{
						if((code[i]&15-ptn) != code[i])continue outer;
					}
				}
				
				for(int i = 0;i < n;i++){
					int lptn = i % 2 == 0 ? ptn : 15-ptn;
					int e = even[i] == 0 ? -1 : Integer.numberOfTrailingZeros(even[i]);
					int o = odd[i] == 0 ? -1 : Integer.numberOfTrailingZeros(odd[i]);
					if(e != -1){
						o = Integer.numberOfTrailingZeros(lptn^(1<<e));
					}else if(o != -1){
						e = Integer.numberOfTrailingZeros(lptn^(1<<o));
					}else{
						o = Integer.numberOfTrailingZeros(lptn);
						e = Integer.numberOfTrailingZeros(lptn^(1<<o));
					}
					for(int j = 0;j < m;j++){
						map[i][j] = (char)('1' + (j % 2 == 0 ? e : o));
					}
				}
				return true;
			}
		}
		return false;
	}
	
	void run() throws Exception
	{
//		int n = 1000, m = 1000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for(int i = 0;i < n;i++){
//			for(int j = 0;j < m;j++){
//				if(i == 997 && j == 997){
//					sb.append(1);
//				}else if(i == 999 && j == 997){
//					sb.append(2);
//				}else{
//					sb.append(0);
//				}
//			}
//			sb.append("\n");
//		}
//		INPUT = sb.toString();
		
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