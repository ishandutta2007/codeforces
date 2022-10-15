import java.util.*;
import java.io.*;
public class code{
    public static class node{
        long a;
        int ind;
        public node(long a,int i){
            this.a = a;
            ind = i;
        }
    }
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        PrintWriter out = new PrintWriter(System.out);
        node[] no = new node[n];
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++){
            no[i] = new node(Long.parseLong(st.nextToken()),i+1);
        }
        Arrays.sort(no,new Comparator<node>(){
            public int compare(node n1,node n2){
                long d = n2.a-n1.a;
                if(d<0) d=-1;
                if(d>0) d=1;
                return (int)d;
            }
        });
        long sum = 0;
        int[] ind = new int[m*k];
        for(int i=0;i<m*k;i++){
            sum += no[i].a;
            ind[i] = no[i].ind;
        }
        Arrays.sort(ind);
        out.println(sum);
        out.print(ind[m-1]);
        for(int i=2*m-1;i<m*k-1;i+=m){
            out.print(" "+ind[i]);
        }
        out.flush();
    }
}