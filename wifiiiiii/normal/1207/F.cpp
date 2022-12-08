#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
random_device rng;
mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int N = 707;
ll a[500005];
ll ans[709][709];

inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
int main()
{
    int q=read();
    while(q--)
    {
        int t=read(),x=read(),y=read();
        if(t==1)
        {
            a[x] += y;
            for(int i=1;i<=N;++i) ans[i][x%i] += y;
        }
        else
        {
            if(x<=N) printf("%lld\n",ans[x][y]);
            else
            {
                ll tmp=0;
                for(int i=y;i<=500000;i+=x) tmp+=a[i];
                printf("%lld\n",tmp);
            }
        }
    }
}