//package round7;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int t = ni(), m = ni();
		int[][] has = new int[101][];
		int al = 0;
		int p = 0;
		inner:
		for(int i = 0;i < t;i++){
			String com = ns();
			if("alloc".equals(com)){
				int sz = ni();
				if(al == 0){
					if(m >= sz){
						has[al++] = new int[]{0, sz, ++p};
						out.println(p);
						continue inner;
					}
				}else{
					if(has[0][0] >= sz){
						has[al++] = new int[]{0, sz, ++p};
						out.println(p);
						Arrays.sort(has, 0, al, new Comparator<int[]>() {
							public int compare(int[] a, int[] b) {
								return a[0] - b[0];
							}
						});
						continue inner;
					}
					for(int j = 0;j < al-1;j++){
						if(has[j+1][0]-(has[j][0]+has[j][1]) >= sz){
							has[al++] = new int[]{has[j][0]+has[j][1], sz, ++p};
							out.println(p);
							Arrays.sort(has, 0, al, new Comparator<int[]>() {
								public int compare(int[] a, int[] b) {
									return a[0] - b[0];
								}
							});
							continue inner;
						}
					}
					if(m-(has[al-1][0]+has[al-1][1]) >= sz){
						has[al] = new int[]{has[al-1][0]+has[al-1][1], sz, ++p};
						al++;
						out.println(p);
						Arrays.sort(has, 0, al, new Comparator<int[]>() {
							public int compare(int[] a, int[] b) {
								return a[0] - b[0];
							}
						});
						continue inner;
					}
				}
				out.println("NULL");
			}else if("erase".equals(com)){
				int x = ni();
				for(int j = 0;j < al;j++){
					if(has[j][2] == x){
						if(j < al-1){
							has[j] = has[al-1];
							al--;
							Arrays.sort(has, 0, al, new Comparator<int[]>() {
								public int compare(int[] a, int[] b) {
									return a[0] - b[0];
								}
							});
						}else{
							al--;
						}
						continue inner;
					}
				}
				out.println("ILLEGAL_ERASE_ARGUMENT");
			}else{
				int q = 0;
				for(int j = 0;j < al;j++){
					has[j][0] = q;
					q += has[j][1];
				}
			}
		}
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