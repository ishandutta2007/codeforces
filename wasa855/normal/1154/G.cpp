#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e15
int a[1000005];
int used[10000005];
int prim[1000005];
bool vis[10000005];
int cnt;
void prime(int N)
{
    for(int i=2;i<=N;i++)
    {
        if(vis[i]==false)
        {
            prim[++cnt]=i;
        }
        for(int j=1;j<=cnt;j++)
        {
            if(i*prim[j]>N)
            {
                break;
            }
            int to=i*prim[j];
            vis[to]=true;
            if(i%prim[j]==0)
            {
                break;
            }
        }
    }
}
int gcd(int x,int y)
{
    if(y==0)
    {
        return x;
    }
    return gcd(y,x%y);
}
signed main()
{
    int n;
    cin>>n;
    int maxn=0;
    int ans=INF;
    int t1=0,t2=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if(used[a[i]]!=0)
        {
            if(a[i]<ans)
            {
                ans=a[i];
                t1=used[a[i]];
                t2=i;
            }
        }
        used[a[i]]=i;
        if(a[i]>maxn)
        {
            maxn=a[i];
        }
    }
    // prime(maxn);
    for(int i=1;i<=maxn;i++)
    {
        if(i>ans)
        {
            break;
        }
        int sum=0;
        int x=0,y=0;
        for(int j=i;j<=maxn;j+=i)
        {
            if(used[j]==0)
            {
                continue;
            }
            if(x==0)
            {
                x=j;
                y=used[j];
            }
            else
            {
//                cout<<"ZHI\n";
                int lcm=x*j/i;
//                printf("%lld %lld %lld\n",y,used[j],lcm);
                if(lcm<ans)
                {
                    ans=lcm;
                    t1=y;
                    t2=used[j];
                }
            }
        }
    }
    if(t1>t2)
    {
        swap(t1,t2);
    }
    // cout<<ans<<endl;
    printf("%lld %lld\n",t1,t2);
    return 0;
}