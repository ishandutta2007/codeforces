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
		int n = Integer.parseInt(st.nextToken());
		String[] a = new String[n];
		String[] b = new String[n];
		String[] c = new String[n];
		String[] d = new String[n];
		int k = Integer.parseInt(st.nextToken());
		for(int i = 0; i < n; i++)	{
			a[i] = get(br.readLine(), k);
			if(a[i] == null)	{
				System.out.println("NO");
				return;
			}
			b[i] = get(br.readLine(), k);
			if(b[i] == null)	{
				System.out.println("NO");
				return;
			}
			c[i] = get(br.readLine(), k);
			if(c[i] == null)	{
				System.out.println("NO");
				return;
			}
			d[i] = get(br.readLine(), k);
			if(d[i] == null)	{
				System.out.println("NO");
				return;
			}
		}
		boolean aaaa = true;
		boolean aabb = true;
		boolean abab = true;
		boolean abba = true;
		for(int i = 0; i < n; i++)	{
			if(!a[i].equals(b[i]))	{
				aaaa = false;
				aabb = false;
			}
			if(!a[i].equals(c[i]))	{
				aaaa = false;
				abab = false;
			}
			if(!a[i].equals(d[i]))	{
				aaaa = false;
				abba = false;
			}
			if(!b[i].equals(c[i]))	{
				aaaa = false;
				abba = false;
			}
			if(!b[i].equals(d[i]))	{
				aaaa = false;
				abab = false;
			}
			if(!c[i].equals(d[i]))	{
				aaaa = false;
				aabb = false;
			}
		}
		if(aaaa)	{
			System.out.println("aaaa");
			return;
		}
		if(aabb)	{
			System.out.println("aabb");
			return;
		}
		if(abab)	{
			System.out.println("abab");
			return;
		}
		if(abba)	{
			System.out.println("abba");
			return;
		}
		System.out.println("NO");
	}
	public static String get(String curr, int k)	{
		int seen = 0;
		int index = curr.length() - 1;
		while(seen != k && index >= 0)	{
			switch(curr.charAt(index))	{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				seen++;
				break;
			}
			index--;
		}
		index++;
		if(seen != k)
			return null;
		return curr.substring(index);
	}
}