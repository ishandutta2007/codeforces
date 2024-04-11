#include<bits/stdc++.h>
#define MAXN 1005
#define MAXM 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,a[MAXN][MAXN];
int go(int col)
{
    int x=1,y=col;
    while(x<=n&&y>=1&&y<=m)
    {
        if(a[x][y]==1) {a[x][y]=2; y++;}
        else if(a[x][y]==3) {a[x][y]=2; y--;}
        else x++;
    }
    return y;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=k;i++)
    {
        int x;
        scanf("%d",&x);
        printf("%d ",go(x));
    }
    return 0;
}