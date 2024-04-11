import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class A {
	static int[] dx = new int[]{-1,-1,-1,0,0,0,1,1,1};
	static int[] dy = new int[]{-1,0,1,-1,0,1,-1,0,1};
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		ArrayList<State> list = new ArrayList<State>();
		for(int i = 0; i < 8; i++)	{
			String s = br.readLine();
			for(int j = 0; j < 8; j++)	{
				if(s.charAt(j) == 'S')
					list.add(new State(i,j,0));
			}
		}
		LinkedList<State> q = new LinkedList<State>();
		q.add(new State(7,0,0));
		while(!q.isEmpty()){
			State curr = q.removeFirst();
			if(curr.m == 8) {
				System.out.println("WIN");
				return;
			}
			outer: for(int k = 0; k < dx.length; k++)	{
				int nx = curr.x + dx[k];
				int ny = curr.y + dy[k];
				if(nx < 0 || nx >= 8 || ny < 0 || ny >= 8)
					continue;
				for(State s: list)	{
					if(s.y == ny)	{
						int firstCan = s.x + curr.m;
						int secondCan = s.x + curr.m + 1;
						if(nx == firstCan || nx == secondCan)
							continue outer;
					}
				}
				q.addFirst(new State(nx,ny,curr.m+1));
			}
		}
		System.out.println("LOSE");
	}
	static class State	{
		public int x,y,m;
		public State(int a, int b, int c)	{
			x=a;
			y=b;
			m=c;
		}
	}
}