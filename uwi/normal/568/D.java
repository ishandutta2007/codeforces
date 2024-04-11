//package round315;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Random;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		List<long[]> co = new ArrayList<long[]>();
		for(int i = 0;i < n;i++)co.add(new long[]{ni(), ni(), ni(), i+1});
		Random gen = new Random();
		List<long[]> hist = new ArrayList<>();
		outer:
		for(int z = 0;z < K;z++){
			if(n == 0)break;
			if(n <= K-z){
				hist.add(new long[]{co.get(0)[3], -1});
				co.remove(0);
				n--;
				continue;
			}
			int ex = (n+K-z-1)/(K-z);
			for(int rep = 0;rep < 200;rep++){
				int s = gen.nextInt(n);
				int t = gen.nextInt(n);
				if(s == t)continue;
				// ax+by+c=0
				// a'x+b'y+c'=0
				// -1/(ab'-ba')*(b' -b -a' a)(c c')
				long sa = co.get(s)[0], sb = co.get(s)[1], sc = co.get(s)[2];
				long ta = co.get(t)[0], tb = co.get(t)[1], tc = co.get(t)[2];
				if(sa*tb-sb*ta == 0)continue;
				long xnum = tb*sc-sb*tc;
				long ynum = -ta*sc+sa*tc;
				long den = -(sa*tb-sb*ta);
				int ct = 0;
				for(int i = 0;i < n;i++){
					long a = co.get(i)[0];
					long b = co.get(i)[1];
					long c = co.get(i)[2];
					if(a*xnum+b*ynum+c*den == 0){
						ct++;
					}
				}
				if(ct >= ex){
					List<long[]> nco = new ArrayList<long[]>();
					for(int i = 0;i < n;i++){
						long a = co.get(i)[0];
						long b = co.get(i)[1];
						long c = co.get(i)[2];
						if(a*xnum+b*ynum+c*den != 0){
							nco.add(co.get(i));
						}
					}
					hist.add(new long[]{co.get(s)[3], co.get(t)[3]});
					n = nco.size();
					co = nco;
					continue outer;
				}
			}
			out.println("NO");
			return;
		}
		out.println("YES");
		out.println(hist.size());
		for(long[] row : hist){
			out.println(row[0] + " "+ row[1]);
		}
	}
	
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
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