//package round69;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	String[] H = {
			"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"
	};
	
	void solve()
	{
		Map<String, Integer> map = new HashMap<String, Integer>();
		for(int i = 0;i < 7;i++){
			map.put(H[i], i);
		}
		
		int n = ni();
		int[][] li = new int[7][7];
		for(int i = 0;i < n;i++){
			int p = map.get(in.next());
			in.next();
			int q = map.get(in.next());
			li[p][q] = 1;
		}
		int[] hp = new int[3];
		for(int i = 0;i < 3;i++)hp[i] = ni();
		
		int[] k = new int[7];
		int min = Integer.MAX_VALUE;
		int optlp = 0;
		for(k[0] = 0;k[0] <= 2;k[0]++){
			for(k[1] = 0;k[1] <= 2;k[1]++){
				for(k[2] = 0;k[2] <= 2;k[2]++){
					for(k[3] = 0;k[3] <= 2;k[3]++){
						for(k[4] = 0;k[4] <= 2;k[4]++){
							for(k[5] = 0;k[5] <= 2;k[5]++){
								outer:
								for(k[6] = 0;k[6] <= 2;k[6]++){
									int[] ct = new int[3];
									int lp = 0;
									for(int i = 0;i < 7;i++){
										ct[k[i]]++;
										for(int j = 0;j < 7;j++){
											if(j != i && k[i] == k[j]){
												lp += li[i][j];
											}
										}
									}
									int lmax = 0;
									int lmin = Integer.MAX_VALUE;
									for(int i = 0;i < 3;i++){
										if(ct[i] == 0)continue outer;
										int f = hp[i] / ct[i];
										lmax = Math.max(lmax, f);
										lmin = Math.min(lmin, f);
									}
									int sub = lmax - lmin;
									if(sub < min || sub == min && lp > optlp){
										min = sub;
										optlp = lp;
									}
								}
							}
						}
					}
				}
			}
		}
		out.println(min + " " + optlp);
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	public static class Fraction implements Comparable<Fraction> {
		public long num, den;
		
		public Fraction(long num)
		{
			this.num = num;
			this.den = 1;
		}
		
		public Fraction(long num, long den)
		{
			this.num = num;
			this.den = den;
			reduce();
		}
		
		public void reduce()
		{
			if(den == 0) {
			}else if(num == 0) {
				den = 1;
			}else {
				if(den < 0) {
					num = -num;
					den = -den;
				}
				long g = gcd(Math.abs(num), den);
				num /= g;
				den /= g;
			}
		}
		
		public static Fraction add(Fraction a, Fraction b){	return new Fraction(a.num*b.den+a.den*b.num, a.den*b.den); }
		public static Fraction sub(Fraction a, Fraction b){	return new Fraction(a.num*b.den-a.den*b.num, a.den*b.den); }
		public static Fraction mul(Fraction a, Fraction b){	return new Fraction(a.num*b.num, a.den*b.den); }
		public static Fraction div(Fraction a, Fraction b){	return new Fraction(a.num*b.den, a.den*b.num); }
		
		protected static long gcd(long a, long b) {
			while (b > 0) {
				long c = a;
				a = b;
				b = c % b;
			}
			return a;
		}
		
		public int compareTo(Fraction f)
		{
			return Long.signum(num * f.den - f.num * den);
		}
	}
	
	public static void main(String[] args) throws Exception
	{
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}