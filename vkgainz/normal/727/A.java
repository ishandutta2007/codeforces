import java.util.*;
public class susbus{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b =sc.nextInt();
		if(search(a,b) <= 0) {
			System.out.println("NO");
			return;
		}
		System.out.println("YES");
		System.out.println(search(a,b));
		print(a,b);
	}
	public static int search(int a,int b) {
		if(b==a) return 1;
		else if(b<a) return -12346;
		else {
		if(b%10==1) return search(a,(b-1)/10)+1;
		if(b%2==0) return search(a,b/2)+1;
		else return -12346;
		}
		
	}
	public static void print(int a,int b) {
		if(b==a) {
			System.out.println(a);
			return;
		}
		if(b%10==1) {
			print(a,(b-1)/10);
			System.out.println(b);
			
		}
		if(b%2==0) {
			print(a,b/2);
			System.out.println(b);
			
		}
	}
}