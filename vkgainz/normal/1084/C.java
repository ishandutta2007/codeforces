import java.util.ArrayList;
import java.util.Scanner;

public class FairNut {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		ArrayList<Integer> counts = new ArrayList<Integer>();
		int count=0;
		for(int i=0;i<s.length();i++) {
			if(s.charAt(i)=='a') {
				count++;
			}
			if(s.charAt(i)=='b') {
				counts.add(count);
				count=0;
			}
		}
		counts.add(count);
//		for(int i=0;i<counts.size();i++) {
//			System.out.println(counts.get(i));
//		}
		long ans = 1;
		for(int i=0;i<counts.size();i++) {
			ans*=(1+counts.get(i));
			ans = (long) (ans % (Math.pow(10, 9)+7));
			
		}
		ans--;
		System.out.println(ans);
	}
}