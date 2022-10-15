import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String args[]) {
    	Reader in = new Reader();
    	int n=in.nextInt();
    	Pair[] b = new Pair[n];
    	for(int i=0; i<n; ++i)
    		b[i] = new Pair(in.nextInt(), i);
    	long t1=0, t2=0;
    	Arrays.sort(b, Collections.reverseOrder());
    	FenwickTree f1 = new FenwickTree(n), f2 = new FenwickTree(n);
    	for(Pair p : b) {
    		f1.add(p.b, 1);
    		t1+=f1.sum(p.b);
    		f2.add(p.b, p.b+1);
    		t2+=f2.sum(p.b)*(n-p.b);
    	}
    	//System.out.println(t1+" "+t2);
    	System.out.println(t1+(1.0/48*(n-1)*n*(n+1)*(n+2)-t2)/((long)n*(n+1)/2));
    }
    
    static class FenwickTree {
    	long[] a;
    	FenwickTree(int n) {
    		a = new long[n+1];
    	}
    	void add(int i, int x) {
    		for(++i; i<a.length; i+=i&-i)
    			a[i]+=x;
    	}
    	long sum(int n) {
    		long sum=0;
    		for(; n>0; n-=n&-n)
    			sum+=a[n];
    		return sum;
    	}
    }
    
    static class Pair implements Comparable<Pair> {
    	int a, b;
    	Pair(int a, int b) {
    		this.a=a;
    		this.b=b;
    	}
    	public int compareTo(Pair o) {
    		return a-o.a;
    	}
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