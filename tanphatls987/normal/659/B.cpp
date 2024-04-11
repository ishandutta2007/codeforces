#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,string> is;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10;

vector <is> v[N];
string s;
int m;
bool comp(is a,is b){
    return a.X<b.X;
}
void prepare(){
    int n,x,y;
    cin>>n>>m;
    while (n--){
        cin>>s>>x>>y;
        v[x].push_back(is(y,s));
    }
}
void solve(){
    FOR(i,1,m){
        sort(v[i].begin(),v[i].end(),comp);
//        for(auto j:v[i]) cout<<j.X<<" "<<j.Y<<'\n';
        int n1=v[i].size();
        if (n1>2&&v[i][n1-2].X==v[i][n1-3].X){
            printf("?\n");
            continue;
        }
        FOR(j,1,2) cout<<v[i][n1-j].Y<<" \n"[j==2];
    }
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    solve();
}