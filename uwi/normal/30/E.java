//package prac;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class P30E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] s = ns(100001);
		int n = s.length;
		
		int[] rs = palindrome(s);
		int[] sn = new int[n];
		for(int i = 0;i < n;i++){
			sn[i-rs[2*i]/2] = Math.max(sn[i-rs[2*i]/2], rs[2*i]);
		}
		
		char[] rev = new char[n];
		for(int i = 0;i < n;i++){
			rev[i] = s[n-1-i];
		}
		int[] kmp = kmpTable(rev);
		
		int p = 0;
		int maxl = 0;
		int middlepos = -1;
		int maxz = 0;
		
		if(sn[0] > 0){
			maxl = sn[0];
			middlepos = 0;
		}
		for(int i = 0;i < n;i++){
			while(rev[p] != s[i] && p > 0)p = kmp[p];
			if(rev[p] == s[i]){
				p++;
			}
			maxz = Math.max(maxz, p);
			if(i+1 < n && sn[i+1] > 0){
				int v = sn[i+1] + 2*Math.min(maxz, n-(i+1+sn[i+1]));
				if(v > maxl){
					maxl = v;
					middlepos = i+1;
				}
			}
			if(p == n){
				p = kmp[p];
			}
		}
		
		int middlelen = sn[middlepos];
		if(middlelen == maxl){
			out.println(1);
			out.println((middlepos+1) + " " + middlelen);
		}else{
			out.println(3);
			int L = (maxl - middlelen) / 2;
			int lasti = -1;
			{
				int q = 0;
				for(int i = 0;i < n;i++){
					while(rev[q] != s[i] && q > 0)q = kmp[q];
					if(rev[q] == s[i]){
						q++;
						if(q == L){
							lasti = i;
							break;
						}
						if(q == n){
							q = kmp[q];
						}
					}
				}
			}
			
			out.println((lasti-L+1+1) + " " + L);
			out.println((middlepos+1) + " " + middlelen);
			out.println((n-L+1) + " " + L);
		}
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
	
	public static int[] palindrome(char[] str)
	{
		int n = str.length;
		int[] r = new int[2*n];
		int k = 0;
		for(int i = 0, j = 0;i < 2*n;i += k, j = Math.max(j-k, 0)){
			// 
			while(i-j >= 0 && i+j+1 < 2*n && str[(i-j)/2] == str[(i+j+1)/2])j++;
			r[i] = j;
			
			// 
			for(k = 1;i-k >= 0 && r[i]-k >= 0 && r[i-k] != r[i]-k;k++){
				r[i+k] = Math.min(r[i-k], r[i]-k);
			}
		}
		return r;
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
	
	public static void main(String[] args) throws Exception { new P30E().run(); }
	
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