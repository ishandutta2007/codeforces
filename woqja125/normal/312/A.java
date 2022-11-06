import java.util.*;
import java.io.*;
import java.lang.*;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		try {
			String st = in.readLine();
			int a = Integer.parseInt(st);
			for(int i=1; i<=a; i++)
			{
				boolean x, y;
				String str = in.readLine();
				x=(str.indexOf("miao.")==0);
				y=(str.lastIndexOf("lala.")+5==str.length());
				if(x == y) System.out.println("OMG>.< I don\'t know!");
				else if(x)System.out.println("Rainbow\'s");
				else if(y)System.out.println("Freda\'s");
			}
		} catch (IOException e) {
		}

	}

}