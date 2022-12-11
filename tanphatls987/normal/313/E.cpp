#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10;

int n,m,h[2][N],b[2][N];
void add(int type,int x,int v){
    while (x<=m){
        b[type][x]+=v;
        x+=x&-x;
    }
}
int get(int type,int x){
    int ans=0;
    while (x){
        ans+=b[type][x];
        x-=x&-x;
    }
    return ans;
}
int findpre(int type,int v){
    int ans=m+1,pos=0;
    for(int i=1<<(int(log2(m)));i>0;i>>=1){
        int cur=pos+i;
        if (cur>m) continue;
        if (v>b[type][cur]) v-=b[type][cur],pos=cur;
        else ans=cur;
    }
    return ans;
}
int findbest(int type,int x){
    int ya=findpre(type^1,get(type^1,m))-1,yb=findpre(type^1,get(type^1,m-x))-1;
//    printf("%d %d %d %d\n",type,x,ya,yb);
    if (h[type^1][yb]&&(ya+x)%m<(yb+x)%m) return yb;
    return ya;
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(j,0,1)
        FOR(i,1,n) {
            int x;
            scanf("%d",&x);
            h[j][x]++;
            add(j,x+1,1);
        }
    vector <int> ans;
    REP(phase,0,n){
        int x=findpre(0,n-phase)-1,y;
        while (1){
            y=findbest(0,x);
//            printf("%d %d %d\n",phase,x,y);
            int z=findbest(1,y);
            if (z!=x) x=z;
            else break;
        }
//        printf("%d %d\n",x,y);
        ans.push_back((x+y)%m);
        h[0][x]--;h[1][y]--;
        add(0,x+1,-1);
        add(1,y+1,-1);
    }
    sort(ans.begin(),ans.end(),greater<int>());
    for(auto x:ans) printf("%d ",x);
}