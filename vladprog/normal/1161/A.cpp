#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair

const int N=1e5+100,K=1e5+100;

int x[K],l[N],r[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++)
        cin>>x[i];
    for(int i=1;i<=n;i++)
        l[i]=k+1,r[i]=0;
    for(int i=1;i<=k;i++)
        l[x[i]]=min(l[x[i]],i),
        r[x[i]]=max(r[x[i]],i);
    sort(x+1,x+k+1);
    int ans=3*n-2;
    ans-=set<int>(x+1,x+k+1).size();
    for(int i=1;i<=k-1;i++)
    {
        int a=x[i],b=x[i+1];
        if(b!=a+1)
            continue;
        ans-=2;
        if(l[a]>r[b]||l[b]>r[a])
            ans++;
    }
    cout<<ans;
}