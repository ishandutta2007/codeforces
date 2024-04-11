

import java.util.*;
import java.io.*;
import java.math.*;
public class A {
	
    public static void main(String[] args) {
    	PrintWriter out=new PrintWriter(System.out);
        FastScanner fs=new FastScanner();
        int tc=fs.nextInt();
        for(int tt=0;tt<tc;tt++) {
        	int n=fs.nextInt();
        	int k=fs.nextInt();
        	int a[]=new int[n];
        	for (int i=0;i<n;i++) {
        		a[i]=fs.nextInt();
        	}
        	int dif[]=new int[n-1];
        	for (int i=1;i<n;i++) {
        		if(a[i]*2<=a[i-1]) {
        			dif[i-1]=1;
        		}
        	}
        	int ans=0;
        	// 0==good,1==bad
        	segtree st=new segtree(0,n-2,dif);
        	for (int i=0;i<n-k;i++) {
        		// if dif[i]...
        		ans+=st.qry(i, i+k-1);
        	}
        	System.out.println(ans);
        	
        }
        out.close();
        
    }
    static class segtree {
    	int good;
    	int leftmost, rightmost;
    	segtree lchild, rchild;
    	
    	segtree(int left, int right, int a[]) {
    		leftmost=left;
    		rightmost=right;
    		if(left==right) {
    			good=a[left]==0?1:0;
    		} else {
    			int md=(left+right)/2;
    			lchild=new segtree(left,md,a);
    			rchild=new segtree(md+1,right,a);
    			update();
    		}
    	}
    	void update() {
    		good=lchild.good==1&&rchild.good==1?1:0;
    	}
    	
    	int qry(int left, int right) {
    		if(right<leftmost||left>rightmost)
    			return 1;
    		else if(left<=leftmost&&right>=rightmost)
    			return good;
    		
    		return lchild.qry(left, right)==1&&rchild.qry(left,right)==1?1:0;
    	}
    }
    static int conv(int hr, int mn) {
    	return 9973*hr+mn;
    }
    static boolean ispal(String s) {
    	int n=s.length();
    	for (int i=0;i<n/2;i++) {
    		if(s.charAt(i)!=s.charAt(n-i-1)) {
    			return false;
    		}
    	}
    	return true;
    }
    
    static class time {
    	int hour, minute;
    	public time(int bh, int bm) {
    		this.hour=bh;
    		this.minute=bm;
    	}
    	public void add_time(int mns) {
    		hour+=mns/60;
    		minute+=mns%60;
    		if(minute>=60) {
    			hour++;
    			minute%=60;
    		}
    		if(hour>23) {
    			hour%=24;
    		}
    	}
    	public String convtime() {
    		String ans=new String();
    		if(hour<10)
    			ans+="0" + String.valueOf(hour);
    		else
    			ans+=String.valueOf(hour);
    		if(minute<10)
    			ans+="0" + String.valueOf(minute);
    		else
    			ans+=String.valueOf(minute);
    		return ans;
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
        int ni() {
            return nextInt();
        }
        int nextInt()
        {
            return Integer.parseInt(next());
        }
        long nl() {
            return nextLong();
        }
        long nextLong()
        {
            return Long.parseLong(next());
        }
        double nd()
        {
            return nextDouble();
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
        public void sort(int []a) {
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
/*
when stuck:
    dp, see as ranges, greedy
    maybe intuition? ad-hoc?
    bs? bs with bitmasks?
    go backwards?
    solve for complement
    do stuff / write down
    draw? perhaps DAG or two pointers in disguise?
    template wrong?
    STOP PLAYING VALORANT
    STOP WATCHING TWITCH BOZO
WA:
    input right?
    N, M or N, K?
    list[0] when doesn't exist?
    is right DS for problem?
    998244353 or 1000000007?
    overflow
TLE:
    high constant factor? (switch to cpp bozo)
    while loop / for loop?
RTE:
    divide 0 ? overflow? maybe empty ds
    forgot to remove com.company
*/