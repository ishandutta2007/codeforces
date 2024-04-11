import java.util.*;
import java.math.*;
import java.io.*;

public class Main{
	static String s;
	static int n;
	static char tolower(char c){
		if(c < 'a'){return (char) (c + 32);}
		else{return c;}
	}
	static char toupper(char c){
		return (char) (c - 32);
	}
	public static void main(String args[]) throws IOException {
		//BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		s = in.nextLine();
		n = in.nextInt();
		String ans = "";
		for(int i = 0; i < s.length(); i++){
			char curr = tolower(s.charAt(i));
			if((int)curr < n + 97){curr = toupper(curr);}
			ans += curr;
		}
		out.println(ans);
		out.flush();
	}
}