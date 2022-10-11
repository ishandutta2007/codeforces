import java.io.*;
public class A96 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        System.out.println(s.contains("0000000") || s.contains("1111111") ? "YES" : "NO");
    }
}