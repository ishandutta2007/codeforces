#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

const int n=666;
int rx[n+5],ry[n+5];
bool occ[maxn+5][maxn+5];

const int mov[4][2]={1,1,1,-1,-1,1,-1,-1};
const int mov_backup[4][2]={1,0,1,0,-1,0,-1,0};

int gr()
{
    int k,x,y; scanf("%d%d%d",&k,&x,&y);
    if(k==-1) return 1;
    occ[rx[k]][ry[k]]=0;
    rx[k]=x;ry[k]=y;
    occ[rx[k]][ry[k]]=1;
    return 0;
}

int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    rep(i,1,n) scanf("%d%d",&rx[i],&ry[i]);
    rep(i,1,n) occ[rx[i]][ry[i]]=1;
    while(x!=500 || y!=500)
    {
        if(x<500) x++;
        else if(x>500) x--;
        else if(y<500) y++;
        else if(y>500) y--;
        else assert(0);

        printf("%d %d\n",x,y);
        fflush(stdout);
        if(gr()) return 0;
    }
    int cnt[4]={};
    rep(i,1,n)
    {
        if(rx[i]<500 && ry[i]<500) cnt[0]++;
        if(rx[i]<500 && ry[i]>500) cnt[1]++;
        if(rx[i]>500 && ry[i]<500) cnt[2]++;
        if(rx[i]>500 && ry[i]>500) cnt[3]++;
    }
    int id=0,N=cnt[0];
    rep(i,1,3) if(cnt[i]<N) id=i,N=cnt[i];
    while(1)
    {
        int nx=x+mov[id][0];
        int ny=y+mov[id][1];
        if(occ[nx][ny]==0) x=nx,y=ny;
        else x+=mov_backup[id][0],y+=mov_backup[id][1];

        printf("%d %d\n",x,y);
        fflush(stdout);
        if(gr()) return 0;
    }
    return 0;
}