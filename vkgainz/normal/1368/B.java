import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long k = sc.nextLong();
		long prod = 1;
		int freq[] = new int[10];
		for(int i=0;i<10;i++) {
			freq[i] = 1;
		}
		while(prod<k) {
			int min = 10000;
			int minIndex = 0;
			for(int i=0;i<10;i++) {
				if(freq[i]<min) {
					minIndex = i;
					min = freq[i];
				}
			}
			prod/=min;
			prod*=(long) (min+1);
			freq[minIndex]++;
		}
		String ref = "codeforces";
		StringBuilder ret = new StringBuilder();
		for(int i=0;i<10;i++) {
			for(int j=0;j<freq[i];j++) {
				ret.append(ref.charAt(i));
			}
		}
		System.out.println(ret.toString());
	}
}