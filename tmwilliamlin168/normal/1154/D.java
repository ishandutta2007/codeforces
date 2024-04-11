import java.util.Scanner;
public class Main {
	static int b,a,n,s[];
	static {
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		b = scan.nextInt();
		a = scan.nextInt();
		s = new int[n];
		for(int i = 0 ; i < n ; i++)
			s[i] = scan.nextInt();		
	}
	public static void main(String[] args) {
		System.out.println(recFun(0,b,a,0));
	}
	public static int recFun(int i , int b1 , int a1 , int count) {
		if((b1 <= 0 && a1 <= 0) || i == n || count == n)	return count;
		else if(s[i] == 0) {
			if(a1>0)	return(recFun(i+1,b1,a1-1,count+1));
			return(recFun(i+1,b1-1,0,count+1));
		}
		else {
			if(b1>0 && a1 < a)		return recFun(i+1,b1-1,a1+1,count+1);
			return(recFun(i+1,b1,a1-1,count+1));
		}
	}
}