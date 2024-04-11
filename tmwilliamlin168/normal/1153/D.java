import java.util.*;
import java.lang.*;
import java.io.*;

public class Main
{
	PrintWriter out = new PrintWriter(System.out);
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer tok = new StringTokenizer("");
    String next() throws IOException {
        if (!tok.hasMoreTokens()) { tok = new StringTokenizer(in.readLine()); }
        return tok.nextToken();
    }
    int ni() throws IOException { return Integer.parseInt(next()); }
    long nl() throws IOException { return Long.parseLong(next()); }
    
    void solve() throws IOException {
        int n=ni();
        int[]m = new int[n+1];
        ArrayList<Integer>[] C = new ArrayList[n+1];
        for (int x=1;x<=n;x++)  { m[x]=ni(); C[x]=new ArrayList(); }
        int[]p = new int[n+1];
        for (int x=2;x<=n;x++) { p[x]=ni(); C[p[x]].add(x); }
        int[] V = new int[n+1];
        int leaf=0;
        Stack<Integer> S = new Stack();
        Stack<Integer> T = new Stack();
        S.push(1);
        T.push(1);
        int y;
        
        while (!S.empty()) {
            y = S.pop();
            if (C[y].size()==0) { leaf++; V[y]=1; continue; }
            if (m[y]==1) V[y]=Integer.MAX_VALUE;
            for (int x=0; x<C[y].size();x++) { S.push(C[y].get(x));  T.push(C[y].get(x)); }
        }
        
        int z;
        while (!T.empty()) {
            y = T.pop();
            z = p[y];
            if (m[z]==0) V[z] += V[y];
            else V[z] = Math.min(V[z],V[y]);
        }
        
        System.out.println (leaf+1-V[1]);
    }
    
    public static void main(String[] args) throws IOException {
        new Main().solve();
    }
}