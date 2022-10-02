//package test1;


import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class C2 {
	IntReader in;
	PrintWriter out;
	String INPUT = "";
//	String INPUT = "3\r\n" +
//			"0 0 0\r\n" +
//			"12\r\n" +
//			"1 1 0\r\n" +
//			"0 0 -1\r\n" +
//			"0 1 0\r\n" +
//			"2 0\r\n" +
//			"2 2\r\n" +
//			"0 1\r\n" +
//			"0 0 1\r\n" +
//			"1 1\r\n" +
//			"2 2\r\n" +
//			"2 0 1\r\n" +
//			"0 1\r\n" +
//			"1 2\r\n";
	
	void solve()
	{
		int n = in.ni();
		a = new int[n];
		for(int i = 0;i < n;i++)a[i] = in.ni();
		build();
		
		int m = in.ni();
		for(int i = 0;i < m;i++){
			String line = in.nl();
			String[] sp = line.split(" ");
			if(sp.length == 3){
				// inc
				int lf = Integer.parseInt(sp[0]);
				int rg = Integer.parseInt(sp[1]);
				int v = Integer.parseInt(sp[2]);
				if(lf > rg){
					inc(0, rg, v);
					inc(lf, n - 1, v);
				}else{
					inc(lf, rg, v);
				}
				
				tr(line);
				tr(a);
				tr(s);
				tr(bias);
			}else{
				// rmq
				int lf = Integer.parseInt(sp[0]);
				int rg = Integer.parseInt(sp[1]);
				if(lf > rg){
					out.println(Math.min(rmq(0, rg), rmq(lf, n - 1)));
				}else{
					out.println(rmq(lf, rg));
				}
			}
		}
		
	}
	
	int[] a;
	int[] s;
	int[] bias;
	
	int M;
	
	public void build()
	{
		int n = a.length;
		M = (int)Math.ceil(Math.sqrt(n));
		s = new int[M];
		Arrays.fill(s, Integer.MAX_VALUE);
		for(int i = 0;i < n;i++){
			s[i/M] = Math.min(s[i/M], a[i]);
		}
		bias = new int[M];
	}
	
	public int rmq(int x, int y)
	{
		int sx = x / M;
		int sy = y / M;
		int min = Integer.MAX_VALUE;
		if(sx == sy){
			for(int i = x;i <= y;i++){
				min = Math.min(min, a[i] + bias[sx]);
			}
		}else{
			for(int i = sx + 1;i <= sy - 1;i++){
				min = Math.min(min, s[i] + bias[i]);
			}
			for(int i = x;i < M * (sx + 1);i++){
				min = Math.min(min, a[i] + bias[sx]);
			}
			for(int i = M * sy;i <= y;i++){
				min = Math.min(min, a[i] + bias[sy]);
			}
		}
		return min;
	}
	
	public void inc(int x, int y, int v)
	{
		int sx = x / M;
		int sy = y / M;
		if(sx == sy){
			for(int i = x;i <= y;i++){
				a[i] += v;
			}
			update(sx);
		}else{
			for(int i = sx + 1;i <= sy - 1;i++){
				bias[i] += v;
			}
			for(int i = x;i < M * (sx + 1);i++){
				a[i] += v;
			}
			for(int i = M * sy;i <= y;i++){
				a[i] += v;
			}
			update(sx);
			update(sy);
		}
	}
	
	public void update(int c)
	{
		int min = Integer.MAX_VALUE;
		for(int i = c * M;i < (c + 1) * M && i < a.length;i++){
			min = Math.min(min, a[i]);
		}
		s[c] = min;
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new IntReader(System.in) : new IntReader(new ByteArrayInputStream(INPUT.getBytes()));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new C2().run();
	}
	
	public class IntReader {
		private InputStream is;
		
		public IntReader(InputStream is)
		{
			this.is = is;
		}
		
		public String nl()
		{
			try{
				int b = 0;
				StringBuilder sb = new StringBuilder();
				while((b = is.read()) != -1 && (b == '\r' || b == '\n'));
				sb.append((char)b);
				while(true){
					b = is.read();
					if(b == -1)return sb.toString();
					if(b == '\r' || b == '\n')return sb.toString();
					sb.append((char)b);
				}
			} catch (IOException e) {
			}
			return "";
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
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
	static String join(int[] a, int d){StringBuilder sb = new StringBuilder();for(int v : a){sb.append(v + d + " ");}return sb.toString();}
}