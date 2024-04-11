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
const int N=2e6+10;

int p10[10],t[N],s[N],g[N],p,q;
int getdig(int x,int pos){
    return x/p10[pos]%10;
}
void prepare(){
    p10[0]=1;
    FOR(i,1,6) p10[i]=p10[i-1]*10;
    p10[7]=N;
    REP(i,2,N) {
        g[i]=g[i-1];
        if (!t[i]){
            g[i]++;
            for(int j=i+i;j<N;j+=i) t[j]=1;
        }
    }
    FOR(len,0,6){
        REP(i,p10[len],p10[len+1]){
            bool ok=1;
            s[i]=s[i-1];
            FOR(j,0,len) if (getdig(i,j)!=getdig(i,len-j)) ok=0;
            if (ok) s[i]++;
        }
    }
//    cout<<s[999999]<<" "<<g[999999];
}
int solve(){
    int ans=0;
    REP(i,1,p10[7]) if (1LL*q*g[i]<=1LL*p*s[i]) ans=i;
    return ans;
}
int main(){
    prepare();
    cin>>p>>q;
    cout<<solve();
}