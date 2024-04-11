import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class A {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int e = Integer.parseInt(st.nextToken());
		boolean[] in = new boolean[n];
		boolean[] out = new boolean[n];
		int[] start = new int[e];
		int[] end = new int[e];
		int[] amt = new int[e];
		for(int i = 0; i < e; i++)	{
			st = new StringTokenizer(br.readLine());
			start[i] = Integer.parseInt(st.nextToken())-1;
			end[i] = Integer.parseInt(st.nextToken())-1;
			amt[i] = Integer.parseInt(st.nextToken());
			in[end[i]] = true;
			out[start[i]] = true;
		}
		ArrayList<Integer> retA = new ArrayList<Integer>();
		ArrayList<Integer> retB = new ArrayList<Integer>();
		ArrayList<Integer> retC = new ArrayList<Integer>();
		for(int i = 0; i < out.length; i++)	{
			if(out[i] && !in[i]){
				int curr = i;
				int ret = Integer.MAX_VALUE;
				while(true)	{
					boolean flag = true;
					for(int q = 0; q < start.length; q++)	{
						if(start[q] == curr)	{
							flag = false;
							curr = end[q];
							ret = Math.min(ret, amt[q]);
						}
					}
					if(flag)
						break;
				}
				retA.add(i+1);
				retB.add(curr+1);
				retC.add(ret);
			}
		}
		System.out.println(retA.size());
		for(int i = 0; i < retA.size(); i++)	{
			System.out.println(retA.get(i) + " " + retB.get(i) + " " + retC.get(i));
		}
	}
}