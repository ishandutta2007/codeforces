import java.util.*;
import java.io.*;
public class EdA {

	public static void main(String[] args) throws Exception{
		int num = 998244353;

		// TODO Auto-generated method stub
 		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
 		PrintWriter out = new PrintWriter(System.out);
 		int t = Integer.parseInt(bf.readLine());
 		for(int i = 0;i<t;i++){
	 		long n = Long.parseLong(bf.readLine());
	 		long prod = 1;
	 		int index = 0;
	 		long sum =0;
	 		while(n > 0){
	 			if (index%2 == 0){
	 				if (n%4 == 2 || n == 4){
	 					n/=2;
	 					sum+=n;
	 				}
	 				else{
	 					n-=1;
	 					sum+=1;
	 				}
	 			}
	 			else{
	 				if (n%4 == 2 || n == 4){
	 					n/=2;
	 				}
	 				else{
	 					n-=1;
	 				}
	 			}
	 			index++;
	 		}
	 		out.println(sum);
 		}
 		
	 		
 		out.close();
 		
 		
 		
 	}
}
 	
 
//StringJoiner sj = new StringJoiner(" "); 
//sj.add(strings)
//sj.toString() gives string of those stuff w spaces or whatever that sequence is