//package round21;


import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class C {
	private IntReader in;
	private PrintWriter out;
//	private String INPUT = "4 1 2 3 3";
//	private String INPUT = "5 1 2 3 4 5";
//	private String INPUT = "100000 " + add("0 ", 100000);
	private String INPUT = "";
	
	public void solve()
	{
		int n = in.ni();
		int[] a = new int[n];
		long sum = 0;
		for(int i = 0;i < n;i++){
			a[i] = in.ni();
			sum += a[i];
		}
		if(sum % 3 != 0){
			out.println(0);
			return;
		}
		long targ = sum / 3;
		
		long psum = 0;
		ArrayList<Integer> front = new ArrayList<Integer>();
		for(int i = 0;i < n;i++){
			psum += a[i];
			if(psum == targ){
				front.add(i);
			}
		}
		
		psum = 0;
		ArrayList<Integer> back = new ArrayList<Integer>();
		for(int i = n - 1;i >= 0;i--){
			psum += a[i];
			if(psum == targ){
				back.add(i);
			}
		}
		Collections.reverse(back);
		
		long ret = 0;
		for(int f : front){
			int ind = Collections.binarySearch(back, f + 2);
			if(ind < 0)ind = -ind-1;
			ret += back.size() - ind;
		}
		
		out.println(ret);
	}
	
	public void run() throws Exception
	{
		in = INPUT.isEmpty() ? new IntReader(System.in) : new IntReader(new ByteArrayInputStream(INPUT.getBytes()));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new C().run();
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
	}
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
	
	public static String add(String str, int k)
	{
		StringBuilder mul = new StringBuilder(str);
		StringBuilder ret = new StringBuilder();
		for(int i = k;i > 0;i >>= 1){
			if((i & 1) == 1)ret.append(mul);
			mul.append(mul);
		}
		return ret.toString();
	}
}