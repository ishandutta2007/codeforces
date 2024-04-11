//package round154;
import java.io.ByteArrayInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

public class C2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni()+1;
		int r1 = ni()-1, c1 = ni()-1, r2 = ni()-1, c2 = ni()-1;
		int[][] d = new int[n][100002];
		for(int i = 0;i < n;i++){
			Arrays.fill(d[i], 99999999);
		}
		d[r1][c1] = 0;
		
		Queue<int[]> q = new ArrayDeque<int[]>();
		q.add(new int[]{r1, c1});
		while(!q.isEmpty()){
			int[] cur = q.poll();
			int r = cur[0], c = cur[1];
			if(r==r2 && c==c2)break;
			if(c-1 >= 0){
				int nr = r, nc = c-1;
				if(d[nr][nc] > d[r][c] + 1){
					d[nr][nc] = d[r][c]+1;
					q.add(new int[]{nr, nc});
				}
			}
			if(c+1 < a[r]){
				int nr = r, nc = c+1;
				if(d[nr][nc] > d[r][c] + 1){
					d[nr][nc] = d[r][c]+1;
					q.add(new int[]{nr, nc});
				}
			}
			if(r+1 < n){
				int nr = r+1, nc = c < a[r+1] ? c : a[r+1]-1;
				if(d[nr][nc] > d[r][c] + 1){
					d[nr][nc] = d[r][c]+1;
					q.add(new int[]{nr, nc});
				}
			}
			if(r-1 >= 0){
				int nr = r-1, nc = c < a[r-1] ? c : a[r-1]-1;
				if(d[nr][nc] > d[r][c] + 1){
					d[nr][nc] = d[r][c]+1;
					q.add(new int[]{nr, nc});
				}
			}
		}
		out.println(d[r2][c2]);
	}
	
	void run() throws Exception
	{
//		int n = 100, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append(gen.nextInt(100000) + " ");
//		}
//		sb.append(gen.nextInt(100)+1 + " ");
//		sb.append(gen.nextInt(100000) + " ");
//		sb.append(gen.nextInt(100)+1 + " ");
//		sb.append(gen.nextInt(100000) + " ");
//		INPUT = sb.toString();
		
		is = oj ? new FileInputStream("input.txt") : new ByteArrayInputStream(INPUT.getBytes());
		out = oj ?  new PrintWriter("output.txt") : new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new C2().run();
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