#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=5e5+100;

int l[N],r[N],a[2*N],p[N];

int leader(int x)
{
    return x==p[x]?x:p[x]=leader(p[x]);
}

void un(int x,int y)
{
    x=leader(x);
    y=leader(y);
    if(x==y)
        cout<<"NO",exit(0);
    if(rand()%2)
        p[x]=y;
    else
        p[y]=x;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
        a[l[i]]=i,
        a[r[i]]=-i;
        p[i]=i;
    }
    set<pair<int,int>> s;
    int cnt=0;
    for(int i=1;i<=2*n;i++)
        if(a[i]<0)
            s.erase({r[-a[i]],-a[i]});
        else
        {
            for(auto x:s)
                if(x.first<r[a[i]])
                    un(a[i],x.second),
                    cnt++;
                else
                    break;
            s.insert({r[a[i]],a[i]});
        }
    cout<<(cnt==n-1?"YES":"NO");
}