import java.io.*;
import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Reader in = new Reader();
		int a=in.nextInt(), b=in.nextInt(), c=in.nextInt(), m=in.nextInt();
		List<Integer> usb = new ArrayList<Integer>(), ps = new ArrayList<Integer>();
		for(int i=0; i<m; ++i) {
			int val=in.nextInt();
			if(in.next().equals("USB"))
				usb.add(val);
			else
				ps.add(val);
		}
		Collections.sort(usb);
		Collections.sort(ps);
		int nComp=0, i_usb=0, i_ps=0;
		long tPrice=0;
		for(; i_usb<usb.size()&&i_usb<a; ++nComp, tPrice+=usb.get(i_usb++));
		for(; i_ps<ps.size()&&i_ps<b; ++nComp, tPrice+=ps.get(i_ps++));
		for(int i=0; i<c&&(i_usb<usb.size()||i_ps<ps.size()); ++i, ++nComp) {
			if(i_usb>=usb.size())
				tPrice+=ps.get(i_ps++);
			else if(i_ps>=ps.size())
				tPrice+=usb.get(i_usb++);
			else if(usb.get(i_usb)>ps.get(i_ps))
				tPrice+=ps.get(i_ps++);
			else
				tPrice+=usb.get(i_usb++);
		}
		System.out.println(nComp+" "+tPrice);
	}
	
	static class Reader {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String next() {
			while(st==null||!st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch(Exception e) {}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
	}
}