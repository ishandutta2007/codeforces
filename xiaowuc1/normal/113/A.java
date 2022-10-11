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
		String mA = "lios";
		String mN = "etr";
		String mV = "initis";
		String fA = "liala";
		String fN = "etra";
		String fV = "inites";
		boolean m = true;
		boolean f = true;
		ArrayList<String> list = new ArrayList<String>();
		while(st.hasMoreTokens())
			list.add(st.nextToken());
		for(String s: list)	{
			if(s.endsWith(mA) || s.endsWith(mN) || s.endsWith(mV))	{
				f = false;
			}
			else if(s.endsWith(fA) || s.endsWith(fN) || s.endsWith(fV))	{
				m = false;
			}
			else	{
				System.out.println("NO");
				return;
			}
		}
		if(!f && !m)	{
			System.out.println("NO");
			return;
		}
		if(list.size() == 1)	{
			System.out.println("YES");
			return;
		}
		int nounIndex = -1;
		for(int i = 0; i < list.size(); i++)	{
			String now = list.get(i);
			if(now.endsWith(mN) || now.endsWith(fN))	{
				if(nounIndex != -1)	{
					System.out.println("NO");
					return;
				}
				nounIndex = i;
			}
		}
		if(nounIndex == -1)	{
			System.out.println("NO");
			return;
		}
		for(int i = 0; i < nounIndex; i++)	{
			String now = list.get(i);
			if(!now.endsWith(mA) && !now.endsWith(fA))	{
				System.out.println("NO");
				return;
			}
		}
		for(int i = nounIndex+1; i < list.size(); i++)	{
			String now = list.get(i);
			if(!now.endsWith(mV) && !now.endsWith(fV))	{
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
	}
}