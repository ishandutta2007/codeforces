#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define rrep(it,st,en) for(int it=(en-1);it>=(int)(st);--it)
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int tt=0;
    vector<pii> v(n);
    rep(i,0,n) cin>>v[i].Y,tt+=v[i].Y;
    rep(i,0,n) cin>>v[i].X;
    sort(allof(v));
    reverse(allof(v));
    int k = 0,vol=0;
    while(vol<tt) vol+=v[k++].X;
    vector<vector<vector<int> > > dp(n+1,vvi(k+1,vi(tt+1,-1e9)));
    dp[n][k][tt]=0;
    rrep(pos,0,n){
        rep(left,0,k+1){
            rrep(vl,0,tt+1){
                dp[pos][left][vl] = max(dp[pos][left][vl], dp[pos+1][left][vl]);
                if(left<k) dp[pos][left][vl] = max(dp[pos][left][vl], dp[pos+1][left+1][min(tt,vl+v[pos].X)]+v[pos].Y);
            }
        }
    }
    cout<<k<<" "<<tt-dp[0][0][0]<<endl;
    return 0;
}