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

const ll md = 1000000007;

long long inv(long long a, long long b){
    return 1<a ? b - inv(b%a,a)*b/a : 1;
}

ll pow(ll a,ll n){
    ll r=1;
    while(n){
        if(n&1)r=(r*a)%md;
        a=(a*a)%md;
        n>>=1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,n,x;
    cin>>a>>b>>n>>x;
    ll t = (a==1 ? n : ((pow(a,n)-1) * inv(a-1,md)))%md;
    ll ans = ((pow(a,n) * x)%md) + (b * t)%md;
    cout<<((ans)%md+md)%md<<endl;
    return 0;
}