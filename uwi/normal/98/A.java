//package round78;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class A2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "AAAABB";
	
	void solve()
	{
		char[] C = in.next().toCharArray();
		int[] a = new int[6];
		for(int i = 0;i < C.length;i++){
			a[i] = C[i] - 'A';
		}
		
		int[] ord = new int[6];
		for(int i = 0;i < 6;i++)ord[i] = i;
		int[] b = new int[6];
		Set<Long> used = new HashSet<Long>();
		int ct = 0;
		do{
			for(int i = 0;i < 6;i++){
				b[i] = a[ord[i]];
			}
			if(!used.contains(enc(b))){
				ct++;
				for(int i = 0;i < 6;i++){
					if(i%2==0){
						int u = b[1]; b[1] = b[0]; b[0] = b[4]; b[4] = b[5]; b[5] = u;
					}else{
						int u = b[0]; b[0] = b[2]; b[2] = b[5]; b[5] = b[3]; b[3] = u;
					}
					for(int j = 0;j < 4;j++){
						int u = b[1]; b[1] = b[2]; b[2] = b[4]; b[4] = b[3]; b[3] = u;
						used.add(enc(b));
					}
				}
			}
		}while(nextPermutation(ord));
		
		out.println(ct);
	}
	
	public static void rotZ(int[] a)
	{
		int u = a[1]; a[1] = a[2]; a[2] = a[4]; a[4] = a[3]; a[3] = u;
	}
	
	public static void rotX(int[] a)
	{
		int u = a[1]; a[1] = a[0]; a[0] = a[4]; a[4] = a[5]; a[5] = u;
	}
	
	public static void rotY(int[] a)
	{
		int u = a[0]; a[0] = a[2]; a[2] = a[5]; a[5] = a[3]; a[3] = u;
	}
	
	public static boolean nextPermutation(int[] src)
	{
		int i;
		for(i = src.length - 2;i >= 0 && src[i] > src[i+1];i--);
		if(i == -1)return false;
		int j;
		for(j = i + 1;j < src.length && src[i] < src[j];j++);
		int d = src[i]; src[i] = src[j - 1]; src[j - 1] = d;
		for(int p = i + 1, q = src.length - 1;p < q;p++,q--){
			d = src[p]; src[p] = src[q]; src[q] = d;
		}
		return true;
	}
	
	long enc(int[] a)
	{
		long c = 0;
		for(int i = 0;i < 6;i++){
			c = c * 26 + a[i];
		}
		return c;
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
		new A2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}