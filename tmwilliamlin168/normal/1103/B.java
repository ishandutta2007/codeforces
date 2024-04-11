import java.io.*;
import java.util.*;


public class d{



   public static void main(String[] args) {
      MyScanner sc = new MyScanner();
      out = new PrintWriter(new BufferedOutputStream(System.out));
      
      while(true) {
          String input = sc.nextLine();
          if(input.equals("start")) {
              int x = 2;
              int y = 1;
              for(int i=0; i<30; i++) {
                  out.println("? "+x+" "+y);
                  out.flush();
                  String result = sc.nextLine();
                  if(result.equals("y")) {
                      break;
                  } else {
                      x*=2;
                      y*=2;
                  }
              }
              if(y==(int)Math.pow(2,30)) {
                  out.println("! "+1);
                  out.flush();
                  continue;
              }
              int left = y+1;
              int right = x;
              while(left!=right) {
                  int mid = (left+right)/2;
                  x = (left+right)/4;
                  y = (left+right)/2;
                  out.println("? "+x+" "+y);
                  out.flush();
                  String result = sc.nextLine();
                  if(result.equals("x")) {
                      right = mid;
                  } else {
                      left = mid+1;
                  }
              }
              out.println("! "+left);
              out.flush();

          } else {
              out.close();
              break;
          }
      }
      

      
      
      // Start writing your solution here. -------------------------------------
   
      /*
      int n      = sc.nextInt();        // read input as integer
      long k     = sc.nextLong();       // read input as long
      double d   = sc.nextDouble();     // read input as double
      String str = sc.next();           // read input as String
      String s   = sc.nextLine();       // read whole line as String

      int result = 3*n;
      out.println(result);                    // print via PrintWriter
      */

      // Stop writing your solution here. -------------------------------------
      out.close();
   }

   //-----------PrintWriter for faster output---------------------------------
   public static PrintWriter out;
      
   //-----------MyScanner class for faster input----------
   public static class MyScanner {
      BufferedReader br;
      StringTokenizer st;
 
      public MyScanner() {
         br = new BufferedReader(new InputStreamReader(System.in));
      }
 
      String next() {
          while (st == null || !st.hasMoreElements()) {
              try {
                  st = new StringTokenizer(br.readLine());
              } catch (IOException e) {
                  e.printStackTrace();
              }
          }
          return st.nextToken();
      }
 
      int nextInt() {
          return Integer.parseInt(next());
      }
 
      long nextLong() {
          return Long.parseLong(next());
      }
 
      double nextDouble() {
          return Double.parseDouble(next());
      }
 
      String nextLine(){
          String str = "";
	  try {
	     str = br.readLine();
	  } catch (IOException e) {
	     e.printStackTrace();
	  }
	  return str;
      }

   }
   //--------------------------------------------------------
}