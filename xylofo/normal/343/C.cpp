#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define allof(c) (c).begin(), (c).end()
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define X first
#define Y second
typedef long long ll; 
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vi h(n),p(m);
    rep(i,0,n)cin>>h[i];
    rep(i,0,m)cin>>p[i];
    auto f = [&](ll d){
        ll pi=0;
        rep(i,0,n){
            ll left=p[pi];
            while(pi<m && min(abs(p[pi]-h[i]),abs(left-h[i])) + p[pi]-left <= d) pi++;
            if(pi==m)return true;
        }
        return false;
    };
    ll a=-1,b=1e11;
    while(a+1<b){
        ll mid=(a+b)/2;
        if(f(mid))b=mid;
        else a=mid;
    }
    cout<<b<<endl;
    return 0;
}