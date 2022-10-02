//package round32;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class D {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "5 6 1 ....*. ...*** ....*. ..*... .***..";
//	private String INPUT = "5 6 2 ....*. ...*** ....*. ..*... .***..";
//	private String INPUT = "7 7 2 ...*... ....... ...*... *.***.* ...*... ....... ...*...";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int m = ni();
		int k = ni();
		char[][] s = new char[n][m];
		for(int i = 0;i < n;i++){
			s[i] = in.next().toCharArray();
		}
		
		Cross[] cs = new Cross[4500000];
		int p = 0;
		for(int y = 0;y < n;y++){
			for(int x = 0;x < m;x++){
				if(s[y][x] == '*'){
					int sup = Math.min(Math.min(x, m - 1 - x), Math.min(y, n - 1 - y));
					for(int z = 1;z <= sup;z++){
						if(s[y-z][x] == '*' && s[y+z][x] == '*' && s[y][x-z] == '*' && s[y][x+z] == '*'){
							cs[p++] = new Cross(y, x, z);
						}
					}
				}
			}
		}
		if(k - 1 >= p){
			out.println(-1);
			return;
		}
//		cs = Arrays.copyOf(cs, p);
		int se = select(cs, k - 1, 0, p, new Comparator<Cross>(){
			public int compare(Cross a, Cross b)
			{
				if(a.size != b.size)return a.size - b.size;
				if(a.y != b.y)return a.y - b.y;
				return a.x - b.x;
			}
		});
//		Arrays.sort(cs, new Comparator<Cross>(){
//			public int compare(Cross a, Cross b)
//			{
//				if(a.size != b.size)return a.size - b.size;
//				if(a.y != b.y)return a.y - b.y;
//				return a.x - b.x;
//			}
//		});
		out.println((cs[se].y + 1) + " " + (cs[se].x + 1));
		out.println((cs[se].y + 1 - cs[se].size) + " " + (cs[se].x + 1));
		out.println((cs[se].y + 1 + cs[se].size) + " " + (cs[se].x + 1));
		out.println((cs[se].y + 1) + " " + (cs[se].x + 1 - cs[se].size));
		out.println((cs[se].y + 1) + " " + (cs[se].x + 1 + cs[se].size));
	}
	
	public int partition(Cross[] c, int f, int t, int pind, Comparator<Cross> comp)
	{
		Cross pv = c[pind];
		c[pind] = c[t-1]; c[t-1] = pv;
		int ind = f;
		for(int i = f;i < t - 1;i++){
			if(comp.compare(c[i], pv) <= 0){
				Cross dm = c[ind]; c[ind] = c[i]; c[i] = dm;
				ind++;
			}
		}
		c[t-1] = c[ind]; c[ind] = pv;
		return ind;
	}
	
	public int select(Cross[] c, int k, int f, int t, Comparator<Cross> comp)
	{
		int p = partition(c, f, t, (f + t) / 2, comp);
		if(k == p){
			return k;
		}else if(k < p){
			return select(c, k, f, p, comp);
		}else{
			return select(c, k, p+1, t, comp);
		}
	}
	
	public class Cross
	{
		public int y, x, size;
		public Cross(int y, int x, int size)
		{
			this.y = y;
			this.x = x;
			this.size = size;
		}
	}
	
	public void run() throws Exception
	{
//		StringBuilder sb = new StringBuilder("300 300 1000000\n");
//		for(int i = 0;i < 300;i++){
//			for(int j = 0;j < 300;j++){
//				sb.append('*');
//			}
//			sb.append('\n');
//		}
//		INPUT = sb.toString();
		long s = System.currentTimeMillis();
		
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
		long g = System.currentTimeMillis();
//		tr(g - s);
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}