import java.util.*;
public class Main {
  static ArrayList<Integer>[] appears;
  static HashSet<String> ret;
  public static void main(String[] args) throws Exception {
    appears = new ArrayList[2005];
    for(int i = 0; i < appears.length; i++) appears[i] = new ArrayList<Integer>();
    ret = new HashSet<String>();
    Scanner scan = new Scanner(System.in);
    int n = scan.nextInt();
    for(int i = 1; i <= n; i++) appears[scan.nextInt()].add(i);
    dfs(0, new LinkedList<Integer>());
    if(ret.size() == 3) {
      System.out.println("YES");
      for(String out: ret) System.out.println(out);
    }
    else {
      System.out.println("NO");
    }
  }

  public static void dfs(int index, LinkedList<Integer> curr) {
    if(ret.size() == 3) return;
    if(index == 2002) {
      StringBuilder sb = new StringBuilder();
      for(int out: curr) sb.append(out + " ");
      ret.add(sb.toString().trim());
      return;
    }
    if(appears[index].isEmpty()) dfs(index+1, curr);
    else {
      ArrayList<ArrayList<Integer>> lists = new ArrayList<ArrayList<Integer>>();
      lists.add(appears[index]);
      if(appears[index].size() > 1) {
        ArrayList<Integer> temp = copy(appears[index]);
        swap(temp, 0, temp.size()-1);
        lists.add(temp);
      }
      if(appears[index].size() > 2) {
        ArrayList<Integer> temp = copy(appears[index]);
        swap(temp, 0, 1);
        lists.add(temp);
      }
      for(ArrayList<Integer> append: lists) {
        LinkedList<Integer> next = new LinkedList<Integer>();
        for(int out2: curr) next.addLast(out2);
        for(int out2: append) next.addLast(out2);
        dfs(index+1, next);
      }
    }
  }

  public static void swap(ArrayList<Integer> temp, int i, int j) {
    int iCurr = temp.get(i);
    int jCurr = temp.get(j);
    temp.set(i, jCurr);
    temp.set(j, iCurr);
  }
 
  public static ArrayList<Integer> copy(ArrayList<Integer> list) {
    ArrayList<Integer> ret = new ArrayList<Integer>();
    for(int out: list) ret.add(out);
    return ret;
  }

}