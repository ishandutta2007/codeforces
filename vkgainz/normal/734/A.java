import java.util.*;

public class susbus{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String s= sc.next();
		
		int count=0;
		for (int i=0;i<n;i++) {
			if (s.charAt(i) == 'D') {
				count++;
			}
		}
		if (n%2==1){
			if (count > n/2)
			System.out.println("Danik");
			else
				System.out.println("Anton");
		}
		else {
			if (count >n/2) {
				System.out.println("Danik");
			}
			else if (count == n/2) {
				System.out.println("Friendship");
			}
			else {
				System.out.println("Anton");
			}
		}

	}
}