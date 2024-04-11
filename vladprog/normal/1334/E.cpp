#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int L=55,MOD=998244353;

int f[L],r[L];

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

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int d;
    cin>>d;
    vector<int> divs;
    for(int i=2;i*i<=d;i++)
        if(d%i==0)
        {
            divs.push_back(i);
            while(d%i==0)
                d/=i;
        }
    if(d>1)
        divs.push_back(d);

    f[0]=1;
    for(int i=1;i<L;i++)
        f[i]=f[i-1]*i%MOD;
    r[L-1]=ppow(f[L-1],MOD-2);
    for(int i=L-2;i>=0;i--)
        r[i]=r[i+1]*(i+1)%MOD;

    int q;
    cin>>q;
    while(q--)
    {
        int v,u;
        cin>>v>>u;
        vector<int> a;
        for(int x:divs)
        {
            int k=0;
            while(v%x==0)
                v/=x,
                k++;
            a.push_back(k);
        }
        vector<int> b;
        for(int x:divs)
        {
            int k=0;
            while(u%x==0)
                u/=x,
                k++;
            b.push_back(k);
        }
        int add=0,sub=0;
        int ans=1;
        for(int i=0;i<divs.size();i++)
        {
            int cur=b[i]-a[i];
            if(cur>0)
                add+=cur;
            else
                sub+=-cur;
            ans=ans*r[abs(cur)]%MOD;
        }
//        cout<<add<<" "<<sub<<" -> ";
        ans=ans*f[add]%MOD*f[sub]%MOD;
        cout<<ans<<"\n";
    }
}