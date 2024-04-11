#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=5e5+100,MOD=998244353;

int ppow(int x,int y=MOD-2)
{
    int res=1;
    while(y)
    {
        if(y&1)
            res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}

int dp[N][10];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int d=0;d<10;d++)
        dp[0][d]=d+1;
    for(int d=0;d<10;d++)
        dp[1][d]=9-d+2*dp[0][d];
    for(int i=2;i<=n;i++)
        for(int d=0;d<10;d++)
            dp[i][d]=(2*dp[i-1][d]+
                      8*dp[i-2][d])%MOD;
    string c;
    cin>>c;
    set<int> s;
    for(int i=0;i<n;i++)
        if(c[i]!='1'||i==n-1)
            s.insert(i);
    int ans=1;
    #define f(l,r) dp[r-l][c[r]-'0']
    int l=0;
    for(int r:s)
    {
        ans=ans*f(l,r)%MOD;
        l=r+1;
    }
//    cout<<ans<<"\n";
    s.insert(-1);
    while(m--)
    {
        int x,d;
        cin>>x>>d;
        x--;
        bool was=(c[x]!='1'||x==n-1);
        bool now=(d!=1||x==n-1);
//        cout<<x<<" "<<d<<" -> "<<was<<" "<<now<<" -> ";
        if(was&&!now)
        {
//            cout<<"one ";
            auto it=s.find(x);
            int l1=(*prev(it))+1;
            int r1=x;
            int l2=x+1;
            int r2=*next(it);
            ans=ans*ppow(f(l1,r1))%MOD;
            ans=ans*ppow(f(l2,r2))%MOD;
            ans=ans*f(l1,r2)%MOD;
            s.erase(it);
            c[x]='0'+d;
        }
        if(now&&!was)
        {
//            cout<<"two ";
            c[x]='0'+d;
            s.insert(x);
            auto it=s.find(x);
            int l1=(*prev(it))+1;
            int r1=x;
            int l2=x+1;
            int r2=*next(it);
            ans=ans*ppow(f(l1,r2))%MOD;
            ans=ans*f(l1,r1)%MOD;
            ans=ans*f(l2,r2)%MOD;
        }
        if(was==now&&c[x]!='0'+d)
        {
//            cout<<"three ";
            auto it=s.find(x);
            int l=(*prev(it))+1;
            int r=x;
            ans=ans*ppow(f(l,r))%MOD;
            c[x]='0'+d;
            ans=ans*f(l,r)%MOD;
        }
        cout<<ans<<"\n";
    }
}