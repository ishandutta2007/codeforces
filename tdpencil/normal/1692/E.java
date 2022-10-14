

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
        	int a[]=new int[n];
        	int prefixes[]=new int[n];
        	int suffixes[]=new int[n];
        	int s=fs.nextInt();
        	int ans=1000000;
        	for (int i=0;i<n;i++) {
        		a[i]=fs.nextInt();
        		if(i==0)
        			prefixes[i]=a[i];
        		else
        			prefixes[i]=prefixes[i-1]+a[i];
        	}
        	if(prefixes[n-1]==s)
        		ans=0;
        	for (int i=n-1;i>=0;i--) {
        		if(i==n-1)
        			suffixes[i]=a[i];
        		else
        			suffixes[i]=suffixes[i+1]+a[i];
        		if(suffixes[i]==prefixes[n-1]-s) ans=Math.min(ans,n-i);
        		if(prefixes[i]==prefixes[n-1]-s) ans=Math.min(ans, i+1);
        	}
        	
        	for (int i=0;i<n;i++) {
        		int to_get=prefixes[n-1]-s;
        		to_get-=prefixes[i];
        		int lb=0,rb=n-1;
        		while(lb<rb) {
        			int mid=(lb+rb+1)/2;
        			if(suffixes[mid]>=to_get) {
        				lb=mid;
        			} else {
        				rb=mid-1;
        			}
        		}
        		if(lb>=0&&lb<n&&suffixes[lb]==to_get) {
        			ans=Math.min(ans, (i+1)+(n-lb));
        		}
        	}
        	System.out.println(ans==1000000?-1:ans);
        }
        out.close();
        
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