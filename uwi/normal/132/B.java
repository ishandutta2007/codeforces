//package round96;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int h = ni(), n = ni();
		char[][] b = new char[h][];
		for(int i = 0;i < h;i++){
			b[i] = ns(50);
		}
		int w = b[0].length;
		
		int[][] block = new int[h][w];
		for(int i = 0;i < h;i++)Arrays.fill(block[i], -1);
		int[][] binfo = new int[h*w][5];
		int blp = 0;
		for(int i = 0;i < h;i++){
			for(int j = 0;j < w;j++){
				if(block[i][j] != -1)continue;
				int k, z;
				if(b[i][j] == '0'){
					k = 1;
					z = 1;
				}else{
					for(k = 1;i+k-1<h && b[i+k-1][j] == b[i][j];k++);
					for(z = 1;j+z-1<w && b[i][j+z-1] == b[i][j];z++);
					k--;
					z--;
				}
				for(int l = 0;l < k;l++){
					for(int m = 0;m < z;m++){
						block[i+l][j+m] = blp;
					}
				}
				binfo[blp][0] = i;
				binfo[blp][1] = j;
				binfo[blp][2] = k;
				binfo[blp][3] = z;
				binfo[blp][4] = b[i][j]-'0';
				blp++;
			}
		}
		
		int[] f = new int[blp*8];
		int gp = 0;
		for(int i = 0;i < blp;i++){
			int R = binfo[i][0];
			int C = binfo[i][1];
			int K = binfo[i][2];
			int Z = binfo[i][3];
			int r, c;
			r = R; c = C+Z;
			if(r >= 0 && r < h && c >= 0 && c < w && b[r][c] != '0'){
				f[gp] = block[r][c]*8+0;
			}else{
				f[gp] = i*8+1;
			}
			gp++;
			
			r = R+K-1; c = C+Z;
			if(r >= 0 && r < h && c >= 0 && c < w && b[r][c] != '0'){
				f[gp] = block[r][c]*8+1;
			}else{
				f[gp] = i*8+2;
			}
			gp++;
			
			r = R+K; c = C+Z-1;
			if(r >= 0 && r < h && c >= 0 && c < w && b[r][c] != '0'){
				f[gp] = block[r][c]*8+2;
			}else{
				f[gp] = i*8+3;
			}
			gp++;
			
			r = R+K; c = C;
			if(r >= 0 && r < h && c >= 0 && c < w && b[r][c] != '0'){
				f[gp] = block[r][c]*8+3;
			}else{
				f[gp] = i*8+4;
			}
			gp++;
			
			r = R+K-1; c = C-1;
			if(r >= 0 && r < h && c >= 0 && c < w && b[r][c] != '0'){
				f[gp] = block[r][c]*8+4;
			}else{
				f[gp] = i*8+5;
			}
			gp++;
			
			r = R; c = C-1;
			if(r >= 0 && r < h && c >= 0 && c < w && b[r][c] != '0'){
				f[gp] = block[r][c]*8+5;
			}else{
				f[gp] = i*8+6;
			}
			gp++;
			
			r = R-1; c = C;
			if(r >= 0 && r < h && c >= 0 && c < w && b[r][c] != '0'){
				f[gp] = block[r][c]*8+6;
			}else{
				f[gp] = i*8+7;
			}
			gp++;
			
			r = R-1; c = C+Z-1;
			if(r >= 0 && r < h && c >= 0 && c < w && b[r][c] != '0'){
				f[gp] = block[r][c]*8+7;
			}else{
				f[gp] = i*8+0;
			}
			gp++;
		}
		
		int hare = detectCycle(f, 0);
		int cur = 0;
		while(n > 0){
			cur = f[cur]; n--;
			if(cur == hare)n %= cyc;
		}
		out.println(binfo[cur/8][4]);
	}
	
	static int cyc = -1;
	
	public static int detectCycle(int[] f, int s) {
		int power = 1, lambda = 1;
		int tortoise = s;
		int hare = f[s];
		while(tortoise != hare) {
			if(power == lambda) {
				tortoise = hare;
				power <<= 1;
				lambda = 0;
			}
			hare = f[hare];
			lambda++;
		}
		
		cyc = lambda;
		return hare; // cycle = lambda
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
		new B().run();
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