
import java.io.*;
import java.util.*;
import java.lang.*;

public class B {
    public static void main(String args[]) throws Exception {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int A[] = new int[N];
        
        st=new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(A);
        TreeSet<Pair> ts=new TreeSet<>();
        for(int i = 0; i < N; i++) {
            ts.add(new Pair(A[i], i));
        }

        int ans = 0;
        for(int i =0; i < N; i++) {
            Pair up=ts.ceiling(new Pair(A[i] + 1, 0));
            if(up == null) {
                continue;
            } else {
                ++ans;
                ts.remove(up);
            }
        }

        System.out.println(ans);
    }
    static class Pair implements Comparable<Pair> {
        int first, second;
        public Pair(int x, int y) {
            this.first = x;
            this.second = y;
        }
        public Pair() {
            this.first = 0;
            this.second = 0;
        }

        public int compareTo(Pair other) {
            if(other.first == this.first)
                return this.second - other.second;
            return this.first - other.first;
        }
    }
}