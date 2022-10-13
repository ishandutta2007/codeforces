import java.util.*;

public class susbus {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long T = sc.nextLong();
        int [] prices = new int[n];
        long sum=0;
        for(int i=0;i<n;i++) {
        	prices[i] = sc.nextInt();
//        	System.out.print(prices[i] + " ");
        	sum+=prices[i];
        }
       int [] left = new int[n];
       int [] right = new int[n];
       for(int i=0;i<n-1;i++) {
    	   right[i] = i+1;
    	   left[i+1] = i;
       }
       right[n-1]=0;
       left[0] = n-1;
       
       
//        System.out.println(numMoves);
//        System.out.println(T);
        int temp = n;
        long numMoves=0;
        int currIndex=0;
        while(n>0) {
        	numMoves+=(T/sum)*n;
        	T=T%sum;
        while(sum>T) {
        	
        	if(prices[currIndex]>T) {
        		
        		left[right[currIndex]]=left[currIndex]; //???
        		right[left[currIndex]]=right[currIndex]; //?????
        		n--;
        		sum-=prices[currIndex];
        	}
        	else {
        		T=T-prices[currIndex];
//        		System.out.println(T);
        		numMoves++;
        	}
//        	System.out.println(currIndex);
        	currIndex = right[currIndex];
        	
        }
        }
        System.out.println(numMoves);
    }
   

}