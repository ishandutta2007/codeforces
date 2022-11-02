import java.util.*;
import java.math.*;
import java.io.*;

public class Main{
	static class InputReader{
		public BufferedReader r;
		public StringTokenizer t;
		public InputReader(InputStream tmp){
			r = new BufferedReader(new InputStreamReader(tmp), 32768);
			t = null;
		}
		public String nextString() throws IOException {
			while(t == null || !t.hasMoreTokens()){
				t = new StringTokenizer(r.readLine());
			}
			return t.nextToken();
		}
		public int nextInt() throws IOException {
			return Integer.parseInt(nextString());
		}
	}
	static BigInteger sum(long l, long r, long cnt){
		if(cnt == 0){return BigInteger.valueOf(0);}
		return BigInteger.valueOf((l + r)).multiply(BigInteger.valueOf(cnt)).divide(BigInteger.valueOf(2));
	}
	static boolean can(long id, long n){
		BigInteger s = BigInteger.valueOf(1).add(sum(6, 6 * id, id));
		return s.compareTo(BigInteger.valueOf(n)) >= 0;
	}
	static long  find(long n){
		long l = 0, r = 10000000000000000L;
		while(r - l > 1){
			long m = (l + r) / 2;
			if(can(m, n)){
				r = m;
			}
			else{
				l = m + 1;
			}
		}
		if(can(l, n)){return l;}
		return r;
	}
	public static void main(String args[]) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		long n = Long.parseLong(in.readLine());
		n++;
		if(n == 1){out.println(0 + " " + 0); out.flush(); return;}
		long id = find(n);
		//if(1 + sum(6, 6 * id, id) > n){id--;}
		n -= 2 + sum(6, 6 * (id - 1), id - 1).longValue();
		//out.println(n);
		//long m = n - id;
		//if(m < 0){m = m + 6 * (id - 1);}
		long m = n + 1;
		if(m == 6 * id){m = 0;}
		//out.println(m);
		long part = m / (long)id;
		long prx = 0;
		long pry = 0;
		long d = m % (long)id;
		if(part == 1){
			prx = id;
			pry = 2 * id;
			prx -= 2 * (m % (long)id);
		}
		if(part == 2){
			prx = -id;
			pry = 2 * id;
			prx -= (m % (long)id);
			pry -= 2 * (m % (long)id);
		}
		if(part == 3){
			prx = -2 * id;
			pry = 0;
			prx += (m % (long)id);
			pry -= 2 * d;
		}
		if(part == 4){
			prx = -id;
			pry = -2 * id;
			prx += 2 * d;
		}
		if(part == 5){
			prx = id;
			pry = -2 * id;
			prx += d;
			pry += 2 * d;
		}
		if(part == 0){
			prx = 2 * id;
			pry = 0;
			prx -= (m % (long)id);
			pry += 2 * (m % (long)id);
		}
		out.println(prx + " " + pry);
		out.flush();
	}
}