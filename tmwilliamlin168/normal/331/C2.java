import java.io.*;
import java.util.*;

public class Solution {
	static int bS=1_000_000;
	static int[][] dp1 = new int[10][bS];
	static int[][] dp2 = new int[10][bS];
	
    public static void main(String args[]) {
    	for(int i=0; i<10; ++i) {
    		for(int j=1; j<bS; ++j) {
    			int a=j;
    			int largestDig=Math.max(i, a%10);
    			while((a/=10)>0)
    				largestDig=Math.max(largestDig, a%10);
    			if(j-largestDig>=0) {
    				dp1[i][j]=dp1[i][j-largestDig]+1;
    				dp2[i][j]=dp2[i][j-largestDig];
    			} else {
    				dp1[i][j]=1;
    				dp2[i][j]=j-largestDig;
    			}
    		}
    	}
    	
    	Reader in = new Reader();
    	long n=in.nextLong(), t=0;
    	int b1=(int)(n/bS), b2=(int)(n%bS);
    	while(b1>=0) {
    		int a=b1, largestDig=a%10;
    		while((a/=10)>0)
    			largestDig=Math.max(largestDig, a%10);
    		t+=dp1[largestDig][b2];
    		if(dp2[largestDig][b2]==0&&b1>0) {
    			b2=bS-largestDig;
    			++t;
    		} else
    			b2=bS+dp2[largestDig][b2];
    		--b1;
    	}
    	System.out.println(t);
    }
}
class Reader {
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
	long nextLong() {
		return Long.parseLong(next());
	}
}