import java.util.*;
import java.io.*;
import java.text.*;
//Solution Credits: Taranpreet Singh
public class Main{
    //SOLUTION BEGIN
    //This code is not meant for understanding, proceed with caution
    void pre() throws Exception{}
    void solve(int TC) throws Exception{
        int n = ni();
        TreeSet<Integer> px = new TreeSet<>();TreeSet<Integer> py = new TreeSet<>();
        for(int i = 1; i<= n; i++){
            if(odd(i,1,i,n))px.add(i);
        }
        for(int i = 1; i<= n; i++){
            if(odd(1,i,n,i))py.add(i);
        }
        if(!px.isEmpty() && !py.isEmpty()){
            if(odd(px.first(), py.first(),px.first(),py.first()))ans(px.first(),py.first(),px.last(),py.last());
            else ans(px.first(),py.last(),px.last(),py.first());
        }else if(!px.isEmpty()){
            int x1 = px.first(), x2 = px.last();
            int lo = 1, hi = n;
            while(lo<hi){
                int mid = (lo+hi)/2;
                if(odd(x1,1,x1,mid))hi = mid;
                else lo = mid+1;
            }
            ans(x1,hi,x2,hi);
        }else if(!py.isEmpty()){
            int y1 = py.first(), x2 = py.last();
            int lo = 1, hi = n;
            while(lo<hi){
                int mid = (lo+hi)/2;
                if(odd(1,y1,mid,y1))hi = mid;
                else lo = mid+1;
            }
            ans(hi,y1,hi,x2);
        }else hold(false);
    }
    void ans(int x1, int y1, int x2, int y2){
        pni("! "+x1+" "+y1+" "+x2+" "+y2);
    }
    boolean odd(int x1, int y1, int x2, int y2) throws Exception{
        pni("? "+x1+" "+y1+" "+x2+" "+y2);
        return ni()%2==1;
    }
    //SOLUTION END
    void hold(boolean b)throws Exception{if(!b)throw new Exception("Hold right there, Sparky!");}
    long mod = (long)1e9+7, IINF = (long)1e18;
    final int INF = (int)1e9;
    DecimalFormat df = new DecimalFormat("0.0000000");
    double PI = 3.1415926535897932384626433832792884197169399375105820974944, eps = 1e-8;
    static boolean multipleTC = false, memory = false;
    FastReader in;PrintWriter out;
    void run() throws Exception{
        in = new FastReader();
        out = new PrintWriter(System.out);
        int T = (multipleTC)?ni():1;
        //Solution Credits: Taranpreet Singh
        pre();for(int t = 1; t<= T; t++)solve(t);
        out.flush();
        out.close();
    }
    public static void main(String[] args) throws Exception{
        if(memory)new Thread(null, new Runnable() {public void run(){try{new Main().run();}catch(Exception e){e.printStackTrace();}}}, "1", 1 << 28).start();
        else new Main().run();
    }
    long gcd(long a, long b){return (b==0)?a:gcd(b,a%b);}
    int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
    int bit(long n){return (n==0)?0:(1+bit(n&(n-1)));}
    void p(Object o){out.print(o);}
    void pn(Object o){out.println(o);}
    void pni(Object o){out.println(o);out.flush();}
    String n()throws Exception{return in.next();}
    String nln()throws Exception{return in.nextLine();}
    int ni()throws Exception{return Integer.parseInt(in.next());}
    long nl()throws Exception{return Long.parseLong(in.next());}
    double nd()throws Exception{return Double.parseDouble(in.next());}

    class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastReader(String s) throws Exception{
            br = new BufferedReader(new FileReader(s));
        }

        String next() throws Exception{
            while (st == null || !st.hasMoreElements()){
                try{
                    st = new StringTokenizer(br.readLine());
                }catch (IOException  e){
                    throw new Exception(e.toString());
                }
            }
            return st.nextToken();
        }

        String nextLine() throws Exception{
            String str = "";
            try{   
                str = br.readLine();
            }catch (IOException e){
                throw new Exception(e.toString());
            }  
            return str;
        }
    }
}