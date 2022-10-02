//package round61;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		Datum root = new Datum("", null);
		while(in.hasNext()){
			String line = in.next();
			String[] sp = line.split("\\\\");
			root.add(sp, 0);
		}
		
		out.println(root.maxd()-1 + " " + root.maxs());
	}
	
	class Datum
	{
		public String name;
		public Datum parent;
		public List<Datum> children;
		public Datum(String name, Datum p)
		{
			parent = p;
			this.name = name;
			children = new ArrayList<Datum>();
		}
		
		public void add(String[] sp, int pos)
		{
			if(pos < sp.length){
				for(Datum d : children){
					if(d.name.equals(sp[pos])){
						d.add(sp, pos+1);
						return;
					}
				}
				Datum c = new Datum(sp[pos], this);
				children.add(c);
				c.add(sp, pos+1);
			}
		}
		
		public int maxd()
		{
			if(children.size() == 0)return 0;
			
			if(parent == null || parent.parent == null){
				int max = 0;
				for(Datum d : children){
					max = Math.max(max, d.maxd());
				}
				return max;
			}else{
				int sum = 0;
				for(Datum d : children){
					sum += d.maxd();
				}
				return sum+1;
			}
		}
		
		public int maxs()
		{
			if(children.size() == 0)return 1;
			
			if(parent == null || parent.parent == null){
				int max = 0;
				for(Datum d : children){
					max = Math.max(max, d.maxs());
				}
				return max;
			}else{
				int sum = 0;
				for(Datum d : children){
					sum += d.maxs();
				}
				return sum;
			}
		}
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}