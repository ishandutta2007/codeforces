#include<bits/stdc++.h>

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
        int n;
        cin>>n;
        int p0=0,c0=0;
        bool ok=true;
        while(n--)
        {
            int p,c;
            cin>>p>>c;
            if(p<p0||c<c0||p<c||p-p0<c-c0)
                ok=false;
            p0=p,c0=c;
        }
        cout<<(ok?"YES\n":"NO\n");
    }
}