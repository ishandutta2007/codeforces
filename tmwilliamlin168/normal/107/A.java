import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String args[]) {
    	Scanner in = new Scanner(System.in);
    	int n=in.nextInt(), p=in.nextInt();
    	int[] from = new int[n];
    	Arrays.fill(from, -1);
    	int[] to = new int[n];
    	Arrays.fill(to, -1);
    	int[] d = new int[n];
    	for(; p>0; --p) {
    		int a=in.nextInt()-1, b=in.nextInt()-1, d_i=in.nextInt();
    		from[b]=a;
    		to[a]=b;
    		d[a]=d_i;
    	}
    	int t=0;
    	StringBuilder s = new StringBuilder();
    	for(int i=0; i<n; ++i) {
    		if(from[i]==-1&&to[i]!=-1) {
    			s.append(i+1).append(' ');
    			int maxD=d[i];
    			int i2=i;
    			while(to[(i2=to[i2])]!=-1)
    				maxD=Math.min(d[i2], maxD);
    			s.append(i2+1).append(' ').append(maxD).append('\n');
    			++t;
    		}
    	}
    	System.out.println(t);
    	System.out.println(s);
    }
}