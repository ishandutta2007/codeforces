import java.util.*;
import java.io.*;

public class Main
{
      static int lim=5050;
      static int inf=(int)1e9+7;
      static long oo=(long)1e15; 
      public static void main(String[] args)
      {
            fastio io=new fastio();
            int n=io.nextInt(),m=io.nextInt();
            long[] a=new long[n];
            int[] u=new int[m];
            int[] v=new int[m];
            long[] w=new long[m];
            
            for(int i=0;i<n;i++) a[i]=io.nextLong();
            for(int i=0;i<m;i++)
            {
                  u[i]=io.nextInt()-1;
                  v[i]=io.nextInt()-1;
                  w[i]=io.nextLong();
            }
            
            Flow solver=new Flow(0,n+m+1);
            
            long sum=0;
            for(int i=0;i<n;i++)
            {
                  solver.AddEdge(0,i+1,a[i]);
            }
            for(int i=0;i<m;i++)
            {
                  sum+=w[i];
                  solver.AddEdge(u[i]+1,n+i+1,oo);
                  solver.AddEdge(v[i]+1,n+i+1,oo);
                  solver.AddEdge(n+i+1,n+m+1,w[i]);
            }
            
            System.out.println(sum-solver.MaxFlow());
      }
      
      static class Flow
      {
            public class Edge
            {
                  int u,v;
                  long c;
                  Edge rev;
                  public Edge(int _u, int _v, long _c){ u=_u;v=_v;c=_c;}
            }
            int s,t;
            ArrayList<Edge>[] E;
            ArrayDeque<Integer> q;
            int[] dist;
            int[] was;
            Edge[] go;
            public Flow(int _s, int _t)
            {
                  s=_s;t=_t;
                  E=new ArrayList[t+1];
                  q=new ArrayDeque<Integer>();
                  dist=new int[t+1];
                  was=new int[t+1];
                  go=new Edge[t+1];
                  for(int i=0;i<=t;i++) E[i]=new ArrayList<Edge>();
            }
            public void AddEdge(int u, int v, long c)
            {
                  Edge a=new Edge(u,v,c),b=new Edge(v,u,(long)0);
                  a.rev=b;b.rev=a;
                  E[u].add(a);
                  E[v].add(b);
            }
            public boolean BFS()
            {
                  for(int i=s;i<=t;i++)
                  {
                        was[i]=0;
                        dist[i]=inf;
                  }
                  q.add(s);
                  dist[s]=0;
                  while(!q.isEmpty())
                  {
                        int u=q.poll();
                        for(Edge e:E[u])
                        {
                              if(e.c>0 && dist[e.v]>dist[u]+1)
                              {
                                    dist[e.v]=dist[u]+1;
                                    go[e.v]=e;
                                    q.add(e.v);
                              }
                        }
                  }
                  return dist[t]!=inf;
            }
            public long MaxFlow()
            {
                  long fl=0;
                  while(BFS())
                  {
                        long MinCut=inf;
                        for(int i=t;i!=s;i=go[i].u)
                        {
                              if(MinCut>go[i].c) MinCut=go[i].c;
                        }
                        for(int i=t;i!=s;i=go[i].u)
                        {
                              go[i].c-=MinCut;
                              go[i].rev.c+=MinCut;
                        }
                        fl+=MinCut;
                  }
                  return fl;
            }
      }
      
      static class fastio
      {
		public int BS = 1<<16;
		public char NC = (char)0;
		byte[] buf = new byte[BS];
		int bId = 0, size = 0;
		char c = NC;
		double num = 1;
		BufferedInputStream in;
		
		public fastio() 
		{
			in = new BufferedInputStream(System.in, BS);
		}
		
		public fastio(String s) throws FileNotFoundException 
		{
			in = new BufferedInputStream(new FileInputStream(new File(s)), BS);
		}
		
		public char nextChar()
		{
			while(bId==size) 
			{
				try 
				{
					size = in.read(buf);
				}
				catch(Exception e) 
				{
					return NC;
				}				
				if(size==-1)return NC;
				bId=0;
			}
			return (char)buf[bId++];
		}
		
		public int nextInt() 
		{
			return (int)nextLong();
		}
		
		public long nextLong() 
		{
			num=1;
			boolean neg = false;
			if(c==NC)c=nextChar();
			for(;(c<'0' || c>'9'); c = nextChar()) {
				if(c=='-')neg=true;
			}
			long res = 0;
			for(; c>='0' && c <='9'; c=nextChar()) {
				res = (res<<3)+(res<<1)+c-'0';
				num*=10;
			}
			return neg?-res:res;
		}
      }
}