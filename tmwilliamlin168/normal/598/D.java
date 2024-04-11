import java.io.*;
import java.util.*;

public class Solution {
	static char[][] cells;
	static int[][] colors, neighbors={{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	static List<Integer> answers = new ArrayList(Arrays.asList(-1));
	static int cAns;
	
    public static void main(String args[]) {
    	Reader in = new Reader();
    	int n=in.nextInt(), m=in.nextInt(), k=in.nextInt();
    	cells = new char[n][];
    	colors = new int[n][m];
    	for(int i=0; i<n; ++i)
    		cells[i]=in.next().toCharArray();
    	int color=1;
    	for(int i=0; i<n; ++i) {
    		for(int j=0; j<m; ++j) {
    			if(cells[i][j]=='.'&&colors[i][j]==0) {
    				cAns=0;
    				dfs(i, j, color++);
    				answers.add(cAns);
    			}
    		}
    	}
    	for(; k>0; --k) {
    		int x=in.nextInt()-1, y=in.nextInt()-1;
    		System.out.println(answers.get(colors[x][y]));
    	}
    }
    
    static void dfs(int r, int c, int color) {
    	colors[r][c]=color;
    	for(int[] neighbor : neighbors) {
    		int newR=r+neighbor[0], newC=c+neighbor[1];
    		if(newR<0||newR>=cells.length||newC<0||newC>=cells[0].length)
    			continue;
    		if(cells[newR][newC]=='.'&&colors[newR][newC]==0)
    			dfs(newR, newC, color);
    		else if(cells[newR][newC]=='*')
    			++cAns;
    	}
    }
}
class Reader {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	StringTokenizer st;
	String next() {
		while(st==null||!st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch(Exception e) {}
		}
		return st.nextToken();
	}
	int nextInt() {
		return Integer.parseInt(next());
	}
}