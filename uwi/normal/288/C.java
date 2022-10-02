//package round177;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		out.println((long)n*(n+1));
		int[] a = new int[n+1];
		
		outer:
		for(int d = 1;d <= 1000000;d*=2){
			int ct = 0;
			for(int i = 0;i <= n;i++){
				if((i&d)!=0)ct++;
			}
			
			for(int i = n/2/d*2*d;i >= 0;i -= 2*d){
				for(int j = d-1;j >= 0;j--){
					if(i+j <= n){
						if(ct == 0)continue outer;
						a[i+j] |= d;
						ct--;
					}
				}
			}
		}
//		BitSet bs = new BitSet();
//		for(int i = 0;i <= n;i++){
//			bs.set(a[i]);
//			if((i&a[i]) != 0){
//				throw new AssertionError(i +" " + a[i]);
//			}
//		}
//		if(bs.cardinality() != n+1){
//			throw new AssertionError("kassu");
//		}
		for(int i = 0;i <= n;i++){
			if(i > 0)out.print(" ");
			out.print(a[i]);
		}
		out.println();
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
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}