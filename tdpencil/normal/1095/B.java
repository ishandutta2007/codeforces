import java.util.*;
import java.io.*;
import java.lang.*;


public class A {

    static int INF = -2_000_000_000;
    static long MOD = 1_000_000_007;
    static int MAX_PRIME = 1_000_000_000;
    static int MAX_LOG = 20;
    static boolean on[];
    public static void main(String args[]) throws Exception {
        FastScanner fs=new FastScanner();
        PrintWriter out=new PrintWriter(System.out);
        int tt=1;
        for(int tc=0; tc < tt; ++tc) {
        	int n=fs.nextInt();
        	int a[]=fs.nextArray(n);
        	fs.randomShuffleSort(a);
        	out.println(Math.min(a[n-2]-a[0], a[n-1]-a[1]));
        }
        
        out.close();
    }
    static int gcd(int x, int y) {
    	return (y==0?x:gcd(y,x%y));
    }
    static class seg {
    	int g;
    	int leftmost, rightmost;
    	seg children[]=new seg[2];
    	
    	public seg(int l, int r, int a[]) {
    		
    		leftmost=l;
    		rightmost=r;
    		if(l==r) {
    			g=a[l];
    		} else {
    			int mid=(l+r)/2;
    			
    			children[0]=new seg(l,mid,a);
    			children[1]=new seg(mid+1,r,a);
    			update();
    		}
    	}
    	
    	void update() {
    		g=gcd(children[0].g,children[1].g);
    	}
    	
    	int query(int left, int right) {
    		if(leftmost >= left && right >= rightmost)
    			return g;
    		else if(left > rightmost || right < leftmost)
    			return 0;
    		return gcd(children[0].query(left, right), children[1].query(left, right));
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
            Random r = new Random();
            for(int i =0; i < (a.length)/2; i++) {
                int temp=a[i],p=r.nextInt(a.length);
                a[i]=a[p];
                a[p]=temp;
            }
            Arrays.sort(a);
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