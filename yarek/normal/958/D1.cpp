#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair < int, int > PII;
typedef pair < LL, LL > PLL;
typedef pair < LD, LD > PDD;

#define _upgrade ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
template < typename _T > inline void _DBG(const char *s, _T x) { cerr << s << " = " << x << "\n"; }
template < typename _T, typename... args > void _DBG(const char *s, _T x, args... a) { while(*s != ',') cerr << *s++; cerr << " = " << x << ','; _DBG(s + 1, a...); }

#ifdef LOCAL
#define DBG(...) _DBG(#__VA_ARGS__, __VA_ARGS__)
#else
#define DBG(...) (__VA_ARGS__)
#define cerr if(0) cout
#endif

// ********************** CODE ********************** //

const int N = 1e3 + 7;

int cnt[N][N];

int nwd(int a, int b) {
    if(b == 0)
        return a;
    return nwd(b, a % b);
} 

vector < PII > vec;

int main()
{
    int m;
    scanf("%d\n", &m);
    while(m--) {
        int a, b, c;
        scanf("(%d+%d)/%d\n", &a, &b, &c);
        a += b;
        int d = nwd(a, c);
        a /= d;
        c /= d;
        cnt[a][c]++;
        vec.push_back({a, c});
    }
    for(int i = 0; i < sz(vec); i++)
        printf("%d ", cnt[vec[i].first][vec[i].second]);
	return 0;
}