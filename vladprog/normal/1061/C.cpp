#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=1e5+100;
const int M=1e6+100;
const int MOD=1e9+7;
int lp[M+1],dp[M],add[M];
vector<int> pr;
map<int,int> m;
vector<int> d;

void per(int t,map<int,int>::iterator l,
               map<int,int>::iterator r)
{
    if(l==r)
        d.push_back(t);
    else
    {
        for(int i=0;i<=l->second;i++)
            per(t,next(l),r),t*=l->first;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=2;i<=M;i++)
    {
        if(!lp[i]) lp[i]=i,pr.push_back(i);
        for(int p:pr)
        {
            if(p*i>M||p>lp[i])
                break;
            lp[p*i]=p;
        }
    }
    dp[0]=1;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        m.clear();
        while(t>1)
            m[lp[t]]++,t/=lp[t];
        d.clear();
        per(1,m.begin(),m.end());
//        for(int x:d) cout<<x<<" ";
//        cout<<"\n";
        for(auto x:d)
            /*cout<<x<<" -> "<<(*/add[x]=dp[x-1]/*)<<" , "*/;
//        cout<<"\n";
        for(auto x:d)
            dp[x]=(dp[x]+add[x])%MOD;
    }
    int s=0;
    for(int i=1;i<=n;i++)
        s=(s+dp[i])%MOD;
    cout<<s;
}