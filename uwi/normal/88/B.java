//package round73;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Div2B {
	Scanner in;
	PrintWriter out;
	String INPUT = "3 9 4\r\n" +
			"qwertyuio\r\n" +
			"asdfghjkl\r\n" +
			"SzxcvbnmS\r\n" +
			"35\r\n" +
			"TheQuIcKbRoWnFOXjummsovertHeLazYDOG";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int x = ni();
		char[][] b = new char[n][m];
		for(int i = 0;i < n;i++){
			b[i] = in.next().toCharArray();
		}
		int l = ni();
		char[] s = in.next().toCharArray();
		
		int[][] shift = new int[n*m][2];
		int sp = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(b[i][j] == 'S'){
					shift[sp][0] = i;
					shift[sp][1] = j;
					sp++;
				}
			}
		}
		
		int shiftok = 0;
		int ok = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(b[i][j] != 'S'){
					ok |= 1<<b[i][j]-'a';
					for(int k = 0;k < sp;k++){
						if((i-shift[k][0])*(i-shift[k][0])+(j-shift[k][1])*(j-shift[k][1]) <= x*x){
							shiftok |= 1<<b[i][j]-'a';
							break;
						}
					}
				}
			}
		}
		
		int ct = 0;
		for(int i = 0;i < l;i++){
			if(s[i] >= 'A' && s[i] <= 'Z'){
				if(sp == 0){
					out.println(-1);
					return;
				}
				if(ok<<31-(s[i]-'A')>=0){
					out.println(-1);
					return;
				}
				if(shiftok<<31-(s[i]-'A')>=0){
					ct++;
				}
			}else{
				if(ok<<31-(s[i]-'a')>=0){
					out.println(-1);
					return;
				}
			}
		}
		out.println(ct);
	}
	
	void run() throws Exception
	{
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new Div2B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}