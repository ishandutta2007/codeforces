import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class D {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] list = new int[n];
		for(int i = 0; i < n; i++)	{
			list[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(list);
		int start = -350;
		int pen = 0;
		int ret = 0;
		for(int out: list)	{
			if(start + out <= 360)	{
				start += out;
				ret++;
				pen += Math.max(0, start);
			}
		}
		System.out.println(ret + " " + pen);
	}
}