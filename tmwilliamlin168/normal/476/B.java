import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Reader in = new Reader();
		String s1=in.next();
		String s2=in.next();
		int finalPos=10;
		for(char c : s1.toCharArray())
			if(c=='+')
				++finalPos;
			else
				--finalPos;
		double[][] dp = new double[s2.length()+1][21];
		dp[0][10]=1;
		for(int i=0; i<s2.length(); ++i) {
			if(s2.charAt(i)=='+')
				for(int j=0; j<20; ++j)
					dp[i+1][j+1]=dp[i][j];
			else if(s2.charAt(i)=='-')
				for(int j=1; j<21; ++j)
					dp[i+1][j-1]=dp[i][j];
			else
				for(int j=1; j<20; ++j) {
					dp[i+1][j-1]+=dp[i][j]*0.5;
					dp[i+1][j+1]+=dp[i][j]*0.5;
				}
		}
		System.out.println(dp[s2.length()][finalPos]);
	}
	
	static class Reader {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String next() {
			while(st==null||!st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch(Exception e) {}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
	}
}