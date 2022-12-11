#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=30;

int n,w[N];
vector <ll> a[N];
vector <int> f[N];
string s;
int main(){
    FOR(i,0,25) cin>>w[i];
    cin>>s;
    n=s.length();
    ll ans=0,cur=0;
    REP(i,0,n){
        cur+=w[s[i]-'a'];
        a[s[i]-'a'].push_back(cur);
        //printf("%d %lld\n",i,cur);
    }
    FOR(i,0,25){
        sort(a[i].begin(),a[i].end());
        a[i].resize(unique(a[i].begin(),a[i].end())-a[i].begin());
        FOR(j,1,a[i].end()-a[i].begin()) f[i].push_back(0);
    }
    cur=0;
    REP(i,0,n){
        int x=s[i]-'a';
        cur+=w[x];
        //printf("%d %d %d")
        int pos=lower_bound(a[x].begin(),a[x].end(),cur-w[x])-a[x].begin();
        if (pos<a[x].end()-a[x].begin()&&a[x][pos]==cur-w[x]) ans+=f[x][pos];
        f[x][lower_bound(a[x].begin(),a[x].end(),cur)-a[x].begin()]++;
    }
    cout<<ans;
}