//package croc2012.mbtu.fin;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	int[] go(char[] cur, char[] below, int pos, int dir)
	{
		int m = cur.length;
		int cr = pos;
		int cl = pos;
		
		int step = 0;
		int conc = 0;
		out:
		while(true){
//			tr(pos, dir, cur, step);
			if(below[pos] == '.'){
				step++;
				break;
			}
			if(dir == 1){
				while(cr < m && cur[cr] == '.'){
					if(below[cr] == '.'){
						step += cr-pos+1;
						pos = cr;
						break out;
					}
					cr++;
				}
				step += cr-pos;
				pos = cr-1;
				dir = -dir;
				if(cr < m && cur[cr] == '+'){
					cur[cr] = '.';
					conc = 0;
				}else{
					conc++;
				}
			}else{
				while(cl >= 0 && cur[cl] == '.'){
					if(below[cl] == '.'){
						step += pos-cl+1;
						pos = cl;
						break out;
					}
					cl--;
				}
				step += pos-cl;
				pos = cl+1;
				dir = -dir;
				if(cl >= 0 && cur[cl] == '+'){
					cur[cl] = '.';
					conc = 0;
				}else{
					conc++;
				}
			}
			if(conc >= 2){
				return null;
			}
		}
//		tr(step);
		
		return new int[]{pos, dir, step};
	}
	
	void solve()
	{
		int n = ni(), m = ni();
		char[][] b = new char[n][];
		for(int i = 0;i < n;i++){
			b[i] = ns(m);
		}
		
		int pos = 0, dir = 1;
		long ret = 0;
		for(int i = 0;i < n-1;i++){
			int[] res = go(b[i], b[i+1], pos, dir);
			if(res == null){
				out.println("Never");
				return;
			}
			pos = res[0]; dir = res[1]; ret += res[2];
		}
		out.println(ret);
	}
	
	void run() throws Exception
	{
//		int n = 100, m = 10000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for(int i = 0;i < n;i++){
//			for(int j = 0;j < m;j++){
//				if(i % 2 == 0){
//					if(j == 0){
//						sb.append(".");
//						continue;
//					}
//				}else{
//					if(j == m-1){
//						sb.append(".");
//						continue;
//					}
//				}
//				sb.append('+');
//			}
//			sb.append("\n");
//		}
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
		new E2().run();
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