import java.util.*;
import java.io.*;
public class Main {
    static int n, numDist = 0;
    static String in;
    static char[] arr;
    static int[] freq = new int[26];
	public static void main (String[] args){
	    Scanner sc = new Scanner(System.in);
	    in = sc.next();
	    arr = in.toCharArray();
	    n = arr.length;
	    
	    for(int i = 0; i < n; ++i){
	        int idx = (int)(arr[i] - 'a');
	        if(++freq[idx] == 1) ++numDist;
	    }
	    
	    int one = -1;
	    for(int i = 0; i < 26; ++i){
	        if(freq[i] == 1) one = i;
	    }
	    
	    if(numDist == 1 || (numDist == 2 && n % 2 == 1 && (int)(arr[n / 2] - 'a') == one)){
	        System.out.println("Impossible");
	        return;
	    }
	    
	    if(check()) System.out.println(1);
	    else System.out.println(2);
	    if(n > -1) return;
	    
	    //if even and first half isnt palindrome
	    if(n % 2 == 0){
	        String a = in.substring(0, n / 2);
	        boolean palin = true;
	        for(int i = 0; i < a.length(); ++i){
	            if(a.charAt(i) != a.charAt(a.length() - 1 - i)) palin = false;
	        }
	        if(!palin){
	            System.out.println(1);
	            return;
	        }
	    }
	    
	    //if first half is palindrome and is even, then you can cut off the first 1/4 and put it at the back
	    if(n % 4 == 0){
	        System.out.println(1);
	        return;
	    }
	    
	    System.out.println(2);
	}
	static boolean check(){
	    //try every break point
	    for(int i = 1; i < n; ++i){
	        String s = in.substring(i, n) + in.substring(0, i);
	        if(palin(s) && !s.equals(in)) return true;
	    }
	    return false;
	}
	static boolean palin(String s){
	    for(int i = 0; i < s.length() / 2; ++i){
	        if(s.charAt(i) != s.charAt(s.length() - 1 - i)) return false;
	    }
	    return true;
	}
}