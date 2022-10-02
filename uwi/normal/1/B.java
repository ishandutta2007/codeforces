

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class B {
	private Scanner in;
	private PrintWriter out;
	
	public void solve()
	{
		String str = in.next();
		
		List<String> sp = new ArrayList<String>();
		StringBuilder sb = null;
		int kind = -1;
		for(int i = 0;i < str.length();i++){
			char c = str.charAt(i);
			if(c >= 'A' && c <= 'Z' && kind != 0){
				if(sb != null){
					sp.add(sb.toString());
				}
				sb = new StringBuilder();
				kind = 0;
			}
			if(c >= '0' && c <= '9' && kind != 1){
				if(sb != null){
					sp.add(sb.toString());
				}
				sb = new StringBuilder();
				kind = 1;
			}
			sb.append(c);
		}
		sp.add(sb.toString());
		if(sp.size() == 2){
			// BC23
			String bc = sp.get(0);
			int v = 0;
			for(int i = 0;i < bc.length();i++){
				v = 26 * v + (bc.charAt(i) - 'A' + 1);
			}
			
			out.println("R" + sp.get(1) + "C" + Integer.toString(v));
		}else{
			// R23C55
			
			int v = Integer.parseInt(sp.get(3));
			StringBuilder sbb = new StringBuilder();
			for(;v > 0;v/=26){
				v--;
				sbb.append((char)((v % 26) + 'A'));
			}
			sbb.reverse();
			
			out.println(sbb.toString() + sp.get(1));
		}
		
		out.flush();
	}
	
	public void run() throws Exception
	{
//		in = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("input.txt"))));
//		out = new PrintWriter(new FileWriter(new File("output.txt")));
//		in = new Scanner(new StringReader("2\nR23C55\nR26C26\nZ26"));
		in = new Scanner(System.in);
//		System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
		out = new PrintWriter(System.out);
		
		int n = in.nextInt();
//		int n = 1;
		for(int i = 1;i <= n;i++){
			long t = System.currentTimeMillis();
			solve();
//			System.err.printf("%04d/%04d %7d%n", i, n, System.currentTimeMillis() - t);
		}
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new B().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
	private void tra(int[] a) {System.out.println(Arrays.toString(a));}
	private void tra(int[][] a)
	{
		for(int[] e : a){
			System.out.println(Arrays.toString(e));
		}
	}
	
}