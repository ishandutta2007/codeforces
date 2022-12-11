#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=5e5+10;

int n,pa[N],lv[N];
vector <int> v[N],leaf;
bool comp(int x,int y){
    return lv[x]<lv[y];
}
void DFS(int x){
    lv[x]=lv[pa[x]]+1;
    if (v[x].size()==1){
        leaf.push_back(x);
        return;
    }
    for(auto y:v[x]) if (y!=pa[x]){
        pa[y]=x;
        DFS(y);
    }
}
void prepare(){
    scanf("%d",&n);
    REP(i,1,n){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
}
int solve(){
    int ans=0;
    for(auto st:v[1]) {
        pa[st]=1;
        leaf.clear();
        DFS(st);
        sort(leaf.begin(),leaf.end(),comp);
        int n1=leaf.size(),cur=lv[leaf[0]];
        REP(i,1,n1) cur=max(cur+1,lv[leaf[i]]);
        ans=max(ans,cur);
    }
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}