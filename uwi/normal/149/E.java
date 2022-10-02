//package round106;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] str = ns(100000);
		
		int n = str.length;
		int m = ni();
		int ct = 0;
		for(int r = 0;r < m;r++){
			char[] qf = ns(1000);
			int z = qf.length;
			char[] qr = new char[z];
			for(int i = 0;i < z;i++){
				qr[i] = qf[z-1-i];
			}
			int[] kmpf = kmpTable(qf);
			int[] kmpr = kmpTable(qr);
			
			int p = 0;
			int[] pref = new int[z+1];
			int[] suff = new int[z+1];
			Arrays.fill(pref, -1);
			Arrays.fill(suff, -1);
			
			for(int i = 0;i < n;i++){
				while(p == z || (qf[p] != str[i] && p > 0))p = kmpf[p];
				if(qf[p] == str[i]){
					p++;
					if(pref[p] == -1)pref[p] = i;
				}
			}
			p = 0;
			for(int i = 0;i < n;i++){
				while(p == z || (qr[p] != str[n-1-i] && p > 0))p = kmpr[p];
				if(qr[p] == str[n-1-i]){
					p++;
					if(suff[p] == -1)suff[p] = i;
				}
			}
			tr(pref);
			tr(suff);
			
			for(int i = 1;i <= z-1;i++){
				if(pref[i] != -1 && suff[z-i] != -1 && pref[i]<n-1-suff[z-i]){
					ct++;
					break;
				}
			}
		}
		out.println(ct);
	}
	
	public static int[] kmpTable(char[] str) {
		int n = str.length;
		int[] kmp = new int[n + 1];
		kmp[0] = -1;
		kmp[1] = 0;
		for (int i = 2, j = 0; i <= n; i++) {
			while (j > 0 && str[i - 1] != str[j])
				j = kmp[j];
			kmp[i] = str[i - 1] == str[j] ? ++j : 0;
		}
		return kmp;
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
		new E().run();
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