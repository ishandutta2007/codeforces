//package round154;
import java.io.ByteArrayInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] qs = new int[n][];
		int unk = -1;
		for(int i = 0;i < n;i++){
			qs[i] = new int[]{ni(), ni(), ni(), i};
			if(qs[i][2] == -1)unk = i;
		}
		Arrays.sort(qs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		long T = nl();
		result = new long[n];
		
		int low = 0, high = 1000000001;
		while(high - low > 1){
			int P = (high+low)/2;
			long time = simulate(P, qs, unk);
//			tr(P, time);
			if(time == T){
				boolean ok = true;
				for(int i = 0;i < n;i++){
					if(qs[i][2] == P){
						ok = false;
						break;
					}
				}
				if(ok){
					out.println(P);
					for(int i = 0;i < n;i++){
						if(i > 0)out.print(" ");
						out.print(result[i]);
					}
					out.println();
					return;
				}
			}
			if(time > T){
				low = P;
			}else{
				high = P;
			}
		}
	}
	
	long[] result;
	
	long simulate(int P, int[][] qs, final int unk)
	{
		// {left, priority, ind}
		PriorityQueue<int[]> pq = new PriorityQueue<int[]>(50001, new Comparator<int[]>(){
			public int compare(int[] a, int[] b){
				if(a[1] != b[1])return -(a[1] - b[1]);
				if(a[2] == unk)return -1;
				if(b[2] == unk)return 1;
				return 0;
			}
		});
		
		long t = 0;
		for(int[] q : qs){
			long now = q[0];
			
			while(!pq.isEmpty()){
				int[] cur = pq.peek();
				if(now-t >= cur[0]){
					t += cur[0];
					pq.poll();
					result[cur[2]] = t;
				}else{
					cur[0] -= now-t;
					break;
				}
			}
			t = now;
			
			pq.add(new int[]{q[1], q[3] == unk ? P : q[2], q[3]});
		}
		
		while(!pq.isEmpty()){
			int[] cur = pq.peek();
			t += cur[0];
			pq.poll();
			result[cur[2]] = t;
		}
		return result[unk];
	}
	
	void run() throws Exception
	{
		is = oj ? new FileInputStream("input.txt") : new ByteArrayInputStream(INPUT.getBytes());
		out = oj ?  new PrintWriter("output.txt") : new PrintWriter(System.out);
		
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