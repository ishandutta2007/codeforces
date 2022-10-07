#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define LL long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int MAXN = 100000;
int n, m;
vector < int > v[MAXN + 5], p[MAXN + 5];
int main()
{
    cin>>n>>m;
    for (int i = 1; i <= n; ++i){
        v[i].pb(0);
        p[i].pb(0);
        for (int j = 1; j <= m; ++j){
            int x;
            cin>>x;
            v[i].pb(x);
            p[i].pb(0);
        }
    }
    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= m; ++j){
            if (i < n && v[i][j] <= v[i + 1][j])
                p[i][j] = p[i + 1][j];
            else
                p[i][j] = i;
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            p[i][1] = max (p[i][1], p[i][j]);
    int Q;
    cin>>Q;
    while (Q--){
        int l, r;
        cin>>l>>r;
        if (p[l][1] >= r)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}