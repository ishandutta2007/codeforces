//package school3;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.List;
import java.util.Scanner;

public class G {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		if(n == 2){
			out.println("1 1");
		}else{
			int m = n*(n+1)/2;
			List<Integer> primes = sieveEratosthenes(m);
			for(int p = 0, q = primes.size() - 1;p <= q;){
				int psum = primes.get(p) + primes.get(q);
				if(psum == m){
					BitSet painted = new BitSet();
					for(int left = primes.get(p), sup = n;left > 0;){
						if(left >= sup){
							left -= sup;
							painted.set(sup);
							sup--;
						}else{
							painted.set(left);
							break;
						}
					}
					for(int i = 1;i <= n;i++){
						if(painted.get(i)){
							out.print("2 ");
						}else{
							out.print("1 ");
						}
					}
					out.println();
					
					return;
				}else if(psum < m){
					p++;
				}else{
					q--;
				}
			}
			
			for(int p = 0, q = primes.size() - 1;p <= q;){
				int psum = primes.get(p) + primes.get(q);
				if(psum == m - 3){
					BitSet painted = new BitSet();
					for(int left = primes.get(p), sup = n;left > 0;){
						if(left >= sup){
							left -= sup;
							painted.set(sup);
							sup--;
						}else{
							painted.set(left);
							break;
						}
					}
					for(int i = 1;i <= n;i++){
						if(i == 3){
							out.print("3 ");
						}else if(painted.get(i)){
							out.print("2 ");
						}else{
							out.print("1 ");
						}
					}
					out.println();
					
					return;
				}else if(psum < m){
					p++;
				}else{
					q--;
				}
			}
			
//			out.println("");
		}
	}
	
	public static List<Integer> sieveEratosthenes(int n)
	{
		List<Integer> ret = new ArrayList<Integer>();
		ret.add(2);
		
		BitSet bs = new BitSet(n/2+1);
		int sup = (n - 3) / 2;
		for(int i = bs.nextClearBit(0);i <= sup; i = bs.nextClearBit(i+1)){
			int p = 2 * i + 3;
			ret.add(p);
			for(int j = i + p;j <= sup;j += p){
				bs.set(j);
			}
		}
		return ret;
	}
	
	void run() throws Exception
	{
//		for(int i = 1;i <= 100;i++){
//			INPUT = Integer.toString(i);
			in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
			out = new PrintWriter(System.out);
//			out.println(i);
	
			solve();
			out.flush();
//		}
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new G().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}