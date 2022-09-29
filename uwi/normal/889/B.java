//package round445;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.InputMismatchException;
import java.util.List;

public class B3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	// aed
	// edb
	// cae
	// caedb
	
	void solve()
	{
		int n = ni();
		char[][] ss = new char[n][];
		
		for(int i = 0;i < n;i++){
			ss[i] = ns().toCharArray();
			int f = 0;
			for(int j = 0;j < ss[i].length;j++){
				f |= 1<<ss[i][j]-'a';
			}
			if(Integer.bitCount(f) != ss[i].length){
				out.println("NO");
				return;
			}
		}
		
		boolean[][] g = new boolean[26][26];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < ss[i].length-1;j++){
				g[ss[i][j]-'a'][ss[i][j+1]-'a'] = true;
			}
		}
		for(int i = 0;i < 26;i++){
			int od = 0;
			for(int j = 0;j < 26;j++){
				if(g[i][j])od++;
			}
			if(od >= 2){
				out.println("NO");
				return;
			}
		}
		for(int i = 0;i < 26;i++){
			int id = 0;
			for(int j = 0;j < 26;j++){
				if(g[j][i])id++;
			}
			if(id >= 2){
				out.println("NO");
				return;
			}
		}
		
		boolean[] use = new boolean[26];
		for(int i = 0;i < n;i++){
			for(char c : ss[i]){
				use[c-'a'] = true;
			}
		}
		List<String> list = new ArrayList<>();
		for(int i = 0;i < 26;i++){
			if(!use[i])continue;
			int od = 0;
			for(int j = 0;j < 26;j++){
				if(g[i][j])od++;
			}
			
			int id = 0;
			for(int j = 0;j < 26;j++){
				if(g[j][i])id++;
			}
			if(od == 0 && id == 0){
				use[i] = false;
				list.add("" + (char)('a'+i));
			}
			if(od == 1 && id == 0){
				StringBuilder sb = new StringBuilder();
				inner:
				for(int cur = i;;){
					use[cur] = false;
					sb.append((char)('a'+cur));
					for(int j = 0;j < 26;j++){
						if(g[cur][j]){
							cur = j;
							continue inner;
						}
					}
					break;
				}
				list.add(sb.toString());
			}
		}
		for(int i = 0;i < 26;i++){
			if(use[i]){
				out.println("NO");
				return;
			}
		}

		Collections.sort(list, (x, y) -> (x + y).compareTo(y + x));
		String ret = "";
		for(String l : list)ret += l;
		out.println(ret);
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
	
	public static void main(String[] args) throws Exception { new B3().run(); }
	
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