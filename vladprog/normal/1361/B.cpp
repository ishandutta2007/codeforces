#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e6+100,MOD=1e9+7;

int ppow(int x,int y)
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

int k[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        cin>>n>>p;
        for(int i=1;i<=n;i++)
            cin>>k[i];
        sort(k+1,k+n+1,greater<int>());
        k[n+1]=0;
        int ans=0;
        bool big=false;
        for(int i=1;i<=n;i++)
        {
            if(!big)
                ans--,
                ans=abs(ans);
            else
                ans=(ans+MOD-1)%MOD;
//            if(ans>N)
//                big=true;
            int mult=k[i]-k[i+1];
            if(p==1||ans==0)
                continue;
            if(mult>25)
            {
                ans=ans*ppow(p,mult)%MOD;
                big=true;
            }
            else while(mult--)
            {
                ans=ans*p;
                if(ans>N)
                    big=true;
                ans%=MOD;
            }
        }
        cout<<ans<<"\n";
    }
}