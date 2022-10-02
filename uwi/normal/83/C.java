//package round72;
import java.io.PrintWriter;
import java.lang.reflect.Field;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

public class C4 {
	Scanner in;
	PrintWriter out;
//	String INPUT = "5 3 2\r\n" +
//	"Sba\r\n" +
//	"ccc\r\n" +
//	"aac\r\n" +
//	"ccc\r\n" +
//	"abT";
//	String INPUT = "3 4 1\r\n" +
//	"Sxyy\r\n" +
//	"yxxx\r\n" +
//	"yyyT";
//	String INPUT = "3 4 1\r\n" +
//	"SbbT\r\n" +
//	"aaaa\r\n" +
//	"abba";
//	String INPUT = "1 3 3\r\n" +
//			"TyS";
//	String INPUT = "1 4 1\r\n" +
//	"SxyT";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int k = ni();
		char[][] map = new char[n][m];
		int sr = 0, sc = 0, gr = 0, gc = 0;
		for(int i = 0;i < n;i++){
			map[i] = in.next().toCharArray();
			for(int j = 0;j < m;j++){
				if(map[i][j] == 'S'){
					sr = i;
					sc = j;
				}
				if(map[i][j] == 'T'){
					gr = i;
					gc = j;
				}
			}
		}
		
		int[][] info = new int[n][m];
		Set<Long> cache = new HashSet<Long>();
		
		Queue<Datum> q = new PriorityQueue<Datum>(100000, new Comparator<Datum>() {
			public int compare(Datum a, Datum b)
			{
				if(a.route.length() != b.route.length())return a.route.length() - b.route.length();
				if(!a.route.equals(b.route))return a.route.compareTo(b.route);
				if(a.r-b.r!=0)return a.r-b.r;
				if(a.c-b.c!=0)return a.c-b.c;
				return a.used-b.used;
			}
		});
		
		q.add(new Datum(sr, sc, "", 0, 0));
		int[] dr = {-1,1,0,0};
		int[] dc = {0,0,-1,1};
		long gcode = ((long)(sr*m+sc))<<26|0;
		cache.add(gcode);
		while(q.size() > 0) {
			Datum cur = q.poll();
//			tr(desc(cur));
			if(cur.r == gr && cur.c == gc) {
				out.println(cur.route);
				return;
			}
			for(int l = 0;l < 4;l++) {
				int nr = cur.r + dr[l];
				int nc = cur.c + dc[l];
				if(nr >= 0 && nr < n && nc >= 0 && nc < m && !(nr==sr && nc==sc)) {
					if(map[nr][nc] != 'T') {
						int nexused = cur.used | 1<<map[nr][nc]-'a';
						int nexn = cur.nused + (cur.used<<31-(map[nr][nc]-'a')>=0?1:0);
						long code = ((long)(nr*m+nc))<<26|nexused;
						if(nexn <= k && (info[nr][nc] == 0 || (info[nr][nc] & nexused) != info[nr][nc]) && !cache.contains(code)) {
							info[nr][nc] = nexused;
							cache.add(code);
							q.add(new Datum(nr, nc, cur.route + map[nr][nc], nexused, nexn));
						}
					}else {
						if(info[nr][nc] == 0 || (info[nr][nc] & cur.used) != info[nr][nc]) {
							info[nr][nc] = cur.used;
							q.add(new Datum(nr, nc, cur.route, cur.used, cur.nused));
						}
					}
				}
			}
		}
		out.println(-1);
	}
	
	public String[][] desc(Object bean)
	{
		if(bean == null)return new String[0][2];
	    Class<?> c = bean.getClass();
	    Field[] fs = c.getFields();
	    String[][] ret = new String[fs.length][2];
	    for(int i = 0;i < fs.length;i++) {
	    	ret[i][0] = fs[i].getName();
	    	try {
				ret[i][1] = fs[i].get(bean).toString();
			} catch (Exception e) {}
	    }
	    return ret;
	}
	
	static class Datum
	{
		public int r, c;
		public String route;
		public int used; // used letter
		public int nused;
		
		public Datum(int r, int c, String route, int used, int nused)
		{
			this.r = r; this.c = c; this.route = route; this.used = used; this.nused = nused;
		}
	}
	
	void run() throws Exception
	{
//		int n = 50;
//		StringBuilder sb = new StringBuilder(n + " " + n + " 4 ");
//		Random r = new Random();
//		for(int i = 0;i < n;i++){
//			for(int j = 0;j < n;j++) {
//				if(i == 0 && j == 0) {
//					sb.append('S');
//				}else if(i == n - 1 && j == n - 1) {
//					sb.append('T');
//				}else {
//					sb.append((char)(r.nextInt(1)+'a'));
//				}
//			}
//			sb.append(" ");
//		}
//		INPUT = sb.toString();
//
//		long s = System.currentTimeMillis();
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
//		long g = System.currentTimeMillis();
//		tr(g-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new C4().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}