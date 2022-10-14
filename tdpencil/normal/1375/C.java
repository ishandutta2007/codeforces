

import java.util.*;
import java.io.*;
import java.lang.Math;


public class A {
	
	public static void main(String args[]) {
		PrintWriter out = new PrintWriter(System.out);
		FastScanner fs = new FastScanner();
		int t = fs.nextInt();
		outer: while(t-->0) {
			int n = fs.nextInt();
			ArrayList<Integer> a = new ArrayList<>();
			for(int i=0;i<n;i++)
				a.add(fs.nextInt());
			
			out.println(a.get(0) < a.get(n-1) ? "YES" : "NO");
		}
		out.close();
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
        public void fine_sort(int a[]) {
            ArrayList<Integer> A = new ArrayList<>();
            for(int i : a) A.add(i);
            Collections.sort(A);
            for(int i=0; i < a.length; i++) {
                a[i]=A.get(i);
            }
        } 
    }
	static class SegmentTree {
    	int leftmost, rightmost;
    	SegmentTree lChild, rChild;
    	int sum;
    	long lz_val;
    	
    	public SegmentTree(int l, int r, int a[]) {
    		leftmost = l;
    		rightmost = r;
    		lz_val=0;
    		if(l == r)
    			sum = a[l];
    		else {
    			int mid = (l + r) / 2;
    			lChild = new SegmentTree(l, mid, a);
    			rChild = new SegmentTree(mid+1, r, a);
    			update();
    		}
    	}
    	public void update() {
    		sum = lChild.sum + rChild.sum + (int)lChild.lz_val + (int)rChild.lz_val;
    	}
    	public void pointUpdate(int pos, int val) {
    		if(leftmost == rightmost) {
    			sum = val;
    		} else {
    			int mid = (leftmost + rightmost) / 2;
    			if(pos <= lChild.rightmost) lChild.pointUpdate(pos, val);
    			else rChild.pointUpdate(pos, val);
    			update();
    		}
    	}
    	public void rangeUpdate(int l, int r, int val) {
    		// first check if it's within the range
    		if(l <= leftmost && r >= rightmost) {
    			lz_val += val;
    		} else {
    			// its not within the range so lets update the left if we have to and update the right if we have to
    			if(lChild.rightmost >= l) lChild.rangeUpdate(l, r, val);
    			if(rChild.leftmost <= r) rChild.rangeUpdate(l, r, val);
    			update();
    		}
    	}
    	public long query(int l, int r) {
    		if(l > rightmost || r < leftmost) return 0;
    		else if(l <= leftmost && r >= rightmost) return sum + lz_val;
    		
    		return (long) lChild.query(l, r) + (long) rChild.query(l, r);
    	}
    }
}