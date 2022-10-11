import java.io.*;
public class B11 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int x = Math.abs(Integer.parseInt(br.readLine()));
		for(int i = 0; true; i++)	{
			int test = i*i+i;
			test >>= 1;
			if(test >= x && (test-x)%2==0)	{
				System.out.println(i);
				return;
			}
		}
	}
}