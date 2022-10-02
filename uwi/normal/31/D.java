//package round31;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class D {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "2 2 2 0 1 1 1 1 0 1 2";
//	private String INPUT = "2 2 3 1 0 1 2 0 1 1 1 1 1 2 1";
//	private String INPUT = "2 4 2 0 1 2 1 0 3 2 3";
	private String INPUT = "";
	
	public void solve()
	{
		int w = ni();
		int h = ni();
		int n = ni();
		Part[] ps = new Part[n+1];
		ps[0] = new Part(0, 0, w, h);
		int[] ax = new int[n];
		int[] ay = new int[n];
		int[] bx = new int[n];
		int[] by = new int[n];
		for(int i = 0;i < n;i++){
			ax[i] = ni();
			ay[i] = ni();
			bx[i] = ni();
			by[i] = ni();
		}
		
		BitSet nused = new BitSet();
		nused.set(0, n);
		int p = 1;
		while(p < n + 1){
			for(int i = nused.nextSetBit(0);i != -1;i = nused.nextSetBit(i+1)){
				for(int j = 0;j < p;j++){
					Part nw = ps[j].split(ax[i], ay[i], bx[i], by[i]);
					if(nw != null){
						ps[p] = nw;
						p++;
						nused.clear(i);
					}
				}
			}
		}
		
		long[] area = new long[n+1];
		for(int i = 0;i < n+1;i++){
			area[i] = (long)ps[i].w * ps[i].h;
		}
		Arrays.sort(area);
		for(int i = 0;i < n+1;i++){
			out.print(area[i] + " ");
		}
		out.println();
	}
	
	public static class Part
	{
		public int x;
		public int y;
		public int w;
		public int h;
		
		public Part(int x, int y, int w, int h)
		{
			this.x = x; this.y = y; this.w = w; this.h = h;
		}
		
		public boolean onEdge(int x, int y)
		{
			return
			((x == this.x || x == this.x + this.w) && this.y < y && y < this.y + this.h) ||
			((y == this.y || y == this.y + this.h) && this.x < x && x < this.x + this.w);
		}
		
		public boolean canSplit(int ax, int ay, int bx, int by)
		{
			if(ax == bx && (x < ax && ax < x + w) && ((y == ay && y + h == by) || (y == by && y + h == ay))){
				return true;
			}else if(ay == by && (y < ay && ay < y + h) && ((x == ax && x + w == bx) || (x == bx && x + w == ax))){
				return true;
			}
			return false;
		}
		
		public Part split(int ax, int ay, int bx, int by)
		{
			Part ret = null;
			if(ax == bx && (x < ax && ax < x + w) && ((y == ay && y + h == by) || (y == by && y + h == ay))){
				ret = new Part(ax, y, w - (ax - x), h);
				this.w = ax - x;
			}else if(ay == by && (y < ay && ay < y + h) && ((x == ax && x + w == bx) || (x == bx && x + w == ax))){
				ret = new Part(x, ay, w, h - (ay - y));
				this.h = ay - y;
			}
			return ret;
		}
		
	}
	
	public void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}