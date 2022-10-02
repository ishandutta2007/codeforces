//package round145;
import java.io.ByteArrayInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		BitSet fav = new BitSet();
		for(int i = 0;i < m;i++)fav.set(ni());
		int nfav = fav.cardinality(), nonfav = n - nfav;
		int Q = ni();
		int[][] ra = new int[Q][];
		for(int v = 0;v < Q;v++){
			ns();
			int u = ni();
			int unk = 0;
			int infav = 0;
			int ninfav = 0;
			for(int i = 0;i < u;i++){
				int ind = ni();
				if(ind == 0){
					unk++;
				}else if(fav.get(ind)){
					infav++;
				}else{
					ninfav++;
				}
			}
			ra[v] = new int[]{infav+Math.max(unk-(nonfav-ninfav), 0), infav+Math.min(nfav-infav, unk)};
		}
		tr(ra);
		for(int i = 0;i < Q;i++){
			boolean ok = true;
			for(int j = 0;j < Q;j++){
				if(j == i || ra[j][0] <= ra[i][1]){
				}else{
					ok = false;
				}
			}
			boolean perfect = true;
			for(int j = 0;j < Q;j++){
				if(j == i || ra[j][1] <= ra[i][0]){
				}else{
					perfect = false;
				}
			}
			if(perfect){
				out.println(0);
			}else if(ok){
				out.println(2);
			}else{
				out.println(1);
			}
		}
	}
	
	void run() throws Exception
	{
		is = oj ? new FileInputStream("input.txt") : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter("output.txt");
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
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