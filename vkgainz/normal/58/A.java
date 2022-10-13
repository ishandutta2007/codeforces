import java.util.*;

public class susbus{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int h = s.indexOf("h");
		int o = s.lastIndexOf("o");
		if (h<0 || o<0 || h>o) {
			System.out.println("NO");
		}
		else {
		String a = s.substring(h,o);
		int e = a.indexOf("e");
		int l1 = a.lastIndexOf("l");
		if (e<0 || l1<0 || e>l1) {
			System.out.println("NO");
		}
		
		
		else {
			String b = a.substring(e,l1);
			int l2 = b.indexOf("l");
			if (l2<0) {
				System.out.println("NO");
			}
			else {
				System.out.println("YES");
			}
		}
		
		}

	}
}