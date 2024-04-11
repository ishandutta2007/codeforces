#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("274d.inp","r",stdin)
#define OUTPUT freopen("274d.out","w",stdout)
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
const int N=3e5+10;


bool ok=true;
vector <int> a[N],ans;
vector <ii> p;
int n,m,x,low[N],num[N];
stack <int> s;
void DFS(int x){
    static int c=0;
    s.push(x);
    num[x]=low[x]=++c;
    for(auto y:a[x]) if (num[y]>=0){
        if (num[y]==0) DFS(y);
        low[x]=min(low[x],low[y]);
    }
    if (low[x]>=num[x]){
        int c1=1;
        num[x]=-1;
        while (s.top()!=x){
            num[s.top()]=-1;
            c1++;s.pop();
        }
        ans.push_back(x);
        s.pop();
        if (c1!=1) ok=false;
    }
}
int main(){
    scanf("%d%d",&m,&n);
    int fake=n;
    while (m--){
        p.clear();
        FOR(i,1,n) {
            scanf("%d",&x);
            if (x!=-1) p.push_back(ii(x,i));
        }
        sort(p.begin(),p.end());
        REP(i,p.begin(),p.end()){
            auto j=i;
            while (j<p.end()&&j->X==i->X) j++;
            ++fake;
            //printf("%d %d\n",i-p.begin(),j-i);
            REP(k,i,j){
                if (i!=p.begin()) a[fake-1].push_back(k->Y);
                if (j!=p.end()) a[k->Y].push_back(fake);
            }
            i=j-1;
        }
    }
    FOR(i,1,fake) if (!num[i]) DFS(i);
    if (!ok) printf("-1");
    else REP(i,ans.rbegin(),ans.rend()) if (*i<=n) printf("%d ",*i);
}