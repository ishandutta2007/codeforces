import java.lang.reflect.Array;
import java.util.*;
public class susbus {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		String math = sc.next();
		int [] bayus = new int [(math.length()+1)/2];
		for (int i=0;i<bayus.length;i++) {
			bayus[i] = Integer.parseInt(math.substring(2*i, 2*i+1));
		}
		Arrays.sort(bayus);

		String a = "";
		for (int i=0;i<bayus.length-1;i++) {
			a = a+bayus[i]+"+";
		}
		a=a+bayus[bayus.length-1];
		System.out.println(a);
	}

}