#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=110;

int t[N],l[N],r[N];

bool solve(int n,int m)
{
    int cur=0;
    while(true)
    {
        int pos=1;
        while(pos<=n&&t[pos]<cur)
            pos++;
//        cout<<cur<<" "<<m<<" "<<pos<<"\n";
        while(pos<=n&&t[pos]==cur)
            if(!(l[pos]<=m&&m<=r[pos]))
                return false;
            else
                pos++;
        if(pos==n+1)
            return true;
        int nxt=pos;
        int L=-2e9,R=2e9;
        while(pos<=n&&l[pos]<=m&&m<=r[pos])
            L=max(L,l[pos]),
            R=min(R,r[pos]),
            pos++;
        if(pos==n+1)
            return true;
        int to=(l[pos]<m?r[pos]:l[pos]);
//        cout<<cur<<" "<<m<<" "<<nxt<<" "<<pos<<" "<<L<<" "<<R<<" "<<to<<"\n";
        if(t[pos]-cur<abs(m-to))
            return false;
        to=max(to,L);
        to=min(to,R);
        int len=min(t[nxt]-cur,abs(m-to));
        if(to>m)
            to=min(to,m+len);
        else
            to=max(to,m-len);
        if(len==0)
            cur=t[nxt];
        else
            cur+=len,
            m=to;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>q;
    while(q--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>t[i]>>l[i]>>r[i];
        cout<<(solve(n,m)?"YES\n":"NO\n");
    }
}