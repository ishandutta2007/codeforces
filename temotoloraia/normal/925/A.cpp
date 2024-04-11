#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const ll N = 300005;
int n, m, p, q, v;
set < int > S1, S2;
set < int >::iterator I;
int main()
{
    cin>>n>>m>>p>>q>>v;
    while (p--){
        int x;
        cin>>x;
        S1.insert (x);
    }
    while (q--){
        int x;
        cin>>x;
        S2.insert (x);
    }
    int Q;
    cin>>Q;
    while (Q--){
        int a, b, x, y;
        cin>>a>>b>>x>>y;
        if (a == x){
            cout<<abs (b - y)<<endl;
            continue;
        }
        int ans = 1e9;
        I = S1.lower_bound (b);
        if (I != S1.end())
            ans = min (ans, abs (x - a) + abs ((*I) - b) + abs ((*I) - y));
        if (I != S1.begin()){I--;
            ans = min (ans, abs (x - a) + abs ((*I) - b) + abs ((*I) - y));}
        I = S1.lower_bound (y);
        if (I != S1.end())
            ans = min (ans, abs (x - a) + abs ((*I) - b) + abs ((*I) - y));
        if (I != S1.begin()){I--;
            ans = min (ans, abs (x - a) + abs ((*I) - b) + abs ((*I) - y));}



        I = S2.lower_bound (b);
        if (I != S2.end())
            ans = min (ans, (abs (x - a) - 1) / v + 1 + abs ((*I) - b) + abs ((*I) - y));
        if (I != S2.begin()){I--;
            ans = min (ans, (abs (x - a) - 1) / v + 1 + abs ((*I) - b) + abs ((*I) - y));}
        I = S2.lower_bound (y);
        if (I != S2.end())
            ans = min (ans, (abs (x - a) - 1) / v + 1 + abs ((*I) - b) + abs ((*I) - y));
        if (I != S2.begin()){I--;
            ans = min (ans, (abs (x - a) - 1) / v + 1 + abs ((*I) - b) + abs ((*I) - y));}
        cout<<ans<<endl;
    }
    return 0;
}