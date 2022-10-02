//package round237;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] s = ns().toCharArray();
		int n = s.length;
		// 012*
		int mod = 1000000007;
		int[][] pre = new int[4][4];
		int[][] cur = new int[4][4];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < 4;j++){
				for(int k = 0;k < 4;k++){
					cur[j][k] = 0;
				}
			}
			int flag = 1<<"012*?".indexOf(s[i]);
			if(flag == 16)flag = 15;
			if(i == 0 && n == 1){
				if(flag<<31-0<0){
					cur[0][0] = 1;
				}
				if(flag<<31-3<0){
					cur[0][3] = 1;
				}
			}else if(i == 0){
				if(flag<<31-0<0){
					cur[0][0] = 1;
				}
				if(flag<<31-1<0){
					cur[0][1] = 1;
				}
				if(flag<<31-3<0){
					cur[0][3] = 1;
				}
			}else if(i == n-1){
				for(int j = 0;j < 4;j++){
					if(j <= 2){
						if(flag<<31-0<0){
							cur[0][0] += pre[j][0];
							if(cur[0][0] >= mod)cur[0][0] -= mod;
						}
						if(flag<<31-3<0){
							cur[1][3] += pre[j][1];
							if(cur[1][3] >= mod)cur[1][3] -= mod;
						}
						if(flag<<31-1<0){
							cur[3][1] += pre[j][3];
							if(cur[3][1] >= mod)cur[3][1] -= mod;
						}
						if(flag<<31-3<0){
							cur[3][3] += pre[j][3];
							if(cur[3][3] >= mod)cur[3][3] -= mod;
						}
					}else{
						if(flag<<31-0<0){
							cur[1][0] += pre[j][1];
							if(cur[1][0] >= mod)cur[1][0] -= mod;
						}
						if(flag<<31-3<0){
							cur[2][3] += pre[j][2];
							if(cur[2][3] >= mod)cur[2][3] -= mod;
						}
						if(flag<<31-1<0){
							cur[3][1] += pre[j][3];
							if(cur[3][1] >= mod)cur[3][1] -= mod;
						}
						if(flag<<31-3<0){
							cur[3][3] += pre[j][3];
							if(cur[3][3] >= mod)cur[3][3] -= mod;
						}
					}
				}
			}else{
				for(int j = 0;j < 4;j++){
					if(j <= 2){
						if(flag<<31-0<0){
							cur[0][0] += pre[j][0];
							if(cur[0][0] >= mod)cur[0][0] -= mod;
						}
						if(flag<<31-1<0){
							cur[0][1] += pre[j][0];
							if(cur[0][1] >= mod)cur[0][1] -= mod;
						}
						if(flag<<31-2<0){
							cur[0][2] += pre[j][0];
							if(cur[0][2] >= mod)cur[0][2] -= mod;
						}
						if(flag<<31-3<0){
							cur[1][3] += pre[j][1];
							if(cur[1][3] >= mod)cur[1][3] -= mod;
						}
						if(flag<<31-1<0){
							cur[3][1] += pre[j][3];
							if(cur[3][1] >= mod)cur[3][1] -= mod;
						}
						if(flag<<31-2<0){
							cur[3][2] += pre[j][3];
							if(cur[3][2] >= mod)cur[3][2] -= mod;
						}
						if(flag<<31-3<0){
							cur[3][3] += pre[j][3];
							if(cur[3][3] >= mod)cur[3][3] -= mod;
						}
					}else{
						if(flag<<31-0<0){
							cur[1][0] += pre[j][1];
							if(cur[1][0] >= mod)cur[1][0] -= mod;
						}
						if(flag<<31-1<0){
							cur[1][1] += pre[j][1];
							if(cur[1][1] >= mod)cur[1][1] -= mod;
						}
						if(flag<<31-2<0){
							cur[1][2] += pre[j][1];
							if(cur[1][2] >= mod)cur[1][2] -= mod;
						}
						if(flag<<31-3<0){
							cur[2][3] += pre[j][2];
							if(cur[2][3] >= mod)cur[2][3] -= mod;
						}
						if(flag<<31-1<0){
							cur[3][1] += pre[j][3];
							if(cur[3][1] >= mod)cur[3][1] -= mod;
						}
						if(flag<<31-2<0){
							cur[3][2] += pre[j][3];
							if(cur[3][2] >= mod)cur[3][2] -= mod;
						}
						if(flag<<31-3<0){
							cur[3][3] += pre[j][3];
							if(cur[3][3] >= mod)cur[3][3] -= mod;
						}
					}
				}
			}
			
			int[][] dum = pre; pre = cur; cur = dum;
		}
		
		long sum = 0;
		for(int i = 0;i < 4;i++){
			for(int j = 0;j < 4;j++){
				sum += pre[i][j];
			}
		}
		out.println(sum%mod);
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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