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
const int N=1e5+10,M=1e4+10;

int b[2][M],n,m;
ii p[N];
vector <int> a[N];
void add(int* b,int x,int v){
    while (x<M){
        b[x]+=v;
        x+=x&-x;
    }
}
int get(int* b,int x){
    int ans=0;
    while (x){
        ans+=b[x];
        x-=x&-x;
    }
    return ans;
}
int findfre(int v){
    int pos=0,ans=M;
    for(int i=1<<int(log2(M));i;i>>=1){
        int cur=pos+i;
        if (cur>=M) continue;
        if (v>b[0][cur]) v-=b[0][cur],pos=cur;
        else ans=cur;
    }
    return ans;
}
void prepare(){
    int x,v;
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d%d",&x,&v);
        a[x].push_back(v);
    }
    REP(i,0,N) sort(a[i].begin(),a[i].end(),greater<int>());
//    printf("tick\n");
    m=0;
    REP(i,1,N)
        REP(j,0,a[i].size()) p[++m]=ii(j+1,a[i][j]+1);
    sort(p+1,p+m+1);

}
int solve(){
    FOR(j,1,m) {
        add(b[0],p[j].Y,1);
        add(b[1],p[j].Y,p[j].Y);
    }
//    printf("tik\n");
//    FOR(i,1,m) printf("%d %d\n",p[i].X,p[i].Y);
    int cur=a[0].size(),ans=inf,ccost=0;
    for(int per=n,j=m;per>=0;per--){
        while (j&&p[j].X>=per) {
            add(b[0],p[j].Y,-1);
            add(b[1],p[j].Y,-p[j].Y);
            ccost+=p[j].Y-1;
            j--;
            cur++;
        }
        int cadd=0;
        if (per>cur){
            int cneed=findfre(per-cur);
            int c2=get(b[0],cneed-1);
//            printf("->%d %d %d\n",per,cur,cneed);
            cadd=get(b[1],cneed-1)-c2+(per-cur-c2)*(cneed-1);
        }
//        printf("%d %d %d\n",per,cur,ccost+cadd);
        ans=min(ans,ccost+cadd);
    }
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}