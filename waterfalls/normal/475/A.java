import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in 
    int k = Integer.parseInt(f.readLine());
    
    // draw
    out.println("+------------------------+");
    out.print("|");
    if (k>1) {
      for (int i=0;i<(k+1)/3;i++) out.print("O.");
      for (int i=(k+1)/3;i<11;i++) out.print("#.");
    } else {
      for (int i=0;i<k;i++) out.print("O.");
      for (int i=k;i<11;i++) out.print("#.");
    }
    out.println("|D|)");
    out.print("|");
    if (k>2) {
      for (int i=0;i<k/3;i++) out.print("O.");
      for (int i=k/3;i<11;i++) out.print("#.");
    } else {
      for (int i=0;i<(k+1)/3;i++) out.print("O.");
      for (int i=(k+1)/3;i<11;i++) out.print("#.");
    }
    out.println("|.|");
    out.print("|");
    if (k>2) out.print("O");
    else out.print("#");
    out.println(".......................|");
    out.print("|");
    for (int i=0;i<(k-1)/3;i++) out.print("O.");
    for (int i=(k-1)/3;i<11;i++) out.print("#.");
    out.println("|.|)");
    out.println("+------------------------+");
    
    // cleanup
    out.close();
    System.exit(0);
  }
}