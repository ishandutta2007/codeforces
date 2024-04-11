#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10;

int height,n,h[N<<1];
vector <pll> q[2];
ll cord[N<<1];
int main(){
    scanf("%d%d",&height,&n);
    int lv,type,m=2;
    ll L,R;
    cord[1]=1LL<<(height-1);
    cord[2]=1LL<<height;
    FOR(i,1,n) {
        scanf("%d%I64d%I64d%d",&lv,&L,&R,&type);
        L<<=height-lv,R=(R+1)<<(height-lv);
        cord[++m]=L;
        cord[++m]=R;
        q[type].push_back(pll(L,R));
    }
    sort(cord+1,cord+m+1);
    m=unique(cord+1,cord+m+1)-cord-1;
    FOR(j,0,1)
        for(auto i:q[j]){
            int x=lower_bound(cord+1,cord+m+1,i.X)-cord;
            int y=lower_bound(cord+1,cord+m+1,i.Y)-cord;
//            printf("%d %d %d\n",j,x,y);
            if (j) h[x]++,h[y]--;
            else h[1]++,h[x]--,h[y]++;
        }
    FOR(i,1,m) h[i]+=h[i-1];
//    FOR(i,1,m) cout<<cord[i]<<" \n"[i==m];
//    FOR(i,1,m) cout<<h[i]<<" \n"[i==m];
    if (!count(h+1,h+m,n)) printf("Game cheated!");
    else{
        ll ans=0;
        REP(i,1,m) if (h[i]==n){
            if (cord[i+1]-cord[i]>1||ans){
                printf("Data not sufficient!");
                return 0;
            }
            ans=cord[i];
        }
        cout<<ans;
    }
}