//package round95;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] q = new int[m][3];
		for(int i = 0;i < m;i++){
			q[i][0] = ni();
			q[i][1] = ni();
			q[i][2] = i;
		}
		
		int[] p = new int[m];
		Arrays.sort(q, new Comparator<int[]>(){
			public int compare(int[] a, int[] b){
				if(a[0] - b[0] != 0)return a[0] - b[0];
				return a[1] - b[1];
			}
		});
		
		for(int i = 0;i < m-1;i++){
			if(q[i][0] == q[i+1][0]){
				p[q[i][2]]++;
				p[q[i+1][2]]++;
			}
		}
		
		Arrays.sort(q, new Comparator<int[]>(){
			public int compare(int[] a, int[] b){
				if(a[1] - b[1] != 0)return a[1] - b[1];
				return a[0] - b[0];
			}
		});
		
		for(int i = 0;i < m-1;i++){
			if(q[i][1] == q[i+1][1]){
				p[q[i][2]]++;
				p[q[i+1][2]]++;
			}
		}
		
		Arrays.sort(q, new Comparator<int[]>(){
			public int compare(int[] a, int[] b){
				if((a[0]+a[1])-(b[0]+b[1]) != 0)return (a[0]+a[1])-(b[0]+b[1]);
				return a[0] - b[0];
			}
		});
		
		for(int i = 0;i < m-1;i++){
			if(q[i][0]+q[i][1] == q[i+1][0]+q[i+1][1]){
				p[q[i][2]]++;
				p[q[i+1][2]]++;
			}
		}
		
		
		Arrays.sort(q, new Comparator<int[]>(){
			public int compare(int[] a, int[] b){
				if((a[0]-a[1])-(b[0]-b[1]) != 0)return (a[0]-a[1])-(b[0]-b[1]);
				return a[0] - b[0];
			}
		});
		
		for(int i = 0;i < m-1;i++){
			if(q[i][0]-q[i][1] == q[i+1][0]-q[i+1][1]){
				p[q[i][2]]++;
				p[q[i+1][2]]++;
			}
		}
		
		int[] ct = new int[9];
		for(int i = 0;i < m;i++){
			ct[p[i]]++;
		}
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i <= 8;i++){
			sb.append(" " + ct[i]);
		}
		out.println(sb.substring(1));
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