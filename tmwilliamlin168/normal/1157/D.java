import java.util.*;
public class Class{
	public static long getLow(long y,int x){
		long last=y+x-1;
		if(x%2==0)return ((y+last)*(x/2));
		else return ((y+last)*(x/2))+(y+last)/2;
	}
	public static long getHigh(long y,int x){
    return y*((long)Math.pow(2,x)-1);
	}
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        long n=sc.nextInt();
        int days=sc.nextInt();
        int j=(int)(n/(Math.pow(2,days)-1));
        while(getHigh(j,days)<n){
        	j++;
        }
        if(getLow(j,days)>n){
            System.out.print("NO");
            return;
        }
        
        long arrHigh[] =new long[days],arrLow[]=new long[days];
        long sum=getLow(j,days);
        boolean flag=true;
        for(int i=0;i<days;i++)arrHigh[i]=j*(int)Math.pow(2,i);
        for(int i=0;i<days;i++,j++)arrLow[i]=j;
        for(int i=arrLow.length-1;n>sum;i--){
        	if(i==0||arrLow[i]==arrLow[i-1]*2)i=days-1;
        	if(n>sum-arrLow[i]+arrLow[i-1]*2){
        		sum+=arrLow[i-1]*2;
        		sum-=arrLow[i];
        		arrLow[i]=arrLow[i-1]*2;
        	}
        	else {
        		arrLow[i]+=n-sum;
        		break;
        	}
        }
        { System.out.println("Yes");
        	System.out.println(Arrays.toString(arrLow).replace("[","").replace("]","").replaceAll(",",""));
        }
    }
}