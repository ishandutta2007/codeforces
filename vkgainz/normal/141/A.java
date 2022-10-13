import java.util.*;

public class susbus{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		String b = sc.next();
		String d = sc.next();
		String c = a+b;
		char[] chars = c.toCharArray();
        Arrays.sort(chars);
        
        
        
        
        String sortedO = new String(chars);
        char[] susbus = d.toCharArray();
        Arrays.sort(susbus);
        String sortedT = new String(susbus);
        if (sortedT.equals(sortedO)) {
        	System.out.println("YES");
        }
        else {
        	System.out.println("NO");
        }
		
		
	}
	
}