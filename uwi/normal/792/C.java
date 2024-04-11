//package educational.round18;
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
		char[] s = ns().toCharArray();
		int par = 0;
		for(char c : s){
			par += (c-'0');
		}
		if(par % 3 == 0){
//			out.println(s.length);
			out.println(new String(s));
			return;
		}
		int n = s.length;
		int x = par % 3 == 1 ? 1 : 2;
		int y = par % 3 == 1 ? 2 : 1;
		int min = n;
		boolean[] arg = null;
		{
			boolean[] eed = new boolean[n];
			for(int i = n-1;i >= 0;i--){
				if((s[i]-'0')%3 == x){
					eed[i] = true;
					for(int j = 0;j < n;j++){
						if(eed[j])continue;
						if(s[j] != '0')break;
						eed[j] = true;
					}
					int cost = count(eed);
					// 0
					if(cost == n && n >= 2){
						for(int j = 0;j < n;j++){
							if(s[j] == '0'){
								eed[j] = false;
								break;
							}
						}
						cost--;
					}
					if(cost < min){
						min = cost;
						arg = eed;
					}
					break;
				}
			}
		}
		{
			int two = 0;
			boolean[] eed = new boolean[n];
			for(int i = n-1;i >= 0;i--){
				if((s[i]-'0')%3 == y){
					eed[i] = true;
					if(++two == 2){
						for(int j = 0;j < n;j++){
							if(eed[j])continue;
							if(s[j] != '0')break;
							eed[j] = true;
						}
						int cost = count(eed);
						// 0
						if(cost == n && n >= 3){
							for(int j = 0;j < n;j++){
								if(s[j] == '0'){
									eed[j] = false;
									break;
								}
							}
							cost--;
						}
						if(cost < min){
							min = cost;
							arg = eed;
						}
						break;
					}
				}
			}
		}
		if(arg == null){
			out.println(-1);
		}else{
//			out.println(n-min);
			go(s, arg);
		}
	}
	
	void go(char[] s, boolean[] eed)
	{
		for(int i = 0;i < s.length;i++){
			if(!eed[i]){
				out.print(s[i]);
			}
		}
		out.println();
	}
	
	int count(boolean[] b)
	{
		int ct = 0;
		for(boolean x : b)if(x)ct++;
		return ct;
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