import java.util.*;

public class Solution{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		long n=sc.nextLong();
		long save=n;
		HashSet<Long>hh=new HashSet<>();
		while(true){
			n+=1;
			while(n%10==0)n/=10;
			if(hh.contains(n))break;
			hh.add(n);
		}
		hh.add(save);
// 		System.out.println(hh);
		System.out.println(hh.size());
	}
}