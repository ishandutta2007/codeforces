import java.io.*;
import java.util.*;
public class C5 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] s = br.readLine().toCharArray();
		int best = 0;
		int numBest = 0;
		int last = -1;
		LinkedList<Integer> list = new LinkedList<Integer>();
		for(int i = 0; i < s.length; i++)	{
			if(s[i] == '(')	{
				list.addLast(i);
			}
			else if(list.isEmpty()){
				last = i;
			}
			else	{
				list.removeLast();
				int now = i-(list.isEmpty()?last:list.peekLast());
				if(now == best)	{
					numBest++;
				}
				if(now > best)	{
					best = now;
					numBest = 1;
				}
			}
		}
		if(best == 0)	{
			System.out.println("0 1");
		}
		else	{
			System.out.println(best + (best%2) + " " + numBest);
		}
	}
}