import java.util.Scanner;

public class D {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		String[] ref = new String[10];
		ref[0] = "1110111";
		ref[1] = "0010010";
		ref[2] = "1011101";
		ref[3] = "1011011";
		ref[4] = "0111010";
		ref[5] = "1101011";
		ref[6] = "1101111";
		ref[7] = "1010010";
		ref[8] = "1111111";
		ref[9] = "1111011";
		String[] init = new String[n];
		for(int i=0;i<n;i++) init[i] = sc.next();
		int [][] dp = new int[n][k+1];
		//get dp[i+1][k-j
		for(int j=0;j<k+1;j++) {
			dp[n-1][j] = -1;
		}
		int [][] change = new int[n][10];
		for(int i=0;i<n;i++) {
			for(int j=0;j<10;j++) {
				change[i][j] = compare(init[i],ref[j]);
			}
		}
		for(int i=0;i<10;i++) {
			
			int c = change[n-1][i];
			if(c!=-1 && c<=k)
			dp[n-1][c] = i;
		}
		for(int i=n-2;i>=0;i--) {
			for(int j=0;j<k+1;j++) {
				dp[i][j] = -1;
				for(int dig = 9;dig>=0;dig--) {
					int c = change[i][dig];
					if(c!=-1 && c<=j && dp[i+1][j-c]>=0) {
						dp[i][j] = dig;
						break;
					}
				}
			}
		}
		StringBuilder ret = new StringBuilder();
		int j =k;
		boolean work = true;
		for(int i=0;i<n;i++) {
			ret.append(dp[i][j]);
			if(dp[i][j]==-1) {
				work = false;
				break;
			}
			int c = change[i][dp[i][j]];
			j-=c;
		}
		if(work)
		System.out.println(ret.toString());
		else
			System.out.println(-1);
	}
	static int compare(String a, String b) {
		//b part of ref
		int ret =0;
		for(int i=0;i<7;i++) {
			if(a.charAt(i)=='0' && b.charAt(i)=='1') {
				ret++;
			}
			if(a.charAt(i)=='1' && b.charAt(i)=='0') {
				return -1;
			}
		}
		return ret;
	}
}