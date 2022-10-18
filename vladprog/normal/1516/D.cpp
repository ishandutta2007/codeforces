#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100,A=1e5+100,S=sqrt(N)+10;

int lp[A+1];
int a[N];
int last[A];
int nxt[N];
int cnt[N],pos[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> pr;
    for(int i=2;i<=A;i++)
    {
        if(!lp[i])
            pr.push_back(i),
            lp[i]=i;
        for(int p:pr)
        {
            if(p>lp[i]||p*i>A)
                break;
            lp[p*i]=p;
        }
    }

    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    nxt[n+1]=n+1;
    for(int i=n;i>=1;i--)
    {
        nxt[i]=nxt[i+1];
        while(a[i]>1)
        {
            int p=lp[a[i]];
            while(a[i]%p==0)
                a[i]/=p;
            if(last[p])
                nxt[i]=min(nxt[i],last[p]);
            last[p]=i;
        }
    }
    pos[n+1]=n+1;
    for(int i=n;i>=1;i--)
    {
        int block=i/S;
        int rig=(block+1)*S-1;
        if(nxt[i]>rig)
            cnt[i]=1,
            pos[i]=nxt[i];
        else
            cnt[i]=cnt[nxt[i]]+1,
            pos[i]=pos[nxt[i]];
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int ans=0;
        while(pos[l]<=r)
            ans+=cnt[l],
            l=pos[l];
        while(l<=r)
            ans++,
            l=nxt[l];
        cout<<ans<<"\n";
    }
}