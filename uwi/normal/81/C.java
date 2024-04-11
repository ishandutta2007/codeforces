//package yandex;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	// \sum t_a/a+\sum t_b/b
	void solve()
	{
		int n = ni();
		int a = ni();
		int b = ni();
		Datum[] d = new Datum[n];
		for(int i = 0;i < n;i++){
			d[i] = new Datum(ni(), i);
		}
		int[] ar = new int[n];
		if(a == b){
			for(int i = 0;i < n;i++){
				ar[i] = i < a ? 1 : 2;
			}
		}else if(a < b){
			Arrays.sort(d, new Comparator<Datum>(){
				public int compare(Datum x, Datum y){
					if(x.mark - y.mark != 0)return -(x.mark - y.mark);
					return x.ind - y.ind;
				}
			});
			Arrays.fill(ar, 2);
			for(int i = 0;i < a;i++){
				ar[d[i].ind] = 1;
			}
		}else{
			Arrays.sort(d, new Comparator<Datum>(){
				public int compare(Datum x, Datum y){
					if(x.mark - y.mark != 0)return -(x.mark - y.mark);
					return -(x.ind - y.ind);
				}
			});
			Arrays.fill(ar, 1);
			for(int i = 0;i < b;i++){
				ar[d[i].ind] = 2;
			}
		}
		for(int i = 0;i < n;i++){
			out.print(ar[i] + " ");
		}
		out.println();
		
	}
	
	static class Datum {
		public int mark;
		public int ind;

		public Datum(int a, int b) {
			this.mark = a;
			this.ind = b;
		}

		public String toString() {
			return "(" + mark + "," + ind + ")";
		}
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}