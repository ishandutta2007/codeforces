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
//#define temo

using namespace std;

const ll N = 1507;

ll n, m, ans;

int main()
{
    cin>>n>>m;
    for (ll i = 1; i <= m; i++)
        for (ll j = 1; j <= m; j++)
            if ((i * i + j * j) % m == 0){
                ans += (n - i + m) / m * ((n - j + m) / m);

            }
    cout<<ans<<endl;
    return 0;
}