import java.util.Scanner;

public class E {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		StringBuilder retFirst = new StringBuilder();
		StringBuilder retSecond = new StringBuilder();
		String ref = "abc";
		for(int i=0;i<(s.length()-2)/2;i+=2) {
			String temp = s.substring(i,i+2)+s.substring(s.length()-i-2,s.length()-i);
			int [] freq = new int[3];
			for(int j=0;j<4;j++) {
				freq[temp.charAt(j)-97]++;
			}
			for(int j=0;j<3;j++) {
				if(freq[j]>=2) {
					retFirst.append(ref.charAt(j));
					retSecond.append(ref.charAt(j));
					break;
				}
			}
			
		}
		if(s.length()%4==2 || s.length()%4==3) {
			retFirst.append(s.charAt(s.length()/2));
		}
		StringBuilder reverse = retSecond.reverse();
		retFirst.append(reverse);
		System.out.println(retFirst.toString());
	}
}