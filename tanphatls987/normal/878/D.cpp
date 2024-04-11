#include <bits/stdc++.h>

using namespace std;

const int N=1e5+20;

typedef long long ll;


int w[12][N];
bitset <(1<<12)> f[N];
int p[N][12];

int n,m,g[N*20];

int main(){
    int test;
    cin>>n>>m>>test;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++) cin>>w[i][j];

    for(int i=0;i<m;i++)
        for(int j=0;j<(1<<m);j++) f[i][j]=(j>>i)&1;
    for(int j=0;j<n;j++){
        for(int i=0;i<m;i++) p[j][i]=w[i][j];
        sort(p[j],p[j]+m);
        for(int att=0;att<m;att++){
            int val=0;
            for(int per=m-1;per>=0;per--) val=val*2+(w[per][j]>=p[j][att]);
            g[j*m+att]=val;
//            cout<<g[j*m+att]<<'\n';
        }

    }

    int cur=m-1;
    while (test--){
        int type,x,y;
        cin>>type>>x>>y;
        x--,y--;
        if (type==3){
            int ans=0;
            for(int j=0;j<m;j++){
                int idx=g[y*m+j];
                if (f[x][idx]) ans=max(ans,p[y][j]);
            }
            cout<<ans<<'\n';
            continue;
        }
        cur++;
        if (type==1) f[cur]=f[x]|f[y];
        else f[cur]=f[x]&f[y];
    }
}