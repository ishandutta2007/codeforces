#pragma clang diagnostic ignored "-Wcomma"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wformat"
#pragma clang diagnostic ignored "-Wunused-variable"

#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)


int a[20000],b[20000],c[20000],d[20000],e[20000];
int main()
{
    memset(c,0x3f,sizeof(c));
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        int t;
        cin>>t;
        int cur=0;
        while(t--)
        {
            int k;
            cin>>k;
            cur += 1<<(k-1);
        }
        a[cur]++;
    }
    for(int i=1;i<=m;++i)
    {
        int val, t;
        cin>>val>>t;
        int cur=0;
        while(t--)
        {
            int k;
            cin>>k;
            cur += 1<<(k-1);
        }
        b[cur]++;
        if(val < c[cur])
        {
            c[cur] = val;
            d[cur] = i;
        }
    }
    int minv=1e9,maxx=-1,x=1,y=2;
    for(int i=1;i<512;++i)
    {
        if(!b[i]) continue;
        for(int j=i+1;j<512;++j)
        {
            if(!b[j]) continue;
            int bs[10] = {0};
            for(int k=0;k<9;++k) if(i&(1<<k)) bs[k]=1;
            for(int k=0;k<9;++k) if(j&(1<<k)) bs[k]=1;
            int tmp=0;
            for(int k=0;k<512;++k)
            {
                if(!a[k]) continue;
                int ok=1;
                for(int h=0;h<9;++h) if(((1<<h)&k) && !bs[h]) ok=0;
                if(!ok) continue;;
                tmp += a[k];
            }
            if(tmp>maxx)
            {
                maxx=tmp;
                minv=c[i]+c[j];
                x=d[i],y=d[j];
            }
            else if(tmp==maxx)
            {
                if(minv>c[i]+c[j])
                {
                    minv=c[i]+c[j],x=d[i],y=d[j];
                }
            }
        }
    }
    cout<<x<<" "<<y<<endl;
}