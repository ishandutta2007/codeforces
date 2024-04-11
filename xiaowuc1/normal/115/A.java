import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class A {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int num = Integer.parseInt(br.readLine());
		int[] depth = new int[num];
		int[] last = new int[num];
		for(int i = 0; i < num; i++)	{
			int curr = Integer.parseInt(br.readLine());
			last[i] = curr;
			if(curr == -1)
				depth[i] = 1;
		}
		for(int j = 0; j < num; j++)
			for(int i = 0; i < num; i++)	{
				int curr = last[i];
				if(curr != -1)
					depth[i] = 1 + depth[curr-1];
			}
		Arrays.sort(depth);
		System.out.println(depth[num-1]);
	}
}