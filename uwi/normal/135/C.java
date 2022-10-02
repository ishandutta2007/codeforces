//package round97;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class C2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] line = ns(100000);
		int n = line.length;
		int z = 0, o = 0, q = 0;
		for(int i = 0;i < n-2;i++){
			if(line[i] == '0')z++;
			if(line[i] == '1')o++;
			if(line[i] == '?')q++;
		}
		boolean[] nya = new boolean[4];
		if(line[n-2] != '1' && line[n-1] != '1')nya[0] = true;
		if(line[n-2] != '1' && line[n-1] != '0')nya[1] = true;
		if(line[n-2] != '0' && line[n-1] != '1')nya[2] = true;
		if(line[n-2] != '0' && line[n-1] != '0')nya[3] = true;
		int bit = 0;
		int mid = (n-1)/2;
		if(o <= mid && mid <= o+q){
			// 0123
			for(int i = 0;i < 4;i++){
				if(nya[i]){
					bit |= 1<<i;
				}
			}
		}
		if(o <= mid+1 && mid+1 <= o+q){
			// 2333
			if(nya[0])bit |= 1<<2;
			if(nya[1] || nya[2] || nya[3])bit |= 1<<3;
		}
		if(o <= mid-1 && mid-1 <= o+q){
			// 0001
			if(nya[3])bit |= 1<<1;
			if(nya[0] || nya[1] || nya[2])bit |= 1<<0;
		}
		if(o <= mid-2){
			bit |= 1<<0;
		}
		if(o+q >= mid+2){
			bit |= 1<<3;
		}
		for(int i = 0;i < 4;i++){
			if(bit<<31-i<0){
				out.println(Integer.toBinaryString(i|4).substring(1));
			}
		}
	}
	
	int rec(int x, int left, boolean min)
	{
		if(left == 2)return x;
		
		int opt = min ? 4 : -1;
		for(int i = 0;i < left;i++){
			int v = rec((x&((1<<i)-1))|((x&~((1<<i)-1))>>>1), left-1, !min);
			if(min){
				opt = Math.min(opt, v);
			}else{
				opt = Math.max(opt, v);
			}
		}
		return opt;
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