//package yandex2011.q2;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.HashMap;
import java.util.Map;

public class B {
	IntReader in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		if(n == 2){
			int m = ni();
			int[] a = new int[m];
			for(int i = 0;i < m;i++){
				a[i] = ni();
			}
			out.println("1 " + a[0]);
			out.print((m-1) + " ");
			for(int i = 1;i < m;i++){
				out.print(a[i] + " ");
			}
			out.println();
		}else{
			Map<BitSet, BitSet> map = new HashMap<BitSet, BitSet>();
			BitSet[] bs = new BitSet[201];
			for(int i = 0;i < 201;i++){
				bs[i] = new BitSet();
			}
			for(int i = 0;i < n*(n-1)/2;i++){
				int m = ni();
				for(int j = 0;j < m;j++){
					bs[ni()].set(i);
				}
			}
			for(int i = 0;i < 201;i++){
				if(!bs[i].isEmpty()){
					if(!map.containsKey(bs[i])){
						map.put(bs[i], new BitSet());
					}
					map.get(bs[i]).set(i);
				}
			}
			
			for(BitSet b : map.values()){
				out.print(b.cardinality() + " ");
				for(int i = b.nextSetBit(0);i != -1;i = b.nextSetBit(i + 1)){
					out.print(i + " ");
				}
				out.println();
			}
		}
	}
	
	void run() throws Exception
	{
//		int n = 200;
//		StringBuilder sb = new StringBuilder(n + " ");
//		for(int i = 1;i <= n;i++){
//			for(int j = i+1;j <= n;j++){
//				sb.append("2 " + i + " " + j + " ");
//			}
//		}
//		INPUT = sb.toString();
//
		in = INPUT.isEmpty() ? new IntReader(System.in) : new IntReader(new ByteArrayInputStream(INPUT.getBytes()));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new B().run();
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
		
		public long nl()
		{
			try {
				long num = 0;
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
		
		public String nline()
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
		
		public String ns()
		{
			try{
				int b = 0;
				StringBuilder sb = new StringBuilder();
				while((b = is.read()) != -1 && (b == '\r' || b == '\n' || b == ' '));
				if(b == -1)return "";
				sb.append((char)b);
				while(true){
					b = is.read();
					if(b == -1)return sb.toString();
					if(b == '\r' || b == '\n' || b == ' ')return sb.toString();
					sb.append((char)b);
				}
			} catch (IOException e) {
			}
			return "";
		}
	}
	
	int ni() { return in.ni(); }
	long nl() { return in.nl(); }
	String nline() { return in.nline(); }
	String ns() { return in.ns(); }
	double nd() { return Double.parseDouble(in.ns()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}