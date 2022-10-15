import java.util.*;
public class qc{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int k=sc.nextInt();
        int a[]=new int[n];
        for(int i=0;i<n;i++){
            a[i]=sc.nextInt();
        }
        String s=sc.next();
        int x='/';
        long sum=0;
        PriorityQueue<Integer> pq=new PriorityQueue<Integer>((n1,n2)->n2-n1);
        for(int i=0;i<n;i++){
            if(s.charAt(i)==x){
                pq.add(a[i]);
            }
            else{
                int c=0;
                x=s.charAt(i);
                while(!pq.isEmpty() && c<k){
                    c++;
                    sum+=pq.poll();
                }
                pq=new PriorityQueue<Integer>((n1,n2)->n2-n1);
                pq.add(a[i]);
            }
        }
        int c=0;
        while(!pq.isEmpty() && c<k){
                    c++;
                    sum+=pq.poll();
                }
        System.out.println(sum);
    }
}