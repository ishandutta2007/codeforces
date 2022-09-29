//package round435;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	int get(int[] a)
	{
		out.print("? ");
		for(int v : a){
			out.print(v);
		}
		out.println();
		out.flush();
		return ni();
	}
	
	void solve()
	{
		int n = ni();
		
		int[] a = new int[n];
		int base = get(a);
		int l = 0, r = n;
		int p0 = -1, p1 = -1;
		while(true){
			if(r-l == 1){
				p1 = l;
				break;
			}
			int h = (l+r)/2;
			for(int i = l;i < h;i++)a[i] = 1;
			int got = get(a);
			for(int i = l;i < h;i++)a[i] = 0;
			if(got == base + (h-l)){
				// all 0
				p0 = l;
				l = h;
			}else if(got == base - (h-l)){
				// all 1
				p1 = l;
				l = h;
				break;
			}else{
				r = h;
			}
		}
		if(p0 == -1){
			while(true){
				int h = (l+r)/2;
				for(int i = l;i < h;i++)a[i] = 1;
				int got = get(a);
				for(int i = l;i < h;i++)a[i] = 0;
				if(got == base + (h-l)){
					// all 0
					p0 = l;
					l = h;
					break;
				}else if(got == base - (h-l)){
					// all 1
					l = h;
				}else{
					r = h;
				}
			}
		}
		out.println("! " + (p0+1) + " " + (p1+1));
		out.flush();
	}
	
	void run() throws Exception
	{
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}