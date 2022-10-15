import java.io.*;
import javafx.util.*;

import javax.swing.*;
import java.util.*;
import java.math.*;

public class Test77 {

    Random rnd = new Random();
    PrintWriter pw = new PrintWriter(System.out);
    int a;

    void run(){
        a = ni();
        long cntz = 0, max, l=-1, r = 1000000001, min = Integer.MAX_VALUE;
        for(; l+1!=r;){
            long mid = (l+r)/2;
            System.out.println("> "+mid);
            System.out.flush();
            if(ni()==1) l = mid;
            else r = mid;
            cntz++;
        }
        max = r;
        HashSet<Integer> h = new HashSet<>();
        HashSet<Long> del = new HashSet<>();
        ArrayList<Integer> gg = new ArrayList<>();
        for(int q=0; q<a; q++) gg.add(q+1);
        Collections.shuffle(gg);
        Collections.shuffle(gg);
        for(int q=0; cntz<=60; cntz++, q++){
            if(h.size()==a || del.size()==1) break;
            int c = gg.get(q);
            System.out.println("? "+c);
            System.out.flush();
            long num = ni(); min = Math.min(min, num);
            long d = max - num;
            if(d==0) continue;
            ArrayList<Long> ll = GetDel.get(d);
            if(q==0){
                for(long i : ll){
                    long kolvo = (max-min)/i+1;
                    if(kolvo<=a) del.add(i);
                }
            }
            else{
                HashSet<Long> rem = new HashSet<>();
                for(long i : del) if(!ll.contains(i) || (max-min)/i+1>a) rem.add(i);
                for(long i : rem) del.remove(i);
            }
        }
        long diff = 0;
        for(long u : del) diff = u;
        System.out.println("! "+(max-(a-1)*diff)+" "+diff);
        System.out.flush();
    }

    static class GetDel {

        static ArrayList<Integer> k = new ArrayList<>();

        static ArrayList<Long> get(long ch){
            k = new ArrayList<>();
            long c=1;
            int ks=0, i, del = 1;
            ArrayList<Long> otv = new ArrayList<>(), t = f(ch);
            ks = k.size();
            i = t.size();
            int[] itr = new int[ks];
            long[][] pow = new long[i][40];
            for(int q=0; q<i; q++){
                for(int w=0; w<=k.get(q); w++) pow[q][w] = (long)Math.pow(t.get(q), w);
            }
            for(int q=0; q<ks; q++) del*=k.get(q)+1;
            for(; del>0; c=1, del--){
                for(int w=ks-1; w>=0; w--){
                    if(++itr[w]>k.get(w)) itr[w]=0;
                    else break;
                }
                for(int u=0; u<ks; u++) c*= pow[u][itr[u]];
                otv.add(c);
            }
            Collections.sort(otv);
            return otv;
        }


        static ArrayList<Long> f(long a){
            ArrayList<Long> l = new ArrayList<>();
            for(long d = 2; d*d<=a || d<4; d++){
                if(a%d<1){
                    int u=0;
                    for(; a%d<1; ) {a/=d; u++;}
                    l.add(d);
                    k.add(u);
                }
            }
            for(long d=6; d*d<=a; d+=6){
                if(a%(d-1)<1){
                    int u=0;
                    for(; a%(d-1)<1; ) {a/=(d-1); u++;}
                    l.add(d-1);
                    k.add(u);
                }
                if(a%(d+1)<1){
                    int u=0;
                    for(; a%(d+1)<1; ) {a/=(d+1); u++;}
                    l.add(d+1);
                    k.add(u);
                }
            }
            if(a>1) {
                if(l.size()<1) {l.add(a); k.add(1);}
                else{
                    if(l.get(l.size()-1)!=a) {l.add(a); k.add(1);}
                    else{
                        k.add(k.get(k.size()-1)+1);
                        k.remove(k.size()-2);
                    }
                }
            }
            return l;
        }
    }

    public static void main(String[] args) {
        new Test77().run();
    }

    InputStream is = System.in;
    private byte[] inbuf = new byte[1024];
    public int lenbuf = 0, ptrbuf = 0;

    private int readByte() {
        if (lenbuf == -1) throw new InputMismatchException();
        if (ptrbuf >= lenbuf) {
            ptrbuf = 0;
            try {
                lenbuf = is.read(inbuf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (lenbuf <= 0) return -1;
        }
        return inbuf[ptrbuf++];
    }

    private boolean isSpaceChar(int c) {
        return !(c >= 33 && c <= 126);
    }

    private int skip() {
        int b;
        while ((b = readByte()) != -1 && isSpaceChar(b)) ;
        return b;
    }

    private double nd() {
        return Double.parseDouble(ns());
    }

    private char nc() {
        return (char) skip();
    }

    private String ns() {
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while (!(isSpaceChar(b))) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    private char[] ns(int n) {
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while (p < n && !(isSpaceChar(b))) {
            buf[p++] = (char) b;
            b = readByte();
        }
        return n == p ? buf : Arrays.copyOf(buf, p);
    }

    private char[][] nm(int n, int m) {
        char[][] map = new char[n][];
        for (int i = 0; i < n; i++) map[i] = ns(m);
        return map;
    }

    private int[] na(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = ni();
        return a;
    }

    private int ni() {
        int num = 0, b;
        boolean minus = false;
        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-' || b==':')) ;
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        while (true) {
            if (b >= '0' && b <= '9') {
                num = num * 10 + (b - '0');
            } else {
                return minus ? -num : num;
            }
            b = readByte();
        }
    }

    private long nl() {
        long num = 0;
        int b;
        boolean minus = false;
        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        while (true) {
            if (b >= '0' && b <= '9') {
                num = num * 10 + (b - '0');
            } else {
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
}