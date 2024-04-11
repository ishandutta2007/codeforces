import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class A {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
		String s = br.readLine();
		String t = br.readLine();
		if(s.equals("front") && t.equals("1"))
			pw.println("L");
		else if(s.equals("back") && t.equals("2"))
			pw.println("L");
		else
			pw.println("R");
		pw.close();		
	}
}