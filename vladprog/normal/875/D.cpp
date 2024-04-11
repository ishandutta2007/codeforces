#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,LOG=31;

int a[N],lg2[N],OR[N][LOG],MX[N][LOG];

int getOR(int l,int r)
{
    if(l>r)
        return 0;
    int len=r-l+1;
    int j=lg2[len];
    return OR[l][j]|OR[r-(1<<j)+1][j];
}

int getMX(int l,int r)
{
    if(l>r)
        return 0;
    int len=r-l+1;
    int j=lg2[len];
    return max(MX[l][j],MX[r-(1<<j)+1][j]);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    a[n+1]=-1;

    lg2[1]=0;
    for(int i=2;i<=n;i++)
        lg2[i]=lg2[i/2]+1;
    for(int i=1;i<=n+1;i++)
        OR[i][0]=MX[i][0]=a[i];
    for(int j=1;j<LOG;j++)
        for(int i=1;i+(1<<j)-1<=n+1;i++)
            OR[i][j]=OR[i][j-1]|OR[i+(1<<(j-1))][j-1];
    for(int j=1;j<LOG;j++)
        for(int i=1;i+(1<<j)-1<=n+1;i++)
            MX[i][j]=max(MX[i][j-1],MX[i+(1<<(j-1))][j-1]);

    int ans=0;
    for(int k=1;k<LOG;k++)
    {
        int l=1;
        int orl=a[1];
        int r=1;
        int orr=a[1];
        int sr=a[1];
        for(int i=1;i<=n;i++)
        {
            orr=getOR(i,r);
            orl=getOR(i,l);
            sr=getMX(i,r);
            while(__builtin_popcount(orr)<k||
                  __builtin_popcount(orr)==k&&
                  orr!=sr)
            {
                r++;
                orr=getOR(i,r);
                sr=getMX(i,r);
            }
            while(__builtin_popcount(orl)<k)
            {
                l++;
                orl=getOR(i,l);
            }
            ans+=r-l;
        }
    }
    cout<<ans;
}