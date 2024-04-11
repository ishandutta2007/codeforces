import java.io.*;
import java.util.*;
public class A36 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        int n = Integer.parseInt(br.readLine());
        String s = br.readLine();
        int i;
        for(i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '1')
                break;
        }
        Set<Integer> set = new HashSet<Integer>();
        for(; i < s.length();)  {
            int j = i+1;
            while(j < s.length() && s.charAt(j) != '1') {
                j++;
            }
            if(j != s.length())     {
                set.add(j-i);
            }
            i=j;
        }
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
        pw.println(set.size() == 1 ? "YES" : "NO");
        pw.close();
    }
}