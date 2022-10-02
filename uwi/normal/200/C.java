//package round126;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		Map<String, Integer> map = new HashMap<String, Integer>();
		map.put("BERLAND", 0);
		int p = 1;
		String[] name = new String[4];
		int[] played = new int[4];
		int[] obt = new int[4];
		int[] miss = new int[4];
		int[] point = new int[4];
		
		for(int i = 0;i < 5;i++){
			String a = ns();
			String b = ns();
			if(!map.containsKey(a)){
				map.put(a, p++);
			}
			if(!map.containsKey(b)){
				map.put(b, p++);
			}
			
			int as = ni();
			int bs = ni();
			int at = map.get(a);
			int bt = map.get(b);
			played[at]++;
			played[bt]++;
			
			obt[at] += as; miss[bt] += as;
			obt[bt] += bs; miss[at] += bs;
			if(as > bs){
				point[at] += 3;
			}else if(as < bs){
				point[bt] += 3;
			}else{
				point[at] += 1;
				point[bt] += 1;
			}
		}
		
		for(Map.Entry<String, Integer> e : map.entrySet()){
			name[e.getValue()] = e.getKey();
		}
		
		int op = 0;
		for(int i = 1;i < 4;i++){
			if(played[i] == 2){
				op = i;
				break;
			}
		}
		
		int ox = -1, oy = 9999999;
		int minxy = 9999999;
		
		point[0] += 3;
		for(int x = 0;x <= 300;x++){
			for(int y = 0;y < x;y++){
				obt[0] += x; miss[op] += x;
				obt[op] += y; miss[0] += y;
				int r = rank(name, obt, miss, point);
				if(r <= 2){
					if(x - y < minxy){
						minxy = x - y;
						ox = x;
						oy = y;
					}else if(x - y == minxy && y < oy){
						ox = x;
						oy = y;
					}
				}
				obt[0] -= x; miss[op] -= x;
				obt[op] -= y; miss[0] -= y;
			}
		}
		
		if(ox == -1){
			out.println("IMPOSSIBLE");
		}else{
			out.println(ox + ":" + oy);
		}
	}
	
	int rank(String[] name, int[] obt, int[] miss, int[] point)
	{
		int ret = 1;
		for(int i = 1;i < 4;i++){
			if(point[0] < point[i]){
				ret++; continue;
			}
			if(point[0] > point[i]){
				continue;
			}
			
			if(obt[0] - miss[0] < obt[i] - miss[i]){
				ret++; continue;
			}
			if(obt[0] - miss[0] > obt[i] - miss[i]){
				continue;
			}
			
			if(obt[0] < obt[i]){
				ret++; continue;
			}
			if(obt[0] > obt[i]){
				continue;
			}
			
			if(name[0].compareTo(name[i]) > 0){
				ret++; continue;
			}
			continue;
		}
		return ret;
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
		new C().run();
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