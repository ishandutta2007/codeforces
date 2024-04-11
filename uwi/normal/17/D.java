//package round17;


import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.Scanner;

public class D3 {
	private Scanner in;
	private PrintWriter out;
	
	public void solve()
	{
		char[] b = in.next().toCharArray();
		char[] n = in.next().toCharArray();
		int c = ni();
		
		long bc = 0; // b % c
		for(int i = 0;i < b.length;i++){
			bc = (bc * 10 + (long)(b[i] - '0')) % c;
		}
		
		if(bc == 0L){
			if(n.length == 1 && n[0] == '1'){
				out.println(c - 1);
			}else{
				out.println(c);
			}
			return;
		}
		
		// bc^n % c
		long ret = 1L;
		long mul = bc;
		for(int i = n.length - 1;i >= 0;i--){
			ret = (ret * mulmod(mul, (long)(n[i] - '0'), c)) % c;
			mul = mulmod(mul, 10, c);
		}
		
		// -1
		for(int i = n.length - 1;i >= 0;i--){
			if(n[i] > '0'){
				n[i]--;
				break;
			}else{
				n[i] = '9';
			}
		}
		
		long ret2 = 1L;
		long mul2 = bc;
		for(int i = n.length - 1;i >= 0;i--){
			ret2 = (ret2 * mulmod(mul2, (long)(n[i] - '0'), c)) % c;
			mul2 = mulmod(mul2, 10, c);
		}
//		tr(Arrays.toString(n));
//		tr(ret, ret2);
		
		long r = (ret - ret2 + c) % c;
		if(r == 0)r = c;
		out.println(r);
	}
	
	public long mulmod(long a, long e, long n)
	{
		long ret = 1;
		long mul = a;
		for(;e > 0;e >>= 1){
			if((e & 1) == 1){
				ret = (ret * mul) % n;
			}
			mul = (mul * mul) % n;
		}
		
		return ret;
	}
	
	public int totient(int n)
	{
		int t = 1;
		for(int p = 2;p * p <= n;p++){
			if(n % p == 0){
				int e = 0;
				while(n % p == 0){
					n /= p;
					e++;
				}
				t *= p - 1;
				for(int i = 0;i < e - 1;i++){
					t *= p;
				}
			}
		}
		if(n > 1)t *= n - 1;
		return t;
	}
	
	public void run() throws Exception
	{
//		in = new Scanner(new StringReader("10000000000 100000000000000000000000000000000000000000000000000 55555555"));
//		in = new Scanner(new StringReader("10 9 3"));
//		in = new Scanner(new StringReader("123456789 987654321 999999999"));
//		in = new Scanner(new StringReader("999900 9009999 1000000000"));
//		in = new Scanner(new StringReader("2 3 3"));
//		in = new Scanner(new StringReader("20 777777 96"));
//		in = new Scanner(new StringReader(U.add("9", 999999) + " " + U.add("9", 999999) + " 999999997"));
//		in = new Scanner(new StringReader("1" + U.add("0", 999999) + " 1" + U.add("0", 999999) + " 999999999"));
//		in = new Scanner(new StringReader(U.add("9", 9999) + " " + U.add("9", 9999) + " 2010000"));
		in = new Scanner(System.in);
//		System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
		out = new PrintWriter(System.out);
		
//		int n = in.nextInt();
		int n = 1;
		for(int i = 1;i <= n;i++){
			long t = System.currentTimeMillis();
			solve();
			out.flush();
//			System.err.printf("%04d/%04d %7d%n", i, n, System.currentTimeMillis() - t);
		}
	}
	
	public void run(int b, int n, int c) throws Exception
	{
		in = new Scanner(new StringReader("" + b + " " + n + " " + c));
		out = new PrintWriter(System.out);
		
//		int n = in.nextInt();
		int nm = 1;
		for(int i = 1;i <= nm;i++){
			long t = System.currentTimeMillis();
			solve();
			out.flush();
//			System.err.printf("%04d/%04d %7d%n", i, n, System.currentTimeMillis() - t);
		}
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new D3().run();
//		D3 d = new D3();
//		for(int b = 2;b <= 100;b++){
//			for(int n = 1;n <= 100;n++){
//				for(int c = 1;c <= 100;c++){
//					d.run(b,n,c);
//				}
//			}
//		}
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
	private void tra(int[] a) {System.out.println(Arrays.toString(a));}
	private void tra(int[][] a)
	{
		for(int[] e : a){
			System.out.println(Arrays.toString(e));
		}
	}
	
}