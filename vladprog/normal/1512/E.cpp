#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=510;

int p[N];

bool solve()
{
    int n,l,r,s;
    cin>>n>>l>>r>>s;
    int len=r-l+1;
    for(int i=0;i<=n;i++)
        p[i]=0;
    for(int i=l;i<=r;i++)
        s-=p[i]=p[i-1]+1;
    if(s<0||s>len*(n-len))
        return false;
    int val=s/len;
    for(int i=l;i<=r;i++)
        p[i]+=val,
        s-=val;
    for(int i=r;i>=l;i--)
        if(s)
            p[i]++,
            s--;
    set<int> left;
    for(int i=1;i<=n;i++)
        left.insert(i);
    for(int i=l;i<=r;i++)
        left.erase(p[i]);
    for(int i=1;i<=l-1;i++)
        p[i]=*left.begin(),
        left.erase(left.begin());
    for(int i=r+1;i<=n;i++)
        p[i]=*left.begin(),
        left.erase(left.begin());
    for(int i=1;i<=n;i++)
        cout<<p[i]<<" ";
    cout<<"\n";
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
        if(!solve())
            cout<<-1<<"\n";
}