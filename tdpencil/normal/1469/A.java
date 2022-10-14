

import java.util.*;
import java.io.*;
import java.lang.*;

public class A {
	public static void main(String args[]) {
        FastReader fr = new FastReader();
        int T = fr.nextInt();
        int test_case;
        outer: for(test_case = 0; test_case < T; test_case++) {
        	char []string = fr.next().toCharArray();
            
            if(string.length % 2 == 1) {
            	System.out.println("NO");
            	continue outer;
            }
            
            if(string[0] == ')' || string[string.length-1] == '(') {
            	System.out.println("NO");
            } else {
            	System.out.println("YES");
            }
        }
    }
	public static boolean isPrime(int n) {
		if(n==1) return false;
		if(n==2) return true;
		if(n==3) return true;
		
		if(n%2==0 || n%3==0) return false;
		
		for(int i = 5; i * i < n; i += 6) {
			if(n % i == 0 || n % (i+2) == 0) {
				return false;
			}
		}
		return true;
	}
	
    static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() 
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
        public void randomShuffleSort(int []a) {
            for(int i =0; i < (a.length)/2; i++) {
                int temp=a[i];
                a[i]=a[(a.length)-1-i];
                a[(a.length)-1-i]=temp;
            }
            this.fine_sort(a);
        }
        public void fine_sort(int a[]) {
            ArrayList<Integer> A = new ArrayList<>();
            for(int i : a) A.add(i);
            Collections.sort(A);
            for(int i=0; i < a.length; i++) {
                a[i]=A.get(i);
            }
        }
        public void reverse(int a[]) {
        	for(int i =0; i < a.length/2; i++) {
        		int temp=a[i];
        		a[i] = a[(a.length)-1-i];
        		a[(a.length)-1-i] = temp;
        	}
        }
    }
     
}