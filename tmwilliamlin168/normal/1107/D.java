import java.util.*;
import java.io.*;
public class Solution{
    public static long gcd(long a, long b){
        if(a == 0)  return b;
        return gcd(b%a, a);
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int arr[][] = new int[n][n];
        sc.nextLine();
        
        for(int i=0; i<n; i++){
            
            String s = sc.nextLine();
            
            for(int j=0; j<n/4; j++){
                char q = s.charAt(j);
                
                int t;
                if('0' <= q && q <= '9')
                    t = q - '0';
                else
                    t = (q - 'A') + 10;
                    
                //System.out.print(t+" ");
                    
                for(int k = 0; k < 4; k++){
                    int c = j*4 + k; 
                    
                    //System.out.print(+(t/(1<<(3-k))%2)+" "+c+"\t");
                    
                    arr[i][c] = (t/(1<<(3-k)))%2;
                    //System.out.print(+arr[i][c]);
                }
            }
            //System.out.println();
        }
        //System.out.println();
        
        long ans = n;
        outer: for(int i=0; i<n; i++){
            long count = 1;
            int pos = 0;
            
            for(int j=1; j<n; j++){
                if(arr[i][j] == arr[i][pos])
                    count++;
                else{
                    pos = j;
                    ans = gcd(ans, count);
                    count = 1;
                }
                //System.out.print(count);
                //System.out.print(arr[i][j]);
            }
            //System.out.println();
            ans = gcd(ans, count);
        }
        
        for(int j=0; j<n; j++){
        	long count = 1;
        	int pos = 0;
        	for(int i=1; i<n; i++){
        		if(arr[i][j] == arr[pos][j])
        			count++;
        		else{
        			pos = i;
        			ans = gcd(ans, count);
        			count = 1;
        		}
        	}
        }
        
        System.out.println(ans);
    }
}