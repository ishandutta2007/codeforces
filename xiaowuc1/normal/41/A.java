import java.io.*;
public class A41 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(br.readLine().equals(new StringBuilder(br.readLine()).reverse().toString()) ? "YES" : "NO");
    }
}