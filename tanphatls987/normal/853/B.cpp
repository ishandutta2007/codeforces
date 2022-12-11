#include <bits/stdc++.h>

using namespace std;


typedef pair<int,int> ii;
typedef long long ll;

#define X first
#define Y second

const int N=5e5+10,M=1e6+20;
const ll inf=1e12+10;

vector <ii> v[M][2];

int n,m,k;

ll f[M],g[M];

ll curc[N];
ll solve(){
    fill(curc+1,curc+n+1,inf);
    g[M-1]=inf*n;
    for(int i=M-2;i>=1;i--){
        g[i]=g[i+1];
        for(auto j:v[i][0]) if (curc[j.X]>j.Y){
            g[i]=g[i]-curc[j.X]+j.Y;
            curc[j.X]=j.Y;
        }
    }
    fill(curc+1,curc+n+1,inf);
    f[0]=inf*n;
    for(int i=1;i<M;i++){
        f[i]=f[i-1];
        for(auto j:v[i][1]) if (curc[j.X]>j.Y){
            f[i]=f[i]-curc[j.X]+j.Y;
            curc[j.X]=j.Y;
        }
    }
    ll ans=inf;
    for(int i=1;i<M-k-5;i++) ans=min(ans,f[i]+g[i+k+1]);
    if (ans==inf) return -1;
    return ans;
}
void prepare(){
    scanf("%d%d%d",&n,&m,&k);
    while (m--){
        int d,x,y,wei;
        scanf("%d%d%d%d",&d,&x,&y,&wei);
        if (x==0) v[d][0].push_back(ii(y,wei));
        else v[d][1].push_back(ii(x,wei));
    }
}
int main(){
    prepare();
    cout<<solve();
}