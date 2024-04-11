#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
const ld one=1;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100,INF=1e18;

int a[N],b[N],x[N],k[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
        cin>>a[i],
        a[i]-=b[i];
    for(int i=2;i<=n;i++)
        cin>>x[i]>>k[i];
    for(int i=n;i>=2;i--)
        if(a[i]>0)
        {
            ld res=a[x[i]]+one*a[i]*k[i];
            if(res>INF)
                a[x[i]]=INF;
            else
                a[x[i]]+=a[i]*k[i];
        }
        else
            a[x[i]]-=-a[i],
            a[x[i]]=max(a[x[i]],-INF);
    cout<<(a[1]<=0?"YES":"NO");
}