//package yandex;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int[] a = new int[m];
		for(int i = 0;i < m;i++){
			a[i] = ni();
		}
		int[] ar = new int[n];
		Arrays.fill(ar, -1);
		for(int i = n-1;i >= 1;i-=2){
			if(a[0] > 0){
				ar[i] = 0;
				a[0]--;
			}
		}
		
		a[0] = 0;
		int last = 0;
		for(last = 0;ar[last] == -1;last++);
		
		int prev = -1;
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i < last;i++){
			int max = 0;
			int maxj = -1;
			for(int j = 0;j < m;j++){
				if(a[j] > max && j != prev){
					max = a[j];
					maxj = j;
				}
			}
			if(maxj == -1){
				out.println(-1);
				return;
			}
			ar[i] = maxj;
			prev = maxj;
			a[maxj]--;
		}
		outer:
		for(int i = last+1;i < n;i+=2){
			for(int j = 0;j < m;j++){
				if(a[j] > 0){
					ar[i] = j;
					a[j]--;
					continue outer;
				}
			}
			out.println(-1);
			return;
		}
		
		for(int i = 0;i < n;i++){
			out.print((ar[i]+1) + " ");
		}
		out.println();
		
		out.println(sb);
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
		new D2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}