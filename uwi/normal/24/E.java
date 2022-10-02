//package round24;


import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.Arrays;
import java.util.Random;

public class E3 {
	private IntReader in;
	private PrintWriter out;
//	private String INPUT = "3 -5 9 0 1 5 -1";
//	private String INPUT = "6 1 3 2 3 3 3 4 -3 5 -1 6 -100";
//	private String INPUT = "2 -1000000000 1 1000000000 -1";
	private String INPUT = "";
	
	public void solve()
	{
		int n = in.ni();
		P[] p = new P[n];
		for(int i = 0;i < n;i++){
			int x = in.ni();
			int y = in.ni();
			p[i] = new P(x, y);
		}
		
		BigDecimal inf = BigDecimal.ZERO;
		BigDecimal sup = BigDecimal.valueOf(1000000001);
		double eps = 1E-10;
		if(!collide(p, sup.doubleValue())){
			out.println(-1);
			return;
		}
		while(sup.subtract(inf).doubleValue() > eps){
			BigDecimal mid = sup.add(inf).divide(BigDecimal.valueOf(2));
//			tr(mid);
//			tr(mid, collide(p, mid));
			if(collide(p, mid.doubleValue())){
				sup = mid;
			}else{
				inf = mid;
			}
		}
		out.println(inf);
	}
	
	public boolean collide(P[] ps, double t)
	{
		double eps = 1E-12;
		double max = Double.NEGATIVE_INFINITY;
		for(P p : ps){
			if(p.y > 0){
				max = Math.max(max, p.x + p.y * t);
			}else{
				if(p.x + p.y * t < max + eps){
//					tr(max, t);
					return true;
				}
			}
		}
		return false;
	}
	
	public double tan(P a, P b)
	{
		return (double)(a.y - b.y) / (double)(a.x - b.x);
	}
	
	private class P
	{
		public double x;
		public double y;
		
		public P(double x, double y){
			this.x = x; this.y = y;
		}
	}
	
	public void run() throws Exception
	{
//		int N = 500000;
//		Random r = new Random();
//		StringBuilder sb = new StringBuilder(N + " ");
//		for(int i = 0;i < N;i++){
//			sb.append(i * 400 - 1000000000);
//			sb.append(' ');
//			sb.append((r.nextInt(1000000000) + 1) * (r.nextBoolean() ? 1 : -1));
////			sb.append(i < N / 2 ? -1000000000 : 1000000000);
//			sb.append(' ');
//		}
//		INPUT = sb.toString();
		
		in = INPUT.isEmpty() ? new IntReader(System.in) : new IntReader(new ByteArrayInputStream(INPUT.getBytes()));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new E3().run();
	}
	
	public class IntReader {
		private InputStream is;
		
		public IntReader(InputStream is)
		{
			this.is = is;
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
					if(b == -1)return minus ? -num : num;
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
	}
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}