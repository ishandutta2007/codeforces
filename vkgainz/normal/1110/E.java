import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.TreeSet;

public class E {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int c[] = new int[n];
		for(int i=0;i<n;i++) {
			c[i] = sc.nextInt();
		}
		int t[] = new int[n];
		for(int i=0;i<n;i++) {
			t[i] = sc.nextInt();
		}
		HashMap<Integer, Integer> firstFreq = new HashMap<>();
		HashMap<Integer, Integer> secondFreq = new HashMap<>();
		for(int i=0;i<n-1;i++) {
			firstFreq.put((c[i]-c[i+1]),firstFreq.getOrDefault(c[i]-c[i+1],0)+1);
			secondFreq.put((t[i]-t[i+1]),secondFreq.getOrDefault(t[i]-t[i+1],0)+1);
			

		}
		boolean works = true;
		for(int key : firstFreq.keySet()) {
			if(secondFreq.getOrDefault(key,0)!=firstFreq.get(key)) {
				works = false;
			}
		}
		works = works&&(c[0]==t[0])&&(c[n-1]==t[n-1]);
		if(works) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
		
	}
}