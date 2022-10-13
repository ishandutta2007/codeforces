import java.util.*;
import java.io.*;
public class EdA {
	static long[] mods = {1000000007, 998244353, 1000000009};
	static long mod = mods[0];
	public static MyScanner sc;
    public static PrintWriter out;
	public static void main(String[] omkar) throws Exception{
		// TODO Auto-generated method stub
 		sc = new MyScanner();
 		out = new PrintWriter(System.out);
 		int t = sc.nextInt();
 		for(int i = 0;i<t;i++){
//	 		String input1 = bf.readLine().trim();
//	 		String input2 = bf.readLine().trim();
//			COMPARING INTEGER OBJECTS U DO DOT EQUALS NOT ==
 			int n = sc.nextInt();
 			Map<Fraction, Integer> mp = new HashMap<Fraction, Integer>();
 			for(int j = 0;j<n;j++){
 				int x1 = sc.nextInt();
 				int y1 = sc.nextInt();
 				int u1 = sc.nextInt();
 				int v1 = sc.nextInt();
 				Fraction f = new Fraction(u1-x1, v1-y1);
 				if (!mp.containsKey(f))
 					mp.put(f, 0);
 				mp.put(f,  mp.get(f)+1);
 			}
 			long sum = 0;
 			for(Fraction j : mp.keySet()){
 				Fraction ts = new Fraction(0-j.a, 0-j.b);
 				if (mp.containsKey(ts))
 					sum+=(long)mp.get(ts)*(long)mp.get(j);
 			}
 			sum/=2L;
 			out.println(sum);
//	 		for(int j = 0;j<array.length;j++){
//	 			out.print(array[j] + " ");
//	 		}
//	 		out.println();
 		}
	 		
 		out.close();	
 	}
	static class Fraction{
        private int a;
        private int b;
        public Fraction(int a, int b){
            int y = gcd(Math.abs(a), Math.abs(b));
            this.a = a/y;
            this.b = b/y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Fraction fraction = (Fraction) o;
            return a == fraction.a &&
                    b == fraction.b;
        }

        @Override
        public int hashCode() {
            return Objects.hash(a, b);
        }
    }
	public static int gcd(int a, int b){ 
	      if (b == 0) 
	        return a; 
	      return gcd(b, a % b);  
	    }
		
	public static void sort(int[] array){
		ArrayList<Integer> copy = new ArrayList<Integer>();
		for (int i : array)
			copy.add(i);
		Collections.sort(copy);
		for(int i = 0;i<array.length;i++)
			array[i] = copy.get(i);
	}
	static String[] readArrayString(int n){
		String[] array = new String[n];
		for(int j =0 ;j<n;j++)
			array[j] = sc.next();
		return array;
	}
	static int[] readArrayInt(int n){
    	int[] array = new int[n];
    	for(int j = 0;j<n;j++)
    		array[j] = sc.nextInt();
    	return array;
    }
	static int[] readArrayInt1(int n){
		int[] array = new int[n+1];
		for(int j = 1;j<=n;j++){
			array[j] = sc.nextInt();
		}
		return array;
	}
	static long[] readArrayLong(int n){
		long[] array = new long[n];
		for(int j =0 ;j<n;j++)
			array[j] = sc.nextLong();
		return array;
	}
	static double[] readArrayDouble(int n){
		double[] array = new double[n];
		for(int j =0 ;j<n;j++)
			array[j] = sc.nextDouble();
		return array;
	}
	static int minIndex(int[] array){
		int minValue = Integer.MAX_VALUE;
		int minIndex = -1;
		for(int j = 0;j<array.length;j++){
			if (array[j] < minValue){
				minValue = array[j];
				minIndex = j;
			}
		}
		return minIndex;
	}
	static int minIndex(long[] array){
		long minValue = Long.MAX_VALUE;
		int minIndex = -1;
		for(int j = 0;j<array.length;j++){
			if (array[j] < minValue){
				minValue = array[j];
				minIndex = j;
			}
		}
		return minIndex;
	}
	static int minIndex(double[] array){
		double minValue = Double.MAX_VALUE;
		int minIndex = -1;
		for(int j = 0;j<array.length;j++){
			if (array[j] < minValue){
				minValue = array[j];
				minIndex = j;
			}
		}
		return minIndex;
	}
	static long power(long x, long y){
		if (y == 0)
			return 1;
		if (y%2 == 1)
			return (x*power(x, y-1))%mod;
		return power((x*x)%mod, y/2)%mod;
	}
	static void verdict(boolean a){
        out.println(a ? "YES" : "NO");
    }
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;
        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } 
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }
        String nextLine() {
            String str = "";
            try{
                str = br.readLine();
            } 
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
        
    }	
}

//StringJoiner sj = new StringJoiner(" "); 
//sj.add(strings)
//sj.toString() gives string of those stuff w spaces or whatever that sequence is