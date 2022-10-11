import java.io.*;
import java.util.*;
public class AMain {
	static Map<String, Integer> map;
	public static void main(String[] args) throws IOException {
		map = new HashMap<String, Integer>();
		map.put("C", 0);
		map.put("C#", 1);
		map.put("D", 2);
		map.put("D#", 3);
		map.put("E", 4);
		map.put("F", 5);
		map.put("F#", 6);
		map.put("G", 7);
		map.put("G#", 8);
		map.put("A", 9);
		map.put("B", 10);
		map.put("H", 11);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		String a = st.nextToken();
		String b = st.nextToken();
		String c = st.nextToken();
		if(major(a,b,c))	{
			System.out.println("major");
			return;
		}
		if(major(a,c,b))	{
			System.out.println("major");
			return;
		}
		if(major(b,a,c))	{
			System.out.println("major");
			return;
		}
		if(major(b,c,a))	{
			System.out.println("major");
			return;
		}
		if(major(c,a,b))	{
			System.out.println("major");
			return;
		}
		if(major(c,b,a))	{
			System.out.println("major");
			return;
		}
		if(minor(a,b,c))	{
			System.out.println("minor");
			return;
		}
		if(minor(a,c,b))	{
			System.out.println("minor");
			return;
		}
		if(minor(b,a,c))	{
			System.out.println("minor");
			return;
		}
		if(minor(b,c,a))	{
			System.out.println("minor");
			return;
		}
		if(minor(c,a,b))	{
			System.out.println("minor");
			return;
		}
		if(minor(c,b,a))	{
			System.out.println("minor");
			return;
		}
		System.out.println("strange");
	}
	public static boolean major(String a, String b, String c)	{
		if(map.get(b) != (map.get(a)+4)%12)
			return false;
		if(map.get(c) != (map.get(a)+7)%12)
			return false;
		return true;
	}
	public static boolean minor(String a, String b, String c)	{
		if(map.get(b) != (map.get(a)+3)%12)
			return false;
		if(map.get(c) != (map.get(a)+7)%12)
			return false;
		return true;
	}
}