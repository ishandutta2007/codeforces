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
    int n;
    cin>>n;
    set<int> s;
    int ll=0;
    vi l,r;
    rep(i,0,n){
        int x;
        cin>>x;
        if(s.count(x)){
            r.pb(i+1);
            l.pb(ll+1);
            ll=i+1;
            s.clear();
        }
        else s.insert(x);
    }
    if(l.empty())cout<<-1<<endl;
    else{
        if(ll!=n)r.back()=n;
        cout<<l.size()<<endl;
        rep(i,0,l.size())cout<<l[i]<<" "<<r[i]<<"\n";
    }
    return 0;
}