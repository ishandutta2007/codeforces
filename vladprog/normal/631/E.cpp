#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=2e5+100,INF=1e18;

int n;
int a[N];

#define sum(var) \
int s##var[N]; \
int sum##var(int l,int r) \
{ \
    return s##var[r]-s##var[l-1]; \
}

sum(a)
sum(ai)

int ans=-INF;

int solve(int from,int to)
{
    int res;
    if(from==to)
        res=sumai(1,n);
    if(from<to)
        res=sumai(1,from-1)+sumai(from+1,to)-suma(from+1,to)+sumai(to+1,n)+a[from]*to;
    if(from>to)
        res=sumai(1,to-1)+sumai(to,from-1)+suma(to,from-1)+sumai(from+1,n)+a[from]*to;
//    cout<<from<<" -> "<<to<<" => "<<res<<"\n";
    ans=max(ans,res);
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],
        sa[i]=sa[i-1]+a[i],
        sai[i]=sai[i-1]+a[i]*i;
    for(int i=1;i<=n;i++)
    {
        int l=1,r=n;
        while(r-l>1)
        {
            int m1=(l*2+r)/3;
            int m2=(l+r*2)/3;
            int res1=solve(i,m1);
            int res2=solve(i,m2);
            if(res1<res2)
                l=m1+1;
            else
                r=m2-1;
        }
        for(int m=l;m<=r;m++)
            solve(i,m);
    }
    cout<<ans;
}