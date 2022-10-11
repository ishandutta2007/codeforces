import java.io.*;
import java.util.*;
public class A35 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		int n = Integer.parseInt(br.readLine());
		for(int i = 0; i < 3; i++)	{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			if(a==n)
				n=b;
			else if(b==n)
				n=a;
		}
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
		pw.println(n);
		pw.close();
	}
}