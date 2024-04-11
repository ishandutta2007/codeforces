//package round3;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	static class Datum implements Comparable<Datum>
		{
			public int a;
			public int b;
			
			public Datum(int a, int b) {
				this.a = a;
				this.b = b;
			}
			public int compareTo(Datum o) {
				return -(b - o.b);
			}
			public String toString() {
				return "(" + a + "," + b + ")";
			}
		}
	
	void solve()
	{
		int n = ni();
		int v = ni();
		
		List<Datum> one = new ArrayList<Datum>();
		List<Datum> two = new ArrayList<Datum>();
		for(int i = 0;i < n;i++) {
			int k = ni();
			if(k == 1) {
				one.add(new Datum(i, ni()));
			}else {
				two.add(new Datum(i, ni()));
			}
		}
		Collections.sort(one);
		Collections.sort(two);
		
		int o = 0, t = 0;
		long sum = 0;
		BitSet opt = new BitSet();
		if(v % 2 == 1) {
			if(o < one.size()) {
				sum += one.get(o).b;
				opt.set(one.get(o).a);
				o++;
				v--;
			}
		}
		while(v >= 2 && (o < one.size() || t < two.size())){
			if(o == one.size()) {
				sum += two.get(t).b;
				opt.set(two.get(t).a);
				t++; v-=2;
			}else if(t == two.size()) {
				sum += one.get(o).b;
				opt.set(one.get(o).a);
				o++; v--;
				if(o < one.size()) {
					sum += one.get(o).b;
					opt.set(one.get(o).a);
					o++; v--;
				}
			}else {
				int os = one.get(o).b + (o+1 < one.size() ? one.get(o+1).b : 0);
				int ts = two.get(t).b;
				if(os < ts) {
					sum += two.get(t).b;
					opt.set(two.get(t).a);
					t++; v-=2;
				}else {
					sum += one.get(o).b;
					opt.set(one.get(o).a);
					o++; v--;
					if(o < one.size()) {
						sum += one.get(o).b;
						opt.set(one.get(o).a);
						o++; v--;
					}
				}
			}
		}
		out.println(sum);
		for(int i = opt.nextSetBit(0);i != -1;i = opt.nextSetBit(i+1)){
			out.printf((i+1) + " ");
		}
		out.println();
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}