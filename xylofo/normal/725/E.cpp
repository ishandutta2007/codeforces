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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,c,x;
    cin>>c>>n;
    map<int,int> v;
    rep(i,0,n) cin>>x, ++v[x];
    rep(k,1,c-1){
        ++v[k];
        x = c;
        //cerr<<"!"<<k<<endl;
        vector<pii> p;
        while(x){
            //cerr<<x<<endl;
            auto t = v.upper_bound(x);
            if(t==v.begin()) {
                cout<<k<<endl;
                return 0;
            }
            ll a,b;
            tie(a,b) = *(--t);
            //cerr<<" "<<a<<" "<<b<<endl;
            x -= a * min(b,x/a);

            p.push_back(*t);
            v.erase(t);
        }
        for(auto a:p) v[a.first] = a.second;
        if(--v[k] == 0) v.erase(k);
    }
    cout<<"Greed is good"<<endl;
    return 0;
}