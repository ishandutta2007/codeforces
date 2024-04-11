import java.io.*;
import  java.util.*;
import static java.lang.System.in;

public class Main{
    static TreeMap<Integer,Integer> tm = new TreeMap<>();
    public static void main(String[] args)throws IOException{
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        for(int i=0;i<n;i++) a[i] = sc.nextLong();
        int m = sc.nextInt();
        int[] q = new int[m];
        for(int i=0;i<m;i++) q[i]=sc.nextInt();
        Arrays.sort(a);
        PrintWriter out = new PrintWriter(System.out);
        long sum = 0;
        for(long w:a) sum+=w;
        for(int i=0;i<m;i++){
            long cur = sum - a[n-q[i]];
            out.println(cur);
        }
        out.flush();
    }
}