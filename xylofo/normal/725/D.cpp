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
    vector<pii> v(n-1);
    ll t,w;
    cin>>t>>w;
    rep(i,0,n-1){
        ll x,y;
        cin>>x>>y;
        v[i] = pii(x,y);
    }
    sort(allof(v));
    reverse(allof(v));
    multiset<ll> out,in;
    ll sm = 0;
    ll ans = 1e9;
    v.emplace_back(0,0);
    if(t >= v[0].X) ans=1;
    rep(i,0,n-1){
        ll tt = v[i+1].X;

        ll T = t-tt;
        out.insert(v[i].Y-v[i].X+1);

        while(!out.empty() && !in.empty() && *out.begin() < *in.rbegin()){
            sm -= *in.rbegin(), out.insert(*in.rbegin()), in.erase(--in.end());
            sm += *out.begin(), in.insert(*out.begin()), out.erase(out.begin());
        }
        while(!out.empty() && T-sm >= *out.begin()) {
            sm += *out.begin(), in.insert(*out.begin()), out.erase(out.begin());
        }
        if(T>=0) ans = min(ans, ll(i+2-in.size()));
    }
    cout<<ans<<endl;
    return 0;
}