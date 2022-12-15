#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;

#define pb push_back

const int MN = 1e6+6;
int m, h[2], a[2], x[2], y[2], vis[MN], t, l[2], s[2], c;

int main(){
    scanf("%d",&m);
    for(int i=0;i<2;i++) scanf("%d%d%d%d",&h[i],&a[i],&x[i],&y[i]);
    for(int i=0;i<2;i++){
        memset(vis,-1,sizeof(vis));
        c = h[i];
        for(t=0;;t++){
            if(vis[c]!=-1){
                l[i] = t-vis[c];
                break;
            }
            vis[c] = t;
            c = (1LL*c*x[i]+y[i])%m;
        }
        int ff, ss;
        if(!vis[a[i]]==-1){
            printf("-1\n");
            return 0;
        }
        s[i] = vis[a[i]];
        if(vis[a[i]]<vis[c]) l[i]=0;
    }
    for(int i=0;i<MN;i++){
        ll kek = 1LL*i*l[0]+s[0]-s[1];
        if((l[1]==0&&kek==0)||(l[1]!=0&&kek%l[1]==0&&kek>=0)){
            printf("%lld\n",kek+s[1]);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}