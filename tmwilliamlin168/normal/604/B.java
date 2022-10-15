import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n=in.nextInt(), k=in.nextInt();
        int[] s = new int[n];
        for(int i=0; i<n; ++i)
        	s[i]=in.nextInt();
        int max=0, i=0;
        for(; i<n-k; ++i)
        	max=Math.max(s[i]+s[2*(n-k)-1-i], max);
        for(; i<n; ++i)
        	max=Math.max(s[i], max);
        System.out.println(max);
    }
}