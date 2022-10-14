

import java.util.*;
import java.io.*;
import java.math.*;
public class A {
	
    public static void main(String[] args) {
    	PrintWriter out=new PrintWriter(System.out);
        FastScanner fs=new FastScanner();
        int tc=fs.nextInt();
        for(int tt=0;tt<tc;tt++) {
        	char board[][]= new char[8][];
        	for (int i=0;i<8;i++) { 
        		board[i]=fs.next().toCharArray();
        	}
        	assert(board[2].length == 8);
        	for (int i=1;i<7;i++) {
        		for (int j=1;j<7;j++) {
        			boolean w=board[i][j]=='#';
        			for (int k=0;k<2;k++) {
        				for (int m=0;m<2;m++) {
//        					System.out.println(i + " " + j);
        					w&=board[i+(k%2==0?1:-1)][j+(m%2==0?1:-1)]=='#';
        				}
        			}
        			if(w) {
        				System.out.println((i+1) + " " + (j+1));
        			}
        		}
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