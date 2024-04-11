#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef bitset <1200> bst;
bst operator +(bst a,bst b)
{
    bst c;
    int h=0;
    for(int i=0;i<1200;++i)
    {
        c[i]=(a[i]+b[i]+h)%2;
        if((a[i]+b[i]+h)>=2)
        {
            h=1;
        }
        else
        {
            h=0;
        }
    }
    return c;
}
bst operator -(bst a,bst b)
{
    bst c;
    for(int i=0;i<1200;++i)
    {
        c[i]=0;
    }
    for(int i=1199;i>=0;i--)
    {
        if(a[i]>=b[i])
        {
            c[i]=a[i]-b[i];
        }
        else
        {
            c[i]=1;
            for(int j=(i+1);j<1200;++j)
            {
                if(c[j]==1)
                {
                    c[j]=0;
                    break;
                }
                else
                {
                    c[j]=1;
                }
            }
        }
    }
    return c;
}
int sravn(bst a,bst b)
{
    for(int i=1199;i>=0;i--)
    {
        if(a[i]>b[i])
        {
            return 1;
        }
        else if(b[i]>a[i])
        {
            return -1;
        }
    }
    return 0;
}
bst po(int x)
{
    bst a;
    for(int i=0;i<1200;++i)
    {
        a[i]=0;
    }
    a[x]=1;
    return a;
}
bst go(bst u)
{
    bst a;
    for(int i=0;i<1199;++i)
    {
        a[i]=u[i+1];
    }
    a[1199]=0;
    return a;
}
const int maxn=500;
vector <int> a(maxn);
vector <bst> b(maxn);
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        b[i]=po(a[i]);
    }
    vector <bst> pr(n+1);
    for(int i=0;i<1200;++i)
    {
        pr[0][i]=0;
    }
    for(int i=1;i<=n;++i)
    {
        pr[i]=pr[i-1]+b[i-1];
    }
    bool dp[n][n+1];
    int x,y;
    for(int l=1;l<=n;++l)
    {
        for(int i=0;i<=(n-l);++i)
        {
            //cout<<i<<" "<<l<<endl;
            if(l==1)
            {
                dp[i][i+1]=true;
                continue;
            }
            x=i;
            y=(l+i);
            bst t=pr[y]-pr[x];
            //cout<<x<<" "<<y<<" "<<t.count()<<endl;
            if(t.count()!=1)
            {
                dp[x][y]=false;
            }
            else
            {
                bst u=go(t);
                int low=x;
                int up=y;
                while(true)
                {
                    //cout<<low<<" "<<up<<endl;
                    if((up-low)==1)
                    {
                        dp[x][y]=(dp[x][low] && dp[low][y] && !sravn(pr[low]-pr[x],u));
                        break;
                    }
                    int k=(low+up)/2;
                    if(sravn(pr[k]-pr[x],u)==1)
                    {
                        up=k;
                    }
                    else
                    {
                        low=k;
                    }
                }
            }
        }
    }
    int ans[n+1];
    ans[n]=0;
    for(int i=(n-1);i>=0;i--)
    {
        ans[i]=1e18;
        for(int j=(i+1);j<=n;++j)
        {
            if(dp[i][j])
            {
                //cout<<i<<" "<<j<<endl;
                ans[i]=min(ans[i],ans[j]+1);
            }
        }
    }
    cout<<ans[0];
    return 0;
}