import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in 
    StringTokenizer st = new StringTokenizer(f.readLine());
    int n = Integer.parseInt(st.nextToken());
    int l = Integer.parseInt(st.nextToken());
    int x = Integer.parseInt(st.nextToken());
    int y = Integer.parseInt(st.nextToken());
    ArrayList<Integer> marks = new ArrayList<Integer>();
    st = new StringTokenizer(f.readLine());
    for (int i=0;i<n;i++) marks.add(Integer.parseInt(st.nextToken()));
    
    // check if x can be made
    boolean xFound = false;
    boolean yFound = false;
    for (int i=0;i<n;i++) if (Collections.binarySearch(marks,marks.get(i)+x)>=0) xFound = true;
    for (int i=0;i<n;i++) if (Collections.binarySearch(marks,marks.get(i)+y)>=0) yFound = true;
    
    // check
    if (xFound && yFound) out.println(0);
    else if (xFound) {
      out.println(1);
      out.println(y);
    } else if (yFound) {
      out.println(1);
      out.println(x);
    } else {
      ArrayList<Integer> xNeeds = new ArrayList<Integer>();
      for (int i=0;i<n;i++) {
        if (marks.get(i)>x) xNeeds.add(marks.get(i)-x);
        if (marks.get(i)+x<l) xNeeds.add(x+marks.get(i));
      }
      ArrayList<Integer> yNeeds = new ArrayList<Integer>();
      for (int i=0;i<n;i++) {
        if (marks.get(i)>y) yNeeds.add(marks.get(i)-y);
        if (marks.get(i)+y<l) yNeeds.add(y+marks.get(i));
      }
      Collections.sort(xNeeds);
      Collections.sort(yNeeds);
      int inBoth = -1;
      for (int i: xNeeds) if (Collections.binarySearch(yNeeds,i)>=0) {
        inBoth = i;
        break;
      }
      if (inBoth==-1) {
        out.println(2);
        out.println(x+" "+y);
      } else {
        out.println(1);
        out.println(inBoth);
      }
    }
    
    // cleanup
    out.close();
    System.exit(0);
  }
}