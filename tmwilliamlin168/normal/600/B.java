import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String args[]) {
        Reader in = new Reader();
        int n=in.nextInt(), m=in.nextInt();
        List<Integer> a = new ArrayList<Integer>();
        for(int i=0; i<n; ++i)
        	a.add(in.nextInt());
        Collections.sort(a);
        for(int i=0; i<m; ++i) {
        	int b=in.nextInt();
        	System.out.print(upperBound(a, b)+" ");
        }
    }
    
    static int upperBound(List<Integer> ar, int val) {
    	int start=0, end=ar.size(), ans=end, l=start, r=end;
    	while(l<=r) {
    		int mid=(l+r)/2;
    		if(mid==ar.size()||ar.get(mid)>val) {
    			ans=mid;
    			r=mid-1;
    		} else
    			l=mid+1;
    	}
    	return ans;
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