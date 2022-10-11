import java.util.Scanner;

final public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int w = sc.nextInt();
		int a[] = new int[n];
		int b[] = new int[n];
		int half = 0;
		int sum = 0;
		for(int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
			b[i] = (a[i] + 1) / 2;
			sum += a[i];
			half += (a[i] + 1) / 2;
		}
		if(w < half || w > sum) {
			System.out.println("-1");
		}
		else {
			w -= half;
			while(w > 0) {
				int where = -1;
				int use = 0;
				for(int i = 0; i < n; i++) {
					if(a[i] != b[i] && a[i] > use) {
						use = a[i];
						where = i;
					}
				}
				use = a[where] - b[where];
				if(use > w)
					use = w;
				w -= use;
				b[where] += use;
			}
			
			for(int i = 0; i < n; i++) {
				System.out.print(b[i]);
				if(i + 1 < n)
					System.out.print(" ");
				else
					System.out.println("");
			}
		}
		
	}
}