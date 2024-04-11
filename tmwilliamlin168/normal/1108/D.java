import java.io.*;
import java.util.*;

public class Solution{
    public static char diverseFun(char a, char b){
        char ans='a';
        if((a=='R'||a=='B') &&((b=='R')||(b=='B')))
            ans='G';
        else if(((a=='G')||(a=='B')) &&((b=='G')||(b=='B')))
            ans='R';
        else if(((a=='G')||(a=='R')) &&((b=='G')||(b=='R')))
            ans='B';
        return ans;
    }
    public static void main(String args[]) throws IOException{
    
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        String str=br.readLine();
        char arr[]=str.toCharArray();
        int i=0,val=0;
        for(int k=0;k<n-1;k++){
            char ch='a';
            if(arr[k]==arr[k+1]){
                if(k!=n-2)
                    ch=arr[k+2];
                else
                    ch=arr[k];
                arr[k+1]=diverseFun(arr[k],ch);
                val++;
            }
        }   
        System.out.println(val+"\n"+String.valueOf(arr));
    }
}