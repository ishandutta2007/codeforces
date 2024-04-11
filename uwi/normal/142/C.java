//package round102;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	char[][] b;
	
	char[][][] ptn = {
			{
				"XXX".toCharArray(),
				".X.".toCharArray(),
				".X.".toCharArray()
			},
			{
				".X.".toCharArray(),
				".X.".toCharArray(),
				"XXX".toCharArray()
			},
			{
				"X..".toCharArray(),
				"XXX".toCharArray(),
				"X..".toCharArray()
			},
			{
				"..X".toCharArray(),
				"XXX".toCharArray(),
				"..X".toCharArray()
			}
	};
	
	void solve()
	{
		int n = ni(), m = ni();
		opt = new char[n][m];
		b = new char[n][m];
		for(int i = 0;i < n;i++){
			Arrays.fill(b[i], '.');
			Arrays.fill(opt[i], '.');
		}
		
		if(n >= 3 && m >= 3){
			rec(0, 0, 'A');
		}
		out.println(max);
		for(int i = 0;i < n;i++){
			out.println(new String(opt[i]));
		}
	}
	
	int max = 0;
	char[][] opt = null;
	
	void rec(int r, int c, char C)
	{
		int n = b.length;
		int m = b[0].length;
		
		if(r+2 >= n){
			int v = C-'A';
			if(v > max){
				max = v;
				for(int i = 0;i < n;i++){
					for(int j = 0;j < m;j++){
						opt[i][j] = b[i][j];
					}
				}
			}
			return;
		}
		if(c+2 >= m){
			rec(r+1, 0, C);
			return;
		}
		
		int ct = 0;
		for(int i = r;i < n;i++){
			for(int j = 0;j < m;j++){
				if(((i == r && j >= c) || i > r) && b[i][j] == '.'){
					ct++;
				}
			}
		}
		if(ct / 5 + (C-'A') <= max){
			return;
		}
		
		outer:
		for(int i = 0;i < 4;i++){
			for(int j = 0;j < 3;j++){
				for(int k = 0;k < 3;k++){
					if(ptn[i][j][k] == 'X' && b[r+j][c+k] != '.')continue outer;
				}
			}
			for(int j = 0;j < 3;j++){
				for(int k = 0;k < 3;k++){
					if(ptn[i][j][k] == 'X'){
						b[r+j][c+k] = C;
					}
				}
			}
			rec(r, c+1, (char)(C+1));
			for(int j = 0;j < 3;j++){
				for(int k = 0;k < 3;k++){
					if(ptn[i][j][k] == 'X'){
						b[r+j][c+k] = '.';
					}
				}
			}
		}
		rec(r, c+1, C);
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
		new C().run();
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