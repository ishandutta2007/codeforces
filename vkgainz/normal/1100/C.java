import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class blink {
	static int n;
	static int r;
	public static void main(String[] args) throws IOException {
//		Scanner sc = new Scanner(new File("blink.in"));
//		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("blink.out")));
		Scanner sc = new Scanner(System.in);
		n=sc.nextInt();
		 r = sc.nextInt();
		double a = Math.sin(2*Math.PI/n);
		double b = Math.cos(Math.PI/n);
		double R = r*a/(2*b-a);
		System.out.println(R);
	
	
	}
}