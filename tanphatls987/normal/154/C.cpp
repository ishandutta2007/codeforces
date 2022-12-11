#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define X first
#define Y second

const int alp=27;
const int N=1e6+10;
const int MOD=1e9+7;
const int BASE[2]={2,43};



int n,m;
ll pb[2][N];
ii ha[N];

ii operator +(ii a,ii b){
    return ii((a.X+b.X)%MOD,(a.Y+b.Y)%MOD);
}

bool comp(int x,int y){
    return ha[x]<ha[y];
}
int p[N];
void prepare(){
    for(int j=0;j<=1;j++){
        pb[j][0]=1;
        for(int i=1;i<N;i++) pb[j][i]=pb[j][i-1]*BASE[j]%MOD;
    }
    cin>>n>>m;
    while (m--){
        int x,y;
        cin>>x>>y;
        ha[x]=ha[x]+ii(pb[0][y],pb[1][y]);
        ha[y]=ha[y]+ii(pb[0][x],pb[1][x]);
    }
    ll ans=0;

    for(int i=1;i<=n;i++) p[i]=i;
    sort(p+1,p+n+1,comp);
    for(int en=1;en<=n;){
        int st=en;
        while (en<=n&&ha[p[st]].X==ha[p[en]].X&&ha[p[st]].Y==ha[p[en]].Y) en++;
        ans+=1LL*(en-st)*(en-st-1)/2;
    }
    for(int i=1;i<=n;i++) ha[i]=ha[i]+ii(pb[0][i],pb[1][i]);
    sort(p+1,p+n+1,comp);
    for(int en=1;en<=n;){
        int st=en;
        while (en<=n&&ha[p[st]].X==ha[p[en]].X&&ha[p[st]].Y==ha[p[en]].Y) en++;
        ans+=1LL*(en-st)*(en-st-1)/2;
    }
    cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prepare();

}