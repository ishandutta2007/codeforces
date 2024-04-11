import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		int n=sc.nextInt();
		long ans=1,zz=0;
		long [][] arr=new long[2][n];
		for(int i=0;i<n;i++)
		{
			long a=sc.nextLong();
			long b=sc.nextLong();
			arr[0][i]=a;
			arr[1][i]=b;
			
			if(i==0)
			{
				ans+=Math.min(arr[0][i], arr[1][i]);
			}
			else if(arr[0][i]>=zz && arr[1][i]>=zz)
			{
				ans+=Math.min(arr[0][i], arr[1][i])-zz+1;
				if(arr[0][i-1]==arr[1][i-1])
				{
					ans--;
				}
			}
			zz=Math.max(arr[0][i], arr[1][i]);
		}
		System.out.println(ans);
	}

}