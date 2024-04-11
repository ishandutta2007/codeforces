#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1500
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int c[maxn+5][maxn+5];
int ans[maxn+5];
vector<pii> lst[maxn+5][maxn+5],tmp;
bool used[maxn*maxn+5];

int n,q; 

void solve(int x,int y)
{
    tmp.clear(); tmp.pb({0,c[x][y]});
    if(x>1) for(auto it: lst[x-1][y]) tmp.pb(it);
    if(y>1) for(auto it: lst[x][y-1]) tmp.pb(it);
    if(x>1 && y>1) for(auto it: lst[x-1][y-1]) tmp.pb(it);
    sort(tmp.begin(),tmp.end());
    for(auto [dis,clr]: tmp) if(used[clr]==0)
    {
        used[clr]=1;
        lst[x][y].pb({dis+1,clr});
        if((int)lst[x][y].size()>q) break;
    }
    for(auto [dis,clr]: lst[x][y]) used[clr]=0;
    int L=min(x,y);
    if((int)lst[x][y].size()==q+1) chmin(L,lst[x][y].back().FI-1);
    ans[L]++;
}

int main()
{
    scanf("%d%d",&n,&q);
    rep(i,1,n) rep(j,1,n) scanf("%d",&c[i][j]);
    rep(i,1,n) rep(j,1,n) solve(i,j);
    per(i,1,n-1) ans[i]+=ans[i+1];
    rep(i,1,n) printf("%d\n",ans[i]);
    return 0;
}