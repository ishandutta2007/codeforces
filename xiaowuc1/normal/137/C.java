// k let's not fail this time
// yeah lol should actually think hahaha

import java.util.*; //steven
import java.io.*; // nick reading

public class Main { // i think sort by begin date and store max end date.
  public static void main(String[] args) throws Exception { // nick yeah you can dictate structure
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); //steven, using "br".
    int n = Integer.parseInt(br.readLine()); // nick lol thanks :D
    StringTokenizer st = new StringTokenizer(br.readLine()); //steven let's just go fast
    Pair[] list = new Pair[n]; // nick uh what are you doing you need to include the first one T_T
    for(int i = 0; i < n; ++i) { // steven
      list[i] = new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())); // nick
       if (i < n - 1) st = new StringTokenizer(br.readLine()); //steven my bad
    } // nick sgtm
    Arrays.sort(list); //steven
    int maxEndDate = -1; // nick
    int cnt = 0; //steven, this is the answer.
    for(Pair currDate: list) { // nick, for-each loop will iterate in order
        if (currDate.end < maxEndDate) cnt++; //steven else works too :P
        maxEndDate = Math.max(maxEndDate, currDate.end); // nick yeah i know :P
    } //steven
    System.out.println(cnt); // nick
  } //steven
  static class Pair implements Comparable<Pair> { // nick
        int start, end; //steven
      public Pair(int a, int b) { start = a; end = b; } // nick just one-line it
      public int compareTo(Pair o) { //steven, i have good style.
 /*        return end - o.end; // nick fine
      } //steven
  } // nick
}//steven*/
            return start - o.start; //steven, let's backtrack a bit
    } // nick
}//steven one more
} // nick



//should be start - o.start. hmm how do we fix it.