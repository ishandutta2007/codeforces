import java.io.*;
import java.util.*;
public class A74 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        PriorityQueue<State> q = new PriorityQueue<State>();
        while(n-- > 0)  {
            StringTokenizer st = new StringTokenizer(br.readLine());
            q.add(new State(st.nextToken(), 100*Integer.parseInt(st.nextToken()) - 50*Integer.parseInt(st.nextToken()) + Integer.parseInt(st.nextToken()) + Integer.parseInt(st.nextToken()) + Integer.parseInt(st.nextToken()) + Integer.parseInt(st.nextToken()) + Integer.parseInt(st.nextToken())));
        }
        System.out.println(q.peek());
    }
    static class State implements Comparable<State>     {   
        public String name;
        public int val;
        public State(String a, int b)       {
            name = a;
            val = b;
        }
        public int compareTo(State s)   {
            return s.val-val;
        }
        public String toString()    {
            return name;
        }
    }
}