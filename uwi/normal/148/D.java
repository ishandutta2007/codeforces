//package round105;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int w = ni(), b = ni();
		double[][] p = new double[w+1][b+1];
		for(int j = 0;j <= b;j++){
			for(int i = 0;i <= w;i++){
				if(i+j <= 0)continue;
				double nex = 0;
				// bbb
				// bwb
				// bbw
				// bww
//				if(j-3 >= 0)nex += p[i][j-3] * j / (i+j) * (j-1)/(i+j-1)*(j-2)/(i+j-2);
//				if(i-1 >= 0 && j-2 >= 0)nex += p[i-1][j-2] * j / (i+j)*i/(i+j-1)*(j-1)/(i+j-2);
//				nex += (double)j/(i+j)*(j-1)/(i+j-1)*i/(i+j-2);
//				nex += (double)j/(i+j)*i/(i+j-1)*(i-1)/(i+j-2);
				
				// w
				// bbb
				// bwb
				nex += (double)i/(i+j);
				if(j-3 >= 0)nex += p[i][j-3] * j / (i+j) * (j-1)/(i+j-1)*(j-2)/(i+j-2);
				if(i-1 >= 0 && j-2 >= 0)nex += p[i-1][j-2] * j / (i+j)*i/(i+j-1)*(j-1)/(i+j-2);
				p[i][j] = nex;
			}
		}
		out.printf("%.10f\n", p[w][b]);
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