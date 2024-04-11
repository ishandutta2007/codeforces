//package round23;



import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;

public class C3 {
	private IntReader in;
	private PrintWriter out;
//	private String INPUT = "2 2 10 15 5 7 20 18 1 0 0";
	private String INPUT = "";
	
	public void solve()
	{
		int t = in.nui();
		for(int r = 0;r < t;r++){
			int n = in.nui();
			int m = 2 * n - 1;
			Pair[] p = new Pair[m];
			for(int i = 0;i < m;i++){
				p[i] = new Pair();
				p[i].a = in.nui();
				p[i].o = in.nui();
				p[i].ind = i;
			}
			
			Arrays.sort(p);
			BitSet used = new BitSet();
			BitSet selected = new BitSet();
			{
				int i, j = 0;
				int lower = 0;
				for(i = used.nextClearBit(0);i < m;i = j){
					j = used.nextClearBit(i + 1);
					if(j >= m)continue;
					if(p[i].o < p[j].o){
						selected.set(p[j].ind);
						used.set(i);
						used.set(j);
						int k;
						for(k = i - 1;k >= lower;k--){
							if(!used.get(k)){
								j = k;
								break;
							}
						}
						if(k < lower){
							j = used.nextClearBit(j);
							lower = j;
						}
					}
				}
			}
//			for(int i = used.nextClearBit(0);i < m;i = used.nextClearBit(i + 1)){
//				tr(p[i].a, p[i].o);
//			}
			
			for(int i = used.nextClearBit(0);i < m;){
				selected.set(p[i].ind);
				i = used.nextClearBit(i+1);
				i = used.nextClearBit(i+1);
			}
			
			out.println("YES");
			StringBuilder sb = new StringBuilder();
			for(int i = selected.nextSetBit(0);i != -1;i = selected.nextSetBit(i + 1)){
				sb.append((i + 1) + " ");
			}
			out.println(sb.toString());
		}
	}
	
	private class Pair implements Comparable<Pair>
	{
		public int a;
		public int o;
		public int ind;
		
		@Override
		public int compareTo(Pair p) {
			if(a != p.a)return a - p.a;
			if(o != p.o)return o - p.o;
			return 0;
		}
	}
	
	public void run() throws Exception
	{
//		int n = 100000;
//		StringBuilder sb = new StringBuilder("1 " + n + " ");
//		for(int i = 0;i < 2 * n - 1;i++){
//			sb.append(i + " " + (2 * n - 2 - i) + " ");
//		}
//		INPUT = sb.toString();
		
//		int n = 100;
//		Random r = new Random();
//		StringBuilder sb = new StringBuilder("1 " + n + " ");
//		for(int i = 0;i < 2 * n - 1;i++){
//			sb.append(r.nextInt(1000000) + " " + r.nextInt(1000000) + " ");
//		}
//		INPUT = sb.toString();
		
		in = INPUT.isEmpty() ? new IntReader(System.in) : new IntReader(new ByteArrayInputStream(INPUT.getBytes()));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new C3().run();
	}
	
	public class IntReader {
		private InputStream is;
		
		public IntReader(InputStream is)
		{
			this.is = is;
		}
		
		public int nui()
		{
			try {
				int num = 0;
				while((num = is.read()) != -1 && (num < '0' || num > '9'));
				num -= '0';
				
				while(true){
					int b = is.read();
					if(b == -1)return num;
					if(b >= '0' && b <= '9'){
						num = num * 10 + (b - '0');
					}else{
						return num;
					}
				}
			} catch (IOException e) {
			}
			return -1;
		}
	}
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}