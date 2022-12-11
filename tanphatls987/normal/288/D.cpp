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
const int N=1e5+10;

ll sub[N];
int n;
vector <int> v[N];
ll C2(int x){
    return 1LL*x*(x-1)/2;
}
ll DFS(int par,int x){
    ll ans=0;
    sub[x]=1;
    for(auto y:v[x]) if (y!=par){
        ans+=DFS(x,y);
        sub[x]+=sub[y];
    }
    ll sum1=1,sum2=0;
    for(auto y:v[x]) if (y!=par){
        ans+=2*sum1*sub[y]*C2(n-sub[x]);
        ans-=2*C2(sub[y])*sum2;
        sum1+=sub[y];
        sum2+=C2(sub[y]);
    }
//    cout<<x<<" "<<ans<<'\n';
    return ans;
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n-1){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
}
int main(){
    prepare();
    cout<<DFS(0,1);
}