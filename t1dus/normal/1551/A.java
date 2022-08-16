import static java.lang.Math.*;
import java.util.*;
import java.io.*;

public class a{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t -- > 0){
			int n = sc.nextInt();
			if(n%3 == 0){
				System.out.println(n/3+" "+n/3);
			}
			else if(n%3 == 1){
				System.out.println((n/3+1)+" "+n/3);
			}
			else{
				System.out.println(n/3+" "+(n/3+1));
			}
		}
	}
}