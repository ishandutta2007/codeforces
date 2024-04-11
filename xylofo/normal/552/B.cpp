#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define trav(it,c) for(auto it=(c).begin();it!=(c).end();++it)
#define allof(c) (c).begin(), (c).end()
#define pb push_back
#define mp make_pair
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
    ll p[1000];
    p[0]=1;
    rep(i,1,15)p[i]=10*p[i-1];
    ll n;
    cin>>n;
    ll b=log10(10.0*n)+1e-15;
    ll a=(n+1)*b-(p[b]-1)/9;
    cout<<a<<endl;
    return 0;
}
//a(n) = (n+1)*floor[log10(10n)]-(10^floor[log10(10n)]-1)/(10-1) = a(n-1)+floor[log10(10n)]