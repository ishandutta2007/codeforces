import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner sc=  new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0) {
			t--;
			int n = sc.nextInt();
			int a[] = new int[2*n];
			Queue<Integer> odd = new LinkedList<>();
			Queue<Integer> even = new LinkedList<>();
			for(int i=0;i<2*n;i++) {
				a[i] = sc.nextInt();
				if(a[i]%2==0) {
					even.add(i);
				}
				else {
					odd.add(i);
				}
			}
			for(int i=0;i<n-1;i++) {
				
				 if(odd.size()>1) {
					System.out.println((odd.poll()+1) + " "+ (odd.poll()+1));
				}
				else if(even.size()>1){
					System.out.println((even.poll()+1) + " " + (even.poll()+1));
				}
			}
		}
		
	}
}