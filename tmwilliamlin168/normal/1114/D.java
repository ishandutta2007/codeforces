import java.util.*;
import java.io.*;
import java.math.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);
        //Scanner sc = new Scanner();
        Reader in = new Reader();
        Main solver = new Main();
        solver.solve(out, in);
        out.flush();
        out.close();
 
    }
 
    //<>
    
    static int maxn = (int)1e5*2;
    static long mod=(int)1e9+7;
    static int n,t,m,k;
    
    void solve(PrintWriter out, Reader in) throws IOException{   
        int n = in.nextInt();
        
        ArrayList<Node> list = new ArrayList<>();
        int[] arr = new int[n];
        for(int i=0;i<n;i++) arr[i] = in.nextInt();
        
        int prev = arr[0];
        int cnt=1;
        for(int i=1;i<n;i++){
            if(arr[i]!=prev){
                list.add(new Node(prev,cnt));
                prev = arr[i];
                cnt=1;
            }else cnt++;
        }
        list.add(new Node(prev,cnt));
        
        int[][] dp = new int[list.size()][list.size()];
        for(int i=0;i<list.size();i++)
            for(int j=i+1;j<list.size();j++)
                dp[i][j] = -1000000000;
        
        for(int i=1;i<=list.size()-1;i++){
            for(int j=0;j<=list.size()-1-i;j++){
                if(list.get(j).v==list.get(j+i).v) dp[j][j+i] = dp[j+1][j+i-1]+1;
                else dp[j][j+i] = Math.min(dp[j+1][j+i],dp[j][i+j-1])+1;
            }
        }
        out.println(dp[0][list.size()-1]);
    }
    
    static class Node{
        int v,c;
        
        Node(int v,int c){
            this.v = v;
            this.c = c;
        }
        
    }
    
    static class Edge implements Comparable<Edge> {
        int u,v,w;
        
        Edge(int u,int v,int w){
            this.u = u;
            this.v = v;
            this.w = w;
        }
        
        
        public int compareTo(Edge o){
            return this.w - o.w;
        }
    }
    
    
    static class Reader {
 
        private InputStream mIs;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
 
        public Reader() {
            this(System.in);
        }
 
        public Reader(InputStream is) {
            mIs = is;
        }
 
        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
 
        }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = mIs.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }
 
        public String nextLine() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isEndOfLine(c));
            return res.toString();
        }
 
        public String next() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        public long nextLong() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }
 
        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }
 
        public boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
 
        public boolean isEndOfLine(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }
 
    }
}