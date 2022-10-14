import java.util.*;
import java.io.*;
import java.lang.Math;


public class C {
	
	
	public static void main(String args[]) {
		PrintWriter out = new PrintWriter(System.out);
		FastScanner fs = new FastScanner();
		
		int t=1;
		
		for(int qq=1; qq <= t; qq++) {
			int n=4;
			char line[][]=new char[n][n];
			for(int i=0;i<n;i++) line[i]=fs.next().toCharArray();
			boolean ans=false;
			for(int i=0;i<n-1;i++) {
				for(int j=0;j<n-1;j++) {
					int cnt1=0,cnt2=0;
					cnt1+=line[i][j]=='#'?1:0;
					cnt1+=line[i+1][j]=='#'?1:0;
					cnt1+=line[i][j+1]=='#'?1:0;
					cnt1+=line[i+1][j+1]=='#'?1:0;
					cnt2+=line[i][j]=='.'?1:0;
					cnt2+=line[i+1][j]=='.'?1:0;
					cnt2+=line[i][j+1]=='.'?1:0;
					cnt2+=line[i+1][j+1]=='.'?1:0;
					// out.println(cnt1 + " " + cnt2);
					if(cnt1 >= 3 || cnt2 >= 3) {
						ans=true;
					}
				}
			}

			out.println(ans?"YES":"NO");
		}
		out.close();
	}
    
    static void swap(int []a, int x, int y) {
        int temp=a[x];
        a[x]=a[y];
        a[y]=temp;
    }
	static class Pair implements Comparable<Pair>{
		int first, second;
		public Pair(int x, int y) {
			first=x;second=y;
		}
		public int compareTo(Pair x) {
			if(this.first<x.first)
				return -1;
			if(this.first==x.first)
				return this.second<x.second?-1:(this.second==x.second?0:1);
			return 1;
		}
	}
	
	
	
	
	static class RangeMin {
		long logs[], st[][];
		int N, K;
		public RangeMin(int n) {
			N=n;
			K = (int)((double) (Math.log10((double)n) /(double) Math.log10((double)2) ));
			st = new long [N+2][K+2];
			logs = new long[N+2];
		}
		void init(ArrayList<Integer> A) {
			
			for(int i = 0; i < N; i++) {
				Arrays.fill(st[i], (long)1e18);
				st[i][0]=(long)A.get(i);
			}
			// NLOGN
			for(int j = 1; j <= K; j++) {
				for(int i = 0; i + (1<<j) <= N; i++) {
					st[i][j]=Math.min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
				}
			}
			logs[1]=0;
			for(int i = 2; i <= N; i++) {
				logs[i]=logs[i/2]+1;
			}
		}

		long query(int L, int R) {
			int j = (int)logs[R-L+1];
			return Math.min(st[L][j], st[R - (1 << j) + 1][j]);
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
        public void reverse(int a[]) {
            for(int i = 0; i < a.length / 2; i++) {
                int x=a[i];
                a[i]=a[a.length-1-i];
                a[a.length-1-i]=x;
            }
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
			Random r = new Random();
            for(int i =0; i < (a.length)/2; i++) {
                int temp=a[i],p=r.nextInt(a.length);
                a[i]=a[p];
                a[p]=temp;
            }
            this.fine_sort(a);
        }
        public void fine_sort(int a[]) {
            Arrays.sort(a);
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
    		else if(l <= leftmost && r >= rightmost) return (long)sum + lz_val;
    		
    		return (long) lChild.query(l, r) + (long) rChild.query(l, r);
    	}
    }
}