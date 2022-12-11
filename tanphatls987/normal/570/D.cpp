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
const int N=5e5+10,alp=26;

int in[N],out[N],h[N],pos[N],g[N][alp],n,m,x,y;
char s[N];
vector <int> v[N],b[N];
void DFS(int x){
    static int c=0;
    in[x]=++c;
    b[h[x]].push_back(x);
    for(auto y:v[x]) {
        h[y]=h[x]+1;
        DFS(y);
    }
    out[x]=c;
}
void solve(){
    h[1]=1;
    DFS(1);
    int m1=*max_element(h+1,h+n+1),c=0;
    FOR(i,1,m1)
        for(auto x:b[i]){
//            printf("%d ",x);
            pos[x]=++c;
            REP(j,0,alp) g[c][j]=g[c-1][j];
            g[c][s[x-1]-'a']++;
        }
//    ENDL;
//    FOR(i,1,n) printf("%d ",pos[i]);
}
int findb(int x,int v,int type){
    int L=0,R=b[v].size()-1;
    while (L<=R){
        int M=(L+R)/2;
        if (type==0){
            if (in[b[v][M]]<in[x]) L=M+1;
            else R=M-1;
        }else{
            if (out[b[v][M]]>out[x]) R=M-1;
            else L=M+1;
        }
    }
    if (!type&&L==b[v].size()) return -1;
    if (type&&L==0) return -1;
    return L;
}
bool check(int x,int v){
    int L=findb(x,v,0),R=findb(x,v,1);
    if (L==-1||R==-1) return 1;
    L=pos[b[v][L]],R=pos[b[v][R-1]];
    int ans=0;
//    printf("->%d %d ",L,R);
    REP(i,0,alp) ans+=(g[R][i]-g[L-1][i])&1;
    return (ans<=1);
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,2,n) {
        scanf("%d",&x);
        v[x].push_back(i);
    }
    scanf("\n%s",s);
    solve();
    while (m--){
        scanf("%d%d",&x,&y);
        if (check(x,y)) printf("Yes\n");
        else printf("No\n");
    }
}