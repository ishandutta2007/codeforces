//package round541;
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
	
	// ccabccaccca
	
	static class Datum
	{
		int prelen;
		int suflen;
		char pre, suf;
		int[] mids;
		boolean whole;
		@Override
		public String toString() {
			return "Datum [prelen=" + prelen + ", suflen=" + suflen + ", pre=" + pre + ", suf=" + suf + ", "
					+ (mids != null ? "mids=" + Arrays.toString(mids) + ", " : "") + "whole=" + whole + "]";
		}
		
	}
	
	Datum make(char[] s)
	{
		int n = s.length;
		Datum ret = new Datum();
		ret.pre = s[0];
		ret.suf = s[n-1];
		ret.prelen = ret.suflen = n;
		for(int i = 0;i < n;i++){
			if(s[i] != s[0]){
				ret.prelen = i;
				break;
			}
		}
		for(int i = n-1;i >= 0;i--){
			if(s[i] != s[n-1]){
				ret.suflen = n-1-i;
				break;
			}
		}
		
		int[] mids = new int[26];
		int len = 0;
		for(int i = 0;i < n;i++){
			if(i > 0 && s[i] == s[i-1]){
				len++;
			}else{
				len = 1;
			}
			mids[s[i]-'a'] = Math.max(mids[s[i]-'a'], len);
		}
		
		ret.mids = mids;
		ret.whole = n == len;
		return ret;
	}
	
	Datum dfs(int pos, char[][] ss)
	{
		char[] s = ss[pos];
		Datum d = make(s);
		
		if(pos == 0)return d;
		Datum res = dfs(pos-1, ss);
		
		Datum ret = new Datum();
		ret.pre = d.pre;
		ret.suf = d.suf;
		if(d.whole){
			if(res.whole){
				if(res.mids == d.mids){
					ret.prelen = ret.suflen = d.suflen * (res.suflen + 1) + res.suflen;
					ret.whole = true;
					ret.mids = d.mids;
					ret.mids[s[0]-'a'] = ret.prelen;
					return ret;
				}
			}
			if(res.pre == d.pre){
				ret.prelen = d.suflen * (res.prelen+1) + res.prelen;
			}else{
				ret.prelen = d.suflen;
			}
			if(res.suf == d.suf){
				ret.suflen = d.suflen * (res.suflen+1) + res.suflen;
			}else{
				ret.suflen = d.suflen;
			}
			ret.mids = new int[26];
			for(int j = 0;j < 26;j++){
				if(res.mids[j] > 0)ret.mids[j] = 1;
			}
			int c = s[0]-'a';
			if(res.mids[c] > 0){
				ret.mids[c] = d.suflen * (res.mids[c] + 1) + res.mids[c];
			}
			ret.mids[c] = Math.max(ret.mids[c], d.suflen);
		}else{
			ret.prelen = d.prelen;
			ret.suflen = d.suflen;
			
			ret.mids = new int[26];
			for(int j = 0;j < 26;j++){
				if(res.mids[j] > 0)ret.mids[j] = 1;
			}
			if(d.pre == d.suf){
				int c = d.suf-'a';
				if(res.mids[c] > 0){
					ret.mids[c] = d.suflen + d.prelen + 1;
				}
			}else{
				{
					int c = d.suf-'a';
					if(res.mids[c] > 0){
						ret.mids[c] = Math.max(ret.mids[c], d.suflen + 1);
					}
				}
				{
					int c = d.pre-'a';
					if(res.mids[c] > 0){
						ret.mids[c] = Math.max(ret.mids[c], d.prelen + 1);
					}
				}
			}
			for(int j = 0;j < 26;j++){
				ret.mids[j] = Math.max(ret.mids[j], d.mids[j]);
			}
		}
		return ret;
	}
	
	void solve()
	{
		int n = ni();
		char[][] ss = new char[n][];
		for(int i = 0;i < n;i++){
			ss[i] = ns().toCharArray();
		}
		Datum ret = dfs(n-1, ss);
		int max =0;
		for(int v : ret.mids){
			max = Math.max(max, v);
		}
		out.println(max);
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