#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int p[N];

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
        for(int i=1;i<=n;i++)
            cin>>p[i];
        bool ok=true;
        for(int i=2;i<=n;i++)
            if(p[i]>p[i-1]&&p[i]-p[i-1]!=1)
                ok=false;
        cout<<(ok?"Yes\n":"No\n");
    }
}