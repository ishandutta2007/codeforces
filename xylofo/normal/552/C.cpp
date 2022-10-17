#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define trav(it,c) for(auto it=(c).begin();it!=(c).end();++it)
#define allof(c) (c).begin(), (c).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
typedef unsigned long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll pw[1000];
    ll w,m;
    int mx=0;
    cin>>w>>m;
    pw[0]=1;
    rep(i,1,35){
        pw[i]=w*pw[i-1];
        if(pw[i]>3*m)mx=i+1;
    }
    vi b;
    while(m){
        b.pb(m%w);
        m/=w;
    }
    b.pb(0);
    b.pb(0);
    rep(i,0,b.size()){
        if(b[i]==0 || b[i]==1)continue;
        if(b[i]==w-1 || b[i]==w){
            ++b[i+1];
            continue;
        }
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    return 0;
}