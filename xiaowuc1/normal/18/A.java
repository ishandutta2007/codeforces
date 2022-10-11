import java.io.*;
import java.util.*;
public class A18 {
	static int[] loc;
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		loc = new int[6];
		for(int i = 0; i < 6; i++)		{
			loc[i] = Integer.parseInt(st.nextToken());
		}
		if(valid())		{
			System.out.println("RIGHT");
			return;
		}
		for(int i = 0; i < 6; i++)		{
			loc[i]--;
			if(valid())		{
				System.out.println("ALMOST");
				return;
			}
			loc[i]++;
		}
		for(int i = 0; i < 6; i++)		{
			loc[i]++;
			if(valid())		{
				System.out.println("ALMOST");
				return;
			}
			loc[i]--;
		}
		System.out.println("NEITHER");
	}
	public static boolean valid()		{
		int xDiff1 = loc[0]-loc[2];
		int yDiff1 = loc[1]-loc[3];
		int xDiff2 = loc[0]-loc[4];
		int yDiff2 = loc[1]-loc[5];
		int xDiff3 = loc[4]-loc[2];
		int yDiff3 = loc[5]-loc[3];
		int side1 = (xDiff1*xDiff1+yDiff1*yDiff1);
		int side2 = (xDiff2*xDiff2+yDiff2*yDiff2);
		int side3 = (xDiff3*xDiff3+yDiff3*yDiff3);
		int[] go = new int[]{side1, side2, side3};
		Arrays.sort(go);
		return go[0]+go[1]==go[2] && go[0] != 0 && go[1] != 0;
	}
}