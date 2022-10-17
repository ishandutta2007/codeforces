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

ll f(ll a,ll n){
    return n/a;
}
ll lcm(ll a, ll b){
    return a/__gcd(a,b)*b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,a,b,p,q;
    cin>>n>>a>>b>>p>>q;
    ll m = f(a,n)*p+f(b,n)*q, l=lcm(a,b);
    cout<<m-f(l,n)*min(p,q)<<endl;
    return 0;
}