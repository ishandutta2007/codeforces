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
const int N=0;

int h[4]={0};
string s;
int cv(char c){
    if (c=='A') return 0;
    if (c=='C') return 1;
    if (c=='G') return 2;
    return 3;
}
ll power(ll x,int y){
    if (y==0) return 1;
    if (y==1) return x;
    ll tmp=power(x,y/2);
    return ((tmp*tmp)%MOD*power(x,y%2))%MOD;
}
int main(){
    int m;
    cin>>m>>s;
    for(auto c:s) h[cv(c)]++;
    int r=*max_element(h,h+4);
    int n=0;
    FOR(i,0,3) if (h[i]==r) n++;
    cout<<power(n,m);
}