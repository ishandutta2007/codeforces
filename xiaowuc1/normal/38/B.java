import java.io.*;
public class B38 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		int x1 = s.charAt(0) - 'a' + 1;
		int y1 = s.charAt(1) - '0';
		s = br.readLine();
		int x2 = s.charAt(0) - 'a' + 1;
		int y2 = s.charAt(1) - '0';
		int ret = 0;
		for(int x3 = 1; x3 <= 8; x3++)	{
			for(int y3 = 1; y3 <= 8; y3++)	{
				if(x3 == x1 || y3 == y1)		{
					continue;
				}
				if(x3 == x2 && y3 == y2) {
					continue;
				}
				if(knight(x1,y1,x3,y3))
					continue;
				if(knight(x2,y2,x3,y3))
					continue;
				ret++;
			}
		}
		System.out.println(ret);
	}
	public static boolean knight(int x1, int y1, int x2, int y2)		{
		int xDiff = Math.abs(x1-x2);
		int yDiff = Math.abs(y1-y2);
		return Math.min(xDiff, yDiff) == 1 && Math.max(xDiff, yDiff) == 2;
	}
}