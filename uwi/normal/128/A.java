//package round94;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

public class A {
	InputStream is;
	PrintWriter out;
	String INPUT = ".......A\r\n" + 
			"........\r\n" + 
			"........\r\n" + 
			"........\r\n" + 
			"........\r\n" + 
			"........\r\n" + 
			"........\r\n" + 
			"M.......";
	
	void solve()
	{
		char[][] b = new char[8][];
		for(int i = 0;i < 8;i++){
			b[i] = ns(8);
		}
		
		Queue<int[]> q = new ArrayDeque<int[]>();
		boolean[][][] p = new boolean[8][8][8];
		q.add(new int[]{7, 0, 8});
		while(!q.isEmpty()){
			int[] cur = q.poll();
			int r = cur[0], c = cur[1];
			for(int dr = -1;dr <= 1;dr++){
				for(int dc = -1;dc <= 1;dc++){
					int nr = r+dr, nc = c+dc;
					if(nr < cur[2] && nc >= 0 && nc < 8){
						if(nr < 0){
							out.println("WIN");
							return;
						}
						if(b[nr][nc] != 'S' && nr-1 < 0){
							out.println("WIN");
							return;
						}
						if(b[nr][nc] != 'S' && b[nr-1][nc] != 'S' && !p[nr-1][nc][cur[2]-1]){
							p[nr-1][nc][cur[2]-1] = true;
							q.add(new int[]{nr-1, nc, cur[2]-1});
						}
					}
				}
			}
		}
		out.println("LOSE");
	}
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new A().run();
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