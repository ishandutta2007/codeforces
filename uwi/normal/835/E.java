//package round426;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class E {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	int get(int[] a)
	{
		out.print("? " + a.length);
		for(int v : a){
			out.print(" " + (v+1));
		}
		out.println();
		out.flush();
		return ni();
	}
	
	void solve()
	{
		int n = ni(), x = ni(), y = ni();
		int diff = 0;
		for(int i = 0;i < 10;i++){
			int[] s = new int[1024];
			int p = 0;
			for(int j = 0;j < n;j++){
				if(j<<~i<0){
					s[p++] = j;
				}
			}
			s = Arrays.copyOf(s, p);
			if(p == 0)continue;
			int z = get(s);
			if(p % 2 == 0){
				if(z == (x^y)){
					diff |= 1<<i;
				}
			}else{
				if(z == y){
					diff |= 1<<i;
				}
			}
		}
		int u = Integer.numberOfTrailingZeros(diff);
		int[] s = new int[1024];
		int p = 0;
		for(int j = 0;j < n;j++){
			if(j<<~u<0){
				s[p++] = j;
			}
		}
		s = Arrays.copyOf(s, p);
		while(s.length > 1){
			int h = s.length/2;
			int z = get(Arrays.copyOf(s, h));
			boolean pre = false;
			if(h % 2 == 0){
				if(z == (x^y)){
					pre = true;
				}
			}else{
				if(z == y){
					pre = true;
				}
			}
			if(pre){
				s = Arrays.copyOf(s, h);
			}else{
				s = Arrays.copyOfRange(s, h, s.length);
			}
		}
		int[] rets = {s[0]+1, (s[0]^diff)+1};
		Arrays.sort(rets);
		out.println("! " + rets[0] + " " + rets[1]);
		out.flush();
	}
	
	void run() throws Exception
	{
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
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
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}