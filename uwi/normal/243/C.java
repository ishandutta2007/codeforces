//package round150;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Queue;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int[] dx = { 1, 0, -1, 0 };
	int[] dy = { 0, 1, 0, -1 };
	
	void solve()
	{
		int n = ni();
		long x = 1000000001, y = 1000000001;
		long[][] co = new long[n+1][];
		int[] dirs = new int[n];
		co[0] = new long[]{x, y};
		for(int i = 0;i < n;i++){
			int dir = "RULD".indexOf(nc());
			int s = ni();
			dirs[i] = dir;
			x += s*dx[dir];
			y += s*dy[dir];
			co[i+1] = new long[]{x, y};
		}
		
		long[] xs = new long[n+1];
		long[] ys = new long[n+1];
		for(int i = 0;i < n+1;i++){
			xs[i] = co[i][0];
			ys[i] = co[i][1];
		}
		Object[] xshs = shrink(xs);
		Object[] yshs = shrink(ys);
		int[] xsh = (int[])xshs[0]; 
		int[] ysh = (int[])yshs[0]; 
		
		int U = 2005;
		int[][] map = new int[U][U];
		for(int i = 0;i < n+1;i++){
			co[i][0] = xsh[i];
			co[i][1] = ysh[i];
		}
		for(int i = 0;i < n+1;i++){
			map[2*(int)co[i][0]+1][2*(int)co[i][1]+1] = 1;
			if(i < n){
				int fx = 2*(int)co[i][0]+1;
				int tx = 2*(int)co[i+1][0]+1;
				int fy = 2*(int)co[i][1]+1;
				int ty = 2*(int)co[i+1][1]+1;
				for(int xx = Math.min(fx, tx);xx <= Math.max(fx, tx);xx++){
					for(int yy = Math.min(fy, ty);yy <= Math.max(fy, ty);yy++){
						map[xx][yy] = 1;
					}
				}
			}
		}
		long[] xi = (long[])xshs[1];
		long[] yi = (long[])yshs[1];
		for(int i = 0;i < xi.length;i++){
			if(xi[i] == 1){
				for(int j = 0;j < U;j++){
					if(map[2*i+1][j] == 1 || map[2*i+3][j] == 1){
						map[2*i+2][j] = 1;
					}
				}
			}
		}
		for(int i = 0;i < yi.length;i++){
			if(yi[i] == 1){
				for(int j = 0;j < U;j++){
					if(map[j][2*i+1] == 1 || map[j][2*i+3] == 1){
						map[j][2*i+2] = 1;
					}
				}
			}
		}
		
		map[0][0] = 2;
		Queue<int[]> q = new ArrayDeque<int[]>();
		q.add(new int[]{0, 0});
		while(!q.isEmpty()){
			int[] cur = q.poll();
			int xx = cur[0], yy = cur[1];
			for(int k = 0;k < 4;k++){
				int nx = xx+dx[k], ny = yy+dy[k];
				if(nx >= 0 && nx < U && ny >= 0 && ny < U && map[nx][ny] == 0){
					map[nx][ny] = 2;
					q.add(new int[]{nx, ny});
				}
			}
		}
		long ret = 0;
		for(int i = 0;i < U;i++){
			for(int j = 0;j < U;j++){
				if(map[i][j] != 2){
					long dx = i % 2 == 0 ? xi[i/2-1]-1 : 1;
					long dy = j % 2 == 0 ? yi[j/2-1]-1 : 1;
					ret += dx*dy;
				}
			}
		}
		out.println(ret);
	}
	
	public static Object[] shrink(final long[] a)
	{
		int n = a.length;
		Integer[] b = new Integer[n];
		for(int i = 0;i < n;i++)b[i] = i;
		Arrays.sort(b, new Comparator<Integer>(){
			public int compare(Integer x, Integer y){
				return Long.signum(a[x] - a[y]);
			}
		});
		int[] ret = new int[n];
		long[] interval = new long[n];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(i > 0 && a[b[i]] > a[b[i-1]]){
				interval[p] = a[b[i]]-a[b[i-1]];
				p++;
			}
			ret[b[i]] = p;
		}
		
		return new Object[]{ret, Arrays.copyOf(interval, p)};
	}
	
	char nc() {
		try{
			int b;
			while ((b = is.read()) != -1
					&& (b == ' ' || b == '\r' || b == '\n'))
				;
			if(b == -1)
				return 0;
			return (char) b;
		}catch (IOException e){
		}
		return 0;
	}
	
	void run() throws Exception
	{
//		int n = 1000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append("RLUD".charAt(gen.nextInt(4)) + " ");
//			sb.append(gen.nextInt(100000)+1 + " ");
//		}
//		INPUT = sb.toString();
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new C().run();
	}
	
	public int ni()
	{
		try {
			int num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public long nl()
	{
		try {
			long num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public String ns()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n' || b == ' '));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n' || b == ' ')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
	}
	
	public char[] ns(int n)
	{
		char[] buf = new char[n];
		try{
			int b = 0, p = 0;
			while((b = is.read()) != -1 && (b == ' ' || b == '\r' || b == '\n'));
			if(b == -1)return null;
			buf[p++] = (char)b;
			while(p < n){
				b = is.read();
				if(b == -1 || b == ' ' || b == '\r' || b == '\n')break;
				buf[p++] = (char)b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}
	
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}