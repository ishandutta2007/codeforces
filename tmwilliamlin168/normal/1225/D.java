import java.io.*;
import java.util.*;
import java.math.*;
 
public class D {
 
	public class FHM {
 
		//public int[] key;
		public HashMap<Integer, Integer> key;
		public int value;
 
		public FHM(HashMap<Integer, Integer> key) {
			this.key = key;
			this.value = 1;
		}
	}
 
	public class FHM2 {
		//public ArrayList<FHM> fhms;
 
		public HashMap<HashMap<Integer, Integer>, FHM> fhms;
 
		public FHM2() {
			//fhms = new ArrayList<FHM>();
			fhms = new HashMap<HashMap<Integer, Integer>, FHM>();
		}
	
		public void superAdd(HashMap<Integer, Integer> key) {
			/*for(FHM fhm : fhms) {
				if( key.equals(fhm.key) ) {
					fhm.value++;
					return;
				}
			}*/
 
			FHM fhm = fhms.get(key);
 
			if(fhm != null) {
				fhm.value++;
				return;
			}
			fhm = new FHM(key);
			fhms.put(key, fhm);
		}
 
		/*public void add(int[] key) {
			FHM fhm = new FHM(key);
			fhms.add(fhm);
		}*/
 
		public int countContains(HashMap<Integer, Integer> key) {
			/*for(FHM fhm : fhms) {
				if( key.equals(fhm.key) ) {
					return fhm.value;
				}
			}*/
 
			FHM fhm = fhms.get(key);
			if(fhm == null) {
				return 0;
			}
			return fhm.value;
		}
		
	}
		
	public void realMain() throws Exception {
 
		BufferedReader fin = new BufferedReader(new InputStreamReader(System.in), 1000000);
 
		String in = fin.readLine();
 
		String[] ar = in.split(" ");
 
		int n = Integer.parseInt(ar[0]);
		int k = Integer.parseInt(ar[1]);
 
		boolean[] comp = new boolean[100001];
		ArrayList<Integer> primes = new ArrayList<Integer>();
 
		for(int i = 2; i < 100001; i++) {
			if(!comp[i]) {
				primes.add(i);
				for(int j = i * 2; j < 100001; j+=i) {
					comp[j] = true;
				}
			}
		}
 
		//System.out.println(primes.size());
 
		int np = 9592;
		
		int[] a = new int[n];
 
		FHM2 fhm2 = new FHM2();
 
		for(int i = 0; i < n; i++) {
			int ret = 0;
			boolean dig = false;
			for (int ch = 0; (ch = fin.read()) != -1; ) {
        			if (ch >= '0' && ch <= '9') {
            				dig = true;
           				ret = ret * 10 + ch - '0';
        			} else if (dig) break;
    			}
 
			a[i] = ret;
 
			//int[] key = new int[np];
			HashMap<Integer, Integer> key = new HashMap<Integer, Integer>();
			for(int j = 0; j < np && a[i] > 1; j++) {
				while(a[i] % primes.get(j) == 0) {
					Integer numpow = key.get(primes.get(j));
					if(numpow == null) {
						numpow = 0;
					}
					numpow++;
					numpow %= k;
 
					if(numpow == 0) {
						if(key.get(primes.get(j)) != null) {
							key.remove(primes.get(j));
						} else {
						}
					} else {
						key.put(primes.get(j), numpow);
					}
					
 
					a[i] /= primes.get(j);
				}
			}
 
			
 
			fhm2.superAdd(key);
 
			/*if(!fhm2.contains(key)) {
				fhm2.add(key);
			} else {
				fhm2.increment(key)
			*/
 
			/*if(i % 1000 == 0) {
				System.out.println("added " + i);
			}*/
			
		}
 
		//System.out.println(fhm2.fhms);
 
 
		//int[] allzero = new int[np];
 
		//long ret = 0;
 
		//long tmp = fhm2.countContains(allzero);
		//ret += (tmp * (tmp - 1)) / 2;
 
		//System.out.println(ret);
		//System.out.println(fhm2.fhms.size());
 
		long ret2 = 0;
 
		for(FHM fhm : fhm2.fhms.values()) {
			HashMap<Integer, Integer> needed = new HashMap<Integer, Integer>();
			for(Map.Entry<Integer, Integer> pow : fhm.key.entrySet()) {
				needed.put(pow.getKey(), (k - pow.getValue()) % k);
			}
 
			//System.out.println(needed.toString());
 
			if(fhm.key.equals(needed)) {
				ret2 += ((long)fhm.value * (long)(fhm.value - 1));
				//System.out.println("equals " + fhm.value);
			} else {
				ret2 += (long)fhm2.countContains(needed) * (long)fhm.value;
				//System.out.println("ne " + fhm.value + " " + fhm2.countContains(needed));
			}
 
		}
 
		//ret2 -= (tmp * tmp);
 
		ret2 /= 2;
 
		System.out.println(ret2);
 
 
 
 
 
 
 
 
	}
 
 
	public static void main(String[] args) throws Exception {
		D d = new D();
		d.realMain();
	}
}