import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			String s = sc.next();
			int [] pOne = new int[s.length()+1];
			for(int i=0;i<s.length();i++) {
				pOne[i+1] = pOne[i];
				if(s.charAt(i)=='1') {
					pOne[i+1]++;
				}
			}
			int min = 1000;
			for(int i=0;i<=s.length();i++) {
				//first i (1-indexed) =0
				
				int numZero = i-pOne[i];
				int numOne = pOne[s.length()]-pOne[i];
				int numChange = i-numZero+(s.length()-i)-numOne;
				min = Math.min(min,numChange);
			}
			for(int i=0;i<=s.length();i++) {
				int numOne = pOne[i];
				int numZero = s.length()-i-(pOne[s.length()]-pOne[i]);
				int numChange = i-numOne+(s.length()-i)-numZero;
				min = Math.min(min,numChange);
			}
			System.out.println(min);
		}
	}
}