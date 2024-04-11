
 import java.util.Scanner;

public class r537a {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int x = 0, y = 0;
		String a = scan.nextLine(), b = scan.nextLine();
		if(a.length() != b.length()) {
			System.out.println("no");
			return;
		}
		
		for(int i = 0 ; i < a.length(); i++) {
			if(isVowel(a.charAt(i)) && !isVowel(b.charAt(i)) || !isVowel(a.charAt(i)) && isVowel(b.charAt(i))) {
				System.out.println("no");
				return;
			}
		}
		System.out.println("yes");

	}
	
	static boolean isVowel(char x) {
		return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
	}
}