import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            BigInteger n = new BigInteger(br.readLine());
            BigInteger k = n.divide(BigInteger.valueOf(2));
            BigInteger result = k.multiply(k.add(BigInteger.valueOf(1)));
            result = result.multiply((k.multiply(BigInteger.valueOf(2)).add(BigInteger.valueOf(1))));
            result = result.divide(BigInteger.valueOf(3)).multiply(BigInteger.valueOf(4));

            System.out.println(result);
        }
    }
}