//package school3;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.HashSet;
import java.util.Scanner;

public class F5 {
	Scanner in;
	PrintWriter out;
//	String INPUT = "100000 4";
//	String INPUT = "0 1";
	String INPUT = "";
	
	int[] dec(int n, int m)
	{
		if(n <= m){
			return new int[]{n, 0};
		}else if(n <= 2 * m){
			return new int[]{n - m, n - m};
		}else{
			return new int[]{n - 2 * m - 1, m};
		}
	}
	
	int enc(int x, int y, int m)
	{
		if(y == 0){
			return x;
		}else if(x == y){
			return x + m;
		}else{
			return x + 2 * m + 1;
		}
	}
	
	void solve()
	{
		int m = ni();
		int n = ni();
		if(m <= 0){
			out.println(1);
			return;
		}
		if(n <= 1){
			out.println(-1);
			return;
		}
		
//		for(int i = 0;i <= 3 * m;i++){
//			int[] co = dec(i, m);
//			tr(co);
//			if(enc(co[0], co[1], m) != i){
//				tr("out!",i);
//			}
//		}
		
//		int[] co = {0, 0};
//		{
//			if(co[1] == 0){
//				int inf = co[0] + 1;
//				int sup = Math.min(m, co[0] + n);
//				if(inf <= sup){
//					tr(inf, 0, sup, 0, enc(inf, 0, m), enc(sup, 0, m));
//				}
//			}
//		}
//		{
//			int inf = Math.max(co[0], co[1]);
//			if(co[0] == co[1])inf++;
//			int sup = Math.min(m, (n + co[0] + co[1]) / 2);
//
//			if(inf <= sup){
//				tr(inf, inf, sup, sup, enc(inf, inf, m), enc(sup, sup, m));
//			}
//		}
//		{
//			int inf = co[0];
//			if(co[1] == m)inf++;
//			int sup = Math.min(m - 1, co[0] + n - m + co[1]);
//			if(inf <= sup){
//				tr(inf, m, sup, m, enc(inf, m, m), enc(sup, m, m));
//			}
//		}
//		{
//			if(co[1] == m){
//				int inf = co[0] - 1;
//				int sup = Math.max(0, co[0] - n);
//				if(sup <= inf){
//					tr(sup, m, inf, m, enc(sup, m, m), enc(inf, m, m));
//				}
//			}
//		}
//		{
//			int inf = Math.min(co[0], co[1]);
//			if(co[0] == co[1])inf--;
//			int sup = Math.max(1, (-n + co[0] + co[1] + 1) / 2);
//
////			if(sup == 0)sup++;
//			if(sup <= inf){
//				tr(sup, sup, inf, inf, enc(sup, sup, m), enc(inf, inf, m));
//			}
//		}
//		{
//			int inf = co[0];
//			if(co[1] == 0)inf--;
//			int sup = Math.max(0, co[0] - n + co[1]);
//			if(sup <= inf){
//				tr(sup, 0, inf, 0, enc(sup, 0, m), enc(inf, 0, m));
//			}
//		}
		
		if(n <= Math.sqrt(Math.sqrt(m))){
			solveH(m, n);
		}else{
			solveB(m, n);
		}
	}
	
	void solveB(int m, int n){
			// (a, 0), (a, a), (a, m)
			BitSet visitedo = new BitSet();
			BitSet visitedh = new BitSet();
			BitSet q = new BitSet();
			q.set(0);
			boolean iso = true;
			int step = 0;
			
			while(!q.isEmpty()){
				if(!iso && q.get(2 * m))break;
//				tr(step, q);
				BitSet nq = new BitSet();
				if(iso){
					visitedh.or(q);
				}else{
					visitedo.or(q);
				}
				for(int cur = q.nextSetBit(0);cur != -1;cur = q.nextSetBit(cur+1)){
					int[] co = dec(cur, m);
					if(iso){
						{
							if(co[1] == 0){
								int inf = co[0] + 1;
								int sup = Math.min(m, co[0] + n);
								if(inf <= sup){
									nq.set(enc(inf, 0, m), enc(sup, 0, m) + 1);
								}
							}
						}
						{
							int inf = Math.max(co[0], co[1]);
							if(co[0] == co[1])inf++;
							int sup = Math.min(m, (n + co[0] + co[1]) / 2);
							
							if(inf <= sup){
								nq.set(enc(inf, inf, m), enc(sup, sup, m) + 1);
							}
						}
						{
							int inf = co[0];
							if(co[1] == m)inf++;
							int sup = Math.min(m - 1, co[0] + n - m + co[1]);
							if(inf <= sup){
								nq.set(enc(inf, m, m), enc(sup, m, m) + 1);
							}
						}
					}else{
						{
							if(co[1] == m){
								int inf = co[0] - 1;
								int sup = Math.max(0, co[0] - n);
								if(sup <= inf){
									nq.set(enc(sup, m, m), enc(inf, m, m) + 1);
								}
							}
						}
						{
							int inf = Math.min(co[0], co[1]);
							if(co[0] == co[1])inf--;
							int sup = Math.max(1, (-n + co[0] + co[1] + 1) / 2);
							
//							if(sup == 0)sup++;
							if(sup <= inf){
								nq.set(enc(sup, sup, m), enc(inf, inf, m) + 1);
							}
						}
						{
							int inf = co[0];
							if(co[1] == 0)inf--;
							int sup = Math.max(0, co[0] - n + co[1]);
							if(sup <= inf){
								nq.set(enc(sup, 0, m), enc(inf, 0, m) + 1);
							}
						}
					}
				}
				if(iso){
					nq.andNot(visitedo);
				}else{
					nq.andNot(visitedh);
				}
				q = nq;
				step++;
				iso = !iso;
			}
			if(q.isEmpty()){
				out.println(-1);
			}else{
				out.println(step);
			}
	}
	
	void solveH(int m, int n){
		
		// (a, 0), (a, a), (a, m)
		HashSet<Integer> visitedo = new HashSet<Integer>();
		HashSet<Integer> visitedh = new HashSet<Integer>();
		HashSet<Integer> q = new HashSet<Integer>();
		q.add(0);
		boolean iso = true;
		int step = 0;
		
		while(!q.isEmpty()){
			if(!iso && q.contains(2 * m))break;
//			tr(step, q);
			HashSet<Integer> nq = new HashSet<Integer>();
			if(iso){
				visitedh.addAll(q);
			}else{
				visitedo.addAll(q);
			}
			for(int cur : q){
				int[] co = dec(cur, m);
				if(iso){
					{
						if(co[1] == 0){
							int inf = co[0] + 1;
							int sup = Math.min(m, co[0] + n);
							if(inf <= sup){
								for(int i = enc(inf, 0, m);i <= enc(sup, 0, m);i++){
									nq.add(i);
								}
							}
						}
					}
					{
						int inf = Math.max(co[0], co[1]);
						if(co[0] == co[1])inf++;
						int sup = Math.min(m, (n + co[0] + co[1]) / 2);
						
						if(inf == 0)inf = 1;
						if(inf <= sup){
							for(int i = enc(inf, inf, m);i <= enc(sup, sup, m);i++){
								nq.add(i);
							}
						}
					}
					{
						int inf = co[0];
						if(co[1] == m)inf++;
						int sup = Math.min(m - 1, co[0] + n - m + co[1]);
						if(inf <= sup){
							for(int i = enc(inf, m, m);i <= enc(sup, m, m);i++){
								nq.add(i);
							}
						}
					}
				}else{
					{
						if(co[1] == m){
							int inf = co[0] - 1;
							int sup = Math.max(0, co[0] - n);
							if(sup <= inf){
								for(int i = enc(sup, m, m);i <= enc(inf, m, m);i++){
									nq.add(i);
								}
							}
						}
					}
					{
						int inf = Math.min(co[0], co[1]);
						if(co[0] == co[1])inf--;
						int sup = Math.max(1, (-n + co[0] + co[1] + 1) / 2);
						
//						if(sup == 0)sup++;
						if(sup <= inf){
							for(int i = enc(sup, sup, m);i <= enc(inf, inf, m);i++){
								nq.add(i);
							}
						}
					}
					{
						int inf = co[0];
						if(co[1] == 0)inf--;
						int sup = Math.max(0, co[0] - n + co[1]);
						if(sup <= inf){
							for(int i = enc(sup, 0, m);i <= enc(inf, 0, m);i++){
								nq.add(i);
							}
						}
					}
				}
			}
			if(iso){
				nq.removeAll(visitedo);
			}else{
				nq.removeAll(visitedh);
			}
			q = nq;
			step++;
			iso = !iso;
		}
		if(q.isEmpty()){
			out.println(-1);
		}else{
			out.println(step);
		}
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		out.println(INPUT);
		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new F5().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}