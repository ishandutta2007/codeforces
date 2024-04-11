//package round49;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long h = ni();
		long w = ni();
		long max = 0;
		long maxh = 0;
		long maxw = 0;
		for(long hh = Long.highestOneBit(h);hh > 0;hh>>=1){
			if(4 * hh <= 5 * w){
				long ww = Math.min(w, hh * 5 / 4);
				if(hh * ww > max || (hh * ww == max && hh > maxh)){
					max = hh * ww;
					maxh = hh;
					maxw = ww;
				}
			}
		}
		for(long ww = Long.highestOneBit(w);ww > 0;ww>>=1){
			if(4 * ww <= 5 * h){
				long hh = Math.min(h, ww * 5 / 4);
				if(ww * hh > max || (ww * hh == max && hh > maxh)){
					max = hh * ww;
					maxh = hh;
					maxw = ww;
				}
			}
		}
		
		out.println(maxh + " " + maxw);
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
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}