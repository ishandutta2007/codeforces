#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;
#define LL long long
#define dob complex<double>
#define Abs(a) ((a) < 0 ? (-(a)) : (a))
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define Swap(a, b) ((a) ^= (b), (b) ^= (a), (a) ^= (b))
#define writeln(x) (write(x), putchar('\n'))
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int N = 2000;
void read(int &x) {
    char ch; bool flag = 0;
    for (ch = getchar(); !isdigit(ch) && ((flag |= (ch == '-')) || 1); ch = getchar());
    for (x = 0; isdigit(ch); x = (x<<1)+(x<<3)+ch-48, ch = getchar());
    x *= 1-2*flag;
}
void print(int x) {if (x > 9) print(x/10); putchar(x%10+48); }
void write(int x) {if (x < 0) putchar('-'); print(Abs(x)); }

int n, a[N+5], sum2, ans;
struct mat {
    int a[2][2];
    mat() {a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0; }
    mat operator * (const mat &b) const {
        mat ans;
        ans.a[0][0] = a[0][0]+b.a[0][0];
        ans.a[0][1] = Max(a[0][0]+b.a[0][1], a[0][1]+b.a[1][1]);
        ans.a[1][0] = Max(a[1][1]+b.a[1][0], a[1][0]+b.a[0][0]);
        ans.a[1][1] = a[1][1]+b.a[1][1];
        return ans;
    }
};
struct Segment_Tree {
    mat sgm[(N<<2)+5];
    #define lr(o) (o<<1)
    #define rr(o) (o<<1|1)
    void build(int o, int l, int r) {
        if (l == r) {
            if (a[l] == 1) sgm[o].a[0][0] = sgm[o].a[1][0] = 1;
            else sgm[o].a[0][1] = sgm[o].a[1][1] = 1;
            return;
        }
        int mid = (l+r)>>1;
        build(lr(o), l, mid), build(rr(o), mid+1, r);
        sgm[o] = sgm[lr(o)]*sgm[rr(o)];
    }
    mat query(int o, int l, int r, int a, int b) {
        if (a <= l && r <= b) return sgm[o];
        int mid = (l+r)>>1;
        if (b <= mid) return query(lr(o), l, mid, a, b);
        if (a > mid) return query(rr(o), mid+1, r, a, b);
        return query(lr(o), l, mid, a, b)*query(rr(o), mid+1, r, a, b);
    }
}T1;

void work() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]), sum2 += (a[i] == 2);
    if (sum2 == n || sum2 == 0) {writeln(n); return; }
    T1.build(1, 1, n); ans = Max(T1.sgm[1].a[0][0], T1.sgm[1].a[0][1]); ans = Max(ans, T1.sgm[1].a[1][1]);
    for (int l = 1; l <= n; l++) for (int r = l+1; r <= n; r++) {
        mat a, b, c;
        if (l != 1) a = T1.query(1, 1, n, 1, l-1);
        b = T1.query(1, 1, n, l, r);
        if (r != n) c = T1.query(1, 1, n, r+1, n);
        ans = Max(ans, a.a[0][1]+b.a[1][1]+c.a[1][1]);
        ans = Max(ans, a.a[0][0]+b.a[1][0]+c.a[1][1]);
        ans = Max(ans, a.a[0][0]+b.a[0][0]+c.a[0][1]);
    }
    writeln(ans);
}
int main() {
    work(); return 0;
}