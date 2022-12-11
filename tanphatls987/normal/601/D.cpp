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

const int inf=1e9;
const int MOD=1e9+7;
const int N=3e5+10,alp=26;

int q[N],p[N],n,c[N],a[N],sub[N];
char s[N];
vector <int> v[N];
struct trie{
    int v,x;
    trie* h[alp];
    trie(int _v=0,int _x=0){
        v=_v;x=_x;
        REP(i,0,alp) h[i]=NULL;
    }
};
trie *root[N];
bool comp(int x,int y){
    return sub[x]<sub[y];
}
void BFS(){
    q[1]=1;
    int top=1,bot=1;
    while (top<=bot){
        int x=q[top++];
        for(auto y:v[x]) if (y!=p[x]){
            p[y]=x;
            q[++bot]=y;
        }
    }
    fill(sub+1,sub+n+1,1);
    FORD(i,n,1){
        int x=q[i];
        for(auto y:v[x]) if (y!=p[x]) sub[x]+=sub[y];
    }
    FOR(i,2,n){
        int x=q[i];
        sort(v[x].begin(),v[x].end(),comp);
        v[x].pop_back();
        reverse(v[x].begin(),v[x].end());
    }
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    scanf("\n%s",s);
    FOR(i,1,n) c[i]=s[i-1]-'a';
    int x,y;
    REP(i,1,n){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    BFS();
//    FOR(i,1,n) cout<<c[i]<<" \n"[i==n];
//    FOR(i,1,n) cout<<q[i]<<" \n"[i==n];
//    FOR(i,1,n) cout<<sub[i]<<" \n"[i==n];
//    FOR(i,1,n) cout<<p[i]<<" \n"[i==n];
}
void DFS(trie *croot,trie *cur){
    if (croot->h[cur->x]==NULL) croot->h[cur->x]=new trie(1,cur->x);
    else croot->v-=croot->h[cur->x]->v;
    REP(i,0,alp) if (cur->h[i]!=NULL) DFS(croot->h[cur->x],cur->h[i]);
    croot->v+=croot->h[cur->x]->v;
}
void solve(){
    FORD(pha,n,1){
        int x=q[pha];
        root[x]=new trie(1,c[x]);
        int spe=-1;
        if (!v[x].empty()) {
//            cout<<x<<"<->"<<v[x][0]<<'\n';
            spe=v[x][0];
            root[x]->v+=root[spe]->v;
            root[x]->h[root[spe]->x]=root[spe];
        }
        for(auto y:v[x]) if (y!=p[x]&&y!=spe){
//                printf("->%d %d\n",x,y);
            DFS(root[x],root[y]);
        }
        a[x]+=root[x]->v;
//        cout<<x<<" "<<a[x]<<'\n';
    }
    int ans=*max_element(a+1,a+n+1);
    printf("%d\n%d",ans,count(a+1,a+n+1,ans));
}
int main(){
    prepare();
    solve();
}