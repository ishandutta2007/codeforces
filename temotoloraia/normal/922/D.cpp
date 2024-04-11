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
const int N = 100005;
const double INF = 1e8;
int n;
pair < double, pair < ll, ll > > P[N];
ll ans;
int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++){
        string s;
        cin>>s;
        for (int j = 0; j < s.size(); j++){
            if (s[j] == 's')
                P[i].S.F++;
            else if (s[j] == 'h'){
                P[i].S.S++;
                ans += P[i].S.F;
            }
        }
        double x = P[i].S.F;
        double y = P[i].S.S;
        P[i].F = INF;
        if (x != 0)
            P[i].F = y / x;
    }
    sort (P + 1, P + n + 1);
    ll S = 0;
    for (int i = 1; i <= n; i++){
        ans += S * P[i].S.S;
        S += P[i].S.F;
    }
    cout<<ans<<endl;
    return 0;
}