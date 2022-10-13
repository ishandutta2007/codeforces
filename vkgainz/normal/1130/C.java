import java.util.ArrayList;
import java.util.Scanner;

public class water {
	static ArrayList<Point> orig = new ArrayList<Point>();
	static ArrayList<Point> fin = new ArrayList<Point>();
	static boolean [][] visited;
	static int [][] ter;
	static int n;
	//check for impossible
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		n = sc.nextInt();
		visited=  new boolean[n][n];
		Point a = new Point(sc.nextInt()-1,sc.nextInt()-1);
		Point b= new Point(sc.nextInt()-1,sc.nextInt()-1);
		ter =new int[n][n];
		for(int i=0;i<n;i++) {
			String s = sc.next();
			for(int j=0;j<n;j++) {
				if(s.substring(j,j+1).equals("0")) {
					ter[i][j] = 0;
				}
				else {
				ter[i][j] = 1;
				}
			}
		}
		dfsorig(a.x,a.y);
//		System.out.println(orig.size());
//		System.out.println(orig.size());
//		for(int i=0;i<orig.size();i++) {
//			System.out.println(orig.get(i).x + " " + orig.get(i).y);
//		}
		visited = new boolean[n][n];
		dfsfin(b.x,b.y);
//		System.out.println(fin.size());
		int min = distance(fin.get(0),orig.get(0));
//		System.out.println(min);
		for(int i=0;i<orig.size();i++) {
			for(int j=0;j<fin.size();j++) {
				min = Math.min(min, distance(orig.get(i),fin.get(j)));
			}
		}
		System.out.println(min);
	}
	private static void dfsfin(int row, int col) {
		// TODO Auto-generated method stub
		if(visited[row][col]) {
			return;
		}
//		System.out.println("bayus");
		visited[row][col]=true;
		fin.add(new Point(row,col));
		int [] dx = {-1,0,1,0};
		int [] dy = {0,-1,0,1};
		for(int i=0;i<4;i++) {
			if(inbound(row+dx[i],col+dy[i]) && !visited[row+dx[i]][col+dy[i]]) {
				if(ter[row+dx[i]][col+dy[i]] == 0) {
					
				dfsfin(row+dx[i],col+dy[i]);
				}
		}
		}
	}
	public static void dfsorig(int row, int col) {
		
		if(visited[row][col]) {
			return;
		}
//		System.out.println("bayus");
		visited[row][col]=true;
		orig.add(new Point(row,col));
		int [] dx = {-1,0,1,0};
		int [] dy = {0,-1,0,1};
		for(int i=0;i<4;i++) {
			if(inbound(row+dx[i],col+dy[i]) && !visited[row+dx[i]][col+dy[i]]) {
				if(ter[row+dx[i]][col+dy[i]] == 0) {
					
				dfsorig(row+dx[i],col+dy[i]);
				}
		}
		}
		
	}
	public static int distance(Point a,Point b) {
		return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
	}
	public static boolean inbound(int row,int col) {
		return row>=0 && col>=0 && row<n && col < n;
	}
	static class Point{
		private int x;
		private int y;
		public Point(int x, int y) {
			this.x=x;
			this.y=y;
		}
	}
	

}