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
const int N=0;

string s;
int convert(char ch){
    if (ch>='0'&&ch<='9') return ch-'0';
    if (ch>='A'&&ch<='Z') return 10+ch-'A';
    if (ch>='a'&&ch<='z') return 36+ch-'a';
    if (ch=='-') return 62;
    return 63;
}
int main(){
//    freopen("input.inp","r",stdin);
    cin>>s;
    int val=0;
    for(auto ch:s) val+=6-__builtin_popcount(convert(ch));
    ll ans=1;
    FOR(i,1,val) ans=ans*3%MOD;
    cout<<ans;
}