import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in 
    char dir = f.readLine().charAt(0);
    int d;
    if (dir=='R') d = 1;
    else d = -1;
    
    // bash
    String keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
    String req = f.readLine();
    for (char c: req.toCharArray()) {
      out.print(keyboard.charAt(keyboard.indexOf(c)-d));
    }
    out.println();

    // write to out
    out.println();
    
    // cleanup
    out.close();
    System.exit(0);
  }
}