import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
public class D {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int d = 1;
		int currTime = 0;
		boolean am = true;
		n--;
		String s = br.readLine();
		am = s.charAt(7) == 'a';
		currTime = time(s.substring(1,3), s.substring(4,6), am);
		int num = 1;
		while(n-- > 0)	{
			s = br.readLine();
			boolean newAm = s.charAt(7) == 'a';
			int newTime = time(s.substring(1,3), s.substring(4,6), newAm);
			if(newTime < currTime)	{
				d++;
				num=1;
			}
			else if(newTime == currTime)	{
				if(num == 10)	{
					d++;
					num = 1;
				}
				else	{
					num++;
				}
			}
			else	{
				num = 1;
			}
			currTime = newTime;
		}
		System.out.println(d);
	}
	public static int time(String hour, String min, boolean am)	{
		if(hour.equals("12") && min.equals("00") && am)	{
			return -90001;
		}
		int t = 0;
		if(!hour.equals("12"))
			t += Integer.parseInt(hour)*60;
		t += Integer.parseInt(min);
		if(!am)
			t += 9000;
		return t;
	}
}