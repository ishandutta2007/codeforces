/*
If you want to aim high, aim high
Don't let that studying and grades consume you
Just live life young
******************************
What do you think? What do you think?
1st on Billboard, what do you think of it
Next is a Grammy, what do you think of it
However you think, Im sorry, but shit, I have no fcking interest
*******************************
I'm standing on top of my Monopoly board
That means I'm on top of my game and it don't stop
til my hip don't hop anymore
https://www.a2oj.com/Ladder16.html
*******************************
Shining through the city with a little funk and soul
*******************************
300iq as writer = Sad!
*/
import java.util.*;
import java.io.*;
import java.math.*;

   public class x1423B
   {
      static ArrayDeque<Edge>[] edges;
      public static void main(String hi[]) throws Exception
      {
         FastScanner infile = new FastScanner();
         N = infile.nextInt();
         int M = infile.nextInt();
         edges = new ArrayDeque[N+1];
         for(int i=1; i <= N; i++)
            edges[i] = new ArrayDeque<Edge>();
         ArrayList<Integer> times = new ArrayList<Integer>();
         while(M-->0)
         {
            int a = infile.nextInt();
            int b = infile.nextInt();
            int c = infile.nextInt();
            edges[a].add(new Edge(b, c));
            times.add(c);
         }
         Collections.sort(times);
         if(!works(times.get(times.size()-1)))
            System.out.println(-1);
         else
         {
            int low = 0;
            int high = times.size()-1;
            while(low != high)
            {
               int mid = (low+high)/2;
               int d = times.get(mid);
               if(works(d))
                  high = mid;
               else
                  low = mid+1;
            }
            System.out.println(times.get(low));
         }
      }
      static int N;
      public static boolean works(int d)
      {
         MaxFlow mfmc = new MaxFlow(N+N+2, N+N+1, N+N+2);
         for(int a=1; a <= N; a++)
            for(Edge e: edges[a])
               if(e.val <= d)
                  mfmc.addEdge(a, e.to+N, 1);
         for(int a=1; a <= N; a++)
         {
            mfmc.addEdge(N+N+1, a, 1);
            mfmc.addEdge(a+N, N+N+2, 1);
         }
         long flow = mfmc.mfmc();
         return flow == N;
      }
   }
   class Edge
   {
      public int to;
      public int val;
      
      public Edge(int a, int b)
      {
         to = a;
         val = b;
      }
   }
   class MaxFlow
   {
      public int N, source, sink;
      public ArrayList<Edge>[] edges;
      private int[] depth;
      
      public MaxFlow(int n, int x, int y)
      {
         N = n;
         source = x;
         sink = y;
         edges = new ArrayList[N+1];
         for(int i=1; i <= N; i++)
            edges[i] = new ArrayList<Edge>();
         depth = new int[N+1];
      }
      public void addEdge(int from, int to, int cap)
      {
         Edge forward = new Edge(from, to, cap);
         Edge backward = new Edge(to, from, 0);
         forward.residual = backward;
         backward.residual = forward;
         edges[from].add(forward);
         edges[to].add(backward);
      }
      public int mfmc()
      {
         int res = 0;
         int[] magic = new int[N+1];
         while(assignDepths())
         {
            int flow = dfs(source, Integer.MAX_VALUE/2, magic);
            while(flow > 0)
            {
               res += flow;
               flow = dfs(source, Integer.MAX_VALUE/2, magic);
            }
            magic = new int[N+1];
         }
         return res;
      }
      private boolean assignDepths()
      {
         Arrays.fill(depth, -69);
         ArrayDeque<Integer> q = new ArrayDeque<Integer>();
         q.add(source);
         depth[source] = 0;
         while(q.size() > 0)
         {
            int curr = q.poll();
            for(Edge e: edges[curr])
               if(e.capacityLeft() > 0 && depth[e.to] == -69)
               {
                  depth[e.to] = depth[curr]+1;
                  q.add(e.to);
               }
         }
         return depth[sink] != -69;
      }
      private int dfs(int curr, int bottleneck, int[] magic)
      {
         if(curr == sink)
            return bottleneck;
         for(; magic[curr] < edges[curr].size(); magic[curr]++)
         {
            Edge e = edges[curr].get(magic[curr]);
            if(e.capacityLeft() > 0 && depth[e.to]-depth[curr] == 1)
            {
               int val = dfs(e.to, Math.min(bottleneck, e.capacityLeft()), magic);
               if(val > 0)
               {
                  e.augment(val);
                  return val;
               }
            }
         }
         return 0;  //no flow
      }
      private class Edge
      {
         public int from, to;
         public int flow, capacity;
         public Edge residual;
         
         public Edge(int f, int t, int cap)
         {
            from = f;
            to = t;
            capacity = cap;
         }
         public int capacityLeft()
         {
            return capacity-flow;
         }
         public void augment(long val)
         {
            flow += val;
            residual.flow -= val;
         }
      }
   }
   class FastScanner 
   {
        private int BS = 1 << 16;
        private char NC = (char) 0;
        private byte[] buf = new byte[BS];
        private int bId = 0, size = 0;
        private char c = NC;
        private double cnt = 1;
        private BufferedInputStream in;
 
        public FastScanner() {
            in = new BufferedInputStream(System.in, BS);
        }
 
        public FastScanner(String s) {
            try {
                in = new BufferedInputStream(new FileInputStream(new File(s)), BS);
            } catch (Exception e) {
                in = new BufferedInputStream(System.in, BS);
            }
        }
 
        private char getChar() {
            while (bId == size) {
                try {
                    size = in.read(buf);
                } catch (Exception e) {
                    return NC;
                }
                if (size == -1) return NC;
                bId = 0;
            }
            return (char) buf[bId++];
        }
 
        public int nextInt() {
            return (int) nextLong();
        }
 
        public int[] nextInts(int N) {
            int[] res = new int[N];
            for (int i = 0; i < N; i++) {
                res[i] = (int) nextLong();
            }
            return res;
        }
 
        public long[] nextLongs(int N) {
            long[] res = new long[N];
            for (int i = 0; i < N; i++) {
                res[i] = nextLong();
            }
            return res;
        }
 
        public long nextLong() {
            cnt = 1;
            boolean neg = false;
            if (c == NC) c = getChar();
            for (; (c < '0' || c > '9'); c = getChar()) {
                if (c == '-') neg = true;
            }
            long res = 0;
            for (; c >= '0' && c <= '9'; c = getChar()) {
                res = (res << 3) + (res << 1) + c - '0';
                cnt *= 10;
            }
            return neg ? -res : res;
        }
 
        public double nextDouble() {
            double cur = nextLong();
            return c != '.' ? cur : cur + nextLong() / cnt;
        }
 
        public double[] nextDoubles(int N) {
            double[] res = new double[N];
            for (int i = 0; i < N; i++) {
                res[i] = nextDouble();
            }
            return res;
        }
 
        public String next() {
            StringBuilder res = new StringBuilder();
            while (c <= 32) c = getChar();
            while (c > 32) {
                res.append(c);
                c = getChar();
            }
            return res.toString();
        }
 
        public String nextLine() {
            StringBuilder res = new StringBuilder();
            while (c <= 32) c = getChar();
            while (c != '\n') {
                res.append(c);
                c = getChar();
            }
            return res.toString();
        }
 
        public boolean hasNext() {
            if (c > 32) return true;
            while (true) {
                c = getChar();
                if (c == NC) return false;
                else if (c > 32) return true;
            }
        }
    }