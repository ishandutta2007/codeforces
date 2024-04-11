#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1000000007;
const int N=100000;

vector <int> a;
int h[N+10]={0},n,b[N+10];
ll g[20010];
void prepare(){
    FOR(i,2,50000) if (h[i]==0){
        a.push_back(i);
        for(int j=i+i;j<=50000;j+=i) h[j]=1;
    }
    memset(h,0,sizeof(h));
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&b[i]);
    //FOR(i,1,n) printf("%d ",b[i]);
}
ll power(ll x,int y){
    if (y==0) return 1;
    if (y==1) return x;
    ll tmp=power(x,y/2);
    if (y%2) return (((tmp*tmp)%MOD)*x)%MOD;
    return (tmp*tmp)%MOD;
}
void solve(){
    g[0]=1;
    FOR(i,1,16000) g[i]=(g[i-1]*i)%MOD;
    int top=a.size();
    //cout<<top;
    FOR(i,1,n){
        for(int j=0;b[i]>1&&j<top;j++) while (b[i]%a[j]==0) h[j]++,b[i]/=a[j];
        if (b[i]>1) a.push_back(b[i]),h[top]=1,top++;
    }
    ll ans=1;
    REP(i,0,top) if (h[i]>0)
        ans=(ans*((g[h[i]+n-1]*power((g[n-1]*g[h[i]])%MOD,MOD-2))%MOD))%MOD;
    cout<<ans;
}
int main(){
    prepare();
    solve();
}