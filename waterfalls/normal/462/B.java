import java.io.*;
import java.util.*;

public class Main {
  // main
  public static void main(String [] args) throws IOException {
    // makes the reader and writer
    BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    
    // read in n,k,cards
    StringTokenizer st = new StringTokenizer(f.readLine());
    int n = Integer.parseInt(st.nextToken());
    long k = Long.parseLong(st.nextToken());
    HashMap<Character,Long> coins = new HashMap<Character,Long>();
    char[] cards = f.readLine().toCharArray();
    for (int i=0;i<n;i++) {
      if (!coins.containsKey(cards[i])) coins.put(cards[i],0L);
      coins.put(cards[i],coins.get(cards[i])+1);
    }
    
    // sort values down, add squares until run out
    ArrayList<Long> nums = new ArrayList<Long>(coins.values());
    Collections.sort(nums);
    Collections.reverse(nums);
    long total = 0;
    int count = 0;
    while (k>0) {
      if (nums.get(count)<=k) total+=nums.get(count)*nums.get(count);
      else total+=k*k;
      k-=nums.get(count);
      count+=1;
    }

    // write to out
    out.println(total);
    
    // cleanup
    out.close();
    System.exit(0);
  }
}