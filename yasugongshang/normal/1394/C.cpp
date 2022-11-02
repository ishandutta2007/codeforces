#include<bits/stdc++.h>

#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sd(a) scanf("%lf",&a)
#define sc(a) scahf("%c",&a);
#define ss(a) scanf("%s",a)
#define pi(a) printf("%d\n",a)
#define pl(a) printf("%lld\n",a)
#define pc(a) putchar(a)
#define ms(a) memset(a,0,sizeof(a))
#define repi(i, a, b) for(register int i=a;i<=b;++i)
#define repd(i, a, b) for(register int i=a;i>=b;--i)
#define reps(s) for(register int i=head[s];i;i=Next[i])
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define pii pair<int,int>
#define mii unordered_map<int,int>
#define msi unordered_map<string,int>
#define lowbit(x) ((x)&(-(x)))
#define ce(i, r) i==r?'\n':' '
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define INF 0x3f3f3f3f
#define pr(x) cout<<#x<<": "<<x<<endl
using namespace std;

inline int qr() {
    int f = 0, fu = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')fu = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        f = (f << 3) + (f << 1) + c - 48;
        c = getchar();
    }
    return f * fu;
}

const int N = 5e5 + 10;
char s[N];
int n;
int maxa, mina = INF, maxb, minb = INF, mxd = -INF, mnd = INF;

inline pii check(int x) {
    int minx = max(0, maxa - x), maxx = mina + x, miny = max(0, maxb - x), maxy = minb + x, mind = mxd - x, maxd = mnd + x;
    if (minx > maxx || miny > maxy || mind > maxd || miny - maxx > maxd || maxy - minx < mind)return {-1, -1};
    if (maxd >= maxy - minx && mind <= miny - maxx)return {maxx, maxy};
    if (maxd <= maxy - maxx)return {maxx, maxx + maxd};
    if (maxd <= maxy - minx)return {maxy - maxd, maxy};
    if (mind >= maxy - maxx)return {maxy - mind, maxy};
    if (mind >= miny - maxx)return {maxx, maxx + mind};
}

int main() {
    n = qr();
    repi(i, 1, n) {
        ss(s + 1);
        int l = strlen(s + 1);
        int a = count(s + 1, s + 1 + l, 'N'), b = l - a;
        mina = min(mina, a), maxa = max(maxa, a);
        minb = min(minb, b), maxb = max(maxb, b);
        mnd = min(mnd, b - a), mxd = max(mxd, b - a);
    }
    int l = 0, r = 2e5;
    while (l < r) {
        int mid = (l + r) >> 1;
        check(mid).fi == -1 ? (l = mid + 1) : (r = mid);
    }
    pi(l);
    pii ans = check(l);
    repi(i, 1, ans.fi)pc('N');
    repi(i, 1, ans.se)pc('B');
    return 0;
}