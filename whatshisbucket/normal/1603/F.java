import java.util.*;
import java.io.*;
 
public class cf {
	
	static long modulo(long a, long b, long c) {
	    long x=1;
	    long y=a;
	    while(b > 0){
	        if(b%2 == 1){
	            x=(x*y)%c;
	        }
	        y = (y*y)%c; // squaring the base
	        b /= 2;
	    }
	    return x%c;
	}
 
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		long m = 998244353;
		while (t-- > 0) {
			String[] ss = br.readLine().split(" ");
            long n = Long.parseLong(ss[0]), k = Long.parseLong(ss[1]), x = Long.parseLong(ss[2]);
            if (x == 0) {
            	if (n > k) {
            		System.out.println(0);
            	} else {
            		long power = modulo(2, k, m);
            		long prod = 1;
            		long exp = 1;
            		for (int i = 0; i < n; i++) {
            			prod = prod * (power - exp) % m;
            			exp = 2 * exp % m;
            		}
            		if (prod < 0) {
            			prod += m;
            		}
            		System.out.println(prod);
            	}
            } else {
            	long coeff = 1;
            	long sum = 0;
            	long term = modulo(2, (k - 1) * (n + 1), m);
            	long pow = modulo(2, k - 1, m);
            	long inv = modulo(499122177, n + 1, m);
            	for (int i = 0; i < k; i++) {
            		sum = (sum + term * coeff) % m;
            		term = term * inv % m;
            		coeff = coeff * (1 - pow) % m;
            		pow = pow * 499122177 % m;
            	}
            	if (sum < 0) {
            		sum += m;
            	}
            	System.out.println(sum);
            }
		}
	}
}