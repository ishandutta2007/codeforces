// package cf;

import java.util.*;
import java.io.*;
import java.lang.*;

public class A {
	public static void main(String args[]) {
		FastScanner fs = new FastScanner();
		int tc=fs.nextInt();
		outer: for(int tt=0; tt < tc; tt++) {
			int n = fs.nextInt();
			int a[] = fs.nextArray(n);
			int b[] = fs.nextArray(n);
			int d[] = new int[n];
			for(int i =0 ; i < n; i++)
				d[i] = a[i] - b[i];
			for(int i =0; i < n; i++)
				if(d[i] > 0) {
					System.out.println("NO");
					continue outer;
				}
			int ans =0;
			int nd[] = new int[n+2];
			nd[0] = 0;
			for(int i = 0; i < n; i++)
				nd[i+1] = d[i];
			nd[n+1] = 0;
			
			for(int i =1; i < n+2; i++)
				if(nd[i] != nd[i-1]) ++ans;
			System.out.println(ans <= 2 ? "YES" : "NO");
		}
	}
	
	
	
	
	
	
	
    static class FastScanner 
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastScanner() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        }
        public int[] nextArray(int n) {
            int a[] = new int[n];
            for(int i =0; i < n; i++) a[i]=this.nextInt();
            return a;
        }
        public int max(int a[]) {
        	int mx = Integer.MIN_VALUE;
        	for(int i : a)
        		mx = Math.max(i, mx);
        	return mx;
        }
        public int count(int a[], int val) {
        	int ans =0;
        	for(int i : a)
        		ans += val == i ? 1 : 0;
        	return ans;
        }
        public int min(int a[]) {
        	int mn = Integer.MAX_VALUE;
        	for(int i : a)
        		mn = Math.min(i, mn);
        	return mn;
        }
        public void randomShuffleSort(int []a) {
            for(int i =0; i < (a.length)/2; i++) {
                int temp=a[i];
                a[i]=a[(a.length)-1-i];
                a[(a.length)-1-i]=temp;
            }
            this.fine_sort(a);
        }
        public int idx(int val, int ar[]) {
        	int p = -1;
        	for(int i=0; i < ar.length; i++)
        		if(ar[i] == val) return i;
        	return p;
        }
        public void fine_sort(int a[]) {
            ArrayList<Integer> A = new ArrayList<>();
            for(int i : a) A.add(i);
            Collections.sort(A);
            for(int i=0; i < a.length; i++) {
                a[i]=A.get(i);
            }
        } 
    }
   
}