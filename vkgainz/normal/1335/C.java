
import java.io.*; import java.util.*;
import java.util.Map.Entry;

public class twoteamscomposing {
	static HashSet<Integer> set;
	static HashMap<Integer, Integer> freq;
	static int[] vals;
	static int maxFreq;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		StringBuilder sb = new StringBuilder();
		while(t>0) {
			
			int n = sc.nextInt();
			vals = new int[n];
			for(int i=0;i<n;i++) {
				vals[i] = sc.nextInt();
			}
			//binary search on x...
			//use something that preferably has >=x+1
			set = new HashSet<Integer>();
			freq = new HashMap<Integer, Integer>();
			for(int i=0;i<n;i++) {
				freq.put(vals[i],freq.getOrDefault(vals[i],0)+1);
			}
			for(int i=0;i<n;i++) {
				set.add(vals[i]);
			}
			 maxFreq = 0;
			Iterator it = freq.entrySet().iterator();
			while(it.hasNext()) {
				Map.Entry pair = (Map.Entry)it.next();
				maxFreq = Math.max(maxFreq,(int) pair.getValue());
			}
			int max = 0;
			//max = maxFreq, max<maxFreq
			if(set.size()>=(maxFreq+1)) {
				max = maxFreq;
			}
			max = Math.max(max,Math.min(set.size(),maxFreq-1));
			sb.append(max + " ");
//			System.out.println(binarySearch(0,Math.min(maxFreq,n/2)));
			t--;
		}
		System.out.println(sb.toString());
	}
	
}