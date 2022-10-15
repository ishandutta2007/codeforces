import java.util.*;

public class Main{
	public static void main(String args[] ){
		Scanner ak=new Scanner(System.in);
		int t=ak.nextInt();
		long n,k,ans;
		for(;t>0;t--){
			n=ak.nextLong();
			k=ak.nextLong();
			ans=0;
			for(;n>0;){
				if(n<k){
					ans+=n;
					System.out.println(ans);
					break;
				}
				else if(n%k==0){
					ans+=1;
					n/=k;
				}
				else{
					ans+=n%k;
					n=n-n%k;
				}
			}
		}		
	}
 }