#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int d[N];

int f(int k)
{
    return k*(k+1)/2;
}

int g(int a,int b)
{
    return (a+b)*(b-a+1)/2;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++)
        cin>>d[i];
    int ans=0;
    for(int l=1,r=1,len=0,sum=0;l<=n;len-=d[l],sum-=f(d[l]),l++)
    {
        while(true)
            if(len+d[r]<=x)
            {
                len+=d[r];
                sum+=f(d[r]);
                r++;
                if(r==n+1)
                    r=1;
            }
            else
                break;
        ans=max(ans,sum+f(x-len));
    }
    reverse(d+1,d+n+1);
    for(int l=1,r=1,len=0,sum=0;l<=n;len-=d[l],sum-=f(d[l]),l++)
    {
        while(true)
            if(len+d[r]<=x)
            {
                len+=d[r];
                sum+=f(d[r]);
                r++;
                if(r==n+1)
                    r=1;
            }
            else
                break;
        ans=max(ans,sum+g(d[r]-(x-len)+1,d[r]));
    }
    cout<<ans;
}