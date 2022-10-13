import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class substringandsubsequence {
	static int MOD = (int) (Math.pow(10,9)+7);
	public static void main(String[] args) throws IOException {
		 BufferedReader br = new BufferedReader( 
                 new InputStreamReader(System.in)); 

StringTokenizer st = new StringTokenizer(br.readLine()); 
		String s = st.nextToken();
		st = new StringTokenizer(br.readLine());
		String t = st.nextToken();
		int [][] dp = new int[s.length()][t.length()];
		if(t.charAt(0)==s.charAt(0)) {
			dp[0][0] = 1;
		}
		for(int i=1;i<t.length();i++) {
			dp[0][i]=dp[0][i-1];
			if(t.charAt(i)==s.charAt(0)) {
				dp[0][i]++;
			}
			
		}
		for(int j=1;j<s.length();j++) {
			if(s.charAt(j)==t.charAt(0)) {
				dp[j][0] =1;
			}
		}
		for(int i=1;i<s.length();i++) {
			for(int j=1;j<t.length();j++) {
				dp[i][j] = dp[i][j-1];
				if(s.charAt(i)==t.charAt(j)) {
					dp[i][j]+=(dp[i-1][j-1]+1);
				}
				dp[i][j] = dp[i][j]%MOD;
				
			}
		}
//		for(int i=0;i<s.length();i++) {
//			for(int j=0;j<t.length();j++) {
//				System.out.print(dp[i][j]);
//			}
//			System.out.println();
//		}
		int count = 0;
		for(int i=0;i<s.length();i++) {
			count+=dp[i][t.length()-1];
			count = (count%MOD);
		}
		System.out.println(count);
	}
}