//package round25;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class E2 {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "abacaba abaaba x";
//	private String INPUT = "cd bc ab";
//	private String INPUT = "abc c bcd";
//	private String INPUT = "bc abcd ef";
	private String INPUT = "";
	
	public void solve()
	{
		char[][] s = new char[3][];
		String[] st = new String[3];
		for(int i = 0;i < 3;i++){
			st[i] = in.next();
			s[i] = st[i].toCharArray();
		}
		
		int[][] imp = new int[3][3];
		for(int i = 0;i < 3;i++){
			for(int j = 0;j < 3;j++){
				if(i != j && indexOf(s[i], s[j]) > -1){
//				if(i != j && st[i].indexOf(st[j]) > -1){
					imp[i][j] = 1;
				}
			}
		}
		
		tr("");
		// aad+b
		// bad+b
		int max = 0;
		for(int a = 0;a < 3;a++){
			for(int b = 0;b < 3;b++){
				for(int c = 0;c < 3;c++){
					if(a == b || b == c || c == a)continue;
					
					tr(a,b,c);
					char[] ss;
					int dab, dbc;
					if(imp[a][b] == 1){
						dab = s[b].length;
						ss = s[a];
					}else{
						{
							int d;
							long[] hh = makeHeadHash(s[b]);
							long[] th = makeTailHash(s[a]);
							for(d = Math.min(s[a].length - 1, s[b].length - 1); d >= 0;d--){
								if(th[d] == hh[d]){
									tr("hit", d);
									int i;
									for(i = 0;i <= d && s[b][i] == s[a][s[a].length - 1 - d + i];i++);
									if(i > d)break;
								}
							}
							dab = d + 1;
						}
						ss = new char[s[a].length + s[b].length - dab];
						for(int i = 0;i < s[a].length;i++){
							ss[i] = s[a][i];
						}
						for(int i = dab;i < s[b].length;i++){
							ss[s[a].length + i - dab] = s[b][i];
						}
					}
					
					if(imp[a][c] == 1 || imp[b][c] == 1){
						dbc = s[c].length;
					}else{
						int d;
						long[] hh = makeHeadHash(s[c]);
						long[] th = makeTailHash(ss);
						for(d = Math.min(ss.length - 1, s[c].length - 1); d >= 0;d--){
							if(th[d] == hh[d]){
								tr("hit~", d);
								int i;
								for(i = 0;i <= d && s[c][i] == ss[ss.length - 1 - d + i];i++);
								if(i > d)break;
							}
						}
						dbc = d + 1;
					}
//					tr(dab, dbc, Arrays.toString(ss));
					
					max = Math.max(max, dab + dbc);
				}
			}
		}
		out.println(s[0].length + s[1].length + s[2].length - max);
	}
	
	public int indexOf(char[] c, char[] q)
	{
		if(c.length < q.length)return -1;
		long[] ch = makeLenHash(c, q.length);
		long qh = makeHash(q);
		
		String cs = new String(c);
		String qs = new String(q);
		for(int i = 0;i < ch.length;i++){
			if(ch[i] == qh){
				if(cs.startsWith(qs, i)){
					return i;
				}
			}
		}
		return -1;
	}
	
	long U = Integer.MAX_VALUE;
	
	public long[] makeHeadHash(char[] s)
	{
		long[] headhash = new long[s.length];
		long hh = 0;
		for(int j = 0;j < s.length;j++){
			hh = (hh * 26 + s[j] - 'a') % U;
			headhash[j] = hh;
		}
		return headhash;
	}
		
	public long[] makeTailHash(char[] s)
	{
		long[] tailhash = new long[s.length];
		long d = 1;
		long hh = 0;
		for(int j = s.length - 1;j >= 0;j--){
			hh = (hh + (s[j] - 'a') * d) % U;
			d = (d * 26) % U;
			tailhash[s.length - j - 1] = hh;
		}
		return tailhash;
	}
	
	public void run() throws Exception
	{
//		Random r = new Random();
//		StringBuilder sb = new StringBuilder();
//		for(int i = 0;i < 3;i++){
//			for(int j = 0;j < 100000;j++){
//				int nni = r.nextInt(20000) == 0 ? 1 : 0;
//				if(nni == 1)tr(i, j);
//				sb.append((char)('a' + nni));
////				sb.append('a');
//			}
////			sb.append((char)('a' + i));
//			sb.append(' ');
//		}
//		INPUT = sb.toString();
//		
//		long s = System.currentTimeMillis();
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
//		tr(System.currentTimeMillis() - s);
	}
	
	public long makeHash(char[] s)
	{
		long hh = 0;
		for(int j = 0;j < s.length;j++){
			hh = (hh * 26 + s[j] - 'a') % U;
		}
		return hh;
	}
	
	public long[] makeLenHash(char[] s, int len)
	{
		long[] hash = new long[s.length - len + 1];
		long hh = 0;
		
		long q = 1;
		for(int i = 0;i < len - 1;i++){
			q = (q * 26) % U;
		}
		q = U - q;
		
		for(int j = 0;j < s.length;j++){
			if(j >= len){
				hh += q * (s[j - len] - 'a');
			}
			hh = (hh * 26 + s[j] - 'a') % U;
			if(j >= len - 1){
				hash[j - len + 1] = hh;
			}
		}
		return hash;
	}
	
	public static void main(String[] args) throws Exception
	{
		new E2().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { }
//	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}