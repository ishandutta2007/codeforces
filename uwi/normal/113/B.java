//package round86;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;
	
public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "aaabaaa a aaa";
	
	void solve()
	{
		char[] t = in.next().toCharArray();
		char[] sb = in.next().toCharArray();
		char[] se = in.next().toCharArray();
		
		int[] kb = kmpTable(sb);
		int[] ke = kmpTable(se);
		int n = t.length;
		
		BitSet bb = new BitSet();
		{
			int p = 0;
			for(int i = 0;i < t.length;i++){
				while(sb[p] != t[i] && p > 0)p = kb[p];
				if(sb[p] == t[i]){
					if(++p == sb.length){
						bb.set(i-sb.length+1);
						p = kb[p];
					}
				}
			}
		}
		BitSet be = new BitSet();
		{
			int p = 0;
			for(int i = 0;i < t.length;i++){
				while(se[p] != t[i] && p > 0)p = ke[p];
				if(se[p] == t[i]){
					if(++p == se.length){
						be.set(i-se.length+1);
						p = ke[p];
					}
				}
			}
		}
		
		int cu = bb.cardinality() * be.cardinality();
		long[] nya = new long[cu];
		int q = 0;
		for(int i = bb.nextSetBit(0);i != -1;i = bb.nextSetBit(i+1)){
			long h = 0;
			for(int j = i;j < n;j++){
				if(be.get(j) && i+sb.length<=j+se.length){
					nya[q++] = h;
				}
				h = h * 37 + (t[j]-'a'+1);
			}
		}
		Arrays.sort(nya, 0, q);
		int ct = 0;
		for(int i = 0;i < q;i++){
			if(i == 0 || nya[i-1] != nya[i]){
				ct++;
			}
		}
		out.println(ct);
	}
	
	public static int[] kmpTable(char[] str)
	{
		int n = str.length;
		int[] kmp = new int[n+1];
		kmp[0] = -1; kmp[1] = 0;
		for(int i = 2, j = 0;i <= n;i++){
			while(j > 0 && str[i-1] != str[j])j = kmp[j];
			kmp[i] = str[i-1] == str[j] ? ++j : 0;
		}
		return kmp;
	}
	
	void run() throws Exception
	{
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}