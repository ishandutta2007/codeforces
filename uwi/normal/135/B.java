//package round97;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int[][] co = new int[8][2];
		                     
		for(int i = 0;i < 8;i++){
			co[i][0] = ni();
			co[i][1] = ni();
		}
		
		int[] ord = new int[8];
		for(int i = 0;i < 8;i++)ord[i] = i;
		
		do{
			if(isSq(
					co[ord[0]][0], co[ord[0]][1],
					co[ord[1]][0], co[ord[1]][1],
					co[ord[2]][0], co[ord[2]][1],
					co[ord[3]][0], co[ord[3]][1]) && 
				isRect(
						co[ord[4]][0], co[ord[4]][1],
						co[ord[5]][0], co[ord[5]][1],
						co[ord[6]][0], co[ord[6]][1],
						co[ord[7]][0], co[ord[7]][1])){
				out.println("YES");
				out.println(
						(ord[0]+1) + " " +
								(ord[1]+1) + " " +
								(ord[2]+1) + " " +
								(ord[3]+1));
				out.println(
						(ord[4]+1) + " " +
								(ord[5]+1) + " " +
								(ord[6]+1) + " " +
								(ord[7]+1));
				return;
			}
		}while(nextPermutation(ord));
		out.println("NO");
	}
	
	public static boolean nextPermutation(int[] src)
	{
		int i;
		for(i = src.length - 2;i >= 0 && src[i] > src[i+1];i--);
		if(i == -1)return false;
		int j;
		for(j = i + 1;j < src.length && src[i] < src[j];j++);
		int d = src[i]; src[i] = src[j - 1]; src[j - 1] = d;
		for(int p = i + 1, q = src.length - 1;p < q;p++,q--){
			d = src[p]; src[p] = src[q]; src[q] = d;
		}
		return true;
	}
	
	boolean isRect(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy)
	{
		int vx = bx-ax;
		int vy = by-ay;
		int wx = cx-ax;
		int wy = cy-ay;
		return (!(ax == bx && ay == by) && !(ax == cx && ay == cy) && cx+vx==dx && cy+vy==dy && bx+wx==dx && by+wy==dy && vx*wx+vy*wy == 0);
	}
	
	boolean isSq(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy)
	{
		int vx = bx-ax;
		int vy = by-ay;
		return (!(dx == ax && dy == ay) && cx == ax + vy && cy == ay - vx && dx == bx + vy && dy == by - vx);
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
		new B().run();
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