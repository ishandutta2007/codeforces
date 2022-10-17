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
    int n;
    cin>>n;
    map<pair<int,pii>,int> m;
    vi x,y;
    rep(_,0,n){
        int xx,yy;
        cin>>xx>>yy;
        rep(i,0,x.size()){
            int a=yy-y[i];
            int b=x[i]-xx;
            int c=-(b*yy+a*xx);
            int g=__gcd(__gcd(a,b),c);
            a/=g;
            b/=g;
            c/=g;
            if(c<0)a=-a,b=-b,c=-c;
            m[{c,{a,b}}]++;
        }
        x.pb(xx);
        y.pb(yy);
    }
    ll ans=0;
    for(auto p:m){
        ll k=p.second;
        ll pp=0;
        while(pp*(pp-1)/2!=k)++pp;
        ans+=k*(n-pp);
    }
    cout<<ans/3<<endl;
    return 0;
}