import java.io.*;
import java.math.*;
import java.util.*;
public class A99 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        if(s.indexOf(".") == -1)            {
            if(s.charAt(s.length()-1) == '9')   {
                System.out.println("GOTO Vasilisa.");
                return;
            }
            System.out.println(s);
            return;
        }
        BigInteger first = new BigInteger(s.substring(0,s.indexOf(".")));
        if(first.mod(BigInteger.TEN).equals(BigInteger.valueOf(9))){
            System.out.println("GOTO Vasilisa.");
            return;
        }
        String other = s.substring(s.indexOf(".")+1);
        if(other.charAt(0) >= '5')
            first=first.add(BigInteger.ONE);
        System.out.println(first);
    }
}