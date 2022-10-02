//package round74;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "15 Widget pack(10,10)\r\n" +
			"HBox dummy\r\n" +
			"HBox x\r\n" +
			"VBox y\r\n" +
			"y.pack(dummy)\r\n" +
			"y.set_border(5)\r\n" +
			"y.set_spacing(55)\r\n" +
			"dummy.set_border(10)\r\n" +
			"dummy.set_spacing(20)\r\n" +
			"x.set_border(10)\r\n" +
			"x.set_spacing(10)\r\n" +
			"x.pack(pack)\r\n" +
			"x.pack(dummy)\r\n" +
			"x.pack(pack)\r\n" +
			"x.set_border(0)";
	
	void solve()
	{
		TreeMap<String, Obj> map = new TreeMap<String, Obj>();
		int n = ni();
		Set<Obj> roots = new HashSet<Obj>();
		for(int i = 0;i < n;i++){
			String com = in.next();
			if(com.equals("Widget")){
				String oo = in.next();
				int k = oo.indexOf('(');
				int comma = oo.indexOf(',');
				String name = oo.substring(0, k);
				int w = Integer.parseInt(oo.substring(k+1, comma));
				int h = Integer.parseInt(oo.substring(comma+1, oo.length()-1));
				Obj o = new Obj(name, 0, w, h);
				map.put(name, o);
				roots.add(o);
			}else if(com.equals("VBox")){
				String name = in.next();
				Obj o = new Obj(name, 1);
				map.put(name, o);
				roots.add(o);
			}else if(com.equals("HBox")){
				String name = in.next();
				Obj o = new Obj(name, 2);
				map.put(name, o);
				roots.add(o);
			}else{
				int dot = com.indexOf('.');
				int k = com.indexOf('(');
				String subj = com.substring(0, dot);
				String ob = com.substring(k+1, com.length()-1);
				if(com.indexOf(".pack(") > -1){
					map.get(subj).pack(map.get(ob));
					roots.remove(map.get(ob));
				}else if(com.indexOf(".set_border(") > -1){
					map.get(subj).border = Integer.parseInt(ob);
				}else if(com.indexOf(".set_spacing(") > -1){
					map.get(subj).spacing = Integer.parseInt(ob);
				}else{
					throw new Error();
				}
			}
		}
		
		for(Obj root : roots){
			root.decide();
		}
		
		for(Obj o : map.values()){
			out.println(o.name + " " + o.w + " " + o.h);
		}
	}
	
	static class Obj {
		public String name;
		public long w, h;
		public int vhw;
		public int border, spacing;
		public List<Obj> children;
		
		public void decide()
		{
			if(w >= 0 && h >= 0)return;
			
			if(children.size() > 0){
				if(vhw == 1){
					h = (children.size() - 1) * spacing + 2*border;
					w = 0;
					for(Obj c : children){
						c.decide();
						h += c.h;
						w = Math.max(w, c.w);
					}
					w += 2*border;
				}else if(vhw == 2){
					w = (children.size() - 1) * spacing + 2*border;
					h = 0;
					for(Obj c : children){
						c.decide();
						w += c.w;
						h = Math.max(h, c.h);
					}
					h += 2*border;
				}
			}else{
				if(vhw >= 1){
					w = h = 0;
				}
			}
		}
		
		public Obj(String name, int vhw)
		{
			this.name = name;
			this.vhw = vhw;
			w = -1;
			h = -1;
			border = 0;
			spacing = 0;
			children = new ArrayList<Obj>();
		}
		
		public Obj(String name, int vhw, int w, int h)
		{
			this.name = name;
			this.vhw = vhw;
			this.w = w;
			this.h = h;
			border = 0;
			spacing = 0;
			children = new ArrayList<Obj>();
		}
		
		public void pack(Obj o)
		{
			children.add(o);
		}
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
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}