import java.util.*;

public class Main {
    public static void main(String[] args) {
	    Scanner scanner=new Scanner(System.in);
	
	    int w = scanner.nextInt();
	
	    if(w >= 4 && w % 2 == 0) {
    		System.out.println("YES");
	    } else {
		    System.out.println("NO");
	    }
    }
}