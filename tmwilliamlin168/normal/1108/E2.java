import java.util.*;
import java.io.*;

public class Main {

    FastReader in = new FastReader();
    PrintWriter out = new PrintWriter(System.out);
    int N = (int)1e5+5, n,m,h;
    int[] a = new int[2*N],d = new int[N];

    //set the value at given index
    void apply(int p,int value){
        a[p] += value;
        if(p<n) d[p] += value;
    }

    // build the initial tree
    void build(){
        for(int i=n-1;i>0;i--)a[i] = Math.min(a[i<<1],a[i<<1|1]);
    }

    // update all parents of child at index p
    void build(int p){
        while(p>1){
            p>>=1;
            a[p] = Math.min(a[p<<1],a[p<<1|1])+d[p];
        }
    }

    // increment a[i] by value (l<=i<r)
    void inc(int l,int r,int value){
        l += n; r += n;
        int l0 = l, r0  = r; 
        while(l<r){
            if((l&1)==1)apply(l++,value);
            if((r&1)==1)apply(--r,value);
            l>>=1;
            r>>=1;
        }
        build(l0);
        build(r0-1);
    }

    // push all the delayed changes to child at index p
    void push(int p){
        for (int s = h; s > 0; --s) {
            int i = p >> s;
            if (d[i] != 0) {
              apply(i<<1, d[i]);
              apply(i<<1|1, d[i]);
              d[i] = 0;
            }
        }
    }

    // query[l,r)
    int query(int l, int r) {
      l += n; r += n;
      push(l);
      push(r - 1);
      int res = (int)2e9;
      for (; l < r; l >>= 1, r >>= 1) {
        if ((l&1)==1) res = Math.min(res, a[l++]);
        if ((r&1)==1) res = Math.min(a[--r], res);
      }
      return res;
    }

    // main code 
    void solve(){
        n = in.ni(); m = in.ni(); h = (int)(Math.log(n)/Math.log(2));
        ArrayList<Integer>[] lf = new ArrayList[n], rf = new ArrayList[n];
        int[] data = new int[n];
        for(int i=0;i<n;i++){
            data[i] = in.ni();
            lf[i] = new ArrayList<>();
            rf[i] = new ArrayList<>();
        }
        int[][] seg = new int[m][2];
        for(int i=0;i<m;i++){
            int l = in.ni(), r = in.ni();
            l--;
            r--;
            lf[r].add(l);
            rf[l].add(r);
            seg[i][0] = l;
            seg[i][1] = r;
        }

        int ans, ind = -1,min = data[0],max = data[0];
        for(int i : data){
            min = Math.min(min,i);
            max = Math.max(max,i);
        }
        ans = max-min;


        //left 
        for(int i=0;i<n;i++)a[i+n] = data[i];
        build();
        for(int i=0;i<n;i++){  
            if(ans<data[i]-min){
                ans = data[i]-min;
                ind = i;
            }
            for(int k : lf[i]){
                inc(k,i+1,-1);
                min = query(0,n);
            }
        }

        // right
        Arrays.fill(d,0,n,0);
        Arrays.fill(a,0,n,0);
        for(int i=0;i<n;i++)a[i+n] = data[i];
        build();
        min = data[n-1];
        for(int i=n-1;i>=0;i--){
            if(ans<data[i]-min){
                ans = data[i]-min;
                ind = i;
            }
            for(int k : rf[i]){
                inc(i,k+1,-1);
                min = query(0,n);
            }
            
        }

        out.println(ans);
        int c = 0;
        ArrayList<Integer> res = new ArrayList<>();
        for(int i=0;i<m && ind!=-1;i++)
            if(seg[i][0]>ind || seg[i][1]<ind){
                res.add(i);
                c++;
            }
        out.println(c);
        for(int i : res)
            out.print((i+1)+" ");
    }

    void run(){
        solve();
        out.close();
    }
    public static void main(String[] args) {
        new Main().run();
    }

    // class for fast I/O
    class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastReader(String s) throws Exception{
            br = new BufferedReader(new FileReader(s));
        }

        String next(){
            while (st == null || !st.hasMoreElements()){
                try{
                    st = new StringTokenizer(br.readLine());
                }catch (IOException  e){
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        String nextLine(){
            String str = "";
            try{   
                str = br.readLine();
            }catch (IOException e){
                e.printStackTrace();
            }  
            return str;
        }
        int nextInt(){return Integer.parseInt(in.next());}
        long nextLong(){return Long.parseLong(in.next());}
        double nextDouble(){return Double.parseDouble(in.next());}
        int ni(){return Integer.parseInt(in.next());}
        long nl(){return Long.parseLong(in.next());}
        double nd(){return Double.parseDouble(in.next());}
    }

    void pn(Object o){out.println(o);out.flush();}

    class pair{
        int f,s;
        public pair(int f,int s){
            this.f = f;
            this.s = s;
        }
    }
}