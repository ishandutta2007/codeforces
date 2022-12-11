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
const int M=2e5+5,N=M<<1;

int s[N][2],v[N][2],m,x,y,h[N],ans[N];
vector <int> e[N],g;
void DFS(int x){
    int top=1;
    s[1][1]=x;
    while (top){
        int x=s[top][1];
        if (h[x]==e[x].size()){
            ans[s[top--][0]]=(x>M)?1:-1;
            //printf("%d ",x);
            continue;
        }
        int idx=e[x][h[x]++],nx=v[idx][0]+v[idx][1]-x;
        if (ans[idx]) continue;
        ans[idx]=-2;
        s[++top][1]=nx;
        s[top][0]=idx;
    }
    //if (cur.size()>1) for(auto i:cur) printf("%d ",i);
    //ENDL;
}
int main(){
    scanf("%d",&m);
    FOR(i,1,m){
        scanf("%d%d",&x,&y);
        y+=M;
        v[i][0]=x,v[i][1]=y;
        e[x].push_back(i);
        e[y].push_back(i);
        //printf("%d %d %d\n",i,x,y);
    }
    int n=m;
    FOR(i,1,2*M) if (e[i].size()%2) g.push_back(i);
    int m1=g.size();
    for(int i=0;i<m1;i+=2){
        ++n;
        v[n][0]=g[i];v[n][1]=g[i+1];
        e[g[i]].push_back(n);
        e[g[i+1]].push_back(n);
    }
    FOR(i,1,2*M) if (!h[i]&&!e[i].empty()) DFS(i);
    //FOR(i,1,m) printf("%d\n",ans[i]);
    FOR(i,1,m) printf("%c",(ans[i]==1)?'b':'r');
}