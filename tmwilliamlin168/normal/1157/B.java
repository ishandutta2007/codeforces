import java.util.Scanner;

public class LongNumber {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		sc.nextInt();
		char []a = sc.next().toCharArray();
		int []s = new int[9];
		for(int i=0;i<9;i++)
			s[i] =sc.nextInt();
		int started = 0;
		for(int i=0;i<a.length;i++) {
			int aInt = Integer.parseInt(a[i]+"");
			if(aInt < s[aInt-1] && (started==0 || started==1)) {
				System.out.print(s[aInt-1]);
				started = 1;
			}
			else {
				System.out.print(aInt);
				if(started==1 && aInt > s[aInt-1])
					started=2;
			}
		}
		sc.close();
	}
}