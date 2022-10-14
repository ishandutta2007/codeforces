

import java.util.*;
import java.io.*;
import java.math.*;
public class A {
	
    public static void main(String[] args) {
    	PrintWriter out=new PrintWriter(System.out);
        FastScanner fs=new FastScanner();
        int tc=fs.nextInt();
        for(int tt=0;tt<tc;tt++) {
        	int nf[]=new int[10001];
        	int n=fs.nextInt();int a[]=new int[n];
        	for (int i=0;i<n;i++) 
        		a[i]=fs.nextInt();
        	int ans=0;
        	for (int i=0;i<n;i++) {
        		if(nf[a[i]]>0) ans++;
        		nf[a[i]]++;
        	}
        	if(ans%2==1) {
        		out.println(n-(ans+1));
        	} else {
        		out.println(n-ans);
        	}
        	
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