//package round160;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D5 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int K = ni(), n = ni(), maxb = ni(), t = ni();
		t = Math.min(maxb+2, t);
		cur = new int[maxb+1]; // [last][length]=minpos
		pre = new int[maxb+1]; // [last][length]=minpos
		pp = new int[maxb+1];
		for(int i = 0;i < K;i++){
			int[] a = na(n);
			out.println(go(a, maxb, t));
		}
	}
	
	int[] cur; // [last][length]=minpos
	int[] pre; // [last][length]=minpos
	int[] pp;
	
	int go(int[] a, int maxb, int t)
	{
		for(int v : a)pp[v]++;
		int[][] pos = new int[maxb+1][];
		int n = a.length;
		for(int i = 1;i <= maxb;i++){
			if(pp[i] > 0)pos[i] = new int[pp[i]];
		}
		for(int i = n-1;i >= 0;i--){
			pos[a[i]][--pp[a[i]]] = i;
		}
		
		int I = Integer.MAX_VALUE / 2;
		Arrays.fill(pre, I);
		for(int i = 1;i <= maxb;i++){
			if(pos[i] == null)continue;
//			if(pos[i].length == 0)continue;
			System.arraycopy(pre, 0, cur, 0, maxb+1);
			if(pos[i][0] < cur[1])cur[1] = pos[i][0];
//			cur[1] = Math.min(cur[1], pos[i][0]);
//				Arrays.fill(cur, I);
			int len = pos[i].length;
			for(int j = 1;j <= i;j++){
				if(pre[j] == I)break;
//					cur[j] = Math.min(cur[j], pre[j]);
				int rem = pre[j] % n;
				int ind = Arrays.binarySearch(pos[i], rem);
				if(ind < 0)ind = -ind-1;
				int nex = ind >= len ? pre[j]-rem+n+pos[i][0] : pre[j]-rem+pos[i][ind];
				
//				int nex = next(pre[j], pos[i], n);
				if(nex < cur[j+1] && nex < (long)n*t){
					cur[j+1] = nex;
				}
			}
			int[] dum = cur; cur = pre; pre = dum;
//			tr(pre);
		}
		for(int j = maxb;j >= 1;j--){
			if(pre[j] != I)return j;
		}
		return -1;
	}
	
	int next(int cur, int[] pos, int n)
	{
		int ind = Arrays.binarySearch(pos, (int)(cur % n));
		if(ind < 0)ind = -ind-1;
		if(ind >= pos.length){
			return cur/n*n+n+pos[0];
		}else{
			return cur/n*n+pos[ind];
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
	
	public static void main(String[] args) throws Exception { new D5().run(); }
	
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
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}