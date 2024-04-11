//package round57;


import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class E {
	IntReader in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		final int[] a = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni();
		}
		Integer[] ord = new Integer[n];
		for(int i = 0;i < n;i++){
			ord[i] = i;
		}
		Arrays.sort(ord, new Comparator<Integer>(){
			public int compare(Integer x, Integer y)
			{
				return a[x] - a[y];
			}
		});
		
		st = new int[1<<(N+1)];
		int[] l = new int[n];
		for(int i = 0;i < n;i++){
			int o = ord[i];
			l[i] = sum(o, (1<<N)-1, N);
			inc(o);
		}
		Arrays.fill(st, 0);
		long gsum = 0;
		for(int i = n-1;i >= 0;i--){
			int o = ord[i];
			int r = sum(0, o, N);
			gsum += (long)l[i] * r;
			inc(o);
		}
		out.println(gsum);
	}
	
	int N = 20;
	int[] st = new int[1<<(N+1)];
	
	void inc(int a)
	{
		for(int o = N;o >= 0;o--){
			st[(1<<(N-o))+(a>>o)]++;
		}
	}
	
	int sum(int a, int b, int o)
	{
		if((a&((1<<o)-1)) == 0 && (b&((1<<o)-1)) == (1<<o)-1){
			return st[(1<<(N-o))+(a>>o)];
		}
		int at = (a>>(o-1))&1;
		int bt = (b>>(o-1))&1;
		if(at == bt){
			return sum(a, b, o-1);
		}else{
			int bound = b&~((1<<(o-1))-1);
			return sum(a, bound-1, o-1) + sum(bound, b, o-1);
		}
	}
	
	
	void run() throws Exception
	{
//		int n = 1000000;
//		StringBuilder sb = new StringBuilder(n + " ");
//		Random r = new Random();
//		for(int i = 0;i < n;i++){
//			sb.append(r.nextInt(1000000000) + " ");
//		}
//		INPUT = sb.toString();
//		int n = 1000000;
//		StringBuilder sb = new StringBuilder(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append(i+1 + " ");
//		}
//		INPUT = sb.toString();
		
		in = INPUT.isEmpty() ? new IntReader(System.in) : new IntReader(new ByteArrayInputStream(INPUT.getBytes()));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new E().run();
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
		
		public String nl()
		{
			try{
				int b = 0;
				StringBuilder sb = new StringBuilder();
				while((b = is.read()) != -1 && (b == '\r' || b == '\n'));
				if(b == -1)return "";
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
	}
	
	int ni() { return in.ni(); }
	int nui() { return in.nui(); }
	String nl() { return in.nl(); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}