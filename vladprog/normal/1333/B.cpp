#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int a[N],b[N];

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
        int p=n+1,m=n+1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]==1&&p==n+1)
                p=i;
            if(a[i]==-1&&m==n+1)
                m=i;
        }
        for(int i=1;i<=n;i++)
            cin>>b[i];
        bool ok=true;
        for(int i=n;i>=1;i--)
        {
            if(b[i]>a[i]&&p>=i)
                ok=false;
            if(b[i]<a[i]&&m>=i)
                ok=false;
        }
        cout<<(ok?"YES\n":"NO\n");
    }
}