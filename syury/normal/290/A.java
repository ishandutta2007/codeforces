import java.util.*;
import java.math.*;
import java.io.*;

public class Main{
	public static void main(String args[]) throws IOException {
		//BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int a = in.nextInt();
		String s = "";
		if(a == 1){s = "Washington";}
		if(a == 2 || a == 6){s = "Adams";}
		if(a == 3){s = "Jefferson";}
		if(a == 4){s = "Madison";}
		if(a == 5){s = "Monroe";}
		if(a == 8){s = "Van Buren";}
		if(a == 7){s = "Jackson";}
		if(a == 9 || a == 23){s = "Harrison";}
		if(a == 10){s = "Tyler";}
		if(a == 11){s = "Polk";}
		if(a == 12){s = "Taylor";}
		if(a == 13){s = "Fillmore";}
		if(a == 14){s = "Pierce";}
		if(a == 15){s = "Buchanan";}
		if(a == 16){s = "Lincoln";}
		if(a == 17 || a == 36){s = "Johnson";}
		if(a == 18){s = "Grant";}
		if(a == 19){s = "Hayes";}
		if(a == 20){s = "Garfield";}
		if(a == 21){s = "Arthur";}
		if(a == 22 || a == 24){s = "Cleveland";}
		if(a == 25){s = "McKinley";}
		if(a == 26 || a == 32){s = "Roosevelt";}
		if(a == 27){s = "Taft";}
		if(a == 28){s = "Wilson";}
		if(a == 29){s = "Harding";}
		if(a == 30){s = "Coolidge";}
		if(a == 31){s = "Hoover";}
		if(a == 33){s = "Truman";}
		if(a == 34){s = "Eisenhower";}
		if(a == 35){s = "Kennedy";}
		if(a == 37){s = "Nixon";}
		if(a == 38){s = "Ford";}
		if(a == 39){s = "Carter";}
		if(a == 40){s = "Reagan";}
		out.println(s);
		out.flush();
	}
}