import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.StringTokenizer;


public class D{
	
	static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    }
	static class Dsu
	{	
		int n;
		int[] parent;
		int[] rank;
		
		public Dsu(int n)
		{
			this.n = n;
			parent = new int[n];
			rank = new int[n];
		}
		public void createSet()
		{
			for(int i = 0; i < n; i++)
			{
				parent[i] = i;
				rank[i] = 0;
			}
		}
		public int findParent(int x)
		{
			if(parent[x] == x)
				return x;
			parent[x] = findParent(parent[x]);
			return parent[x];
		}
		
		public void mergeSet(int a,int b)
		{
			int pa = findParent(a);
			int pb = findParent(b);
			
			if(pa == pb) return;
			
			if(rank[pa] > rank[pb])
			{
				parent[pb] = pa;
			}
			else if(rank[pa] < rank[pb])
			{
				parent[pa] = pb;
			}
			else
			{
				parent[pb] = pa;
				rank[pa]++;
			}
		}
	}
	public static int dfs(int s)
	{		
		vis[s] = true;
		Iterator<Integer> itr = ar[s].iterator();
		int max = 0;
		while(itr.hasNext())
		{
			int n = itr.next();
			if(!vis[n])
			{
				max = Math.max(max,dfs(n));
			}
			else
			{
				max = Math.max(max,val[n]);
			}
		}
		
		val[s] = max+1;
		return val[s];
		
	}
	public static boolean isCyclic(int s)
	{
		if(recStack[s] == true)
			return true;
		
		if(vis[s] == true)
			return false;
		
		vis[s] = true;
		recStack[s] = true;
		Iterator<Integer> itr = ar[s].iterator();
		while(itr.hasNext())
		{
			int n = itr.next();
			if(isCyclic(n))
			{
				return true;
			}
		}
		recStack[s] = false;
		return false;
		
		
	}
	static char mat[][];
	static List<Integer> ar[];
	static int val[];
	static boolean vis[];
	static boolean recStack[];
	public static void main(String[] args) 
	{
		OutputStream outputStream = System.out;
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(outputStream);
        int n = sc.nextInt();
        int m = sc.nextInt();
        ar = new List[n+m];
        
        
        for(int i = 0; i < n+m; i++)
        {
        	ar[i] = new ArrayList<>();
        }
        mat = new char[n][m];
        
        for(int i = 0; i < n; i++)
        {
        	mat[i] = sc.nextLine().toCharArray();
        }
        
        vis = new boolean[n+m];
        Arrays.fill(vis,false);
        
        recStack = new boolean[n+m];
        Arrays.fill(recStack,false);
        
        val = new int[n+m];
        
        Dsu d = new Dsu(n+m);
        //System.out.println("Next up finding equality");
        d.createSet();
        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < m; j++)
        	{
        		if(mat[i][j] == '=')
        		{
        			d.mergeSet(i, n+j);
        		}
        	}
        }
        //System.out.println("Next up graph building");
        int pi = -1,pj = -1;
        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < m; j++)
        	{	
        		pi = d.findParent(i);
    			pj = d.findParent(n+j);
        		if(mat[i][j] == '>')
        		{	
        			ar[pi].add(pj);
        		}
        		else if(mat[i][j] == '<')
        		{
        			ar[pj].add(pi);
        		}
        		else
        		{
        			continue;
        		}
        	}
        }
        //System.out.println("Next up cyclic nature");
        for(int i = 0; i < n+m; i++)
        {	
        	if(!vis[d.findParent(i)])
        	{	
        		if(isCyclic(d.findParent(i)))
                {
                	out.println("No");
                	out.close();
                	return;
                }
        	}
        }
        
        
        Arrays.fill(vis,false);
        //System.out.println("Next up dfs");
        for(int i = 0; i < n+m; i++)
        {	
        	if(!vis[d.findParent(i)])
        	dfs(d.findParent(i));
        }
        out.println("Yes");
        for(int i = 0; i < n; i++)
        {
        	out.print(val[d.findParent(i)]+" ");
        }
        out.println();
        for(int i = n; i < n+m; i++)
        {
        	out.print(val[d.findParent(i)]+" ");
        }
        out.close();
	}

}