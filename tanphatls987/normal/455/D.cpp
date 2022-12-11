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
const int N=1e5+10,M=350;

int n,qu,m,g[M][N],a[N],type,x,y,k;
deque <int> q[M];

void prepare(){
    scanf("%d",&n);
    REP(i,0,n) scanf("%d",a+i);
    m=max(int(sqrt(n)),2);
    REP(i,0,n){
        int st=i*m,en=min(st+m,n);
        if (st>=n) break;
        REP(j,st,en) {
            q[i].push_back(j);
            g[i][a[j]]++;
        }
    }
}
void query1(int x,int y){
    if (x==y) return;
    int stbl=x/m,enbl=y/m;
    int cury=q[enbl][y%m];
//    printf("%d %d %d\n",x,y,cury);
    g[enbl][a[cury]]--;
    g[stbl][a[cury]]++;
    q[enbl].erase(q[enbl].begin()+y%m);
    q[stbl].insert(q[stbl].begin()+x%m,cury);
    REP(i,stbl,enbl){
        int x=q[i].back();
        q[i].pop_back();
        g[i][a[x]]--;g[i+1][a[x]]++;
        q[i+1].push_front(x);
    }
}
int query2(int x,int y,int k){
    int stbl=x/m,enbl=y/m,ans=0;
    if (stbl==enbl) FOR(i,x%m,y%m) ans+=(a[q[stbl][i]]==k);
    else{
        FOR(i,stbl+1,enbl-1) ans+=g[i][k];
        REP(i,x%m,m) if (a[q[stbl][i]]==k) ans++;
        FOR(i,0,y%m) if (a[q[enbl][i]]==k) ans++;
    }
    return ans;
}
void getquery(){
    static int last=0;
    scanf("%d%d%d",&type,&x,&y);
    x=(x+last-1)%n;
    y=(y+last-1)%n;
    if (x>y) swap(x,y);
//    printf("->%d %d %d\n",type,x,y);
    if (type==2){
        scanf("%d",&k);
        k=(last+k-1)%n+1;
        last=query2(x,y,k);
        printf("%d\n",last);
    }else query1(x,y);
}
int main(){
    prepare();
    scanf("%d",&qu);
    while (qu--) getquery();
}