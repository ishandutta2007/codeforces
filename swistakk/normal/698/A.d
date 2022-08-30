import std.stdio;
import std.conv;
import std.algorithm;
void main() {
    int d0 = 0, d1 = 0, d2 = 0;
    int n;
    readf("%d", &n);
    foreach (i; 0 .. n) {
    	//write(i);
        int c;
        readf(" %d", &c);
        int n0 = max(d0, max(d1, d2));
        int n1 = -1;
        int n2 = -1;
        if (c & 1) {
            n1 = max(n1, max(d0, d2) + 1);
        }
        if (c & 2) {
            n2 = max(n2, max(d0, d1) + 1);
        }
        d0 = n0, d1 = n1, d2 = n2;
        //writef("%d, %d, %d\n", d0, d1, d2);
    }
    write(n - max(d0, max(d1, d2)));
}