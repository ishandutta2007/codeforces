#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k1,k2,w,b;
        cin>>n>>k1>>k2>>w>>b;
        cout<<(w<=min(k1,k2)+abs(k1-k2)/2&&
               b<=min(n-k1,n-k2)+abs(k1-k2)/2?
               "YES\n":"NO\n");
    }
}