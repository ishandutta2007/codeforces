
import java.io.BufferedOutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;

public class A {
	private Scanner in;
	private PrintWriter out;
	
	public void solve()
	{
		int n = ni();
		String[] name = new String[n];
		int[] score = new int[n];
		
		for(int i = 0;i < n;i++){
			name[i] = in.next();
			score[i] = ni();
		}
		
		HashMap<String, Integer> info = new HashMap<String, Integer>();
		for(int i = 0;i < n;i++){
			Integer val = info.get(name[i]);
			if(val == null)val = 0;
			val += score[i];
			info.put(name[i], val);
		}
		
		int max = Integer.MIN_VALUE;
		HashSet<String> wins = new HashSet<String>();
		for(Map.Entry<String, Integer> entry : info.entrySet()){
			if(entry.getValue() > max){
				max = entry.getValue();
				wins.clear();
				wins.add(entry.getKey());
			}else if(entry.getValue() == max){
				wins.add(entry.getKey());
			}
		}
		
		info = new HashMap<String, Integer>();
		for(int i = 0;i < n;i++){
			Integer val = info.get(name[i]);
			if(val == null)val = 0;
			val += score[i];
			if(val >= max && wins.contains(name[i])){
				out.println(name[i]);
				break;
			}
			info.put(name[i], val);
		}
	}
	
	public void run() throws Exception
	{
//		in = new Scanner(new StringReader("3 mike 3 mike 2 a 5"));
		in = new Scanner(System.in);
		System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
		out = new PrintWriter(System.out);
		
//		int n = in.nextInt();
		int n = 1;
		for(int i = 1;i <= n;i++){
			long t = System.currentTimeMillis();
			solve();
			out.flush();
//			System.err.printf("%04d/%04d %7d%n", i, n, System.currentTimeMillis() - t);
		}
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new A().run();
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