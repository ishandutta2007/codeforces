import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String args[]) {
    	Scanner in = new Scanner(System.in);
    	int n=in.nextInt(), m=in.nextInt();
    	long k=in.nextLong();
    	long start=1, end=(long)(25*1e10), ans=start, l=start, r=end;
    	while(l<=r) {
    		long mid=(l+r)/2;
    		if(numSmaller(n, m, mid)<k) {
    			ans=mid;
    			l=mid+1;
    		} else
    			r=mid-1;
    	}
    	System.out.println(ans);
    }
    
    static long numSmaller(int n, int m, long x) {
    	long t=0;
    	for(int i=1; i<=n; ++i)
    		t+=Math.min((x-1)/i, m);
    	return t;
    }
}