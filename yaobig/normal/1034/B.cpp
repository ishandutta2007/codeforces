#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int spe[10][10];

int main()
{
    spe[1][0]=0;
    spe[1][1]=1;
    spe[1][2]=2;
    spe[1][3]=3;
    spe[1][4]=2;
    spe[1][5]=1;

    spe[2][2]=4;
    spe[2][3]=2;
    spe[2][7]=2;

    int n,m; scanf("%d%d",&n,&m);
    if(n>m) swap(n,m);
    ll ans=1ll*n*m;
    if(n==1) ans-=spe[1][m%6];
    else if(n==2)
    {
        if(m<8) ans-=spe[2][m];
    }
    else
    {
        if(n&1 && m&1) ans--;
    }
    printf("%I64d\n",ans);
    return 0;
}