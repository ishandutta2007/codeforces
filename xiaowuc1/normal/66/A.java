import java.io.*;
import java.math.*;
public class A66 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BigInteger x = new BigInteger(br.readLine());
        if(x.compareTo(BigInteger.valueOf(Byte.MIN_VALUE)) >= 0 && x.compareTo(BigInteger.valueOf(Byte.MAX_VALUE)) <= 0)    {
            System.out.println("byte");
        }
        else if(x.compareTo(BigInteger.valueOf(Short.MIN_VALUE)) >= 0 && x.compareTo(BigInteger.valueOf(Short.MAX_VALUE)) <= 0) {
            System.out.println("short");
        }
        else if(x.compareTo(BigInteger.valueOf(Integer.MIN_VALUE)) >= 0 && x.compareTo(BigInteger.valueOf(Integer.MAX_VALUE)) <= 0) {
            System.out.println("int");
        }
        else if(x.compareTo(BigInteger.valueOf(Long.MIN_VALUE)) >= 0 && x.compareTo(BigInteger.valueOf(Long.MAX_VALUE)) <= 0)   {
            System.out.println("long");
        }
        else    {
            System.out.println("BigInteger");
        }
    }
}