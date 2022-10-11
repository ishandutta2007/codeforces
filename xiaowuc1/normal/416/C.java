import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

import static java.lang.Math.min;
import static java.lang.Math.max;

/*
br = new BufferedReader(new FileReader("input.txt"));
pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
br = new BufferedReader(new InputStreamReader(System.in));
pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
 */

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			State[] list = new State[n];
			for(int i = 0; i < n; i++) {
				list[i] = new State(readInt(), readInt());
			}
			int m = readInt();
			Room[] rooms = new Room[m];
			for(int i = 0; i < m; i++) {
				rooms[i] = new Room(i+1, readInt());
			}
			Arrays.sort(rooms);
			int ret = 0;
			boolean[] used = new boolean[n];
			ArrayList<Answer> ans = new ArrayList<Answer>();
			for(Room room: rooms) {
				int best = -1;
				for(int i = 0; i < n; i++) {
					if(used[i]) continue;
					if(list[i].hold > room.cap) continue;
					if(best == -1 || list[best].pay < list[i].pay) {
						best = i;
					}
				}
				if(best != -1) {
					ret += list[best].pay;
					used[best] = true;
					ans.add(new Answer(best+1, room.index));
				}
			}
			pw.println(ans.size() + " " +ret);
			for(Answer out: ans) {
				pw.println(out);
			}
		}
		pw.close();
	}

	static class Answer {
		public int request, room;
		public String toString() {
			return request + " " + room;
		}
		public Answer(int a, int b) {
			request = a;
			room = b;
		}
	}
	
	static class Room implements Comparable<Room> {
		public int index, cap;
		public Room(int a, int b) {
			index = a;
			cap = b;
		}
		public int compareTo(Room r) {
			return cap - r.cap;
		}
	}
	
	static class State {
		public int hold, pay;
		public State(int a, int b){
			hold = a;
			pay = b;
		}
	}
	
	private static void exitImmediately()	{
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}

	private static String nextToken() throws IOException	{
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}