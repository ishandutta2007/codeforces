import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class B {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int[] list = new int[n];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++)
			list[i] = Integer.parseInt(st.nextToken());
		k--;
		while(list[k] == 0)	{
			k++;
			k %= n;
		}
		pw.println(k+1);
		pw.close();
	}
}