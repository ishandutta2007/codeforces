import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class C {
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int n = sc.nextInt();
		int a[] = new int[n];
		Set<Integer> covered = new HashSet<Integer>();
		for(int i=0;i<n;i++) {
			a[i] = sc.nextInt();
			covered.add(a[i]);
			
		}
		
		TreeSet<Integer> notCovered = new TreeSet<Integer>();
		for(int i=0;i<=n;i++) {
			if(!covered.contains(i)) {
				notCovered.add(i);
			}
		}
		for(int i=n+1;i<=2*n;i++) {
			notCovered.add(i); //do i need this
		}
		int [] lastIndex = new int[n+1];
		Arrays.fill(lastIndex,-1);
		for(int i=0;i<n;i++) {
			lastIndex[a[i]] = Math.max(lastIndex[a[i]],i);
		}
		int b[] = new int[n];
		for(int i=0;i<n;i++) {
			
			b[i] = notCovered.first();
			
			notCovered.remove(notCovered.first());
			if(lastIndex[a[i]]==i) {
				notCovered.add(a[i]);
			}
		}
		StringBuilder sb= new StringBuilder();
		boolean works = true;
		TreeSet<Integer> work = new TreeSet<Integer>();
		for(int i=0;i<=n;i++) {
			work.add(i);
		}
		for(int i=0;i<n;i++) {
			
			if(b[i]<=n) {
				if(work.contains(b[i]))
				work.remove(b[i]);
			}
			if(work.first()!=a[i]) {
				works = false;
				break;
			}
		}
		if(!works) {
			System.out.println(-1);
			return;
		}
		for(int i=0;i<n;i++) {
			sb.append(b[i] + " ");
		}
		System.out.println(sb.toString());
		
	}
}