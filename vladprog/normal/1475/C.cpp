#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int ai[N],bi[N];
int cnta[N],cntb[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int a,b,k;
        cin>>a>>b>>k;
        for(int i=1;i<=a;i++)
            cnta[i]=0;
        for(int i=1;i<=b;i++)
            cntb[i]=0;
        int ans=k*(k-1)/2;
        for(int i=1;i<=k;i++)
            cin>>ai[i];
        for(int i=1;i<=k;i++)
            cin>>bi[i];
        for(int i=1;i<=k;i++)
        {
            cnta[ai[i]]++;
            cntb[bi[i]]++;
        }
        for(int i=1;i<=a;i++)
            ans-=cnta[i]*(cnta[i]-1)/2;
        for(int i=1;i<=b;i++)
            ans-=cntb[i]*(cntb[i]-1)/2;
        cout<<ans<<"\n";
    }
}