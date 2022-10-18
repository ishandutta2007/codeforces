#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int a[N],p[N];
int s=0;

int solve()
{
    int val=p[1]+s;
    if(val%2)
        val++;
    return val/2;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        p[i]=a[i]-a[i-1];
    for(int i=2;i<=n;i++)
        s+=max(0ll,p[i]);
    cout<<solve()<<"\n";
    int q;
    cin>>q;
    while(q--)
    {
        int l,r,x;
        cin>>l>>r>>x;
        if(l>=2)
            s-=max(0ll,p[l]);
        p[l]+=x;
        if(l>=2)
            s+=max(0ll,p[l]);
        if(r<=n-1)
        {
            s-=max(0ll,p[r+1]);
            p[r+1]-=x;
            s+=max(0ll,p[r+1]);
        }
        cout<<solve()<<"\n";
    }
}