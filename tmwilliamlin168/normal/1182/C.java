import java.util.*;
import java.io.*;
import static java.lang.Math.*;
public class Rough {
    static StringBuilder sb = new StringBuilder();
    static PrintWriter pw = new PrintWriter(System.out, true);
    static char[] and, tor;
    static int n, m, dp[][];
    static int dir[][] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //code goes here
        char vowel[] = {'a', 'e', 'i', 'u','o'};
        int n = sc.nextInt();
        Pair arr[] = new Pair[n];
        for (int i = 0; i < n; i++) {
            String str = sc.next();
            int cnt = 0;
            char last = '*';
            for (int j = 0; j < str.length(); j++) {
                for (int k = 0; k < 5; k++) {
                    if (str.charAt(j) == vowel[k]) {
                        cnt++;
                        last = str.charAt(j);
                    }
                }
            }
            arr[i] = new Pair(str, last, cnt);
        }
        Arrays.sort(arr);
        LinkedList<Duo> same = new LinkedList<>();
        LinkedList<Duo> dif  = new LinkedList<>();
        ArrayList<Pair > rejected  = new ArrayList<>();
        boolean last =false;
        for(int i =0;i<n-1;i++){
            if(arr[i].cnt==arr[i+1].cnt) {
                if (arr[i].end == arr[i + 1].end) {
                    same.add(new Duo(arr[i].str, arr[i + 1].str));
                    i++;
                } else
                    rejected.add(arr[i]);
            }else {
                rejected.add(arr[i]);
            }
            if(i==n-1)
                last = true;
        }
        if(!last)
            rejected.add(arr[n-1]);
        Collections.sort(rejected);
        //System.out.println(rejected);
        int sz = rejected.size();
        for(int i =0;i<sz-1;i++) {
            if(rejected.get(i).cnt==rejected.get(i+1).cnt) {
                dif.add(new Duo(rejected.get(i).str,rejected.get(i+1).str));
                i++;
            }
        }
        //for(Pair p : arr)
          //  System.out.println(p);
        //System.out.println(same);
        //System.out.println(dif);
        int cnt =0;
        while(!same.isEmpty() && !dif.isEmpty()) {
            Duo a = same.poll(),b = dif.poll();
            cnt++;
            sb.append(b.x+" "+a.x+"\n"+b.y+" "+a.y+"\n");
        }
        while(!same.isEmpty()) {
            Duo a = same.poll();
            if(same.isEmpty())
                break;
            Duo b = same.poll();
            cnt++;
            sb.append(b.x+" "+a.x+"\n"+b.y+" "+a.y+"\n");
        }
        System.out.println(cnt);
        pw.println(sb);
        pw.flush();
        pw.close();
    }

    static class Pair implements Comparable<Pair> {
        String str;
        int cnt = 0;
        char end;

        Pair(String s, char ch, int cnt) {
            str = s;
            end = ch;
            this.cnt = cnt;
        }

        public int compareTo(Pair o) {
            if (cnt != o.cnt)
                return cnt - o.cnt;
            return end - o.end;
        }

        public String toString() {
            return str + " cnt=" + cnt + " last= " + end;
        }
    }
    static class Duo {
        String x, y;
        Duo(String a,String b) {
            x=a;
            y=b;
        }
        public  String toString() { return x+" "+y;}
    }
}