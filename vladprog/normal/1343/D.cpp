#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N],cnt[2*N];

void add(int l,int r,int val)
{
    cnt[l]+=val;
    cnt[r+1]-=val;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=0;i<=2*k+10;i++)
            cnt[i]=0;
        for(int i=1;i<=n/2;i++)
        {
            int x=a[i],y=a[n-i+1];
            add(2,2*k,2);
            add(min(1+y,x+1),max(k+y,x+k),-1);
            add(x+y,x+y,-1);
        }
        for(int i=1;i<=2*k;i++)
            cnt[i]+=cnt[i-1];
        int ans=1e9;
        for(int i=2;i<=2*k;i++)
            ans=min(ans,cnt[i]);
        cout<<ans<<"\n";
    }
}