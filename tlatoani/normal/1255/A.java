import java.util.*;
import java.io.*;

public class A601{
   public static void main(String[] args) throws IOException{
      BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
      PrintWriter out = new PrintWriter(System.out);
      
      int t = Integer.parseInt(f.readLine());
      
      for(int q = 0; q < t; q++){
         StringTokenizer st = new StringTokenizer(f.readLine());
         
         int a = Integer.parseInt(st.nextToken());
         int b = Integer.parseInt(st.nextToken());
         
         int d = Math.abs(a-b);
         
         int count = 0;
         count += d/5;
         d = d%5;
         count += d/2;
         d = d%2;
         count += d;
         
         out.println(count);
      }
      
      out.close();
   }
}