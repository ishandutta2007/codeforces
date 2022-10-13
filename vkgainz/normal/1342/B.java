import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			String s = sc.next();
			int numZero = 0;
			for(int i=0;i<s.length();i++) {
				if(s.charAt(i)=='0') {
					numZero++;
				}
			}
			if(numZero==0 || numZero==s.length()) {
				System.out.println(s);
				continue;
			}
			String ret = "";
			for(int i=0;i<s.length();i++) {
				ret+="10";
			}
			System.out.println(ret);
		}
	}
}