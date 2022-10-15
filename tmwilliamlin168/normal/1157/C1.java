import java.util.Scanner;

public class incseq_easy {

	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		int n=input.nextInt();
		int[] a=new int[n];
		
		for(int i=0;i<n;i++) {
			a[i]=input.nextInt();
		}
		
		StringBuilder str=new StringBuilder("");
		int i=0,j=n-1;
		
		int prev=-1;
		int ct=0;
		while(i<=j) {
			if(a[i]<prev&&a[j]<prev) break;
			if(a[i]>prev&&(a[i]<=a[j]||a[j]<prev)) {
				ct++;
				prev=a[i];
				i++;
				str.append("L");
				//System.out.println("L");
			}
			else if(a[j]>prev&&(a[j]<a[i]||a[i]<prev)) {
				ct++;
				prev=a[j];
				j--;
				str.append("R");
				//System.out.println("R");
			}
			//System.out.println("Hello");
		}
		
		System.out.println(ct);
		System.out.println(String.valueOf(str));
	}

}