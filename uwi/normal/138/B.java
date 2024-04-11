//package round99;
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
		char[] s = ns(100000);
		int n = s.length;
		int[] ct = new int[10];
		for(int i = 0;i < n;i++){
			ct[s[i]-'0']++;
		}
		// 0+0
		int max = -1;
		int maxi = 0, maxz = 0;
		
		int[] ct2 = Arrays.copyOf(ct, 10);
		if(ct[0] > max){
			max = ct[0];
			maxi = 0;
			maxz = ct[0];
		}
		for(int z = 0;z <= ct[0];z++){
			ct[0] -= z;
			ct2[0] -= z;
			for(int i = 1;i <= 5;i++){
				if(ct[i] >= 1 && ct2[10-i] >= 1){
					int lct = z+1;
					ct[i]--;
					ct2[10-i]--;
					for(int j = 0;j <= 9;j++){
						lct += Math.min(ct[j],ct2[9-j]);
					}
					if(lct > max){
						max = lct;
						maxi = i;
						maxz = z;
					}
					ct[i]++;
					ct2[10-i]++;
				}
			}
			ct[0] += z;
			ct2[0] += z;
		}
//		tr(max, maxi);
		
		if(maxi == 0){
			for(int k = 0;k < 2;k++){
				for(int i = 9;i >= 0;i--){
					for(int j = 0;j < ct[i];j++){
						out.print(i);
					}
				}
				out.println();
			}
		}else{
			ct[0] -= maxz;
			ct2[0] -= maxz;
			ct[maxi]--;
			ct2[10-maxi]--;
			StringBuilder sb1 = new StringBuilder();
			StringBuilder sb2 = new StringBuilder();
			for(int i = 0;i < maxz;i++){
				sb1.append(0);
				sb2.append(0);
			}
			sb1.append(maxi);
			sb2.append(10-maxi);
			for(int j = 0;j <= 9;j++){
				int min = Math.min(ct[j],ct2[9-j]);
				for(int k = 0;k < min;k++){
					sb1.append(j);
					sb2.append(9-j);
				}
				ct[j] -= min;
				ct2[9-j] -= min;
			}
			for(int i = 0;i <= 9;i++){
				for(int j = 0;j < ct[i];j++){
					sb1.append(i);
				}
				for(int j = 0;j < ct2[i];j++){
					sb2.append(i);
				}
			}
			out.println(sb1.reverse());
			out.println(sb2.reverse());
		}
	}
	
	void run() throws Exception
	{
//		int n = 10000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(gen.nextInt(n));
//		tr(sb);
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