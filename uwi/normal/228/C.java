//package round141;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class C4 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		char[][] b = new char[n][];
		for(int i = 0;i < n;i++){
			b[i] = ns(m);
		}
		int[][] bl = new int[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(b[i][j] == '*')bl[i][j] = 1;
			}
		}
		for(int s = 2;s <= 1024;s*=2){
			int h = s/2;
			for(int i = 0;i+s <= n;i++){
				for(int j = 0;j+s <= m;j++){
					if(bl[i][j] == h && bl[i+h][j] == h && bl[i][j+h] == h && bl[i+h][j+h] == h){
						bl[i][j] = s;
					}
				}
			}
		}
		
		int ct = 0;
		for(int pt = 0;pt < 16;pt++){
			int[][] frac = new int[n][m];
			for(int i = 0;i < n-1;i++){
				for(int j = 0;j < m-1;j++){
					if(
							b[i][j] == (pt<<31-0<0 ? '*' : '.') &&
							b[i][j+1] == (pt<<31-1<0 ? '*' : '.') &&
							b[i+1][j] == (pt<<31-2<0 ? '*' : '.') &&
							b[i+1][j+1] == (pt<<31-3<0 ? '*' : '.')
							){
						frac[i][j] = 2;
					}
				}
			}
			for(int s = 4;s <= 1024;s*=2){
				int h = s/2;
				for(int i = 0;i+s <= n;i++){
					for(int j = 0;j+s <= m;j++){
						if(!(pt<<31-0<0 ? bl[i][j] >= h : frac[i][j] == h))continue;
						if(!(pt<<31-1<0 ? bl[i][j+h] >= h : frac[i][j+h] == h))continue;
						if(!(pt<<31-2<0 ? bl[i+h][j] >= h : frac[i+h][j] == h))continue;
						if(!(pt<<31-3<0 ? bl[i+h][j+h] >= h : frac[i+h][j+h] == h))continue;
						frac[i][j] = s;
						ct++;
					}
				}
			}
		}
		out.println(ct);
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
	
	public static void main(String[] args) throws Exception
	{
		new C4().run();
	}
	
	public int ni()
	{
		try {
			int num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public long nl()
	{
		try {
			long num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public String ns()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n' || b == ' '));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n' || b == ' ')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
	}
	
	public char[] ns(int n)
	{
		char[] buf = new char[n];
		try{
			int b = 0, p = 0;
			while((b = is.read()) != -1 && (b == ' ' || b == '\r' || b == '\n'));
			if(b == -1)return null;
			buf[p++] = (char)b;
			while(p < n){
				b = is.read();
				if(b == -1 || b == ' ' || b == '\r' || b == '\n')break;
				buf[p++] = (char)b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}
	
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}