#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;

#define pb push_back

const int MN = 1005;
ll N, M, k, i, j, x, y, id, arr[MN][MN], w[MN*MN], ord[MN*MN], ans[MN][MN], dx[]={-1,1,0,0}, dy[]={0,0,-1,1}, ds[MN*MN], sz[MN*MN], go, vis[MN][MN], ac[MN][MN];
ll fnd(ll x){return ds[x]=ds[x]==x?x:fnd(ds[x]);}
bool cmp(ll i,ll j){return w[i]>w[j];}

void dfs(ll x,ll y,ll lim){
    if(arr[x][y]<lim) return;
    if(!go) return;
    vis[x][y]=1; ans[x][y]=lim; go--;
    for(int k=0;k<4;k++){
        ll nx = x+dx[k], ny = y+dy[k];
        if(nx<1||nx>N||ny<1||ny>M) continue;
        if(!vis[nx][ny]) dfs(nx,ny,lim);
    }
}

int main(){
    for(scanf("%lld%lld%lld",&N,&M,&k),i=1;i<=N;i++){
        for(j=1;j<=M;j++){
            scanf("%lld",&arr[i][j]);
            w[(i-1)*M+j] = arr[i][j];
            ord[(i-1)*M+j] = (i-1)*M+j;
            ds[(i-1)*M+j] = (i-1)*M+j;
            sz[(i-1)*M+j] = 1;
        }
    }
    sort(ord+1,ord+N*M+1,cmp);
    for(i=1;i<=N*M;i++){
        x = ((ord[i]-1)/M)+1;
        y = (ord[i]-1)%M+1;
        ac[x][y] = 1;
        id = ord[i];
        for(int k=0;k<4;k++){
            ll nx = x+dx[k], ny = y+dy[k];
            if(nx<1||nx>N||ny<1||ny>M) continue;
            if(!ac[nx][ny]) continue;
            ll idd = (nx-1)*M+ny;
            if(fnd(id)!=fnd(idd)){
                sz[fnd(id)]+=sz[fnd(idd)];
                ds[fnd(idd)]=fnd(id);
            }
        }
        if(k%w[id]==0){
            ll req = k/w[id];
            if(sz[fnd(id)]>=req){
                go = req;
                dfs(x,y,w[id]);
                printf("YES\n");
                for(i=1;i<=N;i++){
                    for(j=1;j<=M;j++) printf("%lld ",ans[i][j]);
                    printf("\n");
                }
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}