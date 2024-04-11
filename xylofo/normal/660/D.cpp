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
typedef pair<ll,ll> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pii> v;
    rep(i,0,n){
        ll x,y;
        cin>>x>>y;
        v.pb(mp(x,y));
    }
    map<pii,ll> m;
    ll ans=0;
    rep(i,0,n){
        rep(j,i+1,n){
            pii p(v[i].X+v[j].X,v[i].Y+v[j].Y);
            ans+=m[p];
            m[p]++;
        }
    }
    cout<<ans<<endl;
    return 0;
}