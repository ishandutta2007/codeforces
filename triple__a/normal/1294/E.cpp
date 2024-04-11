#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int>
 
using namespace std;
 
typedef long long ll;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn=200007;
int n,m,c[maxn];
vector<int> vec[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    rep(i,n) rep(j,m) {int u; cin>>u; u--; vec[i].pb(u);}
    int ans=0;
    rep(j,m){
        int ret=maxn*2;
        rep(i,n) c[i]=0;
        rep(i,n){
            int r=vec[i][j]/m;
            if (r<n&&r*m+j==vec[i][j]){
                c[(i-r+n)%n]++;
            }
        }
        rep(i,n){
            ret=min(ret,i+n-c[i]);
        }
        ans+=ret;
    }
    cout<<ans<<endl;
    return 0;
}