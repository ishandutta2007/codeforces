import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class C {
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
		long ret = 0;
		for(int i = 0; i < n; i++)	{
			for(int a = 0; a < 3 && list[i] >= k; a++)
				list[i] -= k;
			ret += list[i];
		}
		pw.println(ret);
		pw.close();
	}
}