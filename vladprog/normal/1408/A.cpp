#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=110;

int a[N],b[N],c[N],p[N];

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
            cin>>a[i];
        for(int i=1;i<=n;i++)
            cin>>b[i];
        for(int i=1;i<=n;i++)
            cin>>c[i];
        p[1]=a[1];
        for(int i=2;i<=n-1;i++)
            if(a[i]!=p[i-1])
                p[i]=a[i];
            else
                p[i]=b[i];
        if(a[n]!=p[1]&&a[n]!=p[n-1])
            p[n]=a[n];
        else if(b[n]!=p[1]&&b[n]!=p[n-1])
            p[n]=b[n];
        else
            p[n]=c[n];
        for(int i=1;i<=n;i++)
            cout<<p[i]<<" ";
        cout<<"\n";
    }
}