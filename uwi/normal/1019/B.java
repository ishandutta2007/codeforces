//package round503;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class B2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	// 12123432
	// 12343212
	
	int qc = 0;
	int n;
	
	int[] table;
	
	int val(int x)
	{
		if(table[x] != Integer.MIN_VALUE)return table[x];
		if(qc > 60)throw new RuntimeException();
		out.println("? " + (x+1));
		out.flush();
		table[x] = ni();
		
		if(table[x] == table[(x+table.length/2) % table.length]){
			if(x >= n/2)x -= n/2;
			out.println("! " + (x+1));
			out.flush();
			throw new IllegalStateException();
		}
		return table[x];
	}
	
	void solve()
	{
		n = ni();
		if(n % 4 != 0){
			out.println("! -1");
			out.flush();
			return;
		}
		table = new int[n];
		Arrays.fill(table, Integer.MIN_VALUE);
		Random gen = new Random(1);
		try{
			outer:
			while(true){
				int pu = gen.nextInt(n);
				int pd = (pu+n/2)%n;
				int pl = (pu + gen.nextInt(n/2-1)+1)%n;
				int pr = (pl+n/2)%n;
				
				int vu = val(pu), vd = val(pd);
				int vl = val(pl), vr = val(pr);
				if(cross(vu, vl, vd, vr)){
				}else if(cross(vu, vr, vd, vl)){
					int npu = pr, npl = pu;
					int npd = pl, npr = pd;
					pu = npu; pl = npl;
					pd = npd; pr = npr;
					vu = val(pu);
					vl = val(pl);
					vd = val(pd);
					vr = val(pr);
				}else{
					continue outer;
				}
				// u-l d-r
				while(true){
					int pul = h(pu, pl, n);
					int vul = val(pul);
					int pdr = h(pd, pr, n);
					int vdr = val(pdr);
					if(cross(vul, vu, vdr, vd)){
						pl = pul; vl = vul;
						pr = pdr; vr = vdr;
					}else{
						pu = pul; vu = vul;
						pd = pdr; vd = vdr;
					}
				}
			}
		}catch(IllegalStateException e)
		{
		}
	}
	
	int h(int a, int b, int n)
	{
		if(a > b){
			b += n;
		}
		int u = (a+b)/2;
		if(u >= n)u -= n;
		return u;
	}
	
	boolean cross(int a, int b, int c, int d)
	{
		return Integer.signum(c-a) != Integer.signum(d-b);
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
		new B2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}
//