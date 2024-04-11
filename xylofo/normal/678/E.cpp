#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define allof(c) (c).begin(), (c).end()
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

int n;
double dp[1<<18][20];
double pb[20][20];

double f(int msk,int cur){
    if(msk&1) return 0;
    if(__builtin_popcount(msk)==n-1) return 1;
    if(dp[msk][cur]!=0)return dp[msk][cur];
    double p=0;
    rep(i,0,n){
        if(i!=cur && !(msk&(1<<i))){
           p = max(p, f(msk|(1<<i),cur)*pb[cur][i] + f(msk|(1<<cur),i)*pb[i][cur]);
        }
    }
    return dp[msk][cur]=p;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    rep(i,0,n){
        rep(j,0,n){
            cin>>pb[i][j];
        }
    }
    double ans=0;
    rep(i,0,n) ans=max(ans,f(0,i));
    cout<<setprecision(30);
    cout<<ans<<endl;
    return 0;
}