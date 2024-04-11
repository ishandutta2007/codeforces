#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

int ppow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)
            res=res*x;
        y>>=1;
        x=x*x;
    }
    return res;
}

int root(int x,int y)
{
    int res=pow(x,ld(1)/y);
    while(ppow(res,y)>x)
        res--;
    while(ppow(res,y)<=x)
        res++;
    return res;
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
        int a,b;
        cin>>a>>b;
        int ans=1e10;
        for(int i=1;i<=35;i++)
//            cout<<a<<" "<<b<<" "<<i<<" -> "<<root(a,i)<<" -> "<<i+max(0ll,root(a,i))<<"\n",
            ans=min(ans,i+max(0ll,root(a,i)-b));
        cout<<ans<<"\n";
//        cout<<flush;
    }
}