import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class AMain {
	static Set<String> seen;
	public static void main(String[] args) throws IOException {
		seen = new HashSet<String>();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		PermutationGenerator p = new PermutationGenerator(6);
		int ret = 0;
		outer: while(p.hasMore())	{
			String curr = "";
			int[] index = p.getNext();
			for(int out: index)
				curr += s.charAt(out);
			LinkedList<State> q = new LinkedList<State>();
			q.add(new State(curr.charAt(0), curr.charAt(1), curr.charAt(2), curr.charAt(3), curr.charAt(4), curr.charAt(5)));
			Set<String> over = new HashSet<String>();
			for(int i = 0; i < 1000 && !q.isEmpty(); i++)	{
				State now = q.removeFirst();
				String give = now.toString();
				over.add(give);
				q.addLast(now.spin1());
				q.addLast(now.spin2());
				q.addLast(now.spin3());
			}
			boolean fail = false;
			for(String ss: over)	{
				if(seen.contains(ss))	{
					fail = true;
				}
				seen.add(ss);
			}
			if(!fail)
				ret++;
		}
		System.out.println(ret);
	}
	static class State	{
		public char f,b,u,d,l,r;
		public State(char a1, char a2, char a3, char a4, char a5, char a6)	{
			f = a1;
			b = a2;
			u = a3;
			d = a4;
			l = a5;
			r = a6;
		}
		// ubdf
		public State spin1()	{
			//               f b u d l r
			return new State(u,d,b,f,l,r);
		}
		// frbl
		public State spin2()	{
			//               f b u d l r
			return new State(r,l,u,d,f,b);
		}
		// uldr
		public State spin3()	{
			//               f b u d l r
			return new State(f,b,l,r,d,u);
		}
		public String toString()		{
			StringBuilder sb = new StringBuilder();
			sb.append(f);
			sb.append(b);
			sb.append(l);
			sb.append(u);
			sb.append(r);
			sb.append(d);
			return sb.toString();
		}
	}
	static class PermutationGenerator {
		private int[] a;
		private BigInteger numLeft;
		private BigInteger total;
		public PermutationGenerator (int n) {
			if (n < 1) {
				throw new IllegalArgumentException ("Min 1");
			}
			a = new int[n];
			total = getFactorial (n);
			reset ();
		}
		public void reset () {
			for (int i = 0; i < a.length; i++) {
				a[i] = i;
			}
			numLeft = new BigInteger (total.toString ());
		}
		public BigInteger getNumLeft () {
			return numLeft;
		}
		public BigInteger getTotal () {
			return total;
		}
		public boolean hasMore () {
			return numLeft.compareTo (BigInteger.ZERO) == 1;
		}
		private static BigInteger getFactorial (int n) {
			BigInteger fact = BigInteger.ONE;
			for (int i = n; i > 1; i--) {
				fact = fact.multiply (new BigInteger (Integer.toString (i)));
			}
			return fact;
		}
		public int[] getNext () {
			if (numLeft.equals (total)) {
				numLeft = numLeft.subtract (BigInteger.ONE);
				return a;
			}
			int temp;
			int j = a.length - 2;
			while (a[j] > a[j+1]) {
				j--;
			}
			int k = a.length - 1;
			while (a[j] > a[k]) 
				k--;
			temp = a[k];
			a[k] = a[j];
			a[j] = temp;
			int r = a.length - 1;
			int s = j + 1;
			while (r > s) {
				temp = a[s];
				a[s] = a[r];
				a[r] = temp;
				r--;
				s++;
			}
			numLeft = numLeft.subtract (BigInteger.ONE);
			return a;
		}
	}

}