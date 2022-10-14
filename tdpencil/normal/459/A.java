// package cf;

import java.util.*;
import java.io.*;
import java.lang.*;

public class A {
	public static void main(String args[]) {
		FastScanner fs = new FastScanner();
		int x1 = fs.nextInt(),y1=fs.nextInt(),x2=fs.nextInt(),y2=fs.nextInt();
		if(x1 == x2) {
			int dist = y2 - y1;
			dist = Math.abs(dist);
			
			System.out.println((x1+ dist) + " " + (y1) + " " + (x2 + dist) + " " + (y2));
		} else if(y1 == y2) {
			int dist = x2 - x1;
			dist = Math.abs(dist);
			System.out.println(x1 + " " + (y1 + dist) + " " + (x2) + " " + (y2 + dist));
		} else {
			// two different sides
			if(abs(x1 - x2) != abs(y1 - y2 )) {
				System.out.println(-1);
				return;
			}
			System.out.println(x1 + " " + y2 + " " + x2 + " " + y1);
		}
	}
	static int abs(int x) {
		return x < 0 ? -x : x;
	}
	static int dist(int x1, int y1, int x2, int y2) {
		return (x1 - x2) * (x1 - x2) - (y1 - y2) * (y1 - y2);
	}
	static boolean left(int x1, int y1, int x2, int y2) {
		return x1 == x2 ? y1 < y2 : x1 < x2;
	}
	static boolean right(int x1, int y1, int x2, int y2) {
		return x1 == x2 ? y1 > y2 : x1 > x2;
	}
	static boolean down(int x1, int y1, int x2, int y2) {
		return x1 == x2 ? y1 < y2 : x1 < x2;
	}
	static boolean up(int x1, int y1, int x2, int y2) {
		return x1 == x2 ? y1 > y2 : x1 > x2;
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
    }
   
}