//package round51;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
//	String INPUT = "10 1 9000000000000000000 1 9000000000000000000 1 9000000000000000000 1 9000000000000000000 1 9000000000000000000 1 9000000000000000000 1 9000000000000000000 1 9000000000000000000 1 9000000000000000000 1 9000000000000000000";
//	String INPUT = "1 12 15";
//	String INPUT = "1 1 9";
	String INPUT = "";
	int[] imap = new int[48];
	int[][] u = new int[48][10];
	
	void solve()
	{
		BitSet bs = new BitSet();
		bs.set(1, 10);
		int p = 0;
		for(int i = bs.nextSetBit(0);i != -1;i = bs.nextSetBit(i+1)){
			for(int j = bs.nextSetBit(i+1);j != -1;j = bs.nextSetBit(j+1)){
				bs.set(i*j/gcd(i,j));
			}
			imap[p++] = i;
		}
//		tr(bs.cardinality());
		
		for(int i = 0;i < 48;i++){
			for(int j = 1;j <= 9;j++){
				int lcm = imap[i] * j / gcd(imap[i], j);
				for(int k = 0;k < 48;k++){
					if(lcm == imap[k]){
						u[i][j] = k;
						if(j == 1)u[i][0] = u[i][1];
						break;
					}
				}
			}
		}
		
		for(int i = 0;i < 2520;i++){
			for(int j = 0;j <= 9;j++){
				momo[i][j] = (10*i+j)%2520;
			}
		}
		
		int t = ni();
		long s = System.currentTimeMillis();
		for(int i = 0;i < t;i++){
			long l = in.nextLong();
			long r = in.nextLong();
			out.println(count(r) - count(l-1));
		}
		long g = System.currentTimeMillis();
		tr(g-s+"ms");
	}
	
	int[][] momo = new int[2520][10];
	long[][][] dp = new long[19][48][2520];
	
	int gcd(int a, int b)
	{
		while(b > 0){
			int c = a; a = b; b = c % b;
		}
		return a;
	}
	
	long count(long n)
	{
		for(int i = 0;i < 19;i++){
			for(int j = 0;j < 48;j++){
				Arrays.fill(dp[i][j], 0);
			}
		}
		
		char[] ch = Long.toString(n).toCharArray();
		int code = 0;
		int mod = 0;
		for(int i = 0, j = 19 - ch.length;i < ch.length;i++,j++){
			int sup = i == ch.length - 1 ? ch[i] + 1 : ch[i];
			for(char c = '0';c < sup;c++){
				int d = c - '0';
				dp[j][u[code][d]][momo[mod][d]] = 1;
			}
			code = u[code][ch[i] - '0'];
			mod = momo[mod][ch[i]-'0'];
		}
		for(int i = 0;i < 18;i++){
			for(int j = 0;j < 48;j++){
				for(int k = 0;k < 2520;k++){
					if(dp[i][j][k] > 0){
						for(int l = 0;l <= 9;l++){
							dp[i+1][u[j][l]][momo[k][l]] += dp[i][j][k];
						}
					}
				}
			}
		}
		
		long ct = 0;
		for(int j = 0;j < 48;j++){
			for(int k = 0;k < 2520;k+=imap[j]){
				ct += dp[18][j][k];
			}
		}
		return ct;
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}