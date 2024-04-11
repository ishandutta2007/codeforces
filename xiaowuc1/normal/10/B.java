import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class AMain {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int size = Integer.parseInt(st.nextToken());
		int center = (size+1)/2;
		center--;
		boolean[][] taken = new boolean[size][size];
		st = new StringTokenizer(br.readLine());
		while(n-- > 0)	{
			int curr = Integer.parseInt(st.nextToken());
			int max = Integer.MAX_VALUE;
			int row = -1;
			int col = -1;
			for(int i = 0; i < size; i++)	{
				outer: for(int j = 0; j + curr <= size; j++)		{
					int currCost = 0;
					for(int k = 0; k < curr && currCost <= max; k++)	{
						if(taken[i][j+k])
							continue outer;
						currCost += Math.abs(center - i) + Math.abs(center - j - k);
					}
					if(currCost < max)	{
						max = currCost;
						row = i;
						col = j;
					}
				}
			}
			if(row == -1)
				System.out.println(-1);
			else	{
				System.out.println((row+1) + " " + (col+1) + " " + (col+curr));
				for(int k = 0; k < curr; k++)
					taken[row][col+k] = true;
			}
		}
	}
}