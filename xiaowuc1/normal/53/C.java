import java.io.*;
import java.util.*;
public class C53 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		LinkedList<Integer> list = new LinkedList<Integer>();
		for(int i = 1; i <= n; i++)
			list.addLast(i);
		ArrayList<Integer> ret = new ArrayList<Integer>();
		while(!list.isEmpty())	{
			ret.add(list.removeFirst());
			if(!list.isEmpty())
				ret.add(list.removeLast());
		}
		for(int i = 0; i < ret.size()-1; i++)
			System.out.print(ret.get(i) + " ");
		System.out.println(ret.get(ret.size()-1));
	}
}