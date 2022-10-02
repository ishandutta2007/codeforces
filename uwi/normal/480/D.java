//package round274;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), S = ni();
		n++;
		Parcel[] ps = new Parcel[n];
		Parcel[] qs = new Parcel[n];
		qs[n-1] = ps[n-1] = new Parcel(0, 2*n, 0, S, 0, 0);
		for(int i = 0;i < n-1;i++){
			qs[i] = ps[i] = new Parcel(ni(), ni(), ni(), ni(), ni(), i+1);
		}
		Arrays.sort(ps, new Comparator<Parcel>() {
			public int compare(Parcel a, Parcel b) {
				if(a.out - a.in != b.out - b.in)return (a.out-a.in) - (b.out-b.in);
				return a.in - b.in;
			}
		});
		Arrays.sort(qs, new Comparator<Parcel>() {
			public int compare(Parcel a, Parcel b) {
				return a.out - b.out;
			}
		});
		int[][] has = new int[n][];
		for(int i = 0;i < n;i++){
			int[][] dp = new int[ps[i].out-ps[i].in+1][];
//			ps[i].s+1];
			dp[0] = new int[ps[i].s+1];
			int[] ref = new int[ps[i].out-ps[i].in+1];
			Arrays.fill(ref, 0);
			for(int j = 0;j < n;j++){
				if(qs[j].id == ps[i].id)continue;
				if(ps[i].in <= qs[j].in && qs[j].out <= ps[i].out){
//					tr(ps[i].id, qs[j].id);
					int ind = qs[j].out-ps[i].in;
					if(dp[ind] == null){
						dp[ind] = Arrays.copyOf(dp[ref[ind]], ps[i].s+1);
						Arrays.fill(ref, ind, ref.length, ind);
					}
					int fr = ref[qs[j].in-ps[i].in];
//					tr(qs[j]);
//					tr(dp[fr] != null);
//					tr(has[qs[j].id] != null, qs[j].id, ps[i].id, qs[j].in, qs[j].out, ps[i].in, ps[i].out);
					for(int k = qs[j].w;k <= ps[i].s;k++){
						dp[ind][k] = Math.max(dp[ind][k], dp[fr][k] + has[qs[j].id][Math.min(qs[j].s, k-qs[j].w)] + qs[j].v);
					}
				}
			}
			has[ps[i].id] = dp[ref[ps[i].out-ps[i].in]];
		}
		int max = 0;
		for(int k = 0;k <= S;k++){
			max = Math.max(max, has[0][k]);
		}
		out.println(max);
	}
	
	static class Parcel
	{
		int in, out;
		int w, s;
		int v;
		int id;
		public Parcel(int in, int out, int w, int s, int v, int id) {
			this.in = in;
			this.out = out;
			this.w = w;
			this.s = s;
			this.v = v;
			this.id = id;
		}
		
		
	}
	
	void run() throws Exception
	{
//		int n = 500, m = 1000;
//		for(int u = 23;u < 100;u++){
//			Random gen = new Random(u);
//			StringBuilder sb = new StringBuilder();
//			sb.append(n + " ");
//			sb.append(m + " ");
//			boolean[] ved = new boolean[1000000];
//			for (int i = 0; i < n; i++) {
//				while(true){
//					int v1 = gen.nextInt(2*n);
//					int v2 = gen.nextInt(2*n);
//					if(v1 > v2){
//						int d = v1; v1 = v2; v2 = d;
//					}
//					if(!ved[v1*1000+v2]){
//						ved[v1*1000+v2] = true;
//						sb.append(Math.min(v1, v2) + " ");
//						sb.append(Math.max(v1, v2) + 1 + " ");
//						sb.append(gen.nextInt(1000) + " ");
//						sb.append(gen.nextInt(1000) + " ");
//						sb.append(gen.nextInt(1000000) + 1 + " ");
//						break;
//					}
//				}
//			}
//			INPUT = sb.toString();
		
			is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
			out = new PrintWriter(System.out);
			
			long s = System.currentTimeMillis();
			solve();
			out.flush();
			tr(System.currentTimeMillis()-s+"ms");
//		}
	}
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}