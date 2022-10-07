#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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

const int N = 1e5 + 5;

ll n;
vector < ll > V;

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for (ll k = 1; k * k <= n; k++)
        if (n % k == 0){
            ll X = n * (n / k - 1) / 2 + n / k;
            V.pb (X);
            if (k * k < n){
                X = n * (k - 1) / 2 + k;
                V.pb (X);
            }
        }
    sort (V.begin(), V.end());
    for (int i = 0; i < (int)V.size(); i++)
        cout<<V[i]<<" ";
    cout<<endl;
    return 0;
}