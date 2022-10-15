import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String args[]) {
    	Scanner in = new Scanner(System.in);
    	long n=in.nextLong();
    	int min=Integer.MAX_VALUE;
    	for(int s=1; s<=81; ++s) {
    		int sqrt=isqrt(4*n+s*s);
    		if(sqrt==-1||(sqrt-s)%2==1||sqrt-s<=0)
    			continue;
    		int x=(sqrt-s)/2;
    		if(s(x)==s&&x<min)
    			min=x;
    	}
    	if(min==Integer.MAX_VALUE)
    		System.out.println(-1);
    	else
    		System.out.println(min);
    }
    
    static int s(int x) {
    	int s=0;
    	while(x>0) {
    		s+=x%10;
    		x/=10;
    	}
    	return s;
    }
    
    static int isqrt(long x) {
    	long l=1, r=Integer.MAX_VALUE;
    	while(l<=r) {
    		long mid=(l+r)/2;
    		long sqr = mid*mid;
    		if(sqr==x)
    			return (int) mid;
    		else if(sqr<x)
    			l=mid+1;
    		else
    			r=mid-1;
    	}
    	return -1;
    }
}