//package round11;


import java.io.BufferedOutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	private Scanner in;
	private PrintWriter out;
	
	public void solve()
	{
		int n = ni();
		int m = ni();
		char[][] b = new char[n][m];
		for(int i = 0;i < n;i++){
			String buf = in.next();
			for(int j = 0;j < m;j++){
				b[i][j] = buf.charAt(j);
			}
		}
		
		int[][] mi = new int[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				int val = 0;
				for(int k = -1;k <= 1;k++){
					for(int l = -1;l <= 1;l++){
						if(k == 0 && l == 0)continue;
						if(valid(i + k, j + l, n, m))val += b[i+k][j+l] - '0';
					}
				}
				mi[i][j] = val;
			}
		}
		
		int ret = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(b[i][j] == '0')continue;
				
				int len;
				for(len = 1;i + len < n && i - len >= 0 && j + 2 * len < m && b[i+len][j+len] == '1';len++);
				len--;
				if(len == 0)continue;
				
				boolean f = true;
				for(int k = 0;k <= len;k++){
					if(b[i+k][j+k] == '0'){f = false; break;}
					if(b[i-k][j+k] == '0'){f = false; break;}
					if(b[i+k][j+2*len-k] == '0'){f = false; break;}
					if(b[i-k][j+2*len-k] == '0'){f = false; break;}
					
					if(mi[i+k][j+k] != 2){f = false; break;}
					if(mi[i-k][j+k] != 2){f = false; break;}
					if(mi[i+k][j+2*len-k] != 2){f = false; break;}
					if(mi[i-k][j+2*len-k] != 2){f = false; break;}
				}
				if(!f)continue;
				
				ret++;
			}
		}
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(b[i][j] == '0')continue;
				
				int len;
				for(len = 1;i + len < n && j + len < m && b[i+len][j] == '1';len++);
				len--;
				if(len == 0)continue;
				
				boolean f = true;
				for(int k = 0;k <= len;k++){
					if(b[i+k][j] == '0'){f = false; break;}
					if(b[i][j+k] == '0'){f = false; break;}
					if(b[i+k][j+len] == '0'){f = false; break;}
					if(b[i+len][j+k] == '0'){f = false; break;}
					if(len >= 3){
						if(k == 1 || k == len - 1){
							if(mi[i+k][j] != 3){f = false; break;}
							if(mi[i][j+k] != 3){f = false; break;}
							if(mi[i+k][j+len] != 3){f = false; break;}
							if(mi[i+len][j+k] != 3){f = false; break;}
						}else{
							if(mi[i+k][j] != 2){f = false; break;}
							if(mi[i][j+k] != 2){f = false; break;}
							if(mi[i+k][j+len] != 2){f = false; break;}
							if(mi[i+len][j+k] != 2){f = false; break;}
						}
					}else if(len == 2){
						if(k == 1){
							if(mi[i+k][j] != 4){f = false; break;}
							if(mi[i][j+k] != 4){f = false; break;}
							if(mi[i+k][j+len] != 4){f = false; break;}
							if(mi[i+len][j+k] != 4){f = false; break;}
						}else{
							if(mi[i+k][j] != 2){f = false; break;}
							if(mi[i][j+k] != 2){f = false; break;}
							if(mi[i+k][j+len] != 2){f = false; break;}
							if(mi[i+len][j+k] != 2){f = false; break;}
						}
					}else if(len == 1){
						if(mi[i+k][j] != 3){f = false; break;}
						if(mi[i][j+k] != 3){f = false; break;}
						if(mi[i+k][j+len] != 3){f = false; break;}
						if(mi[i+len][j+k] != 3){f = false; break;}
					}
				}
				if(!f)continue;
				
				ret++;
			}
		}
		
		out.println(ret);
	}
	
	private static boolean valid(int x, int y, int lx, int ly)
	{
		return x >= 0 && x < lx && y >= 0 && y < ly;
	}
	
	public void run() throws Exception
	{
//		String str = "2 " +
//		"8 8 " +
//		"00010001 " +
//		"00101000 " +
//		"01000100 " +
//		"10000010 " +
//		"01000100 " +
//		"00101000 " +
//		"11010011 " +
//		"11000011 " +
//		"10 10 " +
//		"1111111000 " +
//		"1000001000 " +
//		"1011001000 " +
//		"1011001010 " +
//		"1000001101 " +
//		"1001001010 " +
//		"1010101000 " +
//		"1001001000 " +
//		"1000001000 " +
//		"1111111000 ";
//		in = new Scanner(new StringReader(str));
		in = new Scanner(System.in);
		System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
		out = new PrintWriter(System.out);
		
		int n = in.nextInt();
//		int n = 1;
		for(int i = 1;i <= n;i++){
			long t = System.currentTimeMillis();
			solve();
			out.flush();
//			System.err.printf("%04d/%04d %7d%n", i, n, System.currentTimeMillis() - t);
		}
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new C().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
	private void tra(int[] a) {System.out.println(Arrays.toString(a));}
	private void tra(int[][] a)
	{
		for(int[] e : a){
			System.out.println(Arrays.toString(e));
		}
	}
	
}