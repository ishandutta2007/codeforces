//package round390;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;

public class C {
	InputStream is;
	PrintWriter out;
//	String INPUT = "1\n3\na b c\n3\n?:a\n?:c\n?:b";
	String INPUT = "";
	
	void solve()
	{
		String I = "Impossible";
		outer:
		for(int T = ni();T > 0;T--){
			int n = ni();
			Map<String, Integer> nameId = new HashMap<>();
			String[] names = new String[n];
			int idgen = 0;
			for(String s : ns().split(" ")){
				names[idgen] = s;
				nameId.put(s, idgen++);
			}
			int m = ni();
			String[] lines = new String[m];
			String[] whos = new String[m];
			for(int i = 0;i < m;i++){
				String line = ns();
				int colon = line.indexOf(':');
				whos[i] = line.substring(0, colon);
				lines[i] = line.substring(colon+1);
			}
			BitSet[] ments = new BitSet[m];
			for(int i = 0;i < m;i++){
				ments[i] = new BitSet();
				for(String word : lines[i].split("[ ,!\\?\\.]+")){
					if(word == null)continue;
					if(nameId.containsKey(word)){
						ments[i].set(nameId.get(word));
					}
				}
			}
			for(int rep = 0;rep <= m;rep++){
				for(int i = 0;i < m;i++){
					if(whos[i].equals("?")){
						if(i-1 >= 0 && nameId.containsKey(whos[i-1])){
							ments[i].set(nameId.get(whos[i-1]));
						}
						if(i+1 < m && nameId.containsKey(whos[i+1])){
							ments[i].set(nameId.get(whos[i+1]));
						}
						if(ments[i].cardinality() == n){
							out.println(I); continue outer;
						}
						if(ments[i].cardinality() == n-1){
							whos[i] = names[ments[i].nextClearBit(0)];
						}
					}else{
						if(i-1 >= 0 && whos[i].equals(whos[i-1])){
							out.println(I); continue outer;
						}
						if(i+1 < m && whos[i].equals(whos[i+1])){
							out.println(I); continue outer;
						}
						if(ments[i].get(nameId.get(whos[i]))){
							out.println(I); continue outer;
						}
					}
				}
			}
			for(int i = 0;i < m;i++){
				if(whos[i].equals("?")){
					whos[i] = names[ments[i].nextClearBit(0)];
					if(i+1 < m){
						ments[i+1].set(nameId.get(whos[i]));
					}
				}
			}
			for(int i = 0;i < m;i++){
				out.println(whos[i] + ":" + lines[i]);
			}
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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
		while(!(isSpaceChar(b) && b != ' ')){
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