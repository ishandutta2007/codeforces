import javafx.scene.layout.Priority;

import java.io.*;
import java.lang.reflect.Array;
import java.net.Inet4Address;
import java.util.*;
import java.lang.*;
import java.util.HashMap;
import java.util.PriorityQueue;
public class templ implements Runnable {
    static class pair implements Comparable
    {
        int f,s;
        pair(int fi,int se)
        {
            f=fi;
            s=se;
        }
        public int compareTo(Object o)
        {
            pair pr=(pair)o;
            if(f>pr.f)
                return 1;
            else
                return -1;
        }
        public boolean equals(Object o)
        {
            pair ob=(pair)o;
            int ff;
            int ss;
            if(o!=null)
            {
                ff=ob.f;
                ss=ob.s;
                if((ff==this.f)&&(ss==this.s))
                    return true;
            }
            return false;
        }
        public int hashCode()
        {
            return (this.f+" "+this.s).hashCode();
        }
    }
    public class triplet implements Comparable
    {
        int f,s;
        int t;
        triplet(int f,int s,int t)
        {
            this.f=f;
            this.s=s;
            this.t=t;
        }
        public boolean equals(Object o)
        {
            triplet ob=(triplet)o;
            int ff,ss;
            int tt;
            if(o!=null)
            {
                ff=ob.f;
                ss=ob.s;
                tt=ob.t;
                if((ff==this.f)&&(ss==this.s)&&(tt==this.t))
                    return true;
            }
            return false;
        }
        public int hashCode()
        {
            return (this.f+" "+this.s+" "+this.t).hashCode();
        }
        public int compareTo(Object o)
        {
            triplet tr=(triplet)o;
            if(t>tr.t)
                return 1;
            else
                return -1;
        }
    }
    int par[];
    int rank[];
    int find(int x)
    {
        if(x!=par[x])
            par[x]=find(par[x]);
        return par[x];
    }
    void union(int x,int y)
    {
        int a=find(x);
        int b=find(y);
        if(a==b)
            return;
        if(rank[a]>rank[b])
            par[b]=a;
        else if(rank[b]>rank[a])
            par[a]=b;
        else
        {
            par[a]=b;
            rank[b]++;
        }
    }
    public static void main(String args[])throws Exception
    {
        new Thread(null,new templ(),"templ",1<<27).start();
    }
    public void run()
    {
        try
        {
            InputReader in = new InputReader(System.in);
            PrintWriter out = new PrintWriter(System.out);
            int n=in.ni();
            int m=in.ni();
            par=new int[n+1];
            rank=new int[n+1];
            for(int i=1;i<=n;i++)
                par[i]=i;
            PriorityQueue<triplet>pq=new PriorityQueue<>();
            for(int i=1;i<=m;i++)
            {
                int u=in.ni();
                int v=in.ni();
                int w=in.ni();
                pq.add(new triplet(u,v,w));
            }
            int ans=0;
            while(!pq.isEmpty())
            {
                triplet t=pq.remove();
                ArrayList<triplet>al=new ArrayList<>();
                al.add(t);
                while(!pq.isEmpty())
                {
                    triplet tt=pq.remove();
                    if(tt.t==t.t)
                    {
                        al.add(tt);
                    }
                    else
                    {
                        pq.add(tt);
                        break;
                    }
                }
                int k=0;
                for(triplet tt : al)
                {
                    if(find(tt.f)==find(tt.s))
                        k++;
                }
                for(triplet tt : al)
                {
                    int x=find(tt.f);
                    int y=find(tt.s);
                    if(x==y)
                        continue;
                    else
                    {
                        union(x,y);
                        k++;
                    }
                }
                ans+=(al.size()-k);
            }
            out.println(ans);
            out.close();
        }
        catch(Exception e){
            return;
        }
    }
    static class InputReader {

        private final InputStream stream;
        private final byte[] buf = new byte[8192];
        private int curChar, snumChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (snumChars == -1)
                throw new InputMismatchException();
            if (curChar >= snumChars) {
                curChar = 0;
                try {
                    snumChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (snumChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int ni() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long nl() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public int[] nextIntArray(int n) {
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = ni();
            }
            return a;
        }

        public String readString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public String nextLine() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isEndOfLine(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private boolean isEndOfLine(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }

    }
}