#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int MAXN = 300000;
int n, m;
set < pair < int, pair < int, int > > > S;
set < pair < int, pair < int, int > > >::iterator I, it;
int mas[MAXN + 5];
int main()
{
    cin>>n>>m;
    for (int i = 1; i <= n; ++i)
        S.insert({i, {i, i}});
    for (int i = 1; i <= m; ++i){
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        I = S.lower_bound({l, {0, 0}});
        while (I != S.end() && (*I).F <= r){
            if ((*I).F != x){
                mas[(*I).F] = x;
                S.erase(I);
                I = S.lower_bound({l, {0, 0}});
            }
            else
                ++I;
        }
    }
    for (int i = 1; i <= n; ++i)
        cout<<mas[i]<<" ";
    return 0;
}