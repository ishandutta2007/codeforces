import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br;
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
	br = new BufferedReader(new InputStreamReader(System.in));
	int n = readInt();
	int max = readInt();
	PriorityQueue<State> q = new PriorityQueue<State>();
	int a = readInt();
	int b = readInt();
	for(int i = 1; i <= n; i++) {
	    int cost = a * readInt() + b * readInt();
	    q.add(new State(i, cost));
	}
	ArrayList<Integer> ret = new ArrayList<Integer>();
	while(!q.isEmpty()) {
	    State curr = q.poll();
	    if(curr.cost > max)
		break;
	    max -= curr.cost;
	    ret.add(curr.i);
	}
	System.out.println(ret.size());
	if(!ret.isEmpty()) {
	    System.out.print(ret.get(0));
	    for(int i = 1; i < ret.size(); i++)
		System.out.print(" " + ret.get(i));
	}
    }

    static class State implements Comparable<State> {
	public int i,cost;
	public State(int a, int b) {
	    i = a;
	    cost = b;
	}
	public int compareTo(State s) {
	    return cost - s.cost;
	}
    }

    public static String nextToken() throws IOException {
	while(st == null || !st.hasMoreTokens()) {
	    if(!br.ready()) {
		System.exit(0);
	    }
	    st = new StringTokenizer(br.readLine());
	}
	return st.nextToken();
    }

    public static int readInt() throws IOException {
	return Integer.parseInt(nextToken());
    }

    public static long readLong() throws IOException {
	return Long.parseLong(nextToken());
    }

}