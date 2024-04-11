import java.util.*;
public class Bus
{
    public static void main(String[]args)
    {
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        int t=scan.nextInt();
        int s=0;
        int d=0;
        ArrayList<Integer> ans=new ArrayList<>();
        for(int i=0;i<n;i++)
        {
            s=scan.nextInt();
            d=scan.nextInt();
            while(s<t)
                s+=d;
            ans.add(s);
        }
        System.out.println(ans.indexOf(Collections.min(ans))+1);
    }
}