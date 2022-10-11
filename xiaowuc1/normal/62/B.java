import java.io.*;
import java.util.*;
public class B62 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		String s = br.readLine();
		int[] count = new int[26];
		for(int i = 0; i < s.length(); i++)
			count[s.charAt(i)-'a']++;
		int[][] index = new int[26][];
		for(int i = 0; i < index.length; i++)
			index[i] = new int[count[i]];
		Arrays.fill(count, 0);
		for(int i = 0; i < s.length(); i++)	{
			index[s.charAt(i)-'a'][count[s.charAt(i)-'a']++] = i;
		}
		while(n-- > 0)	{
			long ret = 0;
			String test = br.readLine();
			for(int i = 0; i < test.length(); i++)	{
				if(index[test.charAt(i)-'a'].length == 0)
					ret += test.length();
				else	{
					int loc = Arrays.binarySearch(index[test.charAt(i)-'a'], i);
					if(loc < 0)	{
						loc = -loc;
						loc--;
						//System.out.println("Character " + test.charAt(i) + " has index " + i);
						int best = Integer.MAX_VALUE;
						if(loc < index[test.charAt(i)-'a'].length)	{
							//System.out.println(index[test.charAt(i)-'a'][loc]);
							best = Math.min(best, Math.abs(i - index[test.charAt(i)-'a'][loc]));
						}
						if(loc > 0)	{
							//System.out.println(index[test.charAt(i)-'a'][loc-1]);
							best = Math.min(best, Math.abs(i - index[test.charAt(i)-'a'][loc-1]));
						}
						ret += best;
					}
				}
			}
			System.out.println(ret);
		}
	}
}