#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=5e3+10;

int n=0,m,h[N<<1];
string s1,s2,name[N<<1];
vector <int> a[N<<1];
map <string,int> ma;
void solve(){
    cout<<n<<'\n';
    FOR(x,1,n){
        memset(h,0,sizeof(h));
        for(auto y:a[x]) h[y]=1;
        h[x]=1;
        int mcom=0,c=0;
        FOR(y,1,n) if (!h[y]){
            int com=0;
            for(auto z:a[y]) com+=h[z];
            if (com>mcom) mcom=com,c=0;
            if (com==mcom) c++;
        }
        cout<<name[x]<<" "<<c<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>m;
    while (m--){
        cin>>s1>>s2;
        if (!ma[s1]) ma[s1]=++n,name[n]=s1;
        if (!ma[s2]) ma[s2]=++n,name[n]=s2;
        int x=ma[s1],y=ma[s2];
        a[x].push_back(y);
        a[y].push_back(x);
    }
    solve();
}