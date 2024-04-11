import java.util.*;

public class susbus{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String stuff = sc.next();;
		int count=0;
		for (int i=0;i<stuff.length();i++) {
			if (stuff.charAt(i) == '4' || stuff.charAt(i) == '7') {
				count++;
			}
		}
		if (count > 0 && (count == 4 || count == 7 || count == 44 || count == 47 || count == 74 || count == 77 || count == 444 || count == 447 || count == 474 || count == 477 || count == 744 || count == 747 || count == 774 || count == 777)) {
			System.out.println("YES");
		}
		else {
			System.out.println("NO");
		}
	}
}