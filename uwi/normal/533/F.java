//package vk2015.r2;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		char[] s = ns(n);
		char[] t = ns(m);
		int[][] kmps = new int[26][];
		char[][] tts = new char[26][];
		for(int i = 0;i < 26;i++){
			char c = (char)('a'+i);
			char[] tt = Arrays.copyOf(t, m);
			for(int j = 0;j < m;j++){
				if(tt[j] == c){
					tt[j] = '1';
				}else{
					tt[j] = '0';
				}
			}
			tts[i] = tt;
			int[] kmp = kmpTable(tt);
			kmps[i] = kmp;
		}
		
		int[][] ps = new int[26][26];
		boolean[][] g = new boolean[26][26];
		
		int[] hits = new int[n-m+1];
		int q = 0;
		outer:
		for(int j = 0;j < n;j++){
			for(int i = 0;i < 26;i++){
				for(int f = 0;f < 26;f++){
					g[i][f] = false;
					char d = (char)('a'+f);
					char h = s[j] == d ? '1' : '0';
					while(ps[i][f] >= 0 && tts[i][ps[i][f]] != h)ps[i][f] = kmps[i][ps[i][f]];
					if(++ps[i][f] == m){
						g[i][f] = true;
						ps[i][f] = kmps[i][ps[i][f]];
					}
				}
			}
			inner:
			for(int i = 0;i < 26;i++){
				for(int f = 0;f < 26;f++){
					if(g[i][f] && g[f][i]){
						continue inner;
					}
				}
				continue outer;
			}
			hits[q++] = j-m+2;
		}
		out.println(q);
		for(int i = 0;i < q;i++){
			out.print(hits[i] + " ");
		}
		out.println();
		
	}
	
	public static int[] kmpTable(char[] str)
	{
		int n = str.length;
		int[] kmp = new int[n+1];
		kmp[0] = -1; kmp[1] = 0;
		for(int i = 2, j = 0;i <= n;i++){
			while(j > 0 && str[i-1] != str[j])j = kmp[j];
			kmp[i] = str[i-1] == str[j] ? ++j : 0;
		}
		return kmp;
	}
	
	void run() throws Exception
	{
		int n = 200000, m = 99999;
		Random gen = new Random();
		StringBuilder sb = new StringBuilder();
		sb.append(n + " ");
		sb.append(1 + " ");
		for (int i = 0; i < n; i++) {
			sb.append("a");
		}
		sb.append("\n");
		for (int i = 0; i < 1; i++) {
			sb.append("b");
		}
		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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