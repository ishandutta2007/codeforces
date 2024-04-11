import java.util.*;
import java.io.*;
import java.lang.*;

public class A {
	static PrintWriter out;
	static FileWriter file;
	public static void main(String []args) {
		FastScanner fs = new FastScanner();
		int t = fs.nextInt();
		for(int tt=0; tt < t; tt++)
		{
			int x = fs.nextInt();
			int a = fs.nextInt();
			
			System.out.println(2 * a);
		}
	}	
	
	static class pair {
		double x, y;
		public pair() {
			x=0;y=0;
		}
		public pair(double x, double y) {
			this.x = x;
			this.y= y;
		}
	}
	static class point {
		int x, y;
		public point() {
			this.x = 0;
			this.y = 0;
		}
		public point(int x, int y) {
			this.x = x;
			this.y = y;
			
		}
		public pair slope(point p) {
			assert(p.x != this.x);
			double slp = (this.y - p.y) / (this.x - p.x);
			double b = (this.y - slp * this.x);
			pair pt = new pair(slp, b);
			return pt;
		}
		public int dproduct(point p) {
			return (this.x * p.y) - (p.x * this.y); 
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
        public void reverse(int a[]) {
        	for(int i=0; i < a.length/2; i++) {
        		int temp=a[i];
        		a[i] = a[a.length-i-1];
        		a[a.length-i-1] = temp;
        		
        	}
        }
        public boolean sorted(int a[]) {
        	for(int i = 1; i < a.length; i++)
        		if(a[i] > a[i-1]) return false;
        	return true;
        }
        public int search(int a[], int target) {
        	if(!sorted(a)) throw null;
        	int l = 0, r = a.length-1;
        	while(l <= r) {
        		int mid = l + (r - l) / 2;
        		if(a[mid] == target)
        			return mid;
        		else if(a[mid] < target) {
        			l=mid+1;
        		} else if(a[mid] > target) {
        			r = mid-1;
        		}
        	}
        	return -1;
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
        	Random random = new Random();
        	int n = a.length;
            for(int i =0; i < n/2; i++) {
            	int rndm = random.nextInt(n);
                int temp=a[rndm];
                a[rndm]=a[i];
                a[i]=temp;
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
    		if(l > rightmost || r < leftmost) return;
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