#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=5010,S=1e5;

int lp[S+1];
vector<int> pr;

int a[N];
set<int> b;

int f(int x)
{
    int res=0;
    for(int i:pr)
        while(x%i==0)
            x/=i,
            res+=(b.count(i)?-1:1);
    if(x>1)
        res+=(b.count(x)?-1:1);
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=2;i<=S;i++)
    {
        if(lp[i]==0)
            lp[i]=i,
            pr.push_back(i);
        for(int p:pr)
        {
            if(p*i>S||p>lp[i])
                break;
            lp[p*i]=p;
        }
    }

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    while(m--)
    {
        int x;
        cin>>x;
        b.insert(x);
    }
    for(int i=n;i>=1;i--)
    {
        int g=0;
        for(int j=1;j<=i;j++)
            g=__gcd(g,a[j]);
        if(f(g)<0)
            for(int j=1;j<=i;j++)
                a[j]/=g;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=f(a[i]);
    cout<<ans;
}