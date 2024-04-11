//package corc2013.r1;
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
		int n = ni();
		int[] a = na(n);
		int mask = 0;
		for(int v : a)mask |= 1<<v;
		int D = 100;
		ct = 0;
		sb = new StringBuilder();
		for(int L = 2;L <= 6;L++){
			for(int h = 0;h < D;h++){
				int use = 0;
				for(int j = 0, k = h;j < L;j++, k/=10){
					use |= 1<<k%10;
				}
				if(use == mask){
					// odd
					{
						char[] palin = new char[2*L-1];
						char[] x = Integer.toString(h+D).toCharArray();
						for(int i = 0;i < L;i++){
							palin[i] = palin[2*L-2-i] = x[L-i];
						}
						int[] ip = {-1,-1,-1,-1};
						dfs(0, 0, ip, palin);
					}
					
					// even
					{
						char[] palin = new char[2*L];
						char[] x = Integer.toString(h+D).toCharArray();
						for(int i = 0;i < L;i++){
							palin[i] = palin[2*L-1-i] = x[L-i];
						}
						int[] ip = {-1,-1,-1,-1};
						dfs(0, 0, ip, palin);
					}
				}
			}
			D *= 10;
		}
		out.println(ct);
		out.print(sb);
	}
	
	StringBuilder sb;
	int ct = 0;
	
	void dfs(int pos, int clus, int[] ip, char[] palin)
	{
		if(pos == palin.length){
			if(clus == 3 && ip[3] >= 0 && ip[3] <= 255){
				sb.append(ip[0] + "." + ip[1] + "." + ip[2] + "." + ip[3] + "\n");
				ct++;
			}
			return;
		}
		
		if(ip[clus] != -1){
			int ov = ip[clus];
			int nv = ip[clus] * 10 + palin[pos]-'0';
			if(ov != 0 && nv <= 255){
				ip[clus] = nv;
				dfs(pos+1, clus, ip, palin);
				ip[clus] = ov;
			}
			if(clus+1 < 4){
				dfs(pos, clus+1, ip, palin);
			}
		}else{
			int nv = palin[pos]-'0';
			ip[clus] = nv;
			dfs(pos+1, clus, ip, palin);
			ip[clus] = -1;
		}
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