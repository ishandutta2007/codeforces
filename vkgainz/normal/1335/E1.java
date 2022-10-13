
import java.util.Scanner;

public class threeblockspalindromeeasy {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			int n = sc.nextInt();
			//dp nx3
			int [] vals=  new int[n];
			for(int i=0;i<n;i++) {
				vals[i] = sc.nextInt();
			}
//			int [][] dp = new int[n][3];
			//dp[i][0] = only 1 element dp[i][1] = 2 distinct d[i][2] = those two optimized
			//add 26 for characters?
			//create blocks at i,j ==> [0,i-1]U[i,j-1]U[j,n-1];
			int [][] freq = new int[26][n+1]; //1 indexed
			for(int i=1;i<=n;i++) {
				for(int j=0;j<26;j++) {
					freq[j][i] = freq[j][i-1];
					if(vals[i-1]==(j+1)) {
						freq[j][i]++;
					}
				}
			}
			int max =0;
			for(int i=1;i<n;i++) {
				for(int j=i;j<n;j++) {
					int maxFirst = 0;
					int maxSecond =0;
					for(int k=0;k<26;k++) {
						if(freq[k][i]==(freq[k][n]-freq[k][j])) {
							maxFirst = Math.max(maxFirst, freq[k][i]+freq[k][n]-freq[k][j]);

						}
						maxSecond = Math.max(maxSecond,freq[k][j]-freq[k][i]);
					}
					max = Math.max(max,maxFirst+maxSecond);
				}
			}
			for(int k=0;k<26;k++) {
				max = Math.max(max,freq[k][n]);
			}
			System.out.println(max);
			
			t--;
		}
	}
}