import java.util.Arrays;
import java.util.Scanner;

public class Round535C {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scn = new Scanner(System.in);
		/*Didn't strike j%3 in contest :( */
		int n = scn.nextInt();
		String str = scn.next();
		char[] arr=str.toCharArray();
		int mincost=Integer.MAX_VALUE;
		/*How in my mind I could not think of these 6 patterns*/
		String[] perm= {"RGB","RBG","GRB","GBR","BGR","BRG"};
		char[] newstr=new char[n];
		for(int i=0; i<perm.length; i++)
		{
			char[] temp=str.toCharArray();
			int cost=0;
			for(int j=0; j<n; j++)
			{
				char x=perm[i].charAt(j%3);
				if(arr[j]!=x)
				{
					cost++;
					temp[j]=x;
				}
				
			}
			if(cost<mincost)
			{
				mincost=cost;
				newstr=temp;
			}
		}
		System.out.println(mincost);
		System.out.println(newstr);
		
	}

}