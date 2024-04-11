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
    vvi v(n);
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        x--,y--;
        v[x].pb(y);
        v[y].pb(x);
    }
    set<int> s,ss;
    rep(i,0,2*n)s.insert(i);
    function<void(int,int,int)> dfs=[&](int a,int p,int d){
        if(v[a].size()==1){
            int x=*s.lower_bound(d); 
            s.erase(x);
            ss.insert(x);
            return;
        }
        for(int b:v[a])if(b!=p){
            dfs(b,a,d+1);
        }
    };
    int ans=0;
    for(int a:v[0]){
        dfs(a,0,1);
        for(int x:ss)s.insert(x);
        ans=max(ans,*ss.rbegin());
        ss.clear();
    }
    cout<<ans<<endl;
    return 0;
}