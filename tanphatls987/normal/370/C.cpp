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
const int N=1e2+10;

int n,m,x,h[N]={0};
int main(){
    scanf("%d%d",&n,&m);
    while (n--){
        scanf("%d",&x);
        h[x]++;
    }
    priority_queue <ii> q;
    FOR(i,1,m) if (h[i]) q.push(ii(h[i],i));
    vector <ii> ans;
    while (!q.empty()){
        ii cura=q.top();q.pop();
        if (q.empty()){
            q.push(cura);
            break;
        }
        ii curb=q.top();q.pop();
        ans.push_back(ii(cura.Y,curb.Y));
        ans.push_back(ii(curb.Y,cura.Y));
        if (cura.X>1) q.push(ii(cura.X-1,cura.Y));
        if (curb.X>1) q.push(ii(curb.X-1,curb.Y));
    }
    //for(auto i:ans) printf("%d %d\n",i.X,i.Y);
    if (!q.empty()) {
        ii cur=q.top();
        n=ans.size();
        REP(i,0,n) if (cur.X&&ans[i].X!=cur.Y&&ans[i].Y!=cur.Y){
            ans.push_back(ii(cur.Y,ans[i].Y));
            ans[i].Y=cur.Y;
            cur.X--;
        }
        n=ans.size();
        FOR(i,1,cur.X) ans.push_back(ii(cur.Y,cur.Y));
    }else n=ans.size();
    printf("%d\n",n);
    for(auto i:ans) printf("%d %d\n",i.X,i.Y);
}