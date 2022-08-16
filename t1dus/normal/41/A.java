import java.util.*;

public class a{
	public static void main(String args[]){
		Scanner inp = new Scanner(System.in);
		String s,t;
		s = inp.nextLine();
		t = inp.nextLine();
		boolean f = true;
		if(s.length() != t.length()) f = false;
		else{
			for(int i = 0; i < s.length(); i ++){
				if(s.charAt(i) != t.charAt(s.length()-1-i)){
					f = false;
				}
			}
		}
		if(f) System.out.println("YES");
		else System.out.println("NO");
	}
}