#define ENABLE_LL
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

#ifdef ENABLE_LL
#define int long long
#endif

#ifdef ENABLE_LL
#define I "%lld"
#define II "%lld%lld"
#define III "%lld%lld%lld"
#define IIII "%lld%lld%lld%lld"
#define IN "%lld\n"
#define IIN "%lld%lld\n"
#define IIIN "%lld%lld%lld\n"
#define IIIIN "%lld%lld%lld%lld\n"
#else
#define I "%d"
#define II "%d%d"
#define III "%d%d%d"
#define IIII "%d%d%d%d"
#define IN "%d\n"
#define IIN "%d%d\n"
#define IIIN "%d%d%d\n"
#define IIIIN "%d%d%d%d\n"
#endif

#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#define ses(a) std::cout << #a << "=" << a << " " 
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#define ses(a)
#endif
#define repe(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 
#define repb(i,a,b) for (int i=a;i>=b;i--)
typedef pair < int , int > pr;
typedef pair < pr  , int > prr;
#define L first
#define R second
template <class T> inline bool checkMin(T& a , T b) { return (a > b ? a=b,1 : 0); }
template <class T> inline bool checkMax(T& a , T b) { return (a < b ? a=b,1 : 0); }
class Scanner{ private: istream& ist;public: Scanner(istream& in):ist(in){} string next(){ string r; ist >> r; return r; } string nextLine(){ string r; getline(ist,r); return r; } int nextInt(){ int r; ist >> r; return r; } double nextDouble(){ double r; ist >> r; return r; }};
Scanner sc(cin);

const int N = 100005;
int n, A, R, M;
int a[N];

void init() {
    scanf(IIII,&n,&A,&R,&M);
    rep (i,n) scanf(I,&a[i]);
    sort(a, a+n);
}

int getCost(int k) {
    int lower=0, upper=0;
    rep (i,n) {
        if (a[i] < k) lower += k - a[i];
        if (a[i] > k) upper += a[i] - k;
    }
    int both = 0;
    if (M < A + R) both = min(lower, upper);
    lower -= both; upper -= both;
    return lower * A + upper * R + both * M;
}

void solve() {
    int low = a[0], upp = a[n-1];
    while (upp - low > 16) {
        int m1 = low + (upp - low) / 3;
        int m2 = low + (upp - low) / 3 * 2;
        int g1 = getCost(m1);
        int g2 = getCost(m2);
        if (g1 < g2) upp = m2;
        else low = m1;
    } 
    int res = getCost(low);
    repi(i, low, upp) checkMin(res, getCost(i));
    printf(IN, res);
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}