#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=5e4+10;

int n;
string s[N];
bool comp(string a,string b){
    int n=a.length(),m=b.length();
    REP(i,0,min(m,n)) if (a[i]!=b[i]) return a[i]<b[i];
    return a+b<b+a;
}
void prepare(){
    cin>>n;
    FOR(i,1,n) cin>>s[i];
    sort(s+1,s+n+1,comp);
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    FOR(i,1,n) cout<<s[i];
}