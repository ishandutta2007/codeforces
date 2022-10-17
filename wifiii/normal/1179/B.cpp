#include <bits/stdc++.h>
typedef long long ll;
//typedef unsigned long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

int main()
{
    
    int n,m;
    scanf("%d%d",&n,&m);
    int top=1,bot=n,l=1,r=m;
    while(top<bot)
    {
        l=1,r=m;
        for(;l<=m;++l,--r) printf("%d %d\n%d %d\n",top,l,bot,r);
        top++,bot--;
    }
    if(top==bot)
    {
        l=1,r=m;
        for(;l<r;++l,--r) printf("%d %d\n%d %d\n",top,l,bot,r);
    }
    if(l==r) printf("%d %d",top,l);
}