#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

inline int read()
{
    char c=getchar();int x=0;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x;
}

int a[1<<22],f[1<<22];
int main()
{
    memset(f,0,sizeof(f));
    int n=read();
    ii a[i]=read(),f[a[i]]=i;
    for(int i=0;i<22;++i)
        for(int j=0;j<(1<<22);++j)
            if(j & (1<<i))
                f[j]=max(f[j],f[j^(1<<i)]);
    ii
    {
        int x = (~a[i])&((1<<22)-1);
        if(f[x]) printf("%d ",a[f[x]]);
        else printf("-1 ");
    }
}