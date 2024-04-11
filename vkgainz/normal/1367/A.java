import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		StringBuilder sb= new StringBuilder();
		int t = sc.nextInt();
		while(t>0) {
			t--;
			String b = sc.next();
			for(int i=0;i<b.length();i+=2) {
				sb.append(b.charAt(i));
			}
			sb.append(b.charAt(b.length()-1));
			sb.append("\n");
		}
		System.out.println(sb.toString());
	}
}