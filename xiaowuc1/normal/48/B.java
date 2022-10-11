import java.io.*;
import java.util.*;
public class AMain {
	static StreamTokenizer br;
	static boolean[][] valid;
	public static void main(String[] args) throws IOException {
		br = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		valid = new boolean[readInt()][readInt()];
		for(int i = 0; i < valid.length; i++)
			for(int j = 0; j < valid[i].length; j++)
				valid[i][j] = readInt() == 1;
		int sizeR = readInt();
		int sizeC = readInt();
		int ret = Integer.MAX_VALUE;
		for(int i = 0; i < valid.length; i++)	{
			for(int j = 0; j < valid[i].length; j++)	{
				if(i + sizeR > valid.length || j + sizeC > valid[i].length)
					continue;
				int curr = 0;
				for(int k = 0; k < sizeR; k++)	{
					for(int l = 0; l < sizeC; l++)	{
						if(valid[i+k][j+l])
							curr++;
					}
				}
				ret = Math.min(curr, ret);
			}
		}
		for(int i = 0; i < valid.length; i++)	{
			for(int j = 0; j < valid[i].length; j++)	{
				if(i + sizeC > valid.length || j + sizeR > valid[i].length)
					continue;
				int curr = 0;
				for(int k = 0; k < sizeC; k++)	{
					for(int l = 0; l < sizeR; l++)	{
						if(valid[i+k][j+l])
							curr++;
					}
				}
				ret = Math.min(curr, ret);
			}
		}
		System.out.println(ret);
	}
	public static int readInt() throws IOException	{
		br.nextToken();
		return (int)br.nval;
	}
}