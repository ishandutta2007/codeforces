import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class C {
	static int tab[] = {1,2,3,1,3,2,1};
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();int b = sc.nextInt();
		int c = sc.nextInt();
		ArrayList<Integer> A= new ArrayList<Integer>();
		for(int i=0;i<7;i++) {
			A.add(f(i,a,b,c));
		}
		System.out.println(Collections.max(A));
	}
	public static int f(int day, int a,int b,int c) {
		int sum = 0;
		ArrayList<Integer> A = new ArrayList<Integer>();
		int k1= 0,k2=0,k3=0;
		if(a>3) k1 = a/3;
		if(b>2) k2 = b/2;
		if(c>2) k3 = c/2;
		A.add(k1);A.add(k2);A.add(k3);
		int k = Collections.min(A);
		a -= k*3;
		b -= k*2;
		c -= k*2;
		sum+=k*7;
		while(a!=-1 && b!=-1 && c!=-1) {
			if(tab[day]==1) a--;
			if(tab[day]==2) b--;
			if(tab[day]==3) c--;
			day++;
			if(day == 7) day = 0;
			sum++;
		}
		return sum-1;
	}

}