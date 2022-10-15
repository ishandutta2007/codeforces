import java.math.*;
import java.util.*;
//import javafx.util.*;
import java.io.*;

public class Prg10 {

    PrintWriter pw = new PrintWriter(System.out);
    Random rnd = new Random();
    int a;
    long o =0, s, stt;

    void run() {
        //a = ni();
        s = nl();
        long sum=0;
        long[] m = new long[8];
        for(int q=0; q<8; q++) {
            m[q] = nl();
            sum+=m[q]*(q+1);
        }
        if(sum<=s){
            System.out.println(sum);
            return;
        }
        stt = System.currentTimeMillis();
        rec(m, 0);
        pw.print(o);
        pw.flush();
    }

    void rec(long[] m, long cur){
        if(o==s) return;
        if(System.currentTimeMillis()-stt>1400) return;
        o = Math.max(o, cur);
        for(int q=0; q<8; q++){
            if((s-cur)%(q+1)>0) continue;
            long need = (s-cur)/(q+1);
            if(m[q]>=need){
                o = s;
                return;
            }
        }
        for(long q=7; q>=0; q--){
            if(m[(int)q]==0) continue;
            if(o==s) return;
            long can = Math.min(m[(int)q], (s-cur)/(q+1));
            if(can==0) continue;
            for(long w=Math.max(1, can-10), i=0; i<10 && w<=can; w++, i++){
                m[(int)q]-=w;
                rec(m, cur+(q+1)*w);
                m[(int)q]+=w;
            }
        }
    }

    static class PyraSort {

        private static int heapSize;

        public static void sort(long[] a) {
            buildHeap(a);
            while (heapSize > 1) {
                swap(a, 0, heapSize - 1);
                heapSize--;
                heapify(a, 0);
            }
        }

        private static void buildHeap(long[] a) {
            heapSize = a.length;
            for (int i = a.length / 2; i >= 0; i--) {
                heapify(a, i);
            }
        }

        private static void heapify(long[] a, int i) {
            int l = 2 * i + 2;
            int r = 2 * i + 1;
            int largest = i;
            if (l < heapSize && a[i] < a[l]) {
                largest = l;
            }
            if (r < heapSize && a[largest] < a[r]) {
                largest = r;
            }
            if (i != largest) {
                swap(a, i, largest);
                heapify(a, largest);
            }
        }

        private static void swap(long[] a, int i, int j) {
            a[i] ^= a[j] ^= a[i];
            a[j] ^= a[i];
        }
    }

    public static void main(String[] args) {
        new Thread(null, new Runnable() {
            public void run() {
                new Prg10().run();
            }
        }, "1", 1 << 28).start();
    }

    InputStream is = System.in;
    private byte[] inbuf = new byte[1<<16];
    public int lenbuf = 0, ptrbuf = 0;

    private int readByte()
    {
        if(lenbuf == -1)throw new InputMismatchException();
        if(ptrbuf >= lenbuf){
            ptrbuf = 0;
            try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
            if(lenbuf <= 0)return -1;
        }
        return inbuf[ptrbuf++];
    }

    private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
    private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }

    private double nd() { return Double.parseDouble(ns()); }
    private char nc() { return (char)skip(); }

    private String ns()
    {
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while(!(isSpaceChar(b))){
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    private String nline(){
        int b = readByte();
        StringBuilder sb = new StringBuilder();
        while (b!=10) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    private char[] ns(int n)
    {
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while(p < n && !(isSpaceChar(b))){
            buf[p++] = (char)b;
            b = readByte();
        }
        return n == p ? buf : Arrays.copyOf(buf, p);
    }

    private char[][] nm(int n, int m)
    {
        char[][] map = new char[n][];
        for(int i = 0;i < n;i++)map[i] = ns(m);
        return map;
    }

    private int[] na(int n)
    {
        int[] a = new int[n];
        for(int i = 0;i < n;i++)a[i] = ni();
        return a;
    }

    private int ni()
    {
        int num = 0, b;
        boolean minus = false;
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-'){
            minus = true;
            b = readByte();
        }
        while(true){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }

    private long nl()
    {
        long num = 0;
        int b;
        boolean minus = false;
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-'){
            minus = true;
            b = readByte();
        }
        while(true){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
}