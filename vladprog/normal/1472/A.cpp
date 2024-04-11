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
        int w,h,n;
        cin>>w>>h>>n;
        int a=1;
        while(w%2==0)
            w/=2,a*=2;
        int b=1;
        while(h%2==0)
            h/=2,b*=2;
        cout<<(a*b>=n?"YES\n":"NO\n");
    }
}