//package round116;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class A {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] F = new int[n];
		Arrays.fill(F, -1);
		int[] d = new int[m];
		int p = 0;
		for(int i = 0;i < m;i++){
			d[i] = ni();
			for(int j = 0;j < d[i];j++){
				F[ni()-1] = p++;
			}
		}
		
		List<String> ope = new ArrayList<String>();
		{
			int i = 0, j = n-1;
			while(i < j){
				while(i < j && F[i] != -1)i++;
				while(i < j && F[j] == -1)j--;
				if(i >= j)break;
				ope.add((j+1) + " " + (i+1));
				F[i] = F[j];
				F[j] = -1;
			}
		}
		
		int[] IF = new int[p];
		for(int i = 0;i < p;i++)IF[F[i]] = i;
		
		boolean[] ved = new boolean[n];
		for(int i = 0;i < p;i++){
			if(!ved[i]){
				ved[i] = true;
				if(F[i] != i){
					ope.add((i+1) + " " + n);
					F[n-1] = F[i]; F[i] = -1;
					int prev = i;
					for(int j = IF[i];j != i;j = IF[j]){
						ope.add((j+1) + " " + (prev+1));
						F[prev] = F[j]; F[j] = -1;
						ved[j] = true;
						prev = j;
					}
					ope.add(n + " " + (prev+1));
					F[prev] = F[n-1]; F[n-1] = -1;
				}
			}
		}
		
		out.println(ope.size());
		for(String s : ope){
			out.println(s);
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