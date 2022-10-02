//package round81;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		Equip[] es = new Equip[n];
		int ns = 0;
		Map<String, Integer> map = new HashMap<String, Integer>();
		for(int i = 0;i < n;i++){
			Equip e = new Equip();
			e.name = in.next();
			String cl = in.next();
			if(cl.equals("weapon")){
				e.clas = 0;
				e.val = ni(); ni(); ni();
			}else if(cl.equals("armor")){
				e.clas = 1;
				ni(); e.val = ni(); ni();
			}else{
				e.clas = 2;
				ni(); ni(); e.val = ni();
			}
			e.slot = ni();
			es[i] = e;
			
			ns += e.slot;
			map.put(e.name, i);
		}
		
		int m = ni();
		Resident[] rs = new Resident[m];
		for(int i = 0;i < m;i++){
			Resident r = new Resident();
			r.name = in.next();
			String cl = in.next();
			if(cl.equals("gladiator")){
				r.clas = 0;
			}else if(cl.equals("sentry")){
				r.clas = 1;
			}else{
				r.clas = 2;
			}
			r.plus = ni();
			r.home = map.get(in.next());
			rs[i] = r;
		}
		
		if(ns == m){
			String[] heads = new String[n];
			Arrays.fill(heads, "");
			
			for(int i = 0;i < m;i++){
				int ei = rs[i].home;
				if(es[ei].clas == rs[i].clas){
					es[ei].val += rs[i].plus;
				}
				heads[ei] += " " + rs[i].name;
			}
			
			int[] max = new int[3];
			int[] maxi = new int[3];
			for(int i = 0;i < n;i++){
				int k = es[i].clas;
				if(es[i].val > max[k]){
					max[k] = es[i].val;
					maxi[k] = i;
				}
			}
			for(int i = 0;i < 3;i++){
				int x = maxi[i];
				out.println(es[x].name + " " + es[x].slot + heads[x]);
			}
		}else{
			Resident[][] cl = new Resident[3][m];
			int[] cp = new int[3];
			for(int i = 0;i < m;i++){
				cl[rs[i].clas][cp[rs[i].clas]++] = rs[i];
			}
			for(int i = 0;i < 3;i++){
				cl[i] = Arrays.copyOf(cl[i], cp[i]);
				Arrays.sort(cl[i], new Comparator<Resident>(){
					public int compare(Resident a, Resident b){
						return -(a.plus - b.plus);
					}
				});
			}
			
			int[] max = new int[3];
			int[] maxi = new int[3];
			for(int i = 0;i < n;i++){
				int k = es[i].clas;
				int v = es[i].val;
				for(int j = 0;j < es[i].slot && j < cp[k];j++){
					v += cl[k][j].plus;
				}
				if(v > max[k]){
					max[k] = v;
					maxi[k] = i;
				}
			}
			
			int space = ns - m;
			int[] s = new int[3];
			int[] t = new int[3];
			for(int i = 0;i < 3;i++){
				int x = maxi[i];
				t[i] = s[i] = Math.min(es[x].slot, cp[i]);
			}
			
			int z = 0;
			for(int i = 0;i < 3;i++){
				int x = maxi[i];
				StringBuilder sb = new StringBuilder();
				for(int j = 0;j < s[i];j++){
					sb.append(" ");
					sb.append(cl[i][j].name);
				}
				space -= es[x].slot - s[i];
				if(space < 0){
					for(int j = 0;j < -space;j++){
						while(z < 3 && t[z] == cp[z])z++;
						sb.append(" ");
						sb.append(cl[z][t[z]++].name);
					}
					s[i] += -space;
					space = 0;
				}
				out.println(es[x].name + " " + s[i] + sb.toString());
			}
		}
	}
	
	public static class Equip
	{
		public String name;
		public int clas, val, slot;
	}
	
	public static class Resident
	{
		public String name;
		public int clas, plus, home;
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}