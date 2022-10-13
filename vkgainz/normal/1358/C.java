import java.util.Scanner;

public class C {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		StringBuilder sb = new StringBuilder();
		while(t>0) {
			t--;
			long x1 = sc.nextLong();
			long y1= sc.nextLong();
			long x2 = sc.nextLong();
			long y2 = sc.nextLong();
			long a = x2-x1;
			long b = y2-y1;
			long bot = Math.min(a,b);
			long occ = a+b+1-2*(bot+1);
//			System.out.println(bot + " " + occ);
			long x = bot*occ;
			long y = bot*(bot+1);
			sb.append(x+y+1);
			sb.append("\n");
		}
		System.out.println(sb.toString());
	}
}