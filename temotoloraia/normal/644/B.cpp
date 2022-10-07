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
const int MAXN = 200000;
int n, m;
ll mas[MAXN + 5];
deque < pair < ll, ll > > Q;
map < ll, int > M;
int main()
{
    cin>>n>>m;
    ll T = 0;
    for (int i = 0; i < n; ++i){
        int t, d;
        cin>>t>>d;
        M[t] = i;
        while (Q.size() > 0 && max (T, Q.front().F) + Q.front().S <= t){
            T = max (T, Q.front().F);
            T += Q.front().S;
            int I = M[Q.front().F];
            mas[I] = T;
            Q.pop_front();
        }
        if (Q.size() > m){
            mas[i] = -1;
            continue;
        }
        Q.push_back(mp(t, d));
    }
    while (Q.size() > 0){
        T = max (T, Q.front().F);
        T += Q.front().S;
        int I = M[Q.front().F];
        mas[I] = T;
        Q.pop_front();
    }
    for (int i = 0; i < n; ++i)
        cout<<mas[i]<<" ";
    return 0;
}