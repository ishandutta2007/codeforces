import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class B {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		boolean[] list = new boolean[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		while(n-- > 0)	{
			int curr = Integer.parseInt(st.nextToken());
			curr--;
			if(curr >= 0 && curr < list.length)
				list[curr] = true;
		}
		int ret = 0;
		for(boolean b: list)
			if(!b)
				ret++;
		System.out.println(ret);
	}
}