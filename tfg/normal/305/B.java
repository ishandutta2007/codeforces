import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	static private class Fraction {
		public BigInteger p, q;
		
		Fraction(BigInteger p, BigInteger q) {
			this.p = p;
			this.q = q;
		}
		
		public void invert() {
			BigInteger temp = p;
			p = q;
			q = temp;
		}
		
		public void add(BigInteger o) {
			p = p.add(q.multiply(o));
		}
		
		public void simplify() {
			BigInteger g = p.gcd(q);
			p = p.divide(g);
			q = q.divide(g);
		}
	}
	static public void main(String[] args) {
		Scanner in = new Scanner(System.in);
		Fraction target = new Fraction(new BigInteger(in.next()), new BigInteger(in.next()));
		int n = in.nextInt();
		String[] a = new String[n];
		for(int i = 0; i < n; i++) {
			a[i] = in.next();
		}
		Fraction cur = new Fraction(new BigInteger("0"), new BigInteger("1"));
		for(int i = n - 1; i >= 0; i--) {
			cur.add(new BigInteger(a[i]));
			cur.invert();
		}
		cur.invert();
		cur.simplify();
		target.simplify();
		if(target.p.equals(cur.p) && target.q.equals(cur.q)) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}
}